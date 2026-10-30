#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Rupees() {
    Collectable(KF_END_OF_BRIDGE_BLUE_RUPEE, SCENE_KOKIRI_FOREST, 0x11, //
        "KF End of Bridge Blue Rupee", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_BEHIND_MIDOS_HOUSE_BLUE_RUPEE, SCENE_KOKIRI_FOREST, 0x12, //
        "KF Behind Mido's house Blue Rupee", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_BOULDER_MAZE_BLUE_RUPEE_1, SCENE_KOKIRI_FOREST, 0x0F, //
        "KF Boulder Maze Blue Rupee 1", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_BOULDER_MAZE_BLUE_RUPEE_2, SCENE_KOKIRI_FOREST, 0x0E, //
        "KF Boulder Maze Blue Rupee 2", BLUE_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_NEAR_RAMP_GREEN_RUPEE_1, SCENE_KOKIRI_FOREST, 0x24, //
        "KF Near Ramp Green Rupee 1", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_NEAR_RAMP_GREEN_RUPEE_2, SCENE_KOKIRI_FOREST, 0x27, //
        "KF Near Ramp Green Rupee 2", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_NEAR_MIDOS_HOUSE_GREEN_RUPEE_1, SCENE_KOKIRI_FOREST, 0x25, //
        "KF Near Mido's House Green Rupee 1", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_NEAR_MIDOS_HOUSE_GREEN_RUPEE_2, SCENE_KOKIRI_FOREST, 0x26, //
        "KF Near Mido's House Green Rupee 2", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_1, SCENE_KOKIRI_FOREST, 0x40, //
        "KF Rupee circle Green Rupee 1", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_2, SCENE_KOKIRI_FOREST, 0x41, //
        "KF Rupee circle Green Rupee 2", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_3, SCENE_KOKIRI_FOREST, 0x42, //
        "KF Rupee circle Green Rupee 3", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_4, SCENE_KOKIRI_FOREST, 0x43, //
        "KF Rupee circle Green Rupee 4", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_5, SCENE_KOKIRI_FOREST, 0x44, //
        "KF Rupee circle Green Rupee 5", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_GREEN_RUPEE_6, SCENE_KOKIRI_FOREST, 0x45, //
        "KF Rupee circle Green Rupee 6", GREEN_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_RUPEE_CIRCLE_RED_RUPEE, SCENE_KOKIRI_FOREST, 0x46, //
        "KF Rupee circle Red Rupee", RED_RUPEE, //
        { Category::cKokiriForest, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    Collectable(LW_IN_BOULDER_BLUE_RUPEE, SCENE_LOST_WOODS, 0x13, //
        "LW in boulder blue rupee", BLUE_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_1, SCENE_LOST_WOODS, 0x34, //
        "LW in water near ZR Shortcut Green Rupee 1", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_2, SCENE_LOST_WOODS, 0x35, //
        "LW in water near ZR Shortcut Green Rupee 2", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_3, SCENE_LOST_WOODS, 0x36, //
        "LW in water near ZR Shortcut Green Rupee 3", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_4, SCENE_LOST_WOODS, 0x37, //
        "LW in water near ZR Shortcut Green Rupee 4", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_5, SCENE_LOST_WOODS, 0x39, //
        "LW in water near ZR Shortcut Green Rupee 5", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_6, SCENE_LOST_WOODS, 0x3A, //
        "LW in water near ZR Shortcut Green Rupee 6", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_7, SCENE_LOST_WOODS, 0x3B, //
        "LW in water near ZR Shortcut Green Rupee 7", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Collectable(LW_IN_WATER_NEAR_ZR_SHORTCUT_GREEN_RUPEE_8, SCENE_LOST_WOODS, 0x3C, //
        "LW in water near ZR Shortcut Green Rupee 8", GREEN_RUPEE, //
        { Category::cLostWoods, Category::cForest, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);

    Collectable(LH_UNDER_WATER_GREEN_RUPEE_1, SCENE_LAKE_HYLIA, 0x20, //
        "LH Under water green rupee 1", GREEN_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_UNDER_WATER_GREEN_RUPEE_2, SCENE_LAKE_HYLIA, 0x21, //
        "LH Under water green rupee 2", GREEN_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_UNDER_WATER_GREEN_RUPEE_3, SCENE_LAKE_HYLIA, 0x22, //
        "LH Under water green rupee 3", GREEN_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_LAB_DIVE_RED_RUPEE_1, SCENE_LAKESIDE_LABORATORY, 0x01, //
        "LH Lab Dive Red rupee 1", RED_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_LAB_DIVE_RED_RUPEE_2, SCENE_LAKESIDE_LABORATORY, 0x02, //
        "LH Lab Dive Red rupee 2", RED_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    Collectable(LH_LAB_DIVE_RED_RUPEE_3, SCENE_LAKESIDE_LABORATORY, 0x03, //
        "LH Lab Dive Red rupee 3", RED_RUPEE, //
        { Category::cLakeHylia, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);

    Collectable(GV_OCTOROCK_GROTTO_BLUE_RUPEE_1, SCENE_GROTTOS, 0x38, //
        "GV Octorock Grotto Blue Rupee 1", BLUE_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_BLUE_RUPEE_2, SCENE_GROTTOS, 0x39, //
        "GV Octorock Grotto Blue Rupee 2", BLUE_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_BLUE_RUPEE_3, SCENE_GROTTOS, 0x3A, //
        "GV Octorock Grotto Blue Rupee 3", BLUE_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_GREEN_RUPEE_1, SCENE_GROTTOS, 0x3B, //
        "GV Octorock Grotto Green Rupee 1", GREEN_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_GREEN_RUPEE_2, SCENE_GROTTOS, 0x3C, //
        "GV Octorock Grotto Green Rupee 2", GREEN_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_GREEN_RUPEE_3, SCENE_GROTTOS, 0x3D, //
        "GV Octorock Grotto Green Rupee 3", GREEN_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_GREEN_RUPEE_4, SCENE_GROTTOS, 0x3E, //
        "GV Octorock Grotto Green Rupee 4", GREEN_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Collectable(GV_OCTOROCK_GROTTO_RED_RUPEE, SCENE_GROTTOS, 0x3F, //
        "GV Octorock Grotto Red Rupee", RED_RUPEE, //
        { Category::cGerudoValley, Category::cGerudo, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);

    Collectable(DMT_ROCK_BLUE_RUPEE, SCENE_DEATH_MOUNTAIN_TRAIL, 0x07, //
        "DMT Rock Blue Rupee", BLUE_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_ROCK_RED_RUPEE, SCENE_DEATH_MOUNTAIN_TRAIL, 0x0A, //
        "DMT Rock Red Rupee", RED_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_1, SCENE_GROTTOS, 0x40, //
        "DMT Cow Grotto rupee circle Green Rupee 1", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_2, SCENE_GROTTOS, 0x41, //
        "DMT Cow Grotto rupee circle Green Rupee 2", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_3, SCENE_GROTTOS, 0x42, //
        "DMT Cow Grotto rupee circle Green Rupee 3", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_4, SCENE_GROTTOS, 0x43, //
        "DMT Cow Grotto rupee circle Green Rupee 4", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_5, SCENE_GROTTOS, 0x44, //
        "DMT Cow Grotto rupee circle Green Rupee 5", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_GREEN_RUPEE_6, SCENE_GROTTOS, 0x45, //
        "DMT Cow Grotto rupee circle Green Rupee 6", GREEN_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_RUPEE_CIRCLE_RED_RUPEE, SCENE_GROTTOS, 0x46, //
        "DMT Cow Grotto rupee circle Red Rupee", RED_RUPEE, //
        { Category::cDeathMountainTrail, Category::cFreestandingRupee, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);

    Collectable(DMC_LOWER_RED_RUPEE_1, SCENE_DEATH_MOUNTAIN_CRATER, 0x20, //
        "DMC Lower Red Rupee 1", RED_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_RED_RUPEE_2, SCENE_DEATH_MOUNTAIN_CRATER, 0x21, //
        "DMC Lower Red Rupee 2", RED_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_1, SCENE_DEATH_MOUNTAIN_CRATER, 0x22, //
        "DMC Lower Blue Rupee 1", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_2, SCENE_DEATH_MOUNTAIN_CRATER, 0x23, //
        "DMC Lower Blue Rupee 2", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_3, SCENE_DEATH_MOUNTAIN_CRATER, 0x24, //
        "DMC Lower Blue Rupee 3", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_4, SCENE_DEATH_MOUNTAIN_CRATER, 0x25, //
        "DMC Lower Blue Rupee 4", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_5, SCENE_DEATH_MOUNTAIN_CRATER, 0x26, //
        "DMC Lower Blue Rupee 5", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_LOWER_BLUE_RUPEE_6, SCENE_DEATH_MOUNTAIN_CRATER, 0x27, //
        "DMC Lower Blue Rupee 6", BLUE_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_1, SCENE_DEATH_MOUNTAIN_CRATER, 0x40, //
        "DMC Scare crow rupee circle Green Rupee 1", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_2, SCENE_DEATH_MOUNTAIN_CRATER, 0x41, //
        "DMC Scare crow rupee circle Green Rupee 2", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_3, SCENE_DEATH_MOUNTAIN_CRATER, 0x42, //
        "DMC Scare crow rupee circle Green Rupee 3", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_4, SCENE_DEATH_MOUNTAIN_CRATER, 0x43, //
        "DMC Scare crow rupee circle Green Rupee 4", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_5, SCENE_DEATH_MOUNTAIN_CRATER, 0x44, //
        "DMC Scare crow rupee circle Green Rupee 5", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_GREEN_RUPEE_6, SCENE_DEATH_MOUNTAIN_CRATER, 0x45, //
        "DMC Scare crow rupee circle Green Rupee 6", GREEN_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Collectable(DMC_SCARE_CROW_RUPEE_CIRCLE_RED_RUPEE, SCENE_DEATH_MOUNTAIN_CRATER, 0x46, //
        "DMC Scare crow rupee circle Red Rupee", RED_RUPEE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);

    Collectable(ZR_WATERFALL_RED_RUPEE_1, SCENE_ZORAS_RIVER, 0x20, //
        "ZR Waterfall Red Rupee 1", RED_RUPEE, //
        { Category::cZorasRiver, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Collectable(ZR_WATERFALL_RED_RUPEE_2, SCENE_ZORAS_RIVER, 0x21, //
        "ZR Waterfall Red Rupee 2", RED_RUPEE, //
        { Category::cZorasRiver, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Collectable(ZR_WATERFALL_RED_RUPEE_3, SCENE_ZORAS_RIVER, 0x22, //
        "ZR Waterfall Red Rupee 3", RED_RUPEE, //
        { Category::cZorasRiver, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    Collectable(ZR_WATERFALL_RED_RUPEE_4, SCENE_ZORAS_RIVER, 0x23, //
        "ZR Waterfall Red Rupee 4", RED_RUPEE, //
        { Category::cZorasRiver, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);

    Collectable(ZF_UNDERWATER_GREEN_RUPEE_1, SCENE_ZORAS_FOUNTAIN, 0x20, //
        "ZF Underwater Green Rupee 1", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_2, SCENE_ZORAS_FOUNTAIN, 0x21, //
        "ZF Underwater Green Rupee 2", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_3, SCENE_ZORAS_FOUNTAIN, 0x22, //
        "ZF Underwater Green Rupee 3", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_4, SCENE_ZORAS_FOUNTAIN, 0x23, //
        "ZF Underwater Green Rupee 4", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_5, SCENE_ZORAS_FOUNTAIN, 0x24, //
        "ZF Underwater Green Rupee 5", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_6, SCENE_ZORAS_FOUNTAIN, 0x25, //
        "ZF Underwater Green Rupee 6", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_7, SCENE_ZORAS_FOUNTAIN, 0x26, //
        "ZF Underwater Green Rupee 7", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_8, SCENE_ZORAS_FOUNTAIN, 0x27, //
        "ZF Underwater Green Rupee 8", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_9, SCENE_ZORAS_FOUNTAIN, 0x28, //
        "ZF Underwater Green Rupee 9", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_10, SCENE_ZORAS_FOUNTAIN, 0x29, //
        "ZF Underwater Green Rupee 10", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_11, SCENE_ZORAS_FOUNTAIN, 0x2A, //
        "ZF Underwater Green Rupee 11", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_12, SCENE_ZORAS_FOUNTAIN, 0x2B, //
        "ZF Underwater Green Rupee 12", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_13, SCENE_ZORAS_FOUNTAIN, 0x2C, //
        "ZF Underwater Green Rupee 13", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_14, SCENE_ZORAS_FOUNTAIN, 0x2D, //
        "ZF Underwater Green Rupee 14", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_15, SCENE_ZORAS_FOUNTAIN, 0x2E, //
        "ZF Underwater Green Rupee 15", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_16, SCENE_ZORAS_FOUNTAIN, 0x2F, //
        "ZF Underwater Green Rupee 16", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_17, SCENE_ZORAS_FOUNTAIN, 0x30, //
        "ZF Underwater Green Rupee 17", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Collectable(ZF_UNDERWATER_GREEN_RUPEE_18, SCENE_ZORAS_FOUNTAIN, 0x31, //
        "ZF Underwater Green Rupee 18", GREEN_RUPEE, //
        { Category::cZorasFountain, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);

    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_1, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x38, //
        "GY Dampe Race Green Rupee 1", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_2, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x39, //
        "GY Dampe Race Green Rupee 2", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_3, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3A, //
        "GY Dampe Race Green Rupee 3", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_4, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3B, //
        "GY Dampe Race Green Rupee 4", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_5, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3C, //
        "GY Dampe Race Green Rupee 5", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_6, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3D, //
        "GY Dampe Race Green Rupee 6", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_7, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3E, //
        "GY Dampe Race Green Rupee 7", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Collectable(GRAVEYARD_DAMPE_RACE_GREEN_RUPEE_8, SCENE_WINDMILL_AND_DAMPES_GRAVE, 0x3F, //
        "GY Dampe Race Green Rupee 8", GREEN_RUPEE, //
        { Category::cGraveyard, Category::cKakariko, Category::cMinigame, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);

    Collectable(ICE_CAVERN_RED_ICE_BLUE_RUPEE, SCENE_ICE_CAVERN, 0x21, //
        "Ice Cavern Red Ice Blue Rupee", BLUE_RUPEE, //
        { Category::cIceCavern, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_PUSH_BLOCK_ROOM_RED_RUPEE_1, SCENE_ICE_CAVERN, 0x2E, //
        "Ice Cavern Block Room Red Rupee 1", RED_RUPEE, //
        { Category::cIceCavern, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_PUSH_BLOCK_ROOM_RED_RUPEE_2, SCENE_ICE_CAVERN, 0x2F, //
        "Ice Cavern Block Room Red Rupee 2", RED_RUPEE, //
        { Category::cIceCavern, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_PUSH_BLOCK_ROOM_RED_RUPEE_3, SCENE_ICE_CAVERN, 0x30, //
        "Ice Cavern Block Room Red Rupee 3", RED_RUPEE, //
        { Category::cIceCavern, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);

    Collectable(BOTTOM_OF_THE_WELL_CENTER_ROOM_PIT_FALL_BLUE_RUPEE_1, SCENE_BOTTOM_OF_THE_WELL, 0x02, //
        "Bottom of the Well Center Pit fall Blue Rupee 1",
        BLUE_RUPEE, //
        { Category::cBottomOfTheWell, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_CENTER_ROOM_PIT_FALL_BLUE_RUPEE_2, SCENE_BOTTOM_OF_THE_WELL, 0x03, //
        "Bottom of the Well Center Pit fall Blue Rupee 2",
        BLUE_RUPEE, //
        { Category::cBottomOfTheWell, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_CENTER_ROOM_PIT_FALL_BLUE_RUPEE_3, SCENE_BOTTOM_OF_THE_WELL, 0x04, //
        "Bottom of the Well Center Pit fall Blue Rupee 3",
        BLUE_RUPEE, //
        { Category::cBottomOfTheWell, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_CENTER_ROOM_PIT_FALL_BLUE_RUPEE_4, SCENE_BOTTOM_OF_THE_WELL, 0x05, //
        "Bottom of the Well Center Pit fall Blue Rupee 4",
        BLUE_RUPEE, //
        { Category::cBottomOfTheWell, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_CENTER_ROOM_PIT_FALL_BLUE_RUPEE_5, SCENE_BOTTOM_OF_THE_WELL, 0x06, //
        "Bottom of the Well Center Pit fall Blue Rupee 5",
        BLUE_RUPEE, //
        { Category::cBottomOfTheWell, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);

    Collectable(JABU_JABUS_BELLY_MQ_NEAR_COW_BOTTOM_GREEN_RUPEE, SCENE_JABU_JABU, 0x01, //
        "Jabu Jabus Belly MQ Near Cow Bottom Green Rupee",
        GREEN_RUPEE, //
        { Category::cJabuJabusBelly, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Collectable(JABU_JABUS_BELLY_MQ_NEAR_COW_MIDDLE_GREEN_RUPEE, SCENE_JABU_JABU, 0x02, //
        "Jabu Jabus Belly MQ Near Cow Middle Green Rupee",
        GREEN_RUPEE, //
        { Category::cJabuJabusBelly, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Collectable(JABU_JABUS_BELLY_MQ_NEAR_COW_TOP_GREEN_RUPEE, SCENE_JABU_JABU, 0x03, //
        "Jabu Jabus Belly MQ Near Cow Top Green Rupee", GREEN_RUPEE, //
        { Category::cJabuJabusBelly, Category::cFreestandingRupee }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
}
