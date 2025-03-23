#ifndef _Z3DSCENE_H_
#define _Z3DSCENE_H_

typedef enum SceneId {
    /* 0x00 */ SCENE_DEKU_TREE,
    /* 0x01 */ SCENE_DODONGOS_CAVERN,
    /* 0x02 */ SCENE_JABU_JABU,
    /* 0x03 */ SCENE_FOREST_TEMPLE,
    /* 0x04 */ SCENE_FIRE_TEMPLE,
    /* 0x05 */ SCENE_WATER_TEMPLE,
    /* 0x06 */ SCENE_SPIRIT_TEMPLE,
    /* 0x07 */ SCENE_SHADOW_TEMPLE,
    /* 0x08 */ SCENE_BOTTOM_OF_THE_WELL,
    /* 0x09 */ SCENE_ICE_CAVERN,
    /* 0x0A */ SCENE_GANONS_TOWER,
    /* 0x0B */ SCENE_GERUDO_TRAINING_GROUND,
    /* 0x0C */ SCENE_THIEVES_HIDEOUT,
    /* 0x0D */ SCENE_INSIDE_GANONS_CASTLE,
    /* 0x0E */ SCENE_GANONS_TOWER_COLLAPSE_INTERIOR,
    /* 0x0F */ SCENE_INSIDE_GANONS_CASTLE_COLLAPSE,
    /* 0x10 */ SCENE_TREASURE_BOX_SHOP,
    /* 0x11 */ SCENE_DEKU_TREE_BOSS,
    /* 0x12 */ SCENE_DODONGOS_CAVERN_BOSS,
    /* 0x13 */ SCENE_JABU_JABU_BOSS,
    /* 0x14 */ SCENE_FOREST_TEMPLE_BOSS,
    /* 0x15 */ SCENE_FIRE_TEMPLE_BOSS,
    /* 0x16 */ SCENE_WATER_TEMPLE_BOSS,
    /* 0x17 */ SCENE_SPIRIT_TEMPLE_BOSS,
    /* 0x18 */ SCENE_SHADOW_TEMPLE_BOSS,
    /* 0x19 */ SCENE_GANONDORF_BOSS,
    /* 0x1A */ SCENE_GANONS_TOWER_COLLAPSE_EXTERIOR,
    /* 0x1B */ SCENE_MARKET_ENTRANCE_DAY,
    /* 0x1C */ SCENE_MARKET_ENTRANCE_NIGHT,
    /* 0x1D */ SCENE_MARKET_ENTRANCE_RUINS,
    /* 0x1E */ SCENE_BACK_ALLEY_DAY,
    /* 0x1F */ SCENE_BACK_ALLEY_NIGHT,
    /* 0x20 */ SCENE_MARKET_DAY,
    /* 0x21 */ SCENE_MARKET_NIGHT,
    /* 0x22 */ SCENE_MARKET_RUINS,
    /* 0x23 */ SCENE_TEMPLE_OF_TIME_EXTERIOR_DAY,
    /* 0x24 */ SCENE_TEMPLE_OF_TIME_EXTERIOR_NIGHT,
    /* 0x25 */ SCENE_TEMPLE_OF_TIME_EXTERIOR_RUINS,
    /* 0x26 */ SCENE_KNOW_IT_ALL_BROS_HOUSE,
    /* 0x27 */ SCENE_TWINS_HOUSE,
    /* 0x28 */ SCENE_MIDOS_HOUSE,
    /* 0x29 */ SCENE_SARIAS_HOUSE,
    /* 0x2A */ SCENE_KAKARIKO_CENTER_GUEST_HOUSE,
    /* 0x2B */ SCENE_BACK_ALLEY_HOUSE,
    /* 0x2C */ SCENE_BAZAAR,
    /* 0x2D */ SCENE_KOKIRI_SHOP,
    /* 0x2E */ SCENE_GORON_SHOP,
    /* 0x2F */ SCENE_ZORA_SHOP,
    /* 0x30 */ SCENE_POTION_SHOP_KAKARIKO,
    /* 0x31 */ SCENE_POTION_SHOP_MARKET,
    /* 0x32 */ SCENE_BOMBCHU_SHOP,
    /* 0x33 */ SCENE_HAPPY_MASK_SHOP,
    /* 0x34 */ SCENE_LINKS_HOUSE,
    /* 0x35 */ SCENE_DOG_LADY_HOUSE,
    /* 0x36 */ SCENE_STABLE,
    /* 0x37 */ SCENE_IMPAS_HOUSE,
    /* 0x38 */ SCENE_LAKESIDE_LABORATORY,
    /* 0x39 */ SCENE_CARPENTERS_TENT,
    /* 0x3A */ SCENE_GRAVEKEEPERS_HUT,
    /* 0x3B */ SCENE_GREAT_FAIRYS_FOUNTAIN_MAGIC,
    /* 0x3C */ SCENE_FAIRYS_FOUNTAIN,
    /* 0x3D */ SCENE_GREAT_FAIRYS_FOUNTAIN_SPELLS,
    /* 0x3E */ SCENE_GROTTOS,
    /* 0x3F */ SCENE_REDEAD_GRAVE,
    /* 0x40 */ SCENE_GRAVE_WITH_FAIRYS_FOUNTAIN,
    /* 0x41 */ SCENE_ROYAL_FAMILYS_TOMB,
    /* 0x42 */ SCENE_SHOOTING_GALLERY,
    /* 0x43 */ SCENE_TEMPLE_OF_TIME,
    /* 0x44 */ SCENE_CHAMBER_OF_THE_SAGES,
    /* 0x45 */ SCENE_CASTLE_COURTYARD_GUARDS_DAY,
    /* 0x46 */ SCENE_CASTLE_COURTYARD_GUARDS_NIGHT,
    /* 0x47 */ SCENE_CUTSCENE_MAP,
    /* 0x48 */ SCENE_WINDMILL_AND_DAMPES_GRAVE,
    /* 0x49 */ SCENE_FISHING_POND,
    /* 0x4A */ SCENE_CASTLE_COURTYARD_ZELDA,
    /* 0x4B */ SCENE_BOMBCHU_BOWLING_ALLEY,
    /* 0x4C */ SCENE_LON_LON_BUILDINGS,
    /* 0x4D */ SCENE_MARKET_GUARD_HOUSE,
    /* 0x4E */ SCENE_POTION_SHOP_GRANNY,
    /* 0x4F */ SCENE_GANON_BOSS,
    /* 0x50 */ SCENE_HOUSE_OF_SKULLTULA,
    /* 0x51 */ SCENE_HYRULE_FIELD,
    /* 0x52 */ SCENE_KAKARIKO_VILLAGE,
    /* 0x53 */ SCENE_GRAVEYARD,
    /* 0x54 */ SCENE_ZORAS_RIVER,
    /* 0x55 */ SCENE_KOKIRI_FOREST,
    /* 0x56 */ SCENE_SACRED_FOREST_MEADOW,
    /* 0x57 */ SCENE_LAKE_HYLIA,
    /* 0x58 */ SCENE_ZORAS_DOMAIN,
    /* 0x59 */ SCENE_ZORAS_FOUNTAIN,
    /* 0x5A */ SCENE_GERUDO_VALLEY,
    /* 0x5B */ SCENE_LOST_WOODS,
    /* 0x5C */ SCENE_DESERT_COLOSSUS,
    /* 0x5D */ SCENE_GERUDOS_FORTRESS,
    /* 0x5E */ SCENE_HAUNTED_WASTELAND,
    /* 0x5F */ SCENE_HYRULE_CASTLE,
    /* 0x60 */ SCENE_DEATH_MOUNTAIN_TRAIL,
    /* 0x61 */ SCENE_DEATH_MOUNTAIN_CRATER,
    /* 0x62 */ SCENE_GORON_CITY,
    /* 0x63 */ SCENE_LON_LON_RANCH,
    /* 0x64 */ SCENE_OUTSIDE_GANONS_CASTLE,
    /* 0x65 */ SCENE_65,
    /* 0x66 */ SCENE_66,
    /* 0x67 */ SCENE_67,
    /* 0x68 */ SCENE_68,
    /* 0x69 */ SCENE_69,
    /* 0x6A */ SCENE_6A,
    /* 0x6B */ SCENE_HYRULE_FIELD_TITLE_SCREEN,
    /* 0x6C */ SCENE_MAX,
} SceneId;

#endif //_Z3DSCENE_H_
