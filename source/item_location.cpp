#include "item_location.hpp"

#include "debug.hpp"
#include "dungeon.hpp"
#include "keys.hpp"
#include "settings.hpp"
#include "shops.hpp"
#include "spoiler_log.hpp"

#include "s_dungeon.h"

extern bool gInitError;

// Location definitions
std::array<ItemLocation, KEY_ENUM_MAX> ItemLocation::table;
// Count of locations added to the table, excluding hint types
static u32 sInitializedItemLocations = 0;

void ItemLocation::InitTable() {
    InitTable_Overworld();
    InitTable_Dungeons();
    InitTable_GoldSkulltulas();
    InitTable_Misc();
    InitTable_Shops();
    InitTable_Rupees();
    InitTable_Hearts();
    InitTable_Hints();

    // Verify that the max possible location count is less than ITEM_OVERRIDES_MAX
    u32 maxLocCount = sInitializedItemLocations;
    // For each dungeon, only consider the quest type with most locations.
    for (auto dungeon : Dungeon::dungeonList) {
        u32 mqLocCount      = dungeon->GetMQLocations().size();
        u32 vanillaLocCount = dungeon->GetVanillaLocations().size();
        maxLocCount -= std::min(mqLocCount, vanillaLocCount);
    }

    if (maxLocCount > ITEM_OVERRIDES_MAX) {
        CitraPrint("ERROR! Max location count: " + std::to_string(maxLocCount));
        gInitError = true;
    }
}

void ItemLocation::OnInit(void) {
    if (type >= ItemLocationType::HintStone) {
        return; // Ignore hint reachability locations
    }

    sInitializedItemLocations++;
    if (name.size() > 51) { // max length for in-game menu
        CitraPrint("ERROR! Location name too long: " + name);
        gInitError = true;
    }
}

void ItemLocation::AddExcludeOption(void) {
    // setting description  /*--------------------------------------------------*/
    std::string_view desc = "Decide which locations you want to exclude from\n"
                            "the location pool. Locations that require an item\n"
                            "to be placed at them based on your current\n"
                            "settings cannot be excluded and won't be shown\n"
                            "unless you change your settings.\n"
                            "\n"
                            "If you exclude too many locations, it might not\n"
                            "be possible to fill the world.";

    // add option to forbid any location from progress items
    if (name.length() < 23) {
        excludedOption = Option::Bool(name, { "Include", "Exclude" }, { desc });
    } else {
        // insert a newline character if the text is too long for one row
        size_t lastSpace        = name.rfind(' ', 23);
        std::string settingText = name;
        settingText.replace(lastSpace, 1, "\n ");

        excludedOption = Option::Bool(settingText, { "Include", "Exclude" }, { desc });
    }

    Settings::excludeLocationsOptionsVector[collectionCheckGroup].push_back(&excludedOption);
}

void ItemLocation::ResetVariables(void) {
    checked            = false;
    addedToPool        = false;
    placedItem         = NONE;
    delayedItem        = NONE;
    hintedAt           = false;
    isHintable         = false;
    price              = 0;
    hasShopsanityPrice = false;
    overridden         = false;
}

ItemLocation* Location(LocationKey locKey) {
    return ItemLocation::Get(locKey);
}

std::vector<LocationKey> allLocations          = {};
std::vector<LocationKey> everyPossibleLocation = {};

// set of overrides to write to the patch
std::set<ItemOverride, ItemOverride_Compare> overrides = {};

std::vector<std::vector<LocationKey>> playthroughLocations;
std::vector<LocationKey> wothLocations;
bool playthroughBeatable   = false;
bool allLocationsReachable = false;
bool showItemProgress      = false;

u16 itemsPlaced = 0;

void AddLocation(LocationKey loc, std::vector<LocationKey>* destination = &allLocations) {
    destination->push_back(loc);
}

template <typename Container>
void AddLocations(const Container& locations, std::vector<LocationKey>* destination = &allLocations) {
    destination->insert(destination->end(), std::cbegin(locations), std::cend(locations));
}

// sort through Vanilla and MQ dungeon locations
void GenerateLocationPool() {

    allLocations.clear();
    AddLocation(LINKS_POCKET);
    AddLocations(overworldLocations);

    if (Settings::TriforceHunt) {
        AddLocation(TRIFORCE_HUNT_GOAL);
    }

    for (auto dungeon : Dungeon::dungeonList) {
        AddLocations(dungeon->GetDungeonLocations());
    }
}

