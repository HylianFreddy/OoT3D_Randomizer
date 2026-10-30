#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Dungeons(void) {
    // Deku Tree Vanilla
    Chest(DEKU_TREE_MAP_CHEST, SCENE_DEKU_TREE, 0x03, //
        "Deku Tree Map Chest", DEKU_TREE_MAP, //
        { Category::cDekuTree, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_COMPASS_CHEST, SCENE_DEKU_TREE, 0x02, //
        "Deku Tree Compass Chest", DEKU_TREE_COMPASS, //
        { Category::cDekuTree, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_COMPASS_ROOM_SIDE_CHEST, SCENE_DEKU_TREE, 0x06, //
        "Deku Tree Compass Room Side Chest", RECOVERY_HEART, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_BASEMENT_CHEST, SCENE_DEKU_TREE, 0x04, //
        "Deku Tree Basement Chest", RECOVERY_HEART, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_SLINGSHOT_CHEST, SCENE_DEKU_TREE, 0x01, //
        "Deku Tree Slingshot Chest", PROGRESSIVE_SLINGSHOT, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_SLINGSHOT_ROOM_SIDE_CHEST, SCENE_DEKU_TREE, 0x05, //
        "Deku Tree Slingshot Room Side Chest", RECOVERY_HEART, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    // Deku Tree MQ
    Chest(DEKU_TREE_MQ_MAP_CHEST, SCENE_DEKU_TREE, 0x03, //
        "Deku Tree MQ Map Chest", DEKU_TREE_MAP, //
        { Category::cDekuTree, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_COMPASS_CHEST, SCENE_DEKU_TREE, 0x01, //
        "Deku Tree MQ Compass Chest", DEKU_TREE_COMPASS, //
        { Category::cDekuTree, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_SLINGSHOT_CHEST, SCENE_DEKU_TREE, 0x06, //
        "Deku Tree MQ Slingshot Chest", PROGRESSIVE_SLINGSHOT, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_SLINGSHOT_ROOM_BACK_CHEST, SCENE_DEKU_TREE, 0x02, //
        "Deku Tree MQ Slingshot Room Back Chest", DEKU_SHIELD, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_BASEMENT_CHEST, SCENE_DEKU_TREE, 0x04, //
        "Deku Tree MQ Basement Chest", DEKU_SHIELD, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_BEFORE_SPINNING_LOG_CHEST, SCENE_DEKU_TREE, 0x05, //
        "Deku Tree MQ Before Spinning Log Chest", RECOVERY_HEART, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Chest(DEKU_TREE_MQ_AFTER_SPINNING_LOG_CHEST, SCENE_DEKU_TREE, 0x00, //
        "Deku Tree MQ After Spinning Log Chest", PURPLE_RUPEE, //
        { Category::cDekuTree }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Base(DEKU_TREE_MQ_DEKU_SCRUB, SCENE_DEKU_TREE, 0x29, //
        "Deku Tree MQ Deku Scrub", DEKU_SHIELD, //
        { Category::cDekuTree, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x00, 0x05), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);

    // Dodongos Cavern Shared
    Chest(DODONGOS_CAVERN_BOSS_ROOM_CHEST, SCENE_DODONGOS_CAVERN_BOSS, 0x00, //
        "Dodongos Cavern Boss Room Chest", BOMBS_5, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    // Dodongos Cavern Vanilla
    Chest(DODONGOS_CAVERN_MAP_CHEST, SCENE_DODONGOS_CAVERN, 0x08, //
        "Dodongos Cavern Map Chest", DODONGOS_CAVERN_MAP, //
        { Category::cDodongosCavern, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_COMPASS_CHEST, SCENE_DODONGOS_CAVERN, 0x05, //
        "Dodongos Cavern Compass Chest", DODONGOS_CAVERN_COMPASS, //
        { Category::cDodongosCavern, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_BOMB_FLOWER_PLATFORM_CHEST, SCENE_DODONGOS_CAVERN, 0x06, //
        "Dodongos Cavern Bomb Flower Platform Chest", RED_RUPEE, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_BOMB_BAG_CHEST, SCENE_DODONGOS_CAVERN, 0x04, //
        "Dodongos Cavern Bomb Bag Chest", PROGRESSIVE_BOMB_BAG, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_END_OF_BRIDGE_CHEST, SCENE_DODONGOS_CAVERN, 0x0A, //
        "Dodongos Cavern End Of Bridge Chest", DEKU_SHIELD, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_DEKU_SCRUB_NEAR_BOMB_BAG_LEFT, SCENE_DODONGOS_CAVERN, 0x63, //
        "Dodongos Cavern Deku Scrub Near Bomb Bag Left", DEKU_NUTS_5, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x01), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_DEKU_SCRUB_SIDE_ROOM_NEAR_DODONGOS, SCENE_DODONGOS_CAVERN, 0x07, //
        "Dodongos Cavern Deku Scrub Side Room Near Dodongos", DEKU_STICK_1, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x02), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_DEKU_SCRUB_NEAR_BOMB_BAG_RIGHT, SCENE_DODONGOS_CAVERN, 0x69, //
        "Dodongos Cavern Deku Scrub Near Bomb Bag Right", DEKU_SEEDS_30, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x04), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_DEKU_SCRUB_LOBBY, SCENE_DODONGOS_CAVERN, 0x29, //
        "Dodongos Cavern Deku Scrub Lobby", DEKU_SHIELD, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x05), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    // Dodongos Cavern MQ
    Chest(DODONGOS_CAVERN_MQ_MAP_CHEST, SCENE_DODONGOS_CAVERN, 0x00, //
        "Dodongos Cavern MQ Map Chest", DODONGOS_CAVERN_MAP, //
        { Category::cDodongosCavern, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_MQ_BOMB_BAG_CHEST, SCENE_DODONGOS_CAVERN, 0x04, //
        "Dodongos Cavern MQ Bomb Bag Chest", PROGRESSIVE_BOMB_BAG, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_MQ_COMPASS_CHEST, SCENE_DODONGOS_CAVERN, 0x05, //
        "Dodongos Cavern MQ Compass Chest", DODONGOS_CAVERN_COMPASS, //
        { Category::cDodongosCavern, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_MQ_LARVAE_ROOM_CHEST, SCENE_DODONGOS_CAVERN, 0x02, //
        "Dodongos Cavern MQ Larvae Room Chest", DEKU_SHIELD, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_MQ_TORCH_PUZZLE_ROOM_CHEST, SCENE_DODONGOS_CAVERN, 0x03, //
        "Dodongos Cavern MQ Torch Puzzle Room Chest", BLUE_RUPEE, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Chest(DODONGOS_CAVERN_MQ_UNDER_GRAVE_CHEST, SCENE_DODONGOS_CAVERN, 0x01, //
        "Dodongos Cavern MQ Under Grave Chest", HYLIAN_SHIELD, //
        { Category::cDodongosCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_MQ_DEKU_SCRUB_LOBBY_REAR, SCENE_DODONGOS_CAVERN, 0x07, //
        "Dodongos Cavern Deku Scrub Lobby Rear", DEKU_STICK_1, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x02), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_MQ_DEKU_SCRUB_LOBBY_FRONT, SCENE_DODONGOS_CAVERN, 0x69, //
        "Dodongos Cavern Deku Scrub Lobby Front", DEKU_SEEDS_30, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x04), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_MQ_DEKU_SCRUB_STAIRCASE, SCENE_DODONGOS_CAVERN, 0x29, //
        "Dodongos Cavern Deku Scrub Staircase", DEKU_SHIELD, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x05), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(DODONGOS_CAVERN_MQ_DEKU_SCRUB_SIDE_ROOM_NEAR_LOWER_LIZALFOS, SCENE_DODONGOS_CAVERN, 0x10, //
        "Dodongos Cavern Deku Scrub Near Lower Lizalfos", RED_POTION_REFILL, //
        { Category::cDodongosCavern, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x01, 0x08), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);

    // Jabu Jabus Belly Vanilla
    Chest(JABU_JABUS_BELLY_MAP_CHEST, SCENE_JABU_JABU, 0x02, //
        "Jabu Jabus Belly Map Chest", JABU_JABUS_BELLY_MAP, //
        { Category::cJabuJabusBelly, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_COMPASS_CHEST, SCENE_JABU_JABU, 0x04, //
        "Jabu Jabus Belly Compass Chest", JABU_JABUS_BELLY_COMPASS, //
        { Category::cJabuJabusBelly, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_BOOMERANG_CHEST, SCENE_JABU_JABU, 0x01, //
        "Jabu Jabus Belly Boomerang Chest", BOOMERANG, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Base(JABU_JABUS_BELLY_DEKU_SCRUB, SCENE_JABU_JABU, 0x63, //
        "Jabu Jabus Belly Deku Scrub", DEKU_NUTS_5, //
        { Category::cJabuJabusBelly, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x02, 0x01), SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    // Jabu Jabus Belly MQ
    Chest(JABU_JABUS_BELLY_MQ_FIRST_ROOM_SIDE_CHEST, SCENE_JABU_JABU, 0x05, //
        "Jabu Jabus Belly MQ First Room Side Chest", DEKU_NUTS_5, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_MAP_CHEST, SCENE_JABU_JABU, 0x03, //
        "Jabu Jabus Belly MQ Map Chest", JABU_JABUS_BELLY_MAP, //
        { Category::cJabuJabusBelly, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_SECOND_ROOM_LOWER_CHEST, SCENE_JABU_JABU, 0x02, //
        "Jabu Jabus Belly MQ Second Room Lower Chest", DEKU_NUTS_5, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_COMPASS_CHEST, SCENE_JABU_JABU, 0x00, //
        "Jabu Jabus Belly MQ Compass Chest", JABU_JABUS_BELLY_COMPASS, //
        { Category::cJabuJabusBelly, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_SECOND_ROOM_UPPER_CHEST, SCENE_JABU_JABU, 0x07, //
        "Jabu Jabus Belly MQ Second Room Upper Chest", RECOVERY_HEART, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_BASEMENT_NEAR_SWITCHES_CHEST, SCENE_JABU_JABU, 0x08, //
        "Jabu Jabus Belly MQ Basement Near Switches Chest", DEKU_NUTS_5, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_BASEMENT_NEAR_VINES_CHEST, SCENE_JABU_JABU, 0x04, //
        "Jabu Jabus Belly MQ Basement Near Vines Chest", BOMBCHU_10, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_NEAR_BOSS_CHEST, SCENE_JABU_JABU, 0x0A, //
        "Jabu Jabus Belly MQ Near Boss Chest", DEKU_SHIELD, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_FALLING_LIKE_LIKE_ROOM_CHEST, SCENE_JABU_JABU, 0x09, //
        "Jabu Jabus Belly MQ Falling Like Like Room Chest", DEKU_STICK_1, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_BOOMERANG_ROOM_SMALL_CHEST, SCENE_JABU_JABU, 0x01, //
        "Jabu Jabus Belly MQ Boomerang Room Small Chest", DEKU_NUTS_5, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Chest(JABU_JABUS_BELLY_MQ_BOOMERANG_CHEST, SCENE_JABU_JABU, 0x06, //
        "Jabu Jabus Belly MQ Boomerang Chest", BOOMERANG, //
        { Category::cJabuJabusBelly }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);

    // Forest Temple Vanilla
    Chest(FOREST_TEMPLE_FIRST_ROOM_CHEST, SCENE_FOREST_TEMPLE, 0x03, //
        "Forest Temple First Room Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_FIRST_STALFOS_CHEST, SCENE_FOREST_TEMPLE, 0x00, //
        "Forest Temple First Stalfos Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_RAISED_ISLAND_COURTYARD_CHEST, SCENE_FOREST_TEMPLE, 0x05, //
        "Forest Temple Raised Island Courtyard Chest", RECOVERY_HEART, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MAP_CHEST, SCENE_FOREST_TEMPLE, 0x01, //
        "Forest Temple Map Chest", FOREST_TEMPLE_MAP, //
        { Category::cForestTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_WELL_CHEST, SCENE_FOREST_TEMPLE, 0x09, //
        "Forest Temple Well Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_FALLING_CEILING_ROOM_CHEST, SCENE_FOREST_TEMPLE, 0x07, //
        "Forest Temple Falling Ceiling Room Chest", ARROWS_10, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_EYE_SWITCH_CHEST, SCENE_FOREST_TEMPLE, 0x04, //
        "Forest Temple Eye Switch Chest", ARROWS_30, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_BOSS_KEY_CHEST, SCENE_FOREST_TEMPLE, 0x0E, //
        "Forest Temple Boss Key Chest", FOREST_TEMPLE_BOSS_KEY, //
        { Category::cForestTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_FLOORMASTER_CHEST, SCENE_FOREST_TEMPLE, 0x02, //
        "Forest Temple Floormaster Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_BOW_CHEST, SCENE_FOREST_TEMPLE, 0x0C, //
        "Forest Temple Bow Chest", PROGRESSIVE_BOW, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_RED_POE_CHEST, SCENE_FOREST_TEMPLE, 0x0D, //
        "Forest Temple Red Poe Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_BLUE_POE_CHEST, SCENE_FOREST_TEMPLE, 0x0F, //
        "Forest Temple Blue Poe Chest", FOREST_TEMPLE_COMPASS, //
        { Category::cForestTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_BASEMENT_CHEST, SCENE_FOREST_TEMPLE, 0x0B, //
        "Forest Temple Basement Chest", ARROWS_5, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    // Forest Temple MQ
    Chest(FOREST_TEMPLE_MQ_FIRST_ROOM_CHEST, SCENE_FOREST_TEMPLE, 0x03, //
        "Forest Temple MQ First Room Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_WOLFOS_CHEST, SCENE_FOREST_TEMPLE, 0x00, //
        "Forest Temple MQ Wolfos Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_BOW_CHEST, SCENE_FOREST_TEMPLE, 0x0C, //
        "Forest Temple MQ Bow Chest", PROGRESSIVE_BOW, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_RAISED_ISLAND_COURTYARD_LOWER_CHEST, SCENE_FOREST_TEMPLE, 0x01, //
        "Forest Temple MQ Raised Island Lower Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_RAISED_ISLAND_COURTYARD_UPPER_CHEST, SCENE_FOREST_TEMPLE, 0x05, //
        "Forest Temple MQ Raised Island Upper Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_WELL_CHEST, SCENE_FOREST_TEMPLE, 0x09, //
        "Forest Temple MQ Well Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_MAP_CHEST, SCENE_FOREST_TEMPLE, 0x0D, //
        "Forest Temple MQ Map Chest", FOREST_TEMPLE_MAP, //
        { Category::cForestTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_COMPASS_CHEST, SCENE_FOREST_TEMPLE, 0x0F, //
        "Forest Temple MQ Compass Chest", FOREST_TEMPLE_COMPASS, //
        { Category::cForestTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_FALLING_CEILING_ROOM_CHEST, SCENE_FOREST_TEMPLE, 0x06, //
        "Forest Temple MQ Falling Ceiling Room Chest", ARROWS_5, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_BASEMENT_CHEST, SCENE_FOREST_TEMPLE, 0x0B, //
        "Forest Temple MQ Basement Chest", ARROWS_5, //
        { Category::cForestTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_REDEAD_CHEST, SCENE_FOREST_TEMPLE, 0x02, //
        "Forest Temple MQ Redead Chest", FOREST_TEMPLE_SMALL_KEY, //
        { Category::cForestTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Chest(FOREST_TEMPLE_MQ_BOSS_KEY_CHEST, SCENE_FOREST_TEMPLE, 0x0E, //
        "Forest Temple MQ Boss Key Chest", FOREST_TEMPLE_BOSS_KEY, //
        { Category::cForestTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);

    // Fire Temple Vanilla
    Chest(FIRE_TEMPLE_NEAR_BOSS_CHEST, SCENE_FIRE_TEMPLE, 0x01, //
        "Fire Temple Near Boss Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_FLARE_DANCER_CHEST, SCENE_FIRE_TEMPLE, 0x00, //
        "Fire Temple Flare Dancer Chest", BOMBS_10, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BOSS_KEY_CHEST, SCENE_FIRE_TEMPLE, 0x0C, //
        "Fire Temple Boss Key Chest", FIRE_TEMPLE_BOSS_KEY, //
        { Category::cFireTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BIG_LAVA_ROOM_BLOCKED_DOOR_CHEST, SCENE_FIRE_TEMPLE, 0x02, //
        "Fire Temple Big Lava Room Blocked Door Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BIG_LAVA_ROOM_LOWER_OPEN_DOOR_CHEST, SCENE_FIRE_TEMPLE, 0x04, //
        "Fire Temple Big Lava Room Lower Open Door Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BOULDER_MAZE_LOWER_CHEST, SCENE_FIRE_TEMPLE, 0x03, //
        "Fire Temple Boulder Maze Lower Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BOULDER_MAZE_UPPER_CHEST, SCENE_FIRE_TEMPLE, 0x06, //
        "Fire Temple Boulder Maze Upper Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BOULDER_MAZE_SIDE_ROOM_CHEST, SCENE_FIRE_TEMPLE, 0x08, //
        "Fire Temple Boulder Maze Side Room Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_BOULDER_MAZE_SHORTCUT_CHEST, SCENE_FIRE_TEMPLE, 0x0B, //
        "Fire Temple Boulder Maze Shortcut Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_SCARECROW_CHEST, SCENE_FIRE_TEMPLE, 0x0D, //
        "Fire Temple Scarecrow Chest", HUGE_RUPEE, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MAP_CHEST, SCENE_FIRE_TEMPLE, 0x0A, //
        "Fire Temple Map Chest", FIRE_TEMPLE_MAP, //
        { Category::cFireTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_COMPASS_CHEST, SCENE_FIRE_TEMPLE, 0x07, //
        "Fire Temple Compass Chest", FIRE_TEMPLE_COMPASS, //
        { Category::cFireTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_HIGHEST_GORON_CHEST, SCENE_FIRE_TEMPLE, 0x09, //
        "Fire Temple Highest Goron Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MEGATON_HAMMER_CHEST, SCENE_FIRE_TEMPLE, 0x05, //
        "Fire Temple Megaton Hammer Chest", MEGATON_HAMMER, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    // Fire Temple MQ
    Chest(FIRE_TEMPLE_MQ_NEAR_BOSS_CHEST, SCENE_FIRE_TEMPLE, 0x07, //
        "Fire Temple MQ Near Boss Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_MEGATON_HAMMER_CHEST, SCENE_FIRE_TEMPLE, 0x00, //
        "Fire Temple MQ Megaton Hammer Chest", MEGATON_HAMMER, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_COMPASS_CHEST, SCENE_FIRE_TEMPLE, 0x0B, //
        "Fire Temple MQ Compass Chest", FIRE_TEMPLE_COMPASS, //
        { Category::cFireTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_LIZALFOS_MAZE_LOWER_CHEST, SCENE_FIRE_TEMPLE, 0x03, //
        "Fire Temple MQ Lizalfos Maze Lower Chest", BOMBS_10, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_LIZALFOS_MAZE_UPPER_CHEST, SCENE_FIRE_TEMPLE, 0x06, //
        "Fire Temple MQ Lizalfos Maze Upper Chest", BOMBS_10, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_CHEST_ON_FIRE, SCENE_FIRE_TEMPLE, 0x05, //
        "Fire Temple MQ Chest on Fire", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_MAP_ROOM_SIDE_CHEST, SCENE_FIRE_TEMPLE, 0x02, //
        "Fire Temple MQ Map Room Side Chest", HYLIAN_SHIELD, //
        { Category::cFireTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_MAP_CHEST, SCENE_FIRE_TEMPLE, 0x0C, //
        "Fire Temple MQ Map Chest", FIRE_TEMPLE_MAP, //
        { Category::cFireTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_BOSS_KEY_CHEST, SCENE_FIRE_TEMPLE, 0x04, //
        "Fire Temple MQ Boss Key Chest", FIRE_TEMPLE_BOSS_KEY, //
        { Category::cFireTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_BIG_LAVA_ROOM_BLOCKED_DOOR_CHEST, SCENE_FIRE_TEMPLE, 0x01, //
        "Fire Temple MQ Big Lava Room Blocked Door Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Chest(FIRE_TEMPLE_MQ_LIZALFOS_MAZE_SIDE_ROOM_CHEST, SCENE_FIRE_TEMPLE, 0x08, //
        "Fire Temple MQ Lizalfos Maze Side Room Chest", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_MQ_FREESTANDING_KEY, SCENE_FIRE_TEMPLE, 0x1C, //
        "Fire Temple MQ Freestanding Key", FIRE_TEMPLE_SMALL_KEY, //
        { Category::cFireTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    // Water Temple Vanilla
    Chest(WATER_TEMPLE_MAP_CHEST, SCENE_WATER_TEMPLE, 0x02, //
        "Water Temple Map Chest", WATER_TEMPLE_MAP, //
        { Category::cWaterTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_COMPASS_CHEST, SCENE_WATER_TEMPLE, 0x09, //
        "Water Temple Compass Chest", WATER_TEMPLE_COMPASS, //
        { Category::cWaterTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_TORCHES_CHEST, SCENE_WATER_TEMPLE, 0x01, //
        "Water Temple Torches Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_DRAGON_CHEST, SCENE_WATER_TEMPLE, 0x0A, //
        "Water Temple Dragon Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_CENTRAL_BOW_TARGET_CHEST, SCENE_WATER_TEMPLE, 0x08, //
        "Water Temple Central Bow Target Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_CENTRAL_PILLAR_CHEST, SCENE_WATER_TEMPLE, 0x06, //
        "Water Temple Central Pillar Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_CRACKED_WALL_CHEST, SCENE_WATER_TEMPLE, 0x00, //
        "Water Temple Cracked Wall Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_BOSS_KEY_CHEST, SCENE_WATER_TEMPLE, 0x05, //
        "Water Temple Boss Key Chest", WATER_TEMPLE_BOSS_KEY, //
        { Category::cWaterTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_LONGSHOT_CHEST, SCENE_WATER_TEMPLE, 0x07, //
        "Water Temple Longshot Chest", PROGRESSIVE_HOOKSHOT, //
        { Category::cWaterTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_RIVER_CHEST, SCENE_WATER_TEMPLE, 0x03, //
        "Water Temple River Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    // Water Temple MQ
    Chest(WATER_TEMPLE_MQ_CENTRAL_PILLAR_CHEST, SCENE_WATER_TEMPLE, 0x06, //
        "Water Temple MQ Central Pillar Chest", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_MQ_BOSS_KEY_CHEST, SCENE_WATER_TEMPLE, 0x05, //
        "Water Temple MQ Boss Key Chest", WATER_TEMPLE_BOSS_KEY, //
        { Category::cWaterTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_MQ_LONGSHOT_CHEST, SCENE_WATER_TEMPLE, 0x00, //
        "Water Temple MQ Longshot Chest", PROGRESSIVE_HOOKSHOT, //
        { Category::cWaterTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_MQ_COMPASS_CHEST, SCENE_WATER_TEMPLE, 0x01, //
        "Water Temple MQ Compass Chest", WATER_TEMPLE_COMPASS, //
        { Category::cWaterTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Chest(WATER_TEMPLE_MQ_MAP_CHEST, SCENE_WATER_TEMPLE, 0x02, //
        "Water Temple MQ Map Chest", WATER_TEMPLE_MAP, //
        { Category::cWaterTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Collectable(WATER_TEMPLE_MQ_FREESTANDING_KEY, SCENE_WATER_TEMPLE, 0x01, //
        "Water Temple MQ Freestanding Key", WATER_TEMPLE_SMALL_KEY, //
        { Category::cWaterTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);

    // Spirit Temple Shared
    Chest(SPIRIT_TEMPLE_SILVER_GAUNTLETS_CHEST, SCENE_DESERT_COLOSSUS, 0x0B, //
        "Spirit Temple Silver Gauntlets Chest", PROGRESSIVE_STRENGTH, //
        { Category::cSpiritTemple, Category::cDesertColossus }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MIRROR_SHIELD_CHEST, SCENE_DESERT_COLOSSUS, 0x09, //
        "Spirit Temple Mirror Shield Chest", MIRROR_SHIELD, //
        { Category::cSpiritTemple, Category::cDesertColossus }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    // Spirit Temple Vanilla
    Chest(SPIRIT_TEMPLE_CHILD_BRIDGE_CHEST, SCENE_SPIRIT_TEMPLE, 0x08, //
        "Spirit Temple Child Bridge Chest", DEKU_SHIELD, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_CHILD_EARLY_TORCHES_CHEST, SCENE_SPIRIT_TEMPLE, 0x00, //
        "Spirit Temple Child Early Torches Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_COMPASS_CHEST, SCENE_SPIRIT_TEMPLE, 0x04, //
        "Spirit Temple Compass Chest", SPIRIT_TEMPLE_COMPASS, //
        { Category::cSpiritTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_EARLY_ADULT_RIGHT_CHEST, SCENE_SPIRIT_TEMPLE, 0x07, //
        "Spirit Temple Early Adult Right Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_FIRST_MIRROR_LEFT_CHEST, SCENE_SPIRIT_TEMPLE, 0x0D, //
        "Spirit Temple First Mirror Left Chest", ICE_TRAP, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_FIRST_MIRROR_RIGHT_CHEST, SCENE_SPIRIT_TEMPLE, 0x0E, //
        "Spirit Temple First Mirror Right Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MAP_CHEST, SCENE_SPIRIT_TEMPLE, 0x03, //
        "Spirit Temple Map Chest", SPIRIT_TEMPLE_MAP, //
        { Category::cSpiritTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_CHILD_CLIMB_NORTH_CHEST, SCENE_SPIRIT_TEMPLE, 0x06, //
        "Spirit Temple Child Climb North Chest", BOMBCHU_10, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_CHILD_CLIMB_EAST_CHEST, SCENE_SPIRIT_TEMPLE, 0x0C, //
        "Spirit Temple Child Climb East Chest", DEKU_SHIELD, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_SUN_BLOCK_ROOM_CHEST, SCENE_SPIRIT_TEMPLE, 0x01, //
        "Spirit Temple Sun Block Room Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_STATUE_ROOM_HAND_CHEST, SCENE_SPIRIT_TEMPLE, 0x02, //
        "Spirit Temple Statue Room Hand Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_STATUE_ROOM_NORTHEAST_CHEST, SCENE_SPIRIT_TEMPLE, 0x0F, //
        "Spirit Temple Statue Room Northeast Chest", BLUE_RUPEE, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_NEAR_FOUR_ARMOS_CHEST, SCENE_SPIRIT_TEMPLE, 0x05, //
        "Spirit Temple Near Four Armos Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_HALLWAY_RIGHT_INVISIBLE_CHEST, SCENE_SPIRIT_TEMPLE, 0x14, //
        "Spirit Temple Hallway Right Invisible Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_HALLWAY_LEFT_INVISIBLE_CHEST, SCENE_SPIRIT_TEMPLE, 0x15, //
        "Spirit Temple Hallway Left Invisible Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_BOSS_KEY_CHEST, SCENE_SPIRIT_TEMPLE, 0x0A, //
        "Spirit Temple Boss Key Chest", SPIRIT_TEMPLE_BOSS_KEY, //
        { Category::cSpiritTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_TOPMOST_CHEST, SCENE_SPIRIT_TEMPLE, 0x12, //
        "Spirit Temple Topmost Chest", BOMBS_20, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    // Spirit Temple MQ
    Chest(SPIRIT_TEMPLE_MQ_ENTRANCE_FRONT_LEFT_CHEST, SCENE_SPIRIT_TEMPLE, 0x1A, //
        "Spirit Temple MQ Entrance Front Left Chest", BOMBCHU_10, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_ENTRANCE_BACK_RIGHT_CHEST, SCENE_SPIRIT_TEMPLE, 0x1F, //
        "Spirit Temple MQ Entrance Back Right Chest", BOMBCHU_10, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_ENTRANCE_FRONT_RIGHT_CHEST, SCENE_SPIRIT_TEMPLE, 0x1B, //
        "Spirit Temple MQ Entrance Front Right Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_ENTRANCE_BACK_LEFT_CHEST, SCENE_SPIRIT_TEMPLE, 0x1E, //
        "Spirit Temple MQ Entrance Back Left Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_CHILD_HAMMER_SWITCH_CHEST, SCENE_SPIRIT_TEMPLE, 0x1D, //
        "Spirit Temple MQ Child Hammer Switch Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_MAP_CHEST, SCENE_SPIRIT_TEMPLE, 0x00, //
        "Spirit Temple MQ Map Chest", SPIRIT_TEMPLE_MAP, //
        { Category::cSpiritTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_MAP_ROOM_ENEMY_CHEST, SCENE_SPIRIT_TEMPLE, 0x08, //
        "Spirit Temple MQ Map Room Enemy Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_CHILD_CLIMB_NORTH_CHEST, SCENE_SPIRIT_TEMPLE, 0x06, //
        "Spirit Temple MQ Child Climb North Chest", BOMBCHU_10, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_CHILD_CLIMB_SOUTH_CHEST, SCENE_SPIRIT_TEMPLE, 0x0C, //
        "Spirit Temple MQ Child Climb South Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_COMPASS_CHEST, SCENE_SPIRIT_TEMPLE, 0x03, //
        "Spirit Temple MQ Compass Chest", SPIRIT_TEMPLE_COMPASS, //
        { Category::cSpiritTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_STATUE_ROOM_LULLABY_CHEST, SCENE_SPIRIT_TEMPLE, 0x0F, //
        "Spirit Temple MQ Statue Room Lullaby Chest", BLUE_RUPEE, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_STATUE_ROOM_INVISIBLE_CHEST, SCENE_SPIRIT_TEMPLE, 0x02, //
        "Spirit Temple MQ Statue Room Invisible Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_SILVER_BLOCK_HALLWAY_CHEST, SCENE_SPIRIT_TEMPLE, 0x1C, //
        "Spirit Temple MQ Silver Block Hallway Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_SUN_BLOCK_ROOM_CHEST, SCENE_SPIRIT_TEMPLE, 0x01, //
        "Spirit Temple MQ Sun Block Room Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_SYMPHONY_ROOM_CHEST, SCENE_SPIRIT_TEMPLE, 0x07, //
        "Spirit Temple MQ Symphony Room Chest", PURPLE_RUPEE, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_LEEVER_ROOM_CHEST, SCENE_SPIRIT_TEMPLE, 0x04, //
        "Spirit Temple MQ Leever Room Chest", PURPLE_RUPEE, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_BEAMOS_ROOM_CHEST, SCENE_SPIRIT_TEMPLE, 0x19, //
        "Spirit Temple MQ Beamos Room Chest", RECOVERY_HEART, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_CHEST_SWITCH_CHEST, SCENE_SPIRIT_TEMPLE, 0x18, //
        "Spirit Temple MQ Chest Switch Chest", ICE_TRAP, //
        { Category::cSpiritTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_BOSS_KEY_CHEST, SCENE_SPIRIT_TEMPLE, 0x05, //
        "Spirit Temple MQ Boss Key Chest", SPIRIT_TEMPLE_BOSS_KEY, //
        { Category::cSpiritTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Chest(SPIRIT_TEMPLE_MQ_MIRROR_PUZZLE_INVISIBLE_CHEST, SCENE_SPIRIT_TEMPLE, 0x12, //
        "Spirit Temple MQ Mirror Puzzle Invisible Chest", SPIRIT_TEMPLE_SMALL_KEY, //
        { Category::cSpiritTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);

    // Shadow Temple Vanilla
    Chest(SHADOW_TEMPLE_MAP_CHEST, SCENE_SHADOW_TEMPLE, 0x01, //
        "Shadow Temple Map Chest", SHADOW_TEMPLE_MAP, //
        { Category::cShadowTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_HOVER_BOOTS_CHEST, SCENE_SHADOW_TEMPLE, 0x07, //
        "Shadow Temple Hover Boots Chest", HOVER_BOOTS, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_COMPASS_CHEST, SCENE_SHADOW_TEMPLE, 0x03, //
        "Shadow Temple Compass Chest", SHADOW_TEMPLE_COMPASS, //
        { Category::cShadowTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_EARLY_SILVER_RUPEE_CHEST, SCENE_SHADOW_TEMPLE, 0x02, //
        "Shadow Temple Early Silver Rupee Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_INVISIBLE_BLADES_VISIBLE_CHEST, SCENE_SHADOW_TEMPLE, 0x0C, //
        "Shadow Temple Invisible Blades Visible Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_INVISIBLE_BLADES_INVISIBLE_CHEST, SCENE_SHADOW_TEMPLE, 0x16, //
        "Shadow Temple Invisible Blades Invisible Chest", ARROWS_30, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_FALLING_SPIKES_LOWER_CHEST, SCENE_SHADOW_TEMPLE, 0x05, //
        "Shadow Temple Falling Spikes Lower Chest", ARROWS_10, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_FALLING_SPIKES_UPPER_CHEST, SCENE_SHADOW_TEMPLE, 0x06, //
        "Shadow Temple Falling Spikes Upper Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_FALLING_SPIKES_SWITCH_CHEST, SCENE_SHADOW_TEMPLE, 0x04, //
        "Shadow Temple Falling Spikes Switch Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_INVISIBLE_SPIKES_CHEST, SCENE_SHADOW_TEMPLE, 0x09, //
        "Shadow Temple Invisible Spikes Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_WIND_HINT_CHEST, SCENE_SHADOW_TEMPLE, 0x15, //
        "Shadow Temple Wind Hint Chest", ARROWS_10, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_AFTER_WIND_ENEMY_CHEST, SCENE_SHADOW_TEMPLE, 0x08, //
        "Shadow Temple After Wind Enemy Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_AFTER_WIND_HIDDEN_CHEST, SCENE_SHADOW_TEMPLE, 0x14, //
        "Shadow Temple After Wind Hidden Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_SPIKE_WALLS_LEFT_CHEST, SCENE_SHADOW_TEMPLE, 0x0A, //
        "Shadow Temple Spike Walls Left Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_BOSS_KEY_CHEST, SCENE_SHADOW_TEMPLE, 0x0B, //
        "Shadow Temple Boss Key Chest", SHADOW_TEMPLE_BOSS_KEY, //
        { Category::cShadowTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_INVISIBLE_FLOORMASTER_CHEST, SCENE_SHADOW_TEMPLE, 0x0D, //
        "Shadow Temple Invisible Floormaster Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_FREESTANDING_KEY, SCENE_SHADOW_TEMPLE, 0x01, //
        "Shadow Temple Freestanding Key", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    // Shadow Temple MQ
    Chest(SHADOW_TEMPLE_MQ_COMPASS_CHEST, SCENE_SHADOW_TEMPLE, 0x01, //
        "Shadow Temple MQ Compass Chest", SHADOW_TEMPLE_COMPASS, //
        { Category::cShadowTemple, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_HOVER_BOOTS_CHEST, SCENE_SHADOW_TEMPLE, 0x07, //
        "Shadow Temple MQ Hover Boots Chest", HOVER_BOOTS, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_EARLY_GIBDOS_CHEST, SCENE_SHADOW_TEMPLE, 0x03, //
        "Shadow Temple MQ Early Gibdos Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_MAP_CHEST, SCENE_SHADOW_TEMPLE, 0x02, //
        "Shadow Temple MQ Map Chest", SHADOW_TEMPLE_MAP, //
        { Category::cShadowTemple, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_BEAMOS_SILVER_RUPEES_CHEST, SCENE_SHADOW_TEMPLE, 0x0F, //
        "Shadow Temple MQ Beamos Silver Rupees Chest", ARROWS_5, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_FALLING_SPIKES_SWITCH_CHEST, SCENE_SHADOW_TEMPLE, 0x04, //
        "Shadow Temple MQ Falling Spikes Switch Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_FALLING_SPIKES_LOWER_CHEST, SCENE_SHADOW_TEMPLE, 0x05, //
        "Shadow Temple MQ Falling Spikes Lower Chest", ARROWS_10, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_FALLING_SPIKES_UPPER_CHEST, SCENE_SHADOW_TEMPLE, 0x06, //
        "Shadow Temple MQ Falling Spikes Upper Chest", ARROWS_5, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_INVISIBLE_SPIKES_CHEST, SCENE_SHADOW_TEMPLE, 0x09, //
        "Shadow Temple MQ Invisible Spikes Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_BOSS_KEY_CHEST, SCENE_SHADOW_TEMPLE, 0x0B, //
        "Shadow Temple MQ Boss Key Chest", SHADOW_TEMPLE_BOSS_KEY, //
        { Category::cShadowTemple, Category::cVanillaBossKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_SPIKE_WALLS_LEFT_CHEST, SCENE_SHADOW_TEMPLE, 0x0A, //
        "Shadow Temple MQ Spike Walls Left Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_STALFOS_ROOM_CHEST, SCENE_SHADOW_TEMPLE, 0x10, //
        "Shadow Temple MQ Stalfos Room Chest", RED_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_INVISIBLE_BLADES_INVISIBLE_CHEST, SCENE_SHADOW_TEMPLE, 0x16, //
        "Shadow Temple MQ Invisible Blades Invisible Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_INVISIBLE_BLADES_VISIBLE_CHEST, SCENE_SHADOW_TEMPLE, 0x0C, //
        "Shadow Temple MQ Invisible Blades Visible Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_BOMB_FLOWER_CHEST, SCENE_SHADOW_TEMPLE, 0x0D, //
        "Shadow Temple MQ Bomb Flower Chest", ARROWS_10, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_WIND_HINT_CHEST, SCENE_SHADOW_TEMPLE, 0x15, //
        "Shadow Temple MQ Wind Hint Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_AFTER_WIND_HIDDEN_CHEST, SCENE_SHADOW_TEMPLE, 0x14, //
        "Shadow Temple MQ After Wind Hidden Chest", ARROWS_5, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_AFTER_WIND_ENEMY_CHEST, SCENE_SHADOW_TEMPLE, 0x08, //
        "Shadow Temple MQ After Wind Enemy Chest", BLUE_RUPEE, //
        { Category::cShadowTemple }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Chest(SHADOW_TEMPLE_MQ_NEAR_SHIP_INVISIBLE_CHEST, SCENE_SHADOW_TEMPLE, 0x0E, //
        "Shadow Temple MQ Near Ship Invisible Chest", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_MQ_FREESTANDING_KEY, SCENE_SHADOW_TEMPLE, 0x06, //
        "Shadow Temple MQ Freestanding Key", SHADOW_TEMPLE_SMALL_KEY, //
        { Category::cShadowTemple, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    // Bottom of the Well Vanilla
    Chest(BOTTOM_OF_THE_WELL_FRONT_LEFT_FAKE_WALL_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x08, //
        "Bottom of the Well Front Left Fake Wall Chest", BOTTOM_OF_THE_WELL_SMALL_KEY, //
        { Category::cBottomOfTheWell, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_FRONT_CENTER_BOMBABLE_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x02, //
        "Bottom of the Well Front Center Bombable Chest", BOMBCHU_10, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_RIGHT_BOTTOM_FAKE_WALL_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x05, //
        "Bottom of the Well Right Bottom Fake Wall Chest", BOTTOM_OF_THE_WELL_SMALL_KEY, //
        { Category::cBottomOfTheWell, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_COMPASS_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x01, //
        "Bottom of the Well Compass Chest", BOTTOM_OF_THE_WELL_COMPASS, //
        { Category::cBottomOfTheWell, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_CENTER_SKULLTULA_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x0E, //
        "Bottom of the Well Center Skulltula Chest", DEKU_NUTS_5, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_BACK_LEFT_BOMBABLE_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x04, //
        "Bottom of the Well Back Left Bombable Chest", DEKU_NUTS_10, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_LENS_OF_TRUTH_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x03, //
        "Bottom of the Well Lens of Truth Chest", LENS_OF_TRUTH, //
        { Category::cBottomOfTheWell, Category::cSongDungeonReward }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_INVISIBLE_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x14, //
        "Bottom of the Well Invisible Chest", HUGE_RUPEE, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_UNDERWATER_FRONT_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x10, //
        "Bottom of the Well Underwater Front Chest", BOMBS_10, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_UNDERWATER_LEFT_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x09, //
        "Bottom of the Well Underwater Left Chest", RECOVERY_HEART, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_MAP_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x07, //
        "Bottom of the Well Map Chest", BOTTOM_OF_THE_WELL_MAP, //
        { Category::cBottomOfTheWell, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_FIRE_KEESE_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x0A, //
        "Bottom of the Well Fire Keese Chest", DEKU_SHIELD, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_LIKE_LIKE_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x0C, //
        "Bottom of the Well Like Like Chest", HYLIAN_SHIELD, //
        { Category::cBottomOfTheWell }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_FREESTANDING_KEY, SCENE_BOTTOM_OF_THE_WELL, 0x01, //
        "Bottom of the Well Freestanding Key", BOTTOM_OF_THE_WELL_SMALL_KEY, //
        { Category::cBottomOfTheWell, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    // Bottom of the Well MQ
    Chest(BOTTOM_OF_THE_WELL_MQ_MAP_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x03, //
        "Bottom of the Well MQ Map Chest", BOTTOM_OF_THE_WELL_MAP, //
        { Category::cBottomOfTheWell, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_MQ_LENS_OF_TRUTH_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x01, //
        "Bottom of the Well MQ Lens of Truth Chest", LENS_OF_TRUTH, //
        { Category::cBottomOfTheWell, Category::cSongDungeonReward }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Chest(BOTTOM_OF_THE_WELL_MQ_COMPASS_CHEST, SCENE_BOTTOM_OF_THE_WELL, 0x02, //
        "Bottom of the Well MQ Compass Chest", BOTTOM_OF_THE_WELL_COMPASS, //
        { Category::cBottomOfTheWell, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_MQ_DEAD_HAND_FREESTANDING_KEY, SCENE_BOTTOM_OF_THE_WELL, 0x02, //
        "Bottom of the Well MQ Dead Hand Freestanding Key", BOTTOM_OF_THE_WELL_SMALL_KEY, //
        { Category::cBottomOfTheWell, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_MQ_EAST_INNER_ROOM_FREESTANDING_KEY, SCENE_BOTTOM_OF_THE_WELL, 0x01, //
        "Bottom of the Well MQ Inner Room Freestanding Key", BOTTOM_OF_THE_WELL_SMALL_KEY, //
        { Category::cBottomOfTheWell, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);

    // Ice Cavern Vanilla
    Chest(ICE_CAVERN_MAP_CHEST, SCENE_ICE_CAVERN, 0x00, //
        "Ice Cavern Map Chest", ICE_CAVERN_MAP, //
        { Category::cIceCavern, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Chest(ICE_CAVERN_COMPASS_CHEST, SCENE_ICE_CAVERN, 0x01, //
        "Ice Cavern Compass Chest", ICE_CAVERN_COMPASS, //
        { Category::cIceCavern, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Chest(ICE_CAVERN_IRON_BOOTS_CHEST, SCENE_ICE_CAVERN, 0x02, //
        "Ice Cavern Iron Boots Chest", IRON_BOOTS, //
        { Category::cIceCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_FREESTANDING_POH, SCENE_ICE_CAVERN, 0x01, //
        "Ice Cavern Freestanding PoH", PIECE_OF_HEART, //
        { Category::cIceCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    // Ice Cavern MQ
    Chest(ICE_CAVERN_MQ_IRON_BOOTS_CHEST, SCENE_ICE_CAVERN, 0x02, //
        "Ice Cavern MQ Iron Boots Chest", IRON_BOOTS, //
        { Category::cIceCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Chest(ICE_CAVERN_MQ_COMPASS_CHEST, SCENE_ICE_CAVERN, 0x00, //
        "Ice Cavern MQ Compass Chest", ICE_CAVERN_COMPASS, //
        { Category::cIceCavern, Category::cVanillaCompass }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Chest(ICE_CAVERN_MQ_MAP_CHEST, SCENE_ICE_CAVERN, 0x01, //
        "Ice Cavern MQ Map Chest", ICE_CAVERN_MAP, //
        { Category::cIceCavern, Category::cVanillaMap }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_MQ_FREESTANDING_POH, SCENE_ICE_CAVERN, 0x01, //
        "Ice Cavern MQ Freestanding PoH", PIECE_OF_HEART, //
        { Category::cIceCavern }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);

    // Gerudo Training Ground Vanilla
    Chest(GERUDO_TRAINING_GROUNDS_LOBBY_LEFT_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x13, //
        "Gerudo Training Grounds Lobby Left Chest", BLUE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_LOBBY_RIGHT_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x07, //
        "Gerudo Training Grounds Lobby Right Chest", ARROWS_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_STALFOS_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x00, //
        "Gerudo Training Grounds Stalfos Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_BEAMOS_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x01, //
        "Gerudo Training Grounds Beamos Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HIDDEN_CEILING_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0B, //
        "Gerudo Training Grounds Hidden Ceiling Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_PATH_FIRST_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x06, //
        "Gerudo Training Grounds Maze Path First Chest", PURPLE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_PATH_SECOND_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0A, //
        "Gerudo Training Grounds Maze Path Second Chest", RED_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_PATH_THIRD_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x09, //
        "Gerudo Training Grounds Maze Path Third Chest", ARROWS_30, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_PATH_FINAL_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0C, //
        "Gerudo Training Grounds Maze Path Final Chest", ICE_ARROWS, //
        { Category::cGerudoTrainingGrounds, Category::cSongDungeonReward }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_RIGHT_CENTRAL_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x05, //
        "Gerudo Training Grounds Maze Right Central Chest", BOMBCHU_5, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MAZE_RIGHT_SIDE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x08, //
        "Gerudo Training Grounds Maze Right Side Chest", ARROWS_30, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_UNDERWATER_SILVER_RUPEE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0D, //
        "Gerudo Training Grounds Water Room Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HAMMER_ROOM_CLEAR_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x12, //
        "Gerudo Training Grounds Hammer Room Clear Chest", ARROWS_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HAMMER_ROOM_SWITCH_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x10, //
        "Gerudo Training Grounds Hammer Room Switch Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_EYE_STATUE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x03, //
        "Gerudo Training Grounds Eye Statue Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_NEAR_SCARECROW_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x04, //
        "Gerudo Training Grounds Near Scarecrow Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_BEFORE_HEAVY_BLOCK_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x11, //
        "Gerudo Training Grounds Before Heavy Block Chest", ARROWS_30, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HEAVY_BLOCK_FIRST_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0F, //
        "Gerudo Training Grounds Heavy Block First Chest", HUGE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HEAVY_BLOCK_SECOND_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0E, //
        "Gerudo Training Grounds Heavy Block Second Chest", BLUE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HEAVY_BLOCK_THIRD_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x14, //
        "Gerudo Training Grounds Heavy Block Third Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_HEAVY_BLOCK_FOURTH_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x02, //
        "Gerudo Training Grounds Heavy Block Fourth Chest", ICE_TRAP, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Collectable(GERUDO_TRAINING_GROUNDS_FREESTANDING_KEY, SCENE_GERUDO_TRAINING_GROUND, 0x01, //
        "Gerudo Training Grounds Freestanding Key", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    // Gerudo Training Grounds MQ
    Chest(GERUDO_TRAINING_GROUNDS_MQ_LOBBY_RIGHT_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x07, //
        "Gerudo Training Grounds MQ Lobby Right Chest", BOMBCHU_5, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_LOBBY_LEFT_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x13, //
        "Gerudo Training Grounds MQ Lobby Left Chest", ARROWS_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_FIRST_IRON_KNUCKLE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x00, //
        "Gerudo Training Grounds MQ First Iron Knuckle Chest", BLUE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_BEFORE_HEAVY_BLOCK_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x11, //
        "Gerudo Training Grounds MQ Before Heavy Block Chest", ARROWS_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_EYE_STATUE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x03, //
        "Gerudo Training Grounds MQ Eye Statue Chest", BOMBCHU_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_FLAME_CIRCLE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0E, //
        "Gerudo Training Grounds MQ Flame Circle Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_SECOND_IRON_KNUCKLE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x12, //
        "Gerudo Training Grounds MQ 2nd Iron Knuckle Chest", ARROWS_10, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_DINOLFOS_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x01, //
        "Gerudo Training Grounds MQ Dinolfos Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_ICE_ARROWS_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x04, //
        "Gerudo Training Grounds MQ Ice Arrows Chest", ICE_ARROWS, //
        { Category::cGerudoTrainingGrounds, Category::cSongDungeonReward }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_MAZE_RIGHT_CENTRAL_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x05, //
        "Gerudo Training Grounds MQ Maze Right Central Chest", BLUE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_MAZE_PATH_FIRST_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x06, //
        "Gerudo Training Grounds MQ Maze Path First Chest", GREEN_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_MAZE_RIGHT_SIDE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x08, //
        "Gerudo Training Grounds MQ Maze Right Side Chest", TREASURE_GAME_GREEN_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_MAZE_PATH_THIRD_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x09, //
        "Gerudo Training Grounds MQ Maze Path Third Chest", TREASURE_GAME_GREEN_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_MAZE_PATH_SECOND_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0A, //
        "Gerudo Training Grounds MQ Maze Path Second Chest", RED_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_HIDDEN_CEILING_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0B, //
        "Gerudo Training Grounds MQ Hidden Ceiling Chest", PURPLE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_UNDERWATER_SILVER_RUPEE_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x0D, //
        "Gerudo Training Grounds MQ Water Room Chest", GERUDO_TRAINING_GROUNDS_SMALL_KEY, //
        { Category::cGerudoTrainingGrounds, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Chest(GERUDO_TRAINING_GROUNDS_MQ_HEAVY_BLOCK_CHEST, SCENE_GERUDO_TRAINING_GROUND, 0x02, //
        "Gerudo Training Grounds MQ Heavy Block Chest", PURPLE_RUPEE, //
        { Category::cGerudoTrainingGrounds }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);

    // Ganons Castle Shared
    Chest(GANONS_TOWER_BOSS_KEY_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0B, //
        "Ganon's Tower Boss Key Chest", GANONS_CASTLE_BOSS_KEY, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    // Ganons Castle Vanilla
    Chest(GANONS_CASTLE_FOREST_TRIAL_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x09, //
        "Ganon's Castle Forest Trial Chest", BLUE_RUPEE, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_WATER_TRIAL_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x07, //
        "Ganon's Castle Water Trial Left Chest", ICE_TRAP, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_WATER_TRIAL_RIGHT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x06, //
        "Ganon's Castle Water Trial Right Chest", RECOVERY_HEART, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_SHADOW_TRIAL_FRONT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x08, //
        "Ganon's Castle Shadow Trial Front Chest", BLUE_RUPEE, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_SHADOW_TRIAL_GOLDEN_GAUNTLETS_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x05, //
        "Ganon's Castle Shadow Trial Golden Gauntlets Chest", PROGRESSIVE_STRENGTH, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_SPIRIT_TRIAL_CRYSTAL_SWITCH_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x12, //
        "Ganon's Castle Spirit Trial Crystal Switch Chest", BOMBCHU_20, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_SPIRIT_TRIAL_INVISIBLE_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x14, //
        "Ganon's Castle Spirit Trial Invisible Chest", ARROWS_10, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_FIRST_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0C, //
        "Ganon's Castle Light Trial First Left Chest", BLUE_RUPEE, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_SECOND_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0B, //
        "Ganon's Castle Light Trial Second Left Chest", ICE_TRAP, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_THIRD_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0D, //
        "Ganon's Castle Light Trial Third Left Chest", RECOVERY_HEART, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_FIRST_RIGHT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0E, //
        "Ganon's Castle Light Trial First Right Chest", ICE_TRAP, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_SECOND_RIGHT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0A, //
        "Ganon's Castle Light Trial Second Right Chest", ARROWS_30, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_THIRD_RIGHT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0F, //
        "Ganon's Castle Light Trial Third Right Chest", ICE_TRAP, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_INVISIBLE_ENEMIES_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x10, //
        "Ganon's Castle Light Trial Invisible Enemies Chest", GANONS_CASTLE_SMALL_KEY, //
        { Category::cGanonsCastle, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_LIGHT_TRIAL_LULLABY_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x11, //
        "Ganon's Castle Light Trial Lullaby Chest", GANONS_CASTLE_SMALL_KEY, //
        { Category::cGanonsCastle, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_DEKU_SCRUB_CENTER_LEFT, SCENE_INSIDE_GANONS_CASTLE, 0x01, //
        "Ganon's Castle Deku Scrub Center-Left", BOMBS_5, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x06), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_DEKU_SCRUB_CENTER_RIGHT, SCENE_INSIDE_GANONS_CASTLE, 0x69, //
        "Ganon's Castle Deku Scrub Center-Right", ARROWS_30, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x04), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_DEKU_SCRUB_RIGHT, SCENE_INSIDE_GANONS_CASTLE, 0x10, //
        "Ganon's Castle Deku Scrub Right", RED_POTION_REFILL, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x08), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_DEKU_SCRUB_LEFT, SCENE_INSIDE_GANONS_CASTLE, 0x11, //
        "Ganon's Castle Deku Scrub Left", GREEN_POTION_REFILL, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x09), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    // Ganons Castle MQ
    Chest(GANONS_CASTLE_MQ_WATER_TRIAL_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x01, //
        "Ganon's Castle MQ Water Trial Chest", RED_RUPEE, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_FOREST_TRIAL_EYE_SWITCH_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x02, //
        "Ganon's Castle MQ Forest Trial Eye Switch Chest", ARROWS_10, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_FOREST_TRIAL_FROZEN_EYE_SWITCH_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x03, //
        "Ganon's Castle MQ Forest Trial Frozen Eye Chest", BOMBS_5, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_LIGHT_TRIAL_LULLABY_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x04, //
        "Ganon's Castle MQ Light Trial Lullaby Chest", RECOVERY_HEART, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SHADOW_TRIAL_BOMB_FLOWER_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x00, //
        "Ganon's Castle MQ Shadow Trial Bomb Flower Chest", ARROWS_10, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SHADOW_TRIAL_EYE_SWITCH_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x05, //
        "Ganon's Castle MQ Shadow Trial Eye Switch Chest", GANONS_CASTLE_SMALL_KEY, //
        { Category::cGanonsCastle, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_GOLDEN_GAUNTLETS_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x06, //
        "Ganon's Castle MQ Spirit Trial Gauntlets Chest", PROGRESSIVE_STRENGTH, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_SUN_BACK_RIGHT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x07, //
        "Ganon's Castle MQ Spirit Trial Sun Back Right Chest", RECOVERY_HEART, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_SUN_BACK_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x08, //
        "Ganon's Castle MQ Spirit Trial Sun Back Left Chest", GANONS_CASTLE_SMALL_KEY, //
        { Category::cGanonsCastle, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_SUN_FRONT_LEFT_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x09, //
        "Ganon's Castle MQ Spirit Trial Sun Front Left Chest", RECOVERY_HEART, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_FIRST_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x0A, //
        "Ganon's Castle MQ Spirit Trial First Chest", BOMBCHU_10, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Chest(GANONS_CASTLE_MQ_SPIRIT_TRIAL_INVISIBLE_CHEST, SCENE_INSIDE_GANONS_CASTLE, 0x14, //
        "Ganon's Castle MQ Spirit Trial Invisible Chest", ARROWS_10, //
        { Category::cGanonsCastle }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Collectable(GANONS_CASTLE_MQ_FOREST_TRIAL_FREESTANDING_KEY, SCENE_INSIDE_GANONS_CASTLE, 0x01, //
        "Ganon's Castle MQ Forest Trial Freestanding Key", GANONS_CASTLE_SMALL_KEY, //
        { Category::cGanonsCastle, Category::cVanillaSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_MQ_DEKU_SCRUB_RIGHT, SCENE_INSIDE_GANONS_CASTLE, 0x30, //
        "Ganon's Castle MQ Deku Scrub Right", DEKU_NUTS_5, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x01), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_MQ_DEKU_SCRUB_CENTER_LEFT, SCENE_INSIDE_GANONS_CASTLE, 0x01, //
        "Ganon's Castle MQ Deku Scrub Center-Left", BOMBS_5, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x06), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_MQ_DEKU_SCRUB_CENTER, SCENE_INSIDE_GANONS_CASTLE, 0x69, //
        "Ganon's Castle MQ Deku Scrub Center", ARROWS_30, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x04), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_MQ_DEKU_SCRUB_CENTER_RIGHT, SCENE_INSIDE_GANONS_CASTLE, 0x10, //
        "Ganon's Castle MQ Deku Scrub Center-Right", RED_POTION_REFILL, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x08), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Base(GANONS_CASTLE_MQ_DEKU_SCRUB_LEFT, SCENE_INSIDE_GANONS_CASTLE, 0x11, //
        "Ganon's Castle MQ Deku Scrub Left", GREEN_POTION_REFILL, //
        { Category::cGanonsCastle, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x0D, 0x09), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
}
