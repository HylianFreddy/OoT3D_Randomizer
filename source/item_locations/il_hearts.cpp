#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Hearts() {
    Collectable(KF_ON_SARIAS_HOUSE_HEART_1, SCENE_KOKIRI_FOREST, 0x1C, //
        "KF on Saria's House Heart 1", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_ON_SARIAS_HOUSE_HEART_2, SCENE_KOKIRI_FOREST, 0x1D, //
        "KF on Saria's House Heart 2", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_ON_SARIAS_HOUSE_HEART_3, SCENE_KOKIRI_FOREST, 0x1E, //
        "KF on Saria's House Heart 3", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    Collectable(KF_IN_SARIAS_HOUSE_HEART_1, SCENE_SARIAS_HOUSE, 0x38, //
        "KF in Saria's House Heart 1", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_IN_SARIAS_HOUSE_HEART_2, SCENE_SARIAS_HOUSE, 0x39, //
        "KF in Saria's House Heart 2", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_IN_SARIAS_HOUSE_HEART_3, SCENE_SARIAS_HOUSE, 0x3A, //
        "KF in Saria's House Heart 3", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Collectable(KF_IN_SARIAS_HOUSE_HEART_4, SCENE_SARIAS_HOUSE, 0x3B, //
        "KF in Saria's House Heart 4", RECOVERY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    Collectable(DEKU_TREE_2F_FLOATING_HEART, SCENE_DEKU_TREE, 0x2C, //
        "Deku Tree 2F Floating Heart", RECOVERY_HEART, //
        { Category::cDekuTree, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Collectable(DEKU_TREE_3F_FLOATING_HEART, SCENE_DEKU_TREE, 0x2D, //
        "Deku Tree 3F Floating Heart", RECOVERY_HEART, //
        { Category::cDekuTree, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Collectable(DEKU_TREE_B2F_UNDER_WATER_HEART_1, SCENE_DEKU_TREE, 0x2E, //
        "Deku Tree B2F Underwater Heart 1", RECOVERY_HEART, //
        { Category::cDekuTree, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Collectable(DEKU_TREE_B2F_UNDER_WATER_HEART_2, SCENE_DEKU_TREE, 0x30, //
        "Deku Tree B2F Underwater Heart 2", RECOVERY_HEART, //
        { Category::cDekuTree, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Collectable(DEKU_TREE_B2F_UNDER_WATER_HEART_3, SCENE_DEKU_TREE, 0x31, //
        "Deku Tree B2F Underwater Heart 3", RECOVERY_HEART, //
        { Category::cDekuTree, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);

    Collectable(DMT_COW_GROTTO_HEART_1, SCENE_GROTTOS, 0x28, //
        "DMT Cow Grotto Heart 1", RECOVERY_HEART, //
        { Category::cDeathMountainTrail, Category::cRecoveryHeart, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_HEART_2, SCENE_GROTTOS, 0x29, //
        "DMT Cow Grotto Heart 2", RECOVERY_HEART, //
        { Category::cDeathMountainTrail, Category::cRecoveryHeart, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_HEART_3, SCENE_GROTTOS, 0x2A, //
        "DMT Cow Grotto Heart 3", RECOVERY_HEART, //
        { Category::cDeathMountainTrail, Category::cRecoveryHeart, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Collectable(DMT_COW_GROTTO_HEART_4, SCENE_GROTTOS, 0x2B, //
        "DMT Cow Grotto Heart 4", RECOVERY_HEART, //
        { Category::cDeathMountainTrail, Category::cRecoveryHeart, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);

    Collectable(DODONGOS_CAVERN_1F_MINIBOSS_ROOM_HEART_BEHIND_LAVAFALL, SCENE_DODONGOS_CAVERN, 0x18, //
        "Dodongo's Cavern 1F Miniboss Heart Behind Lavafall",
        RECOVERY_HEART, //
        { Category::cDodongosCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Collectable(DODONGOS_CAVERN_2F_BLADE_TRAPS_ROOM_HEART_BEHIND_BLOCK, SCENE_DODONGOS_CAVERN, 0x30, //
        "Dodongo's Cavern 2F Blade Traps Heart Behind Block",
        RECOVERY_HEART, //
        { Category::cDodongosCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Collectable(DODONGOS_CAVERN_2F_MINIBOSS_ROOM_HEART_1, SCENE_DODONGOS_CAVERN, 0x25, //
        "Dodongo's Cavern 2F Miniboss Room Heart 1", RECOVERY_HEART, //
        { Category::cDodongosCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Collectable(DODONGOS_CAVERN_2F_MINIBOSS_ROOM_HEART_2, SCENE_DODONGOS_CAVERN, 0x24, //
        "Dodongo's Cavern 2F Miniboss Room Heart 2", RECOVERY_HEART, //
        { Category::cDodongosCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);

    Collectable(FOREST_TEMPLE_WELL_HEART_1, SCENE_FOREST_TEMPLE, 0x2F, //
        "Forest Temple Well Heart 1", RECOVERY_HEART, //
        { Category::cForestTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Collectable(FOREST_TEMPLE_WELL_HEART_2, SCENE_FOREST_TEMPLE, 0x30, //
        "Forest Temple Well Heart 2", RECOVERY_HEART, //
        { Category::cForestTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Collectable(FOREST_TEMPLE_LEVEL_ISLAND_RIDGE_HEART_1, SCENE_FOREST_TEMPLE, 0x2D, //
        "Forest Temple Level Island Ridge Heart 1", RECOVERY_HEART, //
        { Category::cForestTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Collectable(FOREST_TEMPLE_LEVEL_ISLAND_RIDGE_HEART_2, SCENE_FOREST_TEMPLE, 0x2E, //
        "Forest Temple Level Island Ridge Heart 2", RECOVERY_HEART, //
        { Category::cForestTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);

    Collectable(FIRE_TEMPLE_PILLAR_ROOM_HEART_1, SCENE_FIRE_TEMPLE, 0x2F, //
        "Fire Temple Pillar Room Heart 1", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_PILLAR_ROOM_HEART_2, SCENE_FIRE_TEMPLE, 0x30, //
        "Fire Temple Pillar Room Heart 2", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_PILLAR_ROOM_HEART_3, SCENE_FIRE_TEMPLE, 0x34, //
        "Fire Temple Pillar Room Heart 3", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    Collectable(FIRE_TEMPLE_EAST_CENTRAL_ROOM_HEART_1, SCENE_FIRE_TEMPLE, 0x35, //
        "Fire Temple East Central Room Heart 1", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_EAST_CENTRAL_ROOM_HEART_2, SCENE_FIRE_TEMPLE, 0x36, //
        "Fire Temple East Central Room Heart 2", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_EAST_CENTRAL_ROOM_HEART_3, SCENE_FIRE_TEMPLE, 0x37, //
        "Fire Temple East Central Room Heart 3", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    Collectable(FIRE_TEMPLE_FIRE_WALL_CHASE_HEART_1, SCENE_FIRE_TEMPLE, 0x31, //
        "Fire Temple Fire Wall Chase Pillar Heart 1", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_FIRE_WALL_CHASE_HEART_2, SCENE_FIRE_TEMPLE, 0x32, //
        "Fire Temple Fire Wall Chase Pillar Heart 2", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Collectable(FIRE_TEMPLE_FIRE_WALL_CHASE_HEART_3, SCENE_FIRE_TEMPLE, 0x33, //
        "Fire Temple Fire Wall Chase Platform Heart", RECOVERY_HEART, //
        { Category::cFireTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    Collectable(WATER_TEMPLE_RIVER_HEART_1, SCENE_WATER_TEMPLE, 0x2A, //
        "Water Temple River Heart 1", RECOVERY_HEART, //
        { Category::cWaterTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Collectable(WATER_TEMPLE_RIVER_HEART_2, SCENE_WATER_TEMPLE, 0x2D, //
        "Water Temple River Heart 2", RECOVERY_HEART, //
        { Category::cWaterTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Collectable(WATER_TEMPLE_RIVER_HEART_3, SCENE_WATER_TEMPLE, 0x32, //
        "Water Temple River Heart 3", RECOVERY_HEART, //
        { Category::cWaterTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Collectable(WATER_TEMPLE_RIVER_HEART_4, SCENE_WATER_TEMPLE, 0x34, //
        "Water Temple River Heart 4", RECOVERY_HEART, //
        { Category::cWaterTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);

    Collectable(SPIRIT_TEMPLE_ADULT_CLIMB_HEART_1, SCENE_SPIRIT_TEMPLE, 0x01, //
        "Spirit Temple Adult Climb Heart 1", RECOVERY_HEART, //
        { Category::cSpiritTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Collectable(SPIRIT_TEMPLE_ADULT_CLIMB_HEART_2, SCENE_SPIRIT_TEMPLE, 0x02, //
        "Spirit Temple Adult Climb Heart 2", RECOVERY_HEART, //
        { Category::cSpiritTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);

    Collectable(SHADOW_TEMPLE_INVISIBLE_BLADES_SOT_BLOCK_HEART_1, SCENE_SHADOW_TEMPLE, 0x20, //
        "Shadow Temple Invisible Blades Heart 1", RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_INVISIBLE_BLADES_SOT_BLOCK_HEART_2, SCENE_SHADOW_TEMPLE, 0x21, //
        "Shadow Temple Invisible Blades Heart 2", RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_NEAR_SHIP_SCARECROW_HEART_1, SCENE_SHADOW_TEMPLE, 0x22, //
        "Shadow Temple Near Ship Heart 1", RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_NEAR_SHIP_SCARECROW_HEART_2, SCENE_SHADOW_TEMPLE, 0x23, //
        "Shadow Temple Near Ship Heart 2", RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    Collectable(SHADOW_TEMPLE_ACROSS_CAVERN_BROKEN_PILLAR_HEART, SCENE_SHADOW_TEMPLE, 0x3C, //
        "Shadow Temple Across Cavern Heart", RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_ACROSS_CAVERN_SCARECROW_HEART_1, SCENE_SHADOW_TEMPLE, 0x39, //
        "Shadow Temple Across Cavern Scarecrow Heart 1",
        RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Collectable(SHADOW_TEMPLE_ACROSS_CAVERN_SCARECROW_HEART_2, SCENE_SHADOW_TEMPLE, 0x3A, //
        "Shadow Temple Across Cavern Scarecrow Heart 2",
        RECOVERY_HEART, //
        { Category::cShadowTemple, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    Collectable(BOTTOM_OF_THE_WELL_CLOSED_SARCOPHAGUS_HEART, SCENE_BOTTOM_OF_THE_WELL, 0x1F, //
        "Bottom of the Well Closed Sarcophagus Heart", RECOVERY_HEART, //
        { Category::cBottomOfTheWell, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    Collectable(BOTTOM_OF_THE_WELL_OPEN_SARCOPHAGUS_HEART, SCENE_BOTTOM_OF_THE_WELL, 0x20, //
        "Bottom of the Well Open Sarcophagus Heart", RECOVERY_HEART, //
        { Category::cBottomOfTheWell, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);

    Collectable(ICE_CAVERN_MAP_CHEST_ROOM_HEART_1, SCENE_ICE_CAVERN, 0x22, //
        "Ice Cavern Map Chest Room Heart 1", RECOVERY_HEART, //
        { Category::cIceCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_MAP_CHEST_ROOM_HEART_2, SCENE_ICE_CAVERN, 0x23, //
        "Ice Cavern Map Chest Room Heart 2", RECOVERY_HEART, //
        { Category::cIceCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Collectable(ICE_CAVERN_MAP_CHEST_ROOM_HEART_3, SCENE_ICE_CAVERN, 0x24, //
        "Ice Cavern Map Chest Room Heart 3", RECOVERY_HEART, //
        { Category::cIceCavern, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);

    Collectable(GERUDO_TRAINING_GROUNDS_BEAMOS_ROOM_HEART_1, SCENE_GERUDO_TRAINING_GROUND, 0x22, //
        "Gerudo Training Grounds Beamos Room Heart 1", RECOVERY_HEART, //
        { Category::cGerudoTrainingGrounds, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);
    Collectable(GERUDO_TRAINING_GROUNDS_BEAMOS_ROOM_HEART_2, SCENE_GERUDO_TRAINING_GROUND, 0x23, //
        "Gerudo Training Grounds Beamos Room Heart 2", RECOVERY_HEART, //
        { Category::cGerudoTrainingGrounds, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_TRAINING_GROUND);

    Collectable(GANONS_CASTLE_FIRE_TRIAL_HEART, SCENE_INSIDE_GANONS_CASTLE, 0x24, //
        "Ganon's Castle Fire Trial Heart", RECOVERY_HEART, //
        { Category::cGanonsCastle, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Collectable(GANONS_CASTLE_SPIRIT_TRIAL_HEART, SCENE_INSIDE_GANONS_CASTLE, 0x26, //
        "Ganon's Castle Spirit Trial Heart", RECOVERY_HEART, //
        { Category::cGanonsCastle, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Collectable(GANONS_CASTLE_SHADOW_TRIAL_HEART_1, SCENE_INSIDE_GANONS_CASTLE, 0x21, //
        "Ganon's Castle Shadow Trial Heart 1", RECOVERY_HEART, //
        { Category::cGanonsCastle, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Collectable(GANONS_CASTLE_SHADOW_TRIAL_HEART_2, SCENE_INSIDE_GANONS_CASTLE, 0x22, //
        "Ganon's Castle Shadow Trial Heart 2", RECOVERY_HEART, //
        { Category::cGanonsCastle, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    Collectable(GANONS_CASTLE_SHADOW_TRIAL_HEART_3, SCENE_INSIDE_GANONS_CASTLE, 0x23, //
        "Ganon's Castle Shadow Trial Heart 3", RECOVERY_HEART, //
        { Category::cGanonsCastle, Category::cRecoveryHeart }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
}