void PlaceItemInLocation(LocationKey locKey, ItemKey item, bool applyEffectImmediately /*= false*/) {
    auto loc = Location(locKey);
    PlacementLog_Msg("\n");
    PlacementLog_Msg(ItemTable(item).GetName().GetNAEnglish());
    PlacementLog_Msg(" placed at ");
    PlacementLog_Msg(loc->GetName());
    PlacementLog_Msg("\n\n");

    if (applyEffectImmediately || Settings::Logic.Is(LOGIC_NONE) || Settings::Logic.Is(LOGIC_VANILLA)) {
        ItemTable(item).ApplyEffect();
    }

    itemsPlaced++;
    if (showItemProgress) {
        double completion   = (double)itemsPlaced / (double)(allLocations.size() + dungeonRewardLocations.size());
        std::string message = "\x1b[8;10HPlacing Items.";
        message += completion > 0.25 ? "." : " ";
        message += completion > 0.50 ? "." : " ";
        printf("%s", message.c_str());
    }

    // If we're placing a non-shop item in a shop location, we want to record it for custom messages
    if (ItemTable(item).GetItemType() != ITEMTYPE_SHOP && loc->IsCategory(Category::cShop)) {
        int index                = TransformShopIndex(GetShopIndex(locKey));
        NonShopItems[index].Name = ItemTable(item).GetName();
        NonShopItems[index].Repurchaseable =
            ItemTable(item).GetItemType() == ITEMTYPE_REFILL || ItemTable(item).GetHintKey() == PROGRESSIVE_BOMBCHUS;
    }

    loc->SetPlacedItem(item);
}

std::vector<LocationKey> GetLocations(const std::vector<LocationKey>& locationPool, Category categoryInclude,
                                      Category categoryExclude /*= Category::cNull*/) {
    std::vector<LocationKey> locationsInCategory;
    for (LocationKey locKey : locationPool) {
        if (Location(locKey)->IsCategory(categoryInclude) && !Location(locKey)->IsCategory(categoryExclude)) {
            locationsInCategory.push_back(locKey);
        }
    }
    return locationsInCategory;
}

void LocationReset() {
    for (LocationKey il : allLocations) {
        Location(il)->RemoveFromPool();
    }

    for (LocationKey il : dungeonRewardLocations) {
        Location(il)->RemoveFromPool();
    }

    for (LocationKey il : gossipStoneLocations) {
        Location(il)->RemoveFromPool();
    }

    Location(GANONDORF_HINT)->RemoveFromPool();
}

void ItemReset() {
    for (LocationKey il : allLocations) {
        Location(il)->ResetVariables();
    }

    for (LocationKey il : dungeonRewardLocations) {
        Location(il)->ResetVariables();
    }

    itemsPlaced = 0;
}

void HintReset() {
    for (LocationKey il : gossipStoneLocations) {
        Location(il)->ResetVariables();
    }
}

// Fills everyPossibleLocation and creates an exclusion option for each location.
// everyPossibleLocation is used in the menu to lock/hide excluding locations
void AddExcludedOptions() {
    AddLocations(overworldLocations, &everyPossibleLocation);

    for (auto dungeon : Dungeon::dungeonList) {
        AddLocations(dungeon->GetEveryLocation(), &everyPossibleLocation);
    }

    for (LocationKey il : everyPossibleLocation) {
        Location(il)->AddExcludeOption();
    }
}

void CreateItemOverrides() {
    PlacementLog_Msg("NOW CREATING OVERRIDES\n\n");
    for (LocationKey locKey : allLocations) {
        auto loc               = Location(locKey);
        ItemOverride_Value val = ItemTable(loc->GetPlacedItemKey()).Value();
        // If this is an ice trap in a shop, change the name based on what the model will look like
        if (loc->GetPlacedItemKey() == ICE_TRAP && loc->IsCategory(Category::cShop)) {
            NonShopItems[TransformShopIndex(GetShopIndex(locKey))].Name = GetIceTrapName(val.looksLikeItemId);
        }
        if (loc->IsOverridden()) {
            overrides.insert({
                .key   = loc->Key(),
                .value = val,
            });
        }
        PlacementLog_Msg("\tScene: ");
        PlacementLog_Msg(std::to_string(loc->Key().scene));
        PlacementLog_Msg("\tType: ");
        PlacementLog_Msg(std::to_string(loc->Key().type));
        PlacementLog_Msg("\tFlag:  ");
        PlacementLog_Msg(std::to_string(loc->Key().flag));
        PlacementLog_Msg("\t");
        PlacementLog_Msg(loc->GetName());
        PlacementLog_Msg(": ");
        if (loc->IsOverridden()) {
            PlacementLog_Msg(loc->GetPlacedItemName().GetNAEnglish());
        } else {
            PlacementLog_Msg("Not Overridden");
        }
        PlacementLog_Msg("\n");
    }
    PlacementLog_Msg("Overrides Created: ");
    PlacementLog_Msg(std::to_string(overrides.size()));
}
