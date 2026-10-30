#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_GoldSkulltulas() {
    // Dungeons
    GSToken(DEKU_TREE_GS_BASEMENT_BACK_ROOM, 0x00, 0x01, //
        "Deku Tree GS Basement Back Room", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_GS_BASEMENT_GATE, 0x00, 0x02, //
        "Deku Tree GS Basement Gate", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_GS_BASEMENT_VINES, 0x00, 0x04, //
        "Deku Tree GS Basement Vines", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_GS_COMPASS_ROOM, 0x00, 0x08, //
        "Deku Tree GS Compass Room", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);

    GSToken(DEKU_TREE_MQ_GS_LOBBY, 0x00, 0x02, //
        "Deku Tree MQ GS Lobby", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_MQ_GS_COMPASS_ROOM, 0x00, 0x08, //
        "Deku Tree MQ GS Compass Room", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_MQ_GS_BASEMENT_GRAVES_ROOM, 0x00, 0x04, //
        "Deku Tree MQ GS Basement Graves Room", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    GSToken(DEKU_TREE_MQ_GS_BASEMENT_BACK_ROOM, 0x00, 0x01, //
        "Deku Tree MQ GS Basement Back Room", //
        { Category::cDekuTree, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);

    GSToken(DODONGOS_CAVERN_GS_VINES_ABOVE_STAIRS, 0x01, 0x01, //
        "Dodongos Cavern GS Vines Above Stairs", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_GS_SCARECROW, 0x01, 0x02, //
        "Dodongos Cavern GS Scarecrow", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_GS_ALCOVE_ABOVE_STAIRS, 0x01, 0x04, //
        "Dodongos Cavern GS Alcove Above Stairs", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_GS_BACK_ROOM, 0x01, 0x08, //
        "Dodongos Cavern GS Back Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_GS_SIDE_ROOM_NEAR_LOWER_LIZALFOS, 0x01, 0x10, //
        "Dodongos Cavern GS Side Room Near Lower Lizalfos", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);

    GSToken(DODONGOS_CAVERN_MQ_GS_SCRUB_ROOM, 0x01, 0x02, //
        "Dodongos Cavern MQ GS Scrub Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_MQ_GS_SONG_OF_TIME_BLOCK_ROOM, 0x01, 0x08, //
        "Dodongos Cavern MQ GS Song of Time Block Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_MQ_GS_LIZALFOS_ROOM, 0x01, 0x04, //
        "Dodongos Cavern MQ GS Lizalfos Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_MQ_GS_LARVAE_ROOM, 0x01, 0x10, //
        "Dodongos Cavern MQ GS Larvae Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    GSToken(DODONGOS_CAVERN_MQ_GS_BACK_AREA, 0x01, 0x01, //
        "Dodongos Cavern MQ GS Back Room", //
        { Category::cDodongosCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);

    GSToken(JABU_JABUS_BELLY_GS_LOBBY_BASEMENT_LOWER, 0x02, 0x01, //
        "Jabu Jabus Belly GS Lobby Basement Lower", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_GS_LOBBY_BASEMENT_UPPER, 0x02, 0x02, //
        "Jabu Jabus Belly GS Lobby Basement Upper", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_GS_NEAR_BOSS, 0x02, 0x04, //
        "Jabu Jabus Belly GS Near Boss", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_GS_WATER_SWITCH_ROOM, 0x02, 0x08, //
        "Jabu Jabus Belly GS Water Switch Room", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);

    GSToken(JABU_JABUS_BELLY_MQ_GS_TAILPASARAN_ROOM, 0x02, 0x04, //
        "Jabu Jabus Belly MQ GS Tail Parasan Room", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_MQ_GS_INVISIBLE_ENEMIES_ROOM, 0x02, 0x08, //
        "Jabu Jabus Belly MQ GS Invisible Enemies Room", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_MQ_GS_BOOMERANG_CHEST_ROOM, 0x02, 0x01, //
        "Jabu Jabus Belly MQ GS Boomerang Chest Room", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    GSToken(JABU_JABUS_BELLY_MQ_GS_NEAR_BOSS, 0x02, 0x02, //
        "Jabu Jabus Belly MQ GS Near Boss", //
        { Category::cJabuJabusBelly, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);

    GSToken(FOREST_TEMPLE_GS_RAISED_ISLAND_COURTYARD, 0x03, 0x01, //
        "Forest Temple GS Raised Island Courtyard", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_GS_FIRST_ROOM, 0x03, 0x02, //
        "Forest Temple GS First Room", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_GS_LEVEL_ISLAND_COURTYARD, 0x03, 0x04, //
        "Forest Temple GS Level Island Courtyard", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_GS_LOBBY, 0x03, 0x08, //
        "Forest Temple GS Lobby", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_GS_BASEMENT, 0x03, 0x10, //
        "Forest Temple GS Basement", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);

    GSToken(FOREST_TEMPLE_MQ_GS_FIRST_HALLWAY, 0x03, 0x02, //
        "Forest Temple MQ GS First Hallway", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_MQ_GS_BLOCK_PUSH_ROOM, 0x03, 0x10, //
        "Forest Temple MQ GS Block Push Room", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_MQ_GS_RAISED_ISLAND_COURTYARD, 0x03, 0x01, //
        "Forest Temple MQ GS Raised Island Courtyard", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_MQ_GS_LEVEL_ISLAND_COURTYARD, 0x03, 0x04, //
        "Forest Temple MQ GS Level Island Courtyard", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    GSToken(FOREST_TEMPLE_MQ_GS_WELL, 0x03, 0x08, //
        "Forest Temple MQ GS Well", //
        { Category::cForestTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);

    GSToken(FIRE_TEMPLE_GS_SONG_OF_TIME_ROOM, 0x04, 0x01, //
        "Fire Temple GS Song of Time Room", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_GS_BOSS_KEY_LOOP, 0x04, 0x02, //
        "Fire Temple GS Boss Key Loop", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_GS_BOULDER_MAZE, 0x04, 0x04, //
        "Fire Temple GS Boulder Maze", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_GS_SCARECROW_TOP, 0x04, 0x08, //
        "Fire Temple GS Scarecrow Top", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_GS_SCARECROW_CLIMB, 0x04, 0x10, //
        "Fire Temple GS Scarecrow Climb", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    GSToken(FIRE_TEMPLE_MQ_GS_ABOVE_FIRE_WALL_MAZE, 0x04, 0x02, //
        "Fire Temple MQ GS Above Fire Wall Maze", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_MQ_GS_FIRE_WALL_MAZE_CENTER, 0x04, 0x08, //
        "Fire Temple MQ GS Fire Wall Maze Center", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_MQ_GS_BIG_LAVA_ROOM_OPEN_DOOR, 0x04, 0x01, //
        "Fire Temple MQ GS Big Lava Room Open Door", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_MQ_GS_FIRE_WALL_MAZE_SIDE_ROOM, 0x04, 0x10, //
        "Fire Temple MQ GS Fire Wall Maze Side Room", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    GSToken(FIRE_TEMPLE_MQ_GS_SKULL_ON_FIRE, 0x04, 0x04, //
        "Fire Temple MQ GS Skull on Fire", //
        { Category::cFireTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);

    GSToken(WATER_TEMPLE_GS_BEHIND_GATE, 0x05, 0x01, //
        "Water Temple GS Behind Gate", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_GS_FALLING_PLATFORM_ROOM, 0x05, 0x02, //
        "Water Temple GS Falling Platform Room", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_GS_CENTRAL_PILLAR, 0x05, 0x04, //
        "Water Temple GS Central Pillar", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_GS_NEAR_BOSS_KEY_CHEST, 0x05, 0x08, //
        "Water Temple GS Near Boss Key Chest", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_GS_RIVER, 0x05, 0x10, //
        "Water Temple GS River", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);

    GSToken(WATER_TEMPLE_MQ_GS_BEFORE_UPPER_WATER_SWITCH, 0x05, 0x04, //
        "Water Temple MQ GS Before Upper Water Switch", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_MQ_GS_FREESTANDING_KEY_AREA, 0x05, 0x08, //
        "Water Temple MQ GS Freestanding Key Area", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_MQ_GS_LIZALFOS_HALLWAY, 0x05, 0x01, //
        "Water Temple MQ GS Lizalfos Hallway", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_MQ_GS_RIVER, 0x05, 0x02, //
        "Water Temple MQ GS River", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    GSToken(WATER_TEMPLE_MQ_GS_TRIPLE_WALL_TORCH, 0x05, 0x10, //
        "Water Temple MQ GS Triple Wall Torch", //
        { Category::cWaterTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);

    GSToken(SPIRIT_TEMPLE_GS_HALL_AFTER_SUN_BLOCK_ROOM, 0x06, 0x01, //
        "Spirit Temple GS Hall After Sun Block Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_GS_BOULDER_ROOM, 0x06, 0x02, //
        "Spirit Temple GS Boulder Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_GS_LOBBY, 0x06, 0x04, //
        "Spirit Temple GS Lobby", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_GS_SUN_ON_FLOOR_ROOM, 0x06, 0x08, //
        "Spirit Temple GS Sun on Floor Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_GS_METAL_FENCE, 0x06, 0x10, //
        "Spirit Temple GS Metal Fence", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);

    GSToken(SPIRIT_TEMPLE_MQ_GS_SYMPHONY_ROOM, 0x06, 0x08, //
        "Spirit Temple MQ GS Symphony Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_MQ_GS_LEEVER_ROOM, 0x06, 0x02, //
        "Spirit Temple MQ GS Leever Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_MQ_GS_NINE_THRONES_ROOM_WEST, 0x06, 0x04, //
        "Spirit Temple MQ GS Nine Thrones Room West", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_MQ_GS_NINE_THRONES_ROOM_NORTH, 0x06, 0x10, //
        "Spirit Temple MQ GS Nine Thrones Room North", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    GSToken(SPIRIT_TEMPLE_MQ_GS_SUN_BLOCK_ROOM, 0x06, 0x01, //
        "Spirit Temple MQ GS Sun Block Room", //
        { Category::cSpiritTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);

    GSToken(SHADOW_TEMPLE_GS_SINGLE_GIANT_POT, 0x07, 0x01, //
        "Shadow Temple GS Single Giant Pot", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_GS_FALLING_SPIKES_ROOM, 0x07, 0x02, //
        "Shadow Temple GS Falling Spikes Room", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_GS_TRIPLE_GIANT_POT, 0x07, 0x04, //
        "Shadow Temple GS Triple Giant Pot", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_GS_LIKE_LIKE_ROOM, 0x07, 0x08, //
        "Shadow Temple GS Like Like Room", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_GS_NEAR_SHIP, 0x07, 0x10, //
        "Shadow Temple GS Near Ship", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    GSToken(SHADOW_TEMPLE_MQ_GS_FALLING_SPIKES_ROOM, 0x07, 0x02, //
        "Shadow Temple MQ GS Falling Spikes Room", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_MQ_GS_WIND_HINT_ROOM, 0x07, 0x01, //
        "Shadow Temple MQ GS Wind Hint Room", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_MQ_GS_AFTER_WIND, 0x07, 0x08, //
        "Shadow Temple MQ GS After Wind", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_MQ_GS_AFTER_SHIP, 0x07, 0x10, //
        "Shadow Temple MQ GS After Ship", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    GSToken(SHADOW_TEMPLE_MQ_GS_NEAR_BOSS, 0x07, 0x04, //
        "Shadow Temple MQ GS Near Boss", //
        { Category::cShadowTemple, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    GSToken(BOTTOM_OF_THE_WELL_GS_LIKE_LIKE_CAGE, 0x08, 0x01, //
        "Bottom of the Well GS Like Like Cage", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    GSToken(BOTTOM_OF_THE_WELL_GS_EAST_INNER_ROOM, 0x08, 0x02, //
        "Bottom of the Well GS East Inner Room", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    GSToken(BOTTOM_OF_THE_WELL_GS_WEST_INNER_ROOM, 0x08, 0x04, //
        "Bottom of the Well GS West Inner Room", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);

    GSToken(BOTTOM_OF_THE_WELL_MQ_GS_BASEMENT, 0x08, 0x01, //
        "Bottom of the Well MQ GS Basement", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    GSToken(BOTTOM_OF_THE_WELL_MQ_GS_COFFIN_ROOM, 0x08, 0x04, //
        "Bottom of the Well MQ GS Coffin Room", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);
    GSToken(BOTTOM_OF_THE_WELL_MQ_GS_WEST_INNER_ROOM, 0x08, 0x02, //
        "Bottom of the Well MQ GS West Inner Room", //
        { Category::cBottomOfTheWell, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_BOTTOM_OF_THE_WELL);

    GSToken(ICE_CAVERN_GS_PUSH_BLOCK_ROOM, 0x09, 0x01, //
        "Ice Cavern GS Push Block Room", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    GSToken(ICE_CAVERN_GS_SPINNING_SCYTHE_ROOM, 0x09, 0x02, //
        "Ice Cavern GS Spinning Scythe Room", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    GSToken(ICE_CAVERN_GS_HEART_PIECE_ROOM, 0x09, 0x04, //
        "Ice Cavern GS Heart Piece Room", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);

    GSToken(ICE_CAVERN_MQ_GS_SCARECROW, 0x09, 0x01, //
        "Ice Cavern MQ GS Scarecrow", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    GSToken(ICE_CAVERN_MQ_GS_ICE_BLOCK, 0x09, 0x04, //
        "Ice Cavern MQ GS Ice Block", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    GSToken(ICE_CAVERN_MQ_GS_RED_ICE, 0x09, 0x02, //
        "Ice Cavern MQ GS Red Ice", //
        { Category::cIceCavern, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);

    // Overworld
    GSToken(KF_GS_BEAN_PATCH, 0x0C, 0x01, //
        "KF GS Bean Patch", //
        { Category::cKokiriForest, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    GSToken(KF_GS_KNOW_IT_ALL_HOUSE, 0x0C, 0x02, //
        "KF GS Know It All House", //
        { Category::cKokiriForest, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    GSToken(KF_GS_HOUSE_OF_TWINS, 0x0C, 0x04, //
        "KF GS House of Twins", //
        { Category::cKokiriForest, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    GSToken(LW_GS_BEAN_PATCH_NEAR_BRIDGE, 0x0D, 0x01, //
        "LW GS Bean Patch Near Bridge", //
        { Category::cLostWoods, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    GSToken(LW_GS_BEAN_PATCH_NEAR_THEATER, 0x0D, 0x02, //
        "LW GS Bean Patch Near Theater", //
        { Category::cLostWoods, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    GSToken(LW_GS_ABOVE_THEATER, 0x0D, 0x04, //
        "LW GS Above Theater", //
        { Category::cLostWoods, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    GSToken(SFM_GS, 0x0D, 0x08, //
        "SFM GS", //
        { Category::cSacredForestMeadow, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);

    GSToken(HF_GS_COW_GROTTO, 0x0A, 0x01, //
        "HF GS Cow Grotto", //
        { Category::cHyruleField, Category::cSkulltula, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    GSToken(HF_GS_NEAR_KAK_GROTTO, 0x0A, 0x02, //
        "HF GS Near Kak Grotto", //
        { Category::cHyruleField, Category::cSkulltula, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);

    GSToken(LH_GS_BEAN_PATCH, 0x12, 0x01, //
        "LH GS Bean Patch", //
        { Category::cLakeHylia, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GSToken(LH_GS_SMALL_ISLAND, 0x12, 0x02, //
        "LH GS Small Island", //
        { Category::cLakeHylia, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GSToken(LH_GS_LAB_WALL, 0x12, 0x04, //
        "LH GS Lab Wall", //
        { Category::cLakeHylia, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GSToken(LH_GS_LAB_CRATE, 0x12, 0x08, //
        "LH GS Lab Crate", //
        { Category::cLakeHylia, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);
    GSToken(LH_GS_TREE, 0x12, 0x10, //
        "LH GS Tree", //
        { Category::cLakeHylia, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LAKE_HYLIA);

    GSToken(GV_GS_BEAN_PATCH, 0x13, 0x01, //
        "GV GS Bean Patch", //
        { Category::cGerudoValley, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GSToken(GV_GS_SMALL_BRIDGE, 0x13, 0x02, //
        "GV GS Small Bridge", //
        { Category::cGerudoValley, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GSToken(GV_GS_PILLAR, 0x13, 0x04, //
        "GV GS Pillar", //
        { Category::cGerudoValley, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GSToken(GV_GS_BEHIND_TENT, 0x13, 0x08, //
        "GV GS Behind Tent", //
        { Category::cGerudoValley, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);

    GSToken(GF_GS_ARCHERY_RANGE, 0x14, 0x01, //
        "GF GS Archery Range", //
        { Category::cGerudoFortress, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    GSToken(GF_GS_TOP_FLOOR, 0x14, 0x02, //
        "GF GS Top Floor", //
        { Category::cGerudoFortress, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);

    GSToken(WASTELAND_GS, 0x15, 0x02, //
        "Wasteland GS", //
        { Category::cHauntedWasteland, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    GSToken(COLOSSUS_GS_BEAN_PATCH, 0x15, 0x01, //
        "Colossus GS Bean Patch", //
        { Category::cDesertColossus, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    GSToken(COLOSSUS_GS_HILL, 0x15, 0x04, //
        "Colossus GS Hill", //
        { Category::cDesertColossus, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    GSToken(COLOSSUS_GS_TREE, 0x15, 0x08, //
        "Colossus GS Tree", //
        { Category::cDesertColossus, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);

    GSToken(OGC_GS, 0x0E, 0x01, //
        "OGC GS", //
        { Category::cOutsideGanonsCastle, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);
    GSToken(HC_GS_STORMS_GROTTO, 0x0E, 0x02, //
        "HC GS Storms Grotto", //
        { Category::cHyruleCastle, Category::cSkulltula, Category::cGrotto }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    GSToken(HC_GS_TREE, 0x0E, 0x04, //
        "HC GS Tree", //
        { Category::cHyruleCastle, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    GSToken(MARKET_GS_GUARD_HOUSE, 0x0E, 0x08, //
        "Market GS Guard House", //
        { Category::cInnerMarket, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_MARKET);

    GSToken(KAK_GS_HOUSE_UNDER_CONSTRUCTION, 0x10, 0x08, //
        "Kak GS House Under Construction", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    GSToken(KAK_GS_SKULLTULA_HOUSE, 0x10, 0x10, //
        "Kak GS Skulltula House", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    GSToken(KAK_GS_GUARDS_HOUSE, 0x10, 0x02, //
        "Kak GS Guards House", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    GSToken(KAK_GS_TREE, 0x10, 0x20, //
        "Kak GS Tree", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    GSToken(KAK_GS_WATCHTOWER, 0x10, 0x04, //
        "Kak GS Watchtower", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    GSToken(KAK_GS_ABOVE_IMPAS_HOUSE, 0x10, 0x40, //
        "Kak GS Above Impas House", //
        { Category::cKakarikoVillage, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    GSToken(GRAVEYARD_GS_WALL, 0x10, 0x80, //
        "Graveyard GS Wall", //
        { Category::cGraveyard, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    GSToken(GRAVEYARD_GS_BEAN_PATCH, 0x10, 0x01, //
        "Graveyard GS Bean Patch", //
        { Category::cGraveyard, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);

    GSToken(DMC_GS_BEAN_PATCH, 0x0F, 0x01, //
        "DMC GS Bean Patch", //
        { Category::cDeathMountainCrater, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    GSToken(DMC_GS_CRATE, 0x0F, 0x80, //
        "DMC GS Crate", //
        { Category::cDeathMountainCrater, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);

    GSToken(DMT_GS_BEAN_PATCH, 0x0F, 0x02, //
        "DMT GS Bean Patch", //
        { Category::cDeathMountainTrail, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    GSToken(DMT_GS_NEAR_KAK, 0x0F, 0x04, //
        "DMT GS Near Kak", //
        { Category::cDeathMountainTrail, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    GSToken(DMT_GS_ABOVE_DODONGOS_CAVERN, 0x0F, 0x08, //
        "DMT GS Above Dodongos Cavern", //
        { Category::cDeathMountainTrail, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    GSToken(DMT_GS_FALLING_ROCKS_PATH, 0x0F, 0x10, //
        "DMT GS Falling Rocks Path", //
        { Category::cDeathMountainTrail, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);

    GSToken(GC_GS_CENTER_PLATFORM, 0x0F, 0x20, //
        "GC GS Center Platform", //
        { Category::cGoronCity, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    GSToken(GC_GS_BOULDER_MAZE, 0x0F, 0x40, //
        "GC GS Boulder Maze", //
        { Category::cGoronCity, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_GORON_CITY);

    GSToken(ZR_GS_LADDER, 0x11, 0x01, //
        "ZR GS Ladder", //
        { Category::cZorasRiver, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    GSToken(ZR_GS_TREE, 0x11, 0x02, //
        "ZR GS Tree", //
        { Category::cZorasRiver, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    GSToken(ZR_GS_ABOVE_BRIDGE, 0x11, 0x08, //
        "ZR GS Above Bridge", //
        { Category::cZorasRiver, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);
    GSToken(ZR_GS_NEAR_RAISED_GROTTOS, 0x11, 0x10, //
        "ZR GS Near Raised Grottos", //
        { Category::cZorasRiver, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_RIVER);

    GSToken(ZD_GS_FROZEN_WATERFALL, 0x11, 0x40, //
        "ZD GS Frozen Waterfall", //
        { Category::cZorasDomain, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    GSToken(ZF_GS_ABOVE_THE_LOG, 0x11, 0x04, //
        "ZF GS Above The Log", //
        { Category::cZorasFountain, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    GSToken(ZF_GS_HIDDEN_CAVE, 0x11, 0x20, //
        "ZF GS Hidden Cave", //
        { Category::cZorasFountain, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    GSToken(ZF_GS_TREE, 0x11, 0x80, //
        "ZF GS Tree", //
        { Category::cZorasFountain, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);

    GSToken(LLR_GS_BACK_WALL, 0x0B, 0x01, //
        "LLR GS Back Wall", //
        { Category::cLonLonRanch, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GSToken(LLR_GS_RAIN_SHED, 0x0B, 0x02, //
        "LLR GS Rain Shed", //
        { Category::cLonLonRanch, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GSToken(LLR_GS_HOUSE_WINDOW, 0x0B, 0x04, //
        "LLR GS House Window", //
        { Category::cLonLonRanch, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    GSToken(LLR_GS_TREE, 0x0B, 0x08, //
        "LLR GS Tree", //
        { Category::cLonLonRanch, Category::cSkulltula }, //
        SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
}
