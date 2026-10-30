#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Overworld() {
    // Kokiri Forest
    Chest(KF_KOKIRI_SWORD_CHEST, SCENE_KOKIRI_FOREST, 0x00, //
        "KF Kokiri Sword Chest", KOKIRI_SWORD, //
        { Category::cKokiriForest, Category::cForest }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Chest(KF_MIDOS_TOP_LEFT_CHEST, SCENE_MIDOS_HOUSE, 0x00, //
        "KF Mido Top Left Chest", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Chest(KF_MIDOS_TOP_RIGHT_CHEST, SCENE_MIDOS_HOUSE, 0x01, //
        "KF Mido Top Right Chest", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Chest(KF_MIDOS_BOTTOM_LEFT_CHEST, SCENE_MIDOS_HOUSE, 0x02, //
        "KF Mido Bottom Left Chest", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Chest(KF_MIDOS_BOTTOM_RIGHT_CHEST, SCENE_MIDOS_HOUSE, 0x03, //
        "KF Mido Bottom Right Chest", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Chest(KF_STORMS_GROTTO_CHEST, SCENE_GROTTOS, 0x0C, //
        "KF Storms Grotto Chest", RED_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    // Lost Woods
    Chest(LW_NEAR_SHORTCUTS_GROTTO_CHEST, SCENE_GROTTOS, 0x14, //
        "LW Near Shortcuts Grotto Chest", BLUE_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_SKULL_KID, SCENE_LOST_WOODS, 0x3E, //
        "LW Skull Kid", PIECE_OF_HEART, //
        { Category::cLostWoods, Category::cForest }, //
        SpoilerCollectionCheck::ItemGetInf(30), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_TRADE_COJIRO, SCENE_LOST_WOODS, 0x1F, //
        "LW Trade Cojiro", ODD_MUSHROOM, //
        { Category::cLostWoods, Category::cForest, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(37), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_TRADE_ODD_POULTICE, SCENE_LOST_WOODS, 0x21, //
        "LW Trade Odd Poultice", POACHERS_SAW, //
        { Category::cLostWoods, Category::cForest, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(57), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_OCARINA_MEMORY_GAME, SCENE_LOST_WOODS, 0x76, //
        "LW Ocarina Memory Game", PIECE_OF_HEART, //
        { Category::cLostWoods, Category::cForest, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(31), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_TARGET_IN_WOODS, SCENE_LOST_WOODS, 0x60, //
        "LW Target in Woods", PROGRESSIVE_SLINGSHOT, //
        { Category::cLostWoods, Category::cForest }, //
        SpoilerCollectionCheck::ItemGetInf(21), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_DEKU_SCRUB_NEAR_DEKU_THEATER_RIGHT, SCENE_LOST_WOODS, 0x63, //
        "LW Deku Scrub Near Deku Theater Right", DEKU_NUTS_5, //
        { Category::cLostWoods, Category::cForest, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x5B, 0x01), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_DEKU_SCRUB_NEAR_DEKU_THEATER_LEFT, SCENE_LOST_WOODS, 0x07, //
        "LW Deku Scrub Near Deku Theater Left", DEKU_STICK_1, //
        { Category::cLostWoods, Category::cForest, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x5B, 0x02), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(LW_DEKU_SCRUB_NEAR_BRIDGE, SCENE_LOST_WOODS, 0x77, //
        "LW Deku Scrub Near Bridge", PROGRESSIVE_STICK_UPGRADE, //
        { Category::cLostWoods, Category::cForest, Category::cDekuScrub, Category::cDekuScrubUpgrades }, //
        SpoilerCollectionCheck::Scrub(0x5B, 0x0A), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    GrottoScrub(LW_DEKU_SCRUB_GROTTO_REAR, 0xF5, 0x69, //
        "LW Deku Scrub Grotto Rear", DEKU_SEEDS_30, //
        { Category::cLostWoods, Category::cForest, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x1F, 0x04), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    GrottoScrub(LW_DEKU_SCRUB_GROTTO_FRONT, 0xF5, 0x79, //
        "LW Deku Scrub Grotto Front", PROGRESSIVE_NUT_UPGRADE, //
        { Category::cLostWoods, Category::cForest, Category::cDekuScrub, Category::cDekuScrubUpgrades,
            Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x1F, 0x0B), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(DEKU_THEATER_SKULL_MASK, SCENE_GROTTOS, 0x77, //
        "Deku Theater Skull Mask", PROGRESSIVE_STICK_UPGRADE, //
        { Category::cLostWoods, Category::cForest, Category::cGrotto }, //
        SpoilerCollectionCheck::ItemGetInf(22), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Base(DEKU_THEATER_MASK_OF_TRUTH, SCENE_GROTTOS, 0x7A, //
        "Deku Theater Mask of Truth", PROGRESSIVE_NUT_UPGRADE, //
        { Category::cLostWoods, Category::cForest, Category::cNeedSpiritualStones, Category::cGrotto }, //
        SpoilerCollectionCheck::ItemGetInf(23), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);

    // Sacred Forest Meadow
    Chest(SFM_WOLFOS_GROTTO_CHEST, SCENE_GROTTOS, 0x11, //
        "SFM Wolfos Grotto Chest", PURPLE_RUPEE, //
        { Category::cSacredForestMeadow, Category::cForest, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);
    GrottoScrub(SFM_DEKU_SCRUB_GROTTO_REAR, 0xEE, 0x10, //
        "SFM Deku Scrub Grotto Rear", RED_POTION_REFILL, //
        { Category::cSacredForestMeadow, Category::cForest, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x18, 0x08), SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);
    GrottoScrub(SFM_DEKU_SCRUB_GROTTO_FRONT, 0xEE, 0x11, //
        "SFM Deku Scrub Grotto Front", GREEN_POTION_REFILL, //
        { Category::cSacredForestMeadow, Category::cForest, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x18, 0x09), SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);

    // Hyrule Field
    Chest(HF_SOUTHEAST_GROTTO_CHEST, SCENE_GROTTOS, 0x02, //
        "HF Southeast Grotto Chest", RED_RUPEE, //
        { Category::cHyruleField, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Chest(HF_OPEN_GROTTO_CHEST, SCENE_GROTTOS, 0x03, //
        "HF Open Grotto Chest", BLUE_RUPEE, //
        { Category::cHyruleField, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Chest(HF_NEAR_MARKET_GROTTO_CHEST, SCENE_GROTTOS, 0x00, //
        "HF Near Market Grotto Chest", BLUE_RUPEE, //
        { Category::cHyruleField, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Base(HF_OCARINA_OF_TIME_ITEM, SCENE_HYRULE_FIELD, 0x0C, //
        "HF Ocarina of Time Item", PROGRESSIVE_OCARINA, //
        { Category::cHyruleField, Category::cNeedSpiritualStones }, //
        SpoilerCollectionCheck::EventChkInf(0x43), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_TEKTITE_GROTTO_FREESTANDING_POH, SCENE_GROTTOS, 0x01, //
        "HF Tektite Grotto Freestanding PoH", PIECE_OF_HEART, //
        { Category::cHyruleField, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    GrottoScrub(HF_DEKU_SCRUB_GROTTO, 0xE6, 0x3E, //
        "HF Deku Scrub Grotto", PIECE_OF_HEART, //
        { Category::cHyruleField, Category::cDekuScrub, Category::cDekuScrubUpgrades, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x10, 0x03), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_1, SCENE_HYRULE_FIELD, 0x01, //
        "HF Big Poe near GV along road", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x01), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_2, SCENE_HYRULE_FIELD, 0x02, //
        "HF Big Poe near GV and tree", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x02), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_3, SCENE_HYRULE_FIELD, 0x03, //
        "HF Big Poe near south-east bush", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x03), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_4, SCENE_HYRULE_FIELD, 0x04, //
        "HF Big Poe near south-east grass", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x04), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_5, SCENE_HYRULE_FIELD, 0x05, //
        "HF Big Poe near silver boulder", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x05), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_6, SCENE_HYRULE_FIELD, 0x06, //
        "HF Big Poe near central wall", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x06), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_7, SCENE_HYRULE_FIELD, 0x07, //
        "HF Big Poe near Kakariko", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x07), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_8, SCENE_HYRULE_FIELD, 0x08, //
        "HF Big Poe near Castle", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x08), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_9, SCENE_HYRULE_FIELD, 0x09, //
        "HF Big Poe near Ranch", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x09), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Collectable(HF_BIG_POE_10, SCENE_HYRULE_FIELD, 0x0A, //
        "HF Big Poe near north-west river", UNBOTTLED_BIG_POE, //
        { Category::cHyruleField, Category::cBigPoe }, //
        SpoilerCollectionCheck::Collectable(0x51, 0x0A), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);

    // Lake Hylia
    Base(LH_CHILD_FISHING, SCENE_FISHING_POND, 0x3E, //
        "LH Child Fishing", PIECE_OF_HEART, //
        { Category::cLakeHylia, Category::cMinigame }, //
        SpoilerCollectionCheck::Fishing(0x02), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Base(LH_ADULT_FISHING, SCENE_FISHING_POND, 0x38, //
        "LH Adult Fishing", PROGRESSIVE_SCALE, //
        { Category::cLakeHylia, Category::cMinigame }, //
        SpoilerCollectionCheck::Fishing(0x03), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Base(LH_LAB_DIVE, SCENE_LAKESIDE_LABORATORY, 0x3E, //
        "LH Lab Dive", PIECE_OF_HEART, //
        { Category::cLakeHylia }, //
        SpoilerCollectionCheck::ItemGetInf(24), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Base(LH_TRADE_FROG, SCENE_LAKESIDE_LABORATORY, 0x25, //
        "LH Lab Trade Eyeball Frog", EYEDROPS, //
        { Category::cLakeHylia, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(61), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Base(LH_UNDERWATER_ITEM, SCENE_LAKE_HYLIA, 0x15, //
        "LH Underwater Item", RUTOS_LETTER, //
        { Category::cLakeHylia }, //
        SpoilerCollectionCheck::EventChkInf(0x31), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Base(LH_SUN, SCENE_LAKE_HYLIA, 0x58, //
        "LH Sun", FIRE_ARROWS, //
        { Category::cLakeHylia }, //
        SpoilerCollectionCheck::Chest(0x57, 0x00), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_FREESTANDING_POH, SCENE_LAKE_HYLIA, 0x1E, //
        "LH Freestanding PoH", PIECE_OF_HEART, //
        { Category::cLakeHylia }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GrottoScrub(LH_DEKU_SCRUB_GROTTO_LEFT, 0xEF, 0x63, //
        "LH Deku Scrub Grotto Left", DEKU_NUTS_5, //
        { Category::cLakeHylia, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x19, 0x01), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GrottoScrub(LH_DEKU_SCRUB_GROTTO_RIGHT, 0xEF, 0x01, //
        "LH Deku Scrub Grotto Right", BOMBS_5, //
        { Category::cLakeHylia, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x19, 0x06), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GrottoScrub(LH_DEKU_SCRUB_GROTTO_CENTER, 0xEF, 0x69, //
        "LH Deku Scrub Grotto Center", DEKU_SEEDS_30, //
        { Category::cLakeHylia, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x19, 0x04), SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);

    // Gerudo Valley
    Chest(GV_CHEST, SCENE_GERUDO_VALLEY, 0x00, //
        "GV Chest", PURPLE_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Base(GV_TRADE_SAW, SCENE_GERUDO_VALLEY, 0x22, //
        "GV Trade Saw", BROKEN_SWORD, //
        { Category::cGerudoValley, Category::cGerudo, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(58), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_WATERFALL_FREESTANDING_POH, SCENE_GERUDO_VALLEY, 0x01, //
        "GV Waterfall Freestanding PoH", PIECE_OF_HEART, //
        { Category::cGerudoValley, Category::cGerudo }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_CRATE_FREESTANDING_POH, SCENE_GERUDO_VALLEY, 0x02, //
        "GV Crate Freestanding PoH", PIECE_OF_HEART, //
        { Category::cGerudoValley, Category::cGerudo }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GrottoScrub(GV_DEKU_SCRUB_GROTTO_REAR, 0xF0, 0x10, //
        "GV Deku Scrub Grotto Rear", RED_POTION_REFILL, //
        { Category::cGerudoValley, Category::cGerudo, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x1A, 0x08), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GrottoScrub(GV_DEKU_SCRUB_GROTTO_FRONT, 0xF0, 0x11, //
        "GV Deku Scrub Grotto Front", GREEN_POTION_REFILL, //
        { Category::cGerudoValley, Category::cGerudo, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x1A, 0x09), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);

    // Gerudo Fortress
    Chest(GF_CHEST, SCENE_GERUDOS_FORTRESS, 0x00, //
        "GF Chest", PIECE_OF_HEART, //
        { Category::cGerudoFortress, Category::cGerudo }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Base(GF_HBA_1000_POINTS, SCENE_GERUDOS_FORTRESS, 0x3E, //
        "GF HBA 1000 Points", PIECE_OF_HEART, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cMinigame }, //
        SpoilerCollectionCheck::InfTable(0x19, 0x08), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Base(GF_HBA_1500_POINTS, SCENE_GERUDOS_FORTRESS, 0x30, //
        "GF HBA 1500 Points", PROGRESSIVE_BOW, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(7), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Base(GF_GERUDO_TOKEN, SCENE_THIEVES_HIDEOUT, 0x3A, //
        "GF Gerudo Token", GERUDO_TOKEN, //
        { Category::cGerudoFortress, Category::cGerudo }, //
        SpoilerCollectionCheck::GerudoToken(), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GF_NORTH_F1_CARPENTER, SCENE_THIEVES_HIDEOUT, 0x0C, //
        "GF North F1 Carpenter", GERUDO_FORTRESS_SMALL_KEY, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cVanillaGFSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GF_NORTH_F2_CARPENTER, SCENE_THIEVES_HIDEOUT, 0x0A, //
        "GF North F2 Carpenter", GERUDO_FORTRESS_SMALL_KEY, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cVanillaGFSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GF_SOUTH_F1_CARPENTER, SCENE_THIEVES_HIDEOUT, 0x0E, //
        "GF South F1 Carpenter", GERUDO_FORTRESS_SMALL_KEY, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cVanillaGFSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GF_SOUTH_F2_CARPENTER, SCENE_THIEVES_HIDEOUT, 0x0F, //
        "GF South F2 Carpenter", GERUDO_FORTRESS_SMALL_KEY, //
        { Category::cGerudoFortress, Category::cGerudo, Category::cVanillaGFSmallKey }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);

    // Haunted Wasteland
    Chest(WASTELAND_CHEST, SCENE_HAUNTED_WASTELAND, 0x00, //
        "Wasteland Chest", PURPLE_RUPEE, //
        { Category::cHauntedWasteland }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    Base(WASTELAND_BOMBCHU_SALESMAN, SCENE_HAUNTED_WASTELAND, 0x03, //
        "Wasteland Carpet Salesman", BOMBCHU_10, //
        { Category::cHauntedWasteland, Category::cMerchant }, //
        SpoilerCollectionCheck::EventChkInf(0x34), SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);

    // Desert Colossus
    Collectable(COLOSSUS_FREESTANDING_POH, SCENE_DESERT_COLOSSUS, 0x0D, //
        "Colossus Freestanding PoH", PIECE_OF_HEART, //
        { Category::cDesertColossus }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    GrottoScrub(COLOSSUS_DEKU_SCRUB_GROTTO_REAR, 0xFD, 0x10, //
        "Colossus Deku Scrub Grotto Rear", RED_POTION_REFILL, //
        { Category::cDesertColossus, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x27, 0x08), SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    GrottoScrub(COLOSSUS_DEKU_SCRUB_GROTTO_FRONT, 0xFD, 0x11, //
        "Colossus Deku Scrub Grotto Front", GREEN_POTION_REFILL, //
        { Category::cDesertColossus, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x27, 0x09), SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);

    // Market
    Chest(MARKET_TREASURE_CHEST_GAME_REWARD, SCENE_TREASURE_BOX_SHOP, 0x0A, //
        "MK Treasure Chest Game Reward", TREASURE_GAME_HEART, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(19), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_BOWLING_FIRST_PRIZE, SCENE_BOMBCHU_BOWLING_ALLEY, 0x33, //
        "MK Bombchu Bowling First Prize", PROGRESSIVE_BOMB_BAG, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(25), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_BOWLING_SECOND_PRIZE, SCENE_BOMBCHU_BOWLING_ALLEY, 0x3E, //
        "MK Bombchu Bowling Second Prize", PIECE_OF_HEART, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(26), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_BOWLING_BOMBCHUS, SCENE_BOMBCHU_BOWLING_ALLEY, 0xFF, //
        "MK Bombchu Bowling Bombchus", BOMBCHU_DROP, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame }, //
        SpoilerCollectionCheck::None(), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_LOST_DOG, SCENE_DOG_LADY_HOUSE, 0x3E, //
        "MK Lost Dog", PIECE_OF_HEART, //
        { Category::cInnerMarket, Category::cMarket }, //
        SpoilerCollectionCheck::InfTable(0x19, 0x09), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_SHOOTING_GALLERY_REWARD, SCENE_SHOOTING_GALLERY, 0x60, //
        "MK Shooting Gallery", PROGRESSIVE_SLINGSHOT, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(5), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_10_BIG_POES, SCENE_MARKET_GUARD_HOUSE, 0x0F, //
        "MK 10 Big Poes", EMPTY_BOTTLE, //
        { Category::cInnerMarket, Category::cMarket }, //
        SpoilerCollectionCheck::BigPoePoints(), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Chest(MARKET_TREASURE_CHEST_GAME_ITEM_1, SCENE_TREASURE_BOX_SHOP, 0x01, //
        "MK Chest Game First Room Chest", TREASURE_GAME_SMALL_KEY, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame, Category::cChestMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);
    Chest(MARKET_TREASURE_CHEST_GAME_ITEM_2, SCENE_TREASURE_BOX_SHOP, 0x03, //
        "MK Chest Game Second Room Chest", TREASURE_GAME_SMALL_KEY, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame, Category::cChestMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);
    Chest(MARKET_TREASURE_CHEST_GAME_ITEM_3, SCENE_TREASURE_BOX_SHOP, 0x05, //
        "MK Chest Game Third Room Chest", TREASURE_GAME_SMALL_KEY, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame, Category::cChestMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);
    Chest(MARKET_TREASURE_CHEST_GAME_ITEM_4, SCENE_TREASURE_BOX_SHOP, 0x07, //
        "MK Chest Game Fourth Room Chest", TREASURE_GAME_SMALL_KEY, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame, Category::cChestMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);
    Chest(MARKET_TREASURE_CHEST_GAME_ITEM_5, SCENE_TREASURE_BOX_SHOP, 0x09, //
        "MK Chest Game Fifth Room Chest", TREASURE_GAME_SMALL_KEY, //
        { Category::cInnerMarket, Category::cMarket, Category::cMinigame, Category::cChestMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);

    // Hyrule Castle
    Base(HC_MALON_EGG, SCENE_HYRULE_CASTLE, 0x47, //
        "HC Malon Egg", WEIRD_EGG, //
        { Category::cHyruleCastle, Category::cMarket }, //
        SpoilerCollectionCheck::EventChkInf(0x12), SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);

    // Kakariko
    Chest(KAK_REDEAD_GROTTO_CHEST, SCENE_GROTTOS, 0x0A, //
        "Kak Redead Grotto Chest", HUGE_RUPEE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Chest(KAK_OPEN_GROTTO_CHEST, SCENE_GROTTOS, 0x08, //
        "Kak Open Grotto Chest", RED_RUPEE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_10_GOLD_SKULLTULA_REWARD, SCENE_HOUSE_OF_SKULLTULA, 0x45, //
        "Kak 10 Gold Skulltula Reward", PROGRESSIVE_WALLET, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSkulltulaHouse }, //
        SpoilerCollectionCheck::EventChkInf(0xDA), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_20_GOLD_SKULLTULA_REWARD, SCENE_HOUSE_OF_SKULLTULA, 0x39, //
        "Kak 20 Gold Skulltula Reward", SHARD_OF_AGONY, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSkulltulaHouse }, //
        SpoilerCollectionCheck::EventChkInf(0xDB), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_30_GOLD_SKULLTULA_REWARD, SCENE_HOUSE_OF_SKULLTULA, 0x46, //
        "Kak 30 Gold Skulltula Reward", PROGRESSIVE_WALLET, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSkulltulaHouse }, //
        SpoilerCollectionCheck::EventChkInf(0xDC), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_40_GOLD_SKULLTULA_REWARD, SCENE_HOUSE_OF_SKULLTULA, 0x03, //
        "Kak 40 Gold Skulltula Reward", BOMBCHU_10, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSkulltulaHouse }, //
        SpoilerCollectionCheck::EventChkInf(0xDD), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_50_GOLD_SKULLTULA_REWARD, SCENE_HOUSE_OF_SKULLTULA, 0x3E, //
        "Kak 50 Gold Skulltula Reward", PIECE_OF_HEART, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSkulltulaHouse }, //
        SpoilerCollectionCheck::EventChkInf(0xDE), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_MAN_ON_ROOF, SCENE_KAKARIKO_VILLAGE, 0x3E, //
        "Kak Man on Roof", PIECE_OF_HEART, //
        { Category::cKakarikoVillage, Category::cKakariko }, //
        SpoilerCollectionCheck::ItemGetInf(29), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_SHOOTING_GALLERY_REWARD, SCENE_SHOOTING_GALLERY, 0x30, //
        "Kak Shooting Gallery Reward", PROGRESSIVE_BOW, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(6), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_TRADE_ODD_MUSHROOM, SCENE_POTION_SHOP_GRANNY, 0x20, //
        "Kak Trade Odd Mushroom", ODD_POULTICE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(56), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_GRANNYS_SHOP, SCENE_POTION_SHOP_GRANNY, 0x10, //
        "Kak Granny's Shop", BLUE_POTION_REFILL, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cMerchant }, //
        SpoilerCollectionCheck::EventChkInf(0x32), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_ANJU_AS_ADULT, SCENE_KAKARIKO_VILLAGE, 0x1D, //
        "Kak Anju as Adult", POCKET_EGG, //
        { Category::cKakarikoVillage, Category::cKakariko }, //
        SpoilerCollectionCheck::ItemGetInf(36), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_ANJU_AS_CHILD, SCENE_KAKARIKO_VILLAGE, 0x0F, //
        "Kak Anju as Child", EMPTY_BOTTLE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(4), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_TRADE_POCKET_CUCCO, SCENE_KAKARIKO_VILLAGE, 0x0E, //
        "Kak Trade Pocket Cucco", COJIRO, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(38), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Collectable(KAK_IMPAS_HOUSE_FREESTANDING_POH, SCENE_IMPAS_HOUSE, 0x01, //
        "Kak Impas House Freestanding PoH", PIECE_OF_HEART, //
        { Category::cKakarikoVillage, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Collectable(KAK_WINDMILL_FREESTANDING_POH, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x01, //
        "Kak Windmill Freestanding PoH", PIECE_OF_HEART, //
        { Category::cKakarikoVillage, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    // Graveyard
    Chest(GRAVEYARD_SHIELD_GRAVE_CHEST, SCENE_GRAVE_WITH_FAIRYS_FOUNTAIN, 0x00, //
        "GY Shield Grave Chest", HYLIAN_SHIELD, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Chest(GRAVEYARD_HEART_PIECE_GRAVE_CHEST, SCENE_REDEAD_GRAVE, 0x00, //
        "GY Heart Piece Grave Chest", PIECE_OF_HEART, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Chest(GRAVEYARD_COMPOSERS_GRAVE_CHEST, SCENE_ROYAL_FAMILYS_TOMB, 0x00, //
        "GY Composers Grave Chest", BOMBS_5, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Chest(GRAVEYARD_HOOKSHOT_CHEST, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x00, //
        "GY Hookshot Chest", PROGRESSIVE_HOOKSHOT, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_FREESTANDING_POH, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x07, //
        "GY Dampe Race Freestanding PoH", PIECE_OF_HEART, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_FREESTANDING_POH, SCENE_GRAVEYARD, 0x04, //
        "GY Freestanding PoH", PIECE_OF_HEART, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_GRAVEDIGGING_TOUR, SCENE_GRAVEYARD, 0x08, //
        "GY Dampe Gravedigging Tour", PIECE_OF_HEART, //
        { Category::cGraveyard, Category::cKakariko }, //
        SpoilerCollectionCheck::ItemGetInf(20), SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);

    // Death Mountain Trail
    Chest(DMT_CHEST, SCENE_DEATH_MOUNTAIN_TRAIL, 0x01, //
        "DMT Chest", PURPLE_RUPEE, //
        { Category::cDeathMountainTrail, Category::cDeathMountain }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Chest(DMT_STORMS_GROTTO_CHEST, SCENE_GROTTOS, 0x17, //
        "DMT Storms Grotto Chest", HUGE_RUPEE, //
        { Category::cDeathMountainTrail, Category::cDeathMountain, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Base(DMT_TRADE_BROKEN_SWORD, SCENE_DEATH_MOUNTAIN_TRAIL, 0x23, //
        "DMT Trade Broken Sword", PRESCRIPTION, //
        { Category::cDeathMountainTrail, Category::cDeathMountain, Category::cAdultTrade }, //
        SpoilerCollectionCheck::Biggoron(0x4), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Base(DMT_TRADE_EYEDROPS, SCENE_DEATH_MOUNTAIN_TRAIL, 0x26, //
        "DMT Trade Eyedrops", CLAIM_CHECK, //
        { Category::cDeathMountainTrail, Category::cDeathMountain, Category::cAdultTrade }, //
        SpoilerCollectionCheck::Biggoron(0x2), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Base(DMT_TRADE_CLAIM_CHECK, SCENE_DEATH_MOUNTAIN_TRAIL, 0x57, //
        "DMT Trade Claim Check", BIGGORON_SWORD, //
        { Category::cDeathMountainTrail, Category::cDeathMountain }, //
        SpoilerCollectionCheck::Biggoron(0x1), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_FREESTANDING_POH, SCENE_DEATH_MOUNTAIN_TRAIL, 0x1E, //
        "DMT Freestanding PoH", PIECE_OF_HEART, //
        { Category::cDeathMountainTrail, Category::cDeathMountain }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);

    // Goron City
    Chest(GC_MAZE_LEFT_CHEST, SCENE_GORON_CITY, 0x00, //
        "GC Maze Left Chest", HUGE_RUPEE, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Chest(GC_MAZE_RIGHT_CHEST, SCENE_GORON_CITY, 0x01, //
        "GC Maze Right Chest", PURPLE_RUPEE, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Chest(GC_MAZE_CENTER_CHEST, SCENE_GORON_CITY, 0x02, //
        "GC Maze Center Chest", PURPLE_RUPEE, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_ROLLING_GORON_AS_CHILD, SCENE_GORON_CITY, 0x34, //
        "GC Rolling Goron as Child", PROGRESSIVE_BOMB_BAG, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheck::InfTable(0x11, 0x06), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_ROLLING_GORON_AS_ADULT, SCENE_GORON_CITY, 0x2C, //
        "GC Rolling Goron as Adult", GORON_TUNIC, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheck::InfTable(0x10, 0x01), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_DARUNIAS_JOY, SCENE_GORON_CITY, 0x54, //
        "GC Darunias Joy", PROGRESSIVE_STRENGTH, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheck::EventChkInf(0x36), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Collectable(GC_POT_FREESTANDING_POH, SCENE_GORON_CITY, 0x1F, //
        "GC Pot Freestanding PoH", PIECE_OF_HEART, //
        { Category::cGoronCity }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    GrottoScrub(GC_DEKU_SCRUB_GROTTO_LEFT, 0xFB, 0x63, //
        "GC Deku Scrub Grotto Left", DEKU_NUTS_5, //
        { Category::cGoronCity, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x25, 0x01), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    GrottoScrub(GC_DEKU_SCRUB_GROTTO_RIGHT, 0xFB, 0x01, //
        "GC Deku Scrub Grotto Right", BOMBS_5, //
        { Category::cGoronCity, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x25, 0x06), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    GrottoScrub(GC_DEKU_SCRUB_GROTTO_CENTER, 0xFB, 0x69, //
        "GC Deku Scrub Grotto Center", ARROWS_30, //
        { Category::cGoronCity, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x25, 0x04), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_MEDIGORON, SCENE_GORON_CITY, 0x51, //
        "GC Medigoron", GIANTS_KNIFE, //
        { Category::cGoronCity, Category::cMerchant }, //
        SpoilerCollectionCheck::EventChkInf(0x35), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);

    // Death Mountain Crater
    Chest(DMC_UPPER_GROTTO_CHEST, SCENE_GROTTOS, 0x1A, //
        "DMC Upper Grotto Chest", BOMBS_20, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_WALL_FREESTANDING_POH, SCENE_DEATH_MOUNTAIN_CRATER, 0x02, //
        "DMC Wall Freestanding PoH", PIECE_OF_HEART, //
        { Category::cDeathMountainCrater, Category::cDeathMountain }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_VOLCANO_FREESTANDING_POH, SCENE_DEATH_MOUNTAIN_CRATER, 0x08, //
        "DMC Volcano Freestanding PoH", PIECE_OF_HEART, //
        { Category::cDeathMountainCrater, Category::cDeathMountain }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Base(DMC_DEKU_SCRUB, SCENE_DEATH_MOUNTAIN_CRATER, 0x01, //
        "DMC Deku Scrub", BOMBS_5, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cDekuScrub }, //
        SpoilerCollectionCheck::Scrub(0x61, 0x06), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    GrottoScrub(DMC_DEKU_SCRUB_GROTTO_LEFT, 0xF9, 0x63, //
        "DMC Deku Scrub Grotto Left", DEKU_NUTS_5, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x23, 0x01), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    GrottoScrub(DMC_DEKU_SCRUB_GROTTO_RIGHT, 0xF9, 0x01, //
        "DMC Deku Scrub Grotto Right", BOMBS_5, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x23, 0x06), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    GrottoScrub(DMC_DEKU_SCRUB_GROTTO_CENTER, 0xF9, 0x69, //
        "DMC Deku Scrub Grotto Center", ARROWS_30, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x23, 0x04), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);

    // Zoras River
    Chest(ZR_OPEN_GROTTO_CHEST, SCENE_GROTTOS, 0x09, //
        "ZR Open Grotto Chest", RED_RUPEE, //
        { Category::cZorasRiver, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_MAGIC_BEAN_SALESMAN, SCENE_ZORAS_RIVER, 0x16, //
        "ZR Magic Bean Salesman", MAGIC_BEAN, //
        { Category::cZorasRiver }, //
        SpoilerCollectionCheck::MagicBeans(0x54, 0x01), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_ZELDAS_LULLABY, SCENE_ZORAS_RIVER, 0x01, //
        "ZR Frogs Zelda's Lullaby", PURPLE_RUPEE, //
        { Category::cZorasRiver, Category::cFrogRupees }, //
        SpoilerCollectionCheck::EventChkInf(0xD1), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_EPONAS_SONG, SCENE_ZORAS_RIVER, 0x02, //
        "ZR Frogs Epona's Song", PURPLE_RUPEE, //
        { Category::cZorasRiver, Category::cFrogRupees }, //
        SpoilerCollectionCheck::EventChkInf(0xD2), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_SARIAS_SONG, SCENE_ZORAS_RIVER, 0x03, //
        "ZR Frogs Saria's Song", PURPLE_RUPEE, //
        { Category::cZorasRiver, Category::cFrogRupees }, //
        SpoilerCollectionCheck::EventChkInf(0xD4), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_SUNS_SONG, SCENE_ZORAS_RIVER, 0x04, //
        "ZR Frogs Sun's Song", PURPLE_RUPEE, //
        { Category::cZorasRiver, Category::cFrogRupees }, //
        SpoilerCollectionCheck::EventChkInf(0xD3), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_SONG_OF_TIME, SCENE_ZORAS_RIVER, 0x05, //
        "ZR Frogs Song of Time", PURPLE_RUPEE, //
        { Category::cZorasRiver, Category::cFrogRupees }, //
        SpoilerCollectionCheck::EventChkInf(0xD5), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_IN_THE_RAIN, SCENE_ZORAS_RIVER, 0x3E, //
        "ZR Frogs in the Rain", PIECE_OF_HEART, //
        { Category::cZorasRiver }, //
        SpoilerCollectionCheck::EventChkInf(0xD6), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Base(ZR_FROGS_OCARINA_GAME, SCENE_ZORAS_RIVER, 0x76, //
        "ZR Frogs Ocarina Game", PIECE_OF_HEART, //
        { Category::cZorasRiver, Category::cMinigame }, //
        SpoilerCollectionCheck::EventChkInf(0xD0), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Collectable(ZR_NEAR_OPEN_GROTTO_FREESTANDING_POH, SCENE_ZORAS_RIVER, 0x04, //
        "ZR Near Open Grotto Freestanding PoH", PIECE_OF_HEART, //
        { Category::cZorasRiver }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Collectable(ZR_NEAR_DOMAIN_FREESTANDING_POH, SCENE_ZORAS_RIVER, 0x0B, //
        "ZR Near Domain Freestanding PoH", PIECE_OF_HEART, //
        { Category::cZorasRiver }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    GrottoScrub(ZR_DEKU_SCRUB_GROTTO_REAR, 0xEB, 0x10, //
        "ZR Deku Scrub Grotto Rear", RED_POTION_REFILL, //
        { Category::cZorasRiver, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x15, 0x08), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    GrottoScrub(ZR_DEKU_SCRUB_GROTTO_FRONT, 0xEB, 0x11, //
        "ZR Deku Scrub Grotto Front", GREEN_POTION_REFILL, //
        { Category::cZorasRiver, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x15, 0x09), SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);

    // Zoras Domain
    Chest(ZD_CHEST, SCENE_ZORAS_DOMAIN, 0x00, //
        "ZD Chest", PIECE_OF_HEART, //
        { Category::cZorasDomain }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_DIVING_MINIGAME, SCENE_ZORAS_DOMAIN, 0x37, //
        "ZD Diving Minigame", PROGRESSIVE_SCALE, //
        { Category::cZorasDomain, Category::cMinigame }, //
        SpoilerCollectionCheck::EventChkInf(0x38), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_KING_ZORA_THAWED, SCENE_ZORAS_DOMAIN, 0x2D, //
        "ZD King Zora Thawed", ZORA_TUNIC, //
        { Category::cZorasDomain }, //
        SpoilerCollectionCheck::InfTable(0x13, 0x01), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_TRADE_PRESCRIPTION, SCENE_ZORAS_DOMAIN, 0x24, //
        "ZD Trade Prescription", EYEBALL_FROG, //
        { Category::cZorasDomain, Category::cAdultTrade }, //
        SpoilerCollectionCheck::ItemGetInf(60), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);

    // Zoras Fountain
    Collectable(ZF_ICEBERG_FREESTANDING_POH, SCENE_ZORAS_FOUNTAIN, 0x01, //
        "ZF Iceberg Freestanding PoH", PIECE_OF_HEART, //
        { Category::cZorasFountain }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_BOTTOM_FREESTANDING_POH, SCENE_ZORAS_FOUNTAIN, 0x14, //
        "ZF Bottom Freestanding PoH", PIECE_OF_HEART, //
        { Category::cZorasFountain }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);

    // Lon Lon Ranch
    Base(LLR_TALONS_CHICKENS, SCENE_LON_LON_BUILDINGS, 0x14, //
        "LLR Talons Chickens", BOTTLE_WITH_MILK, //
        { Category::cLonLonRanch, Category::cMinigame }, //
        SpoilerCollectionCheck::ItemGetInf(10), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Collectable(LLR_FREESTANDING_POH, SCENE_LON_LON_BUILDINGS, 0x01, //
        "LLR Freestanding PoH", PIECE_OF_HEART, //
        { Category::cLonLonRanch }, //
        SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GrottoScrub(LLR_DEKU_SCRUB_GROTTO_LEFT, 0xFC, 0x63, //
        "LLR Deku Scrub Grotto Left", DEKU_NUTS_5, //
        { Category::cLonLonRanch, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x26, 0x01), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GrottoScrub(LLR_DEKU_SCRUB_GROTTO_RIGHT, 0xFC, 0x01, //
        "LLR Deku Scrub Grotto Right", BOMBS_5, //
        { Category::cLonLonRanch, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x26, 0x06), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GrottoScrub(LLR_DEKU_SCRUB_GROTTO_CENTER, 0xFC, 0x69, //
        "LLR Deku Scrub Grotto Center", DEKU_SEEDS_30, //
        { Category::cLonLonRanch, Category::cDekuScrub, Category::cGrotto }, //
        SpoilerCollectionCheck::Scrub(0x26, 0x04), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
}
