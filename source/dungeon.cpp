#include "s_dungeon.h"

#include "dungeon.hpp"
#include "category.hpp"
#include "item_location.hpp"
#include "pool_functions.hpp"
#include "keys.hpp"

namespace Dungeon {

DungeonInfo::DungeonInfo(std::string name_, HintKey hintKey_, ItemKey map_, ItemKey compass_, ItemKey smallKey_,
                         ItemKey keyRing_, ItemKey bossKey_, u8 vanillaKeyCount_, u8 mqKeyCount_)
    : name(std::move(name_)), hintKey(hintKey_), map(map_), compass(compass_), smallKey(smallKey_), keyRing(keyRing_),
      bossKey(bossKey_), vanillaKeyCount(vanillaKeyCount_), mqKeyCount(mqKeyCount_) {
}

DungeonInfo::~DungeonInfo() = default;

HintKey DungeonInfo::GetHintKey() const {
    return hintKey;
}

ItemKey DungeonInfo::GetSmallKey() const {
    return smallKey;
}

ItemKey DungeonInfo::GetKeyRing() const {
    return keyRing;
}

ItemKey DungeonInfo::GetMap() const {
    return map;
}

ItemKey DungeonInfo::GetCompass() const {
    return compass;
}

ItemKey DungeonInfo::GetBossKey() const {
    return bossKey;
}

void DungeonInfo::PlaceVanillaMap() {
    if (map == NONE) {
        return;
    }

    auto dungeonLocations = GetDungeonLocations();
    auto mapLocation      = FilterFromPool(
             dungeonLocations, [](const LocationKey loc) { return Location(loc)->IsCategory(Category::cVanillaMap); })[0];
    PlaceItemInLocation(mapLocation, map);
}

void DungeonInfo::PlaceVanillaCompass() {
    if (compass == NONE) {
        return;
    }

    auto dungeonLocations = GetDungeonLocations();
    auto compassLocation  = FilterFromPool(dungeonLocations, [](const LocationKey loc) {
        return Location(loc)->IsCategory(Category::cVanillaCompass);
    })[0];
    PlaceItemInLocation(compassLocation, compass);
}

void DungeonInfo::PlaceVanillaBossKey() {
    if (bossKey == NONE || bossKey == GANONS_CASTLE_BOSS_KEY) {
        return;
    }

    auto dungeonLocations = GetDungeonLocations();
    auto bossKeyLocation  = FilterFromPool(dungeonLocations, [](const LocationKey loc) {
        return Location(loc)->IsCategory(Category::cVanillaBossKey);
    })[0];
    PlaceItemInLocation(bossKeyLocation, bossKey);
}

void DungeonInfo::PlaceVanillaSmallKeys() {
    if (smallKey == NONE) {
        return;
    }

    auto dungeonLocations  = GetDungeonLocations();
    auto smallKeyLocations = FilterFromPool(
        dungeonLocations, [](const LocationKey loc) { return Location(loc)->IsCategory(Category::cVanillaSmallKey); });
    for (auto location : smallKeyLocations) {
        PlaceItemInLocation(location, smallKey);
    }
}

// Gets the chosen dungeon locations for a playthrough (so either MQ or Vanilla)
std::vector<LocationKey> DungeonInfo::GetDungeonLocations() const {
    auto locations = masterQuest ? mqLocations : vanillaLocations;
    AddElementsToPool(locations, sharedLocations);
    return locations;
}

// Gets all dungeon locations (MQ + Vanilla)
std::vector<LocationKey> DungeonInfo::GetEveryLocation() const {
    auto locations = vanillaLocations;
    AddElementsToPool(locations, mqLocations);
    AddElementsToPool(locations, sharedLocations);
    return locations;
}

DungeonInfo DekuTree = DungeonInfo("Deku Tree", DEKU_TREE, DEKU_TREE_MAP, DEKU_TREE_COMPASS, NONE, NONE, NONE, 0, 0);

DungeonInfo DodongosCavern = DungeonInfo("Dodongo's Cavern", DODONGOS_CAVERN, DODONGOS_CAVERN_MAP,
                                         DODONGOS_CAVERN_COMPASS, NONE, NONE, NONE, 0, 0);

DungeonInfo JabuJabusBelly = DungeonInfo("Jabu Jabu's Belly", JABU_JABUS_BELLY, JABU_JABUS_BELLY_MAP,
                                         JABU_JABUS_BELLY_COMPASS, NONE, NONE, NONE, 0, 0);

DungeonInfo ForestTemple =
    DungeonInfo("Forest Temple", FOREST_TEMPLE, FOREST_TEMPLE_MAP, FOREST_TEMPLE_COMPASS, FOREST_TEMPLE_SMALL_KEY,
                FOREST_TEMPLE_KEY_RING, FOREST_TEMPLE_BOSS_KEY, FOREST_KEY_COUNT, FOREST_MQ_KEY_COUNT);

DungeonInfo FireTemple =
    DungeonInfo("Fire Temple", FIRE_TEMPLE, FIRE_TEMPLE_MAP, FIRE_TEMPLE_COMPASS, FIRE_TEMPLE_SMALL_KEY,
                FIRE_TEMPLE_KEY_RING, FIRE_TEMPLE_BOSS_KEY, FIRE_KEY_COUNT, FIRE_MQ_KEY_COUNT);

DungeonInfo WaterTemple =
    DungeonInfo("Water Temple", WATER_TEMPLE, WATER_TEMPLE_MAP, WATER_TEMPLE_COMPASS, WATER_TEMPLE_SMALL_KEY,
                WATER_TEMPLE_KEY_RING, WATER_TEMPLE_BOSS_KEY, WATER_KEY_COUNT, WATER_MQ_KEY_COUNT);

DungeonInfo SpiritTemple =
    DungeonInfo("Spirit Temple", SPIRIT_TEMPLE, SPIRIT_TEMPLE_MAP, SPIRIT_TEMPLE_COMPASS, SPIRIT_TEMPLE_SMALL_KEY,
                SPIRIT_TEMPLE_KEY_RING, SPIRIT_TEMPLE_BOSS_KEY, SPIRIT_KEY_COUNT, SPIRIT_MQ_KEY_COUNT);

DungeonInfo ShadowTemple =
    DungeonInfo("Shadow Temple", SHADOW_TEMPLE, SHADOW_TEMPLE_MAP, SHADOW_TEMPLE_COMPASS, SHADOW_TEMPLE_SMALL_KEY,
                SHADOW_TEMPLE_KEY_RING, SHADOW_TEMPLE_BOSS_KEY, SHADOW_KEY_COUNT, SHADOW_MQ_KEY_COUNT);

DungeonInfo BottomOfTheWell =
    DungeonInfo("Bottom of the Well", BOTTOM_OF_THE_WELL, BOTTOM_OF_THE_WELL_MAP, BOTTOM_OF_THE_WELL_COMPASS,
                BOTTOM_OF_THE_WELL_SMALL_KEY, BOTTOM_OF_THE_WELL_KEY_RING, NONE, BOTW_KEY_COUNT, BOTW_MQ_KEY_COUNT);

DungeonInfo IceCavern =
    DungeonInfo("Ice Cavern", ICE_CAVERN, ICE_CAVERN_MAP, ICE_CAVERN_COMPASS, NONE, NONE, NONE, 0, 0);

DungeonInfo GerudoTrainingGrounds =
    DungeonInfo("Gerudo Training Grounds", GERUDO_TRAINING_GROUNDS, NONE, NONE, GERUDO_TRAINING_GROUNDS_SMALL_KEY,
                GERUDO_TRAINING_GROUNDS_KEY_RING, NONE, GTG_KEY_COUNT, GTG_MQ_KEY_COUNT);

DungeonInfo GanonsCastle =
    DungeonInfo("Ganon's Castle", GANONS_CASTLE, NONE, NONE, GANONS_CASTLE_SMALL_KEY, GANONS_CASTLE_KEY_RING,
                GANONS_CASTLE_BOSS_KEY, GANON_KEY_COUNT, GANON_MQ_KEY_COUNT);

const DungeonArray dungeonList = {
    &DekuTree,        &DodongosCavern, &JabuJabusBelly,        &ForestTemple,
    &FireTemple,      &WaterTemple,    &SpiritTemple,          &ShadowTemple,
    &BottomOfTheWell, &IceCavern,      &GerudoTrainingGrounds, &GanonsCastle,
};

// The HintKey for the passed location must match the location's index in the locationTable
void AddLocToDungeon(const ItemLocation* loc) {
    bool isVanillaQuest  = false;
    bool isMasterQuest   = false;
    DungeonInfo* dungeon = nullptr;
    for (Category cat : loc->GetCategories()) {
        switch (cat) {
            case Category::cVanillaQuest:
                isVanillaQuest = true;
                break;
            case Category::cMasterQuest:
                isMasterQuest = true;
                break;
            case Category::cDekuTree:
                dungeon = &DekuTree;
                break;
            case Category::cDodongosCavern:
                dungeon = &DodongosCavern;
                break;
            case Category::cJabuJabusBelly:
                dungeon = &JabuJabusBelly;
                break;
            case Category::cForestTemple:
                dungeon = &ForestTemple;
                break;
            case Category::cFireTemple:
                dungeon = &FireTemple;
                break;
            case Category::cWaterTemple:
                dungeon = &WaterTemple;
                break;
            case Category::cSpiritTemple:
                dungeon = &SpiritTemple;
                break;
            case Category::cShadowTemple:
                dungeon = &ShadowTemple;
                break;
            case Category::cBottomOfTheWell:
                dungeon = &BottomOfTheWell;
                break;
            case Category::cIceCavern:
                dungeon = &IceCavern;
                break;
            case Category::cGerudoTrainingGrounds:
                dungeon = &GerudoTrainingGrounds;
                break;
            case Category::cGanonsCastle:
                dungeon = &GanonsCastle;
                break;
            default:
                break;
        }
    }
    if (dungeon != nullptr) {
        LocationKey locKey = loc->GetHintKey();
        if (isVanillaQuest) {
            dungeon->AddVanillaLocation(locKey);
        } else if (isMasterQuest) {
            dungeon->AddMQLocation(locKey);
        } else {
            dungeon->AddSharedLocation(locKey);
        }
    }
}

} // namespace Dungeon
