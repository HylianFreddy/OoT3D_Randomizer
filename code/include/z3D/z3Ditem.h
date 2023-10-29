#ifndef _Z3D_ITEM_H_
#define _Z3D_ITEM_H_

#include "z3Dvec.h"

typedef enum {
    /* 0x00 */ SLOT_STICK,
    /* 0x01 */ SLOT_NUT,
    /* 0x02 */ SLOT_BOMB,
    /* 0x03 */ SLOT_BOW,
    /* 0x04 */ SLOT_ARROW_FIRE,
    /* 0x05 */ SLOT_DINS_FIRE,
    /* 0x06 */ SLOT_SLINGSHOT,
    /* 0x07 */ SLOT_OCARINA,
    /* 0x08 */ SLOT_BOMBCHU,
    /* 0x09 */ SLOT_HOOKSHOT,
    /* 0x0A */ SLOT_ARROW_ICE,
    /* 0x0B */ SLOT_FARORES_WIND,
    /* 0x0C */ SLOT_BOOMERANG,
    /* 0x0D */ SLOT_LENS,
    /* 0x0E */ SLOT_BEAN,
    /* 0x0F */ SLOT_HAMMER,
    /* 0x10 */ SLOT_ARROW_LIGHT,
    /* 0x11 */ SLOT_NAYRUS_LOVE,
    /* 0x12 */ SLOT_BOTTLE_1,
    /* 0x13 */ SLOT_BOTTLE_2,
    /* 0x14 */ SLOT_BOTTLE_3,
    /* 0x15 */ SLOT_BOTTLE_4,
    /* 0x16 */ SLOT_TRADE_ADULT,
    /* 0x17 */ SLOT_TRADE_CHILD,
    /* 0x18 */ SLOT_IRON_BOOTS,
    /* 0x19 */ SLOT_HOVER_BOOTS,
    /* 0xFF */ SLOT_NONE = 0xFF
} InventorySlot;

typedef enum {
    /* 0x00 */ ITEM_STICK,
    /* 0x01 */ ITEM_NUT,
    /* 0x02 */ ITEM_BOMB,
    /* 0x03 */ ITEM_BOW,
    /* 0x04 */ ITEM_ARROW_FIRE,
    /* 0x05 */ ITEM_DINS_FIRE,
    /* 0x06 */ ITEM_SLINGSHOT,
    /* 0x07 */ ITEM_OCARINA_FAIRY,
    /* 0x08 */ ITEM_OCARINA_TIME,
    /* 0x09 */ ITEM_BOMBCHU,
    /* 0x0A */ ITEM_HOOKSHOT,
    /* 0x0B */ ITEM_LONGSHOT,
    /* 0x0C */ ITEM_ARROW_ICE,
    /* 0x0D */ ITEM_FARORES_WIND,
    /* 0x0E */ ITEM_BOOMERANG,
    /* 0x0F */ ITEM_LENS,
    /* 0x10 */ ITEM_BEAN,
    /* 0x11 */ ITEM_HAMMER,
    /* 0x12 */ ITEM_ARROW_LIGHT,
    /* 0x13 */ ITEM_NAYRUS_LOVE,
    /* 0x14 */ ITEM_BOTTLE,
    /* 0x15 */ ITEM_POTION_RED,
    /* 0x16 */ ITEM_POTION_GREEN,
    /* 0x17 */ ITEM_POTION_BLUE,
    /* 0x18 */ ITEM_FAIRY,
    /* 0x19 */ ITEM_FISH,
    /* 0x1A */ ITEM_MILK_BOTTLE,
    /* 0x1B */ ITEM_LETTER_RUTO,
    /* 0x1C */ ITEM_BLUE_FIRE,
    /* 0x1D */ ITEM_BUG,
    /* 0x1E */ ITEM_BIG_POE,
    /* 0x1F */ ITEM_MILK_HALF,
    /* 0x20 */ ITEM_POE,
    /* 0x21 */ ITEM_WEIRD_EGG,
    /* 0x22 */ ITEM_CHICKEN,
    /* 0x23 */ ITEM_LETTER_ZELDA,
    /* 0x24 */ ITEM_MASK_KEATON,
    /* 0x25 */ ITEM_MASK_SKULL,
    /* 0x26 */ ITEM_MASK_SPOOKY,
    /* 0x27 */ ITEM_MASK_BUNNY,
    /* 0x28 */ ITEM_MASK_GORON,
    /* 0x29 */ ITEM_MASK_ZORA,
    /* 0x2A */ ITEM_MASK_GERUDO,
    /* 0x2B */ ITEM_MASK_TRUTH,
    /* 0x2C */ ITEM_SOLD_OUT,
    /* 0x2D */ ITEM_POCKET_EGG,
    /* 0x2E */ ITEM_POCKET_CUCCO,
    /* 0x2F */ ITEM_COJIRO,
    /* 0x30 */ ITEM_ODD_MUSHROOM,
    /* 0x31 */ ITEM_ODD_POTION,
    /* 0x32 */ ITEM_SAW,
    /* 0x33 */ ITEM_SWORD_BROKEN,
    /* 0x34 */ ITEM_PRESCRIPTION,
    /* 0x35 */ ITEM_FROG,
    /* 0x36 */ ITEM_EYEDROPS,
    /* 0x37 */ ITEM_CLAIM_CHECK,
    /* 0x38 */ ITEM_BOW_ARROW_FIRE,
    /* 0x39 */ ITEM_BOW_ARROW_ICE,
    /* 0x3A */ ITEM_BOW_ARROW_LIGHT,
    /* 0x3B */ ITEM_SWORD_KOKIRI,
    /* 0x3C */ ITEM_SWORD_MASTER,
    /* 0x3D */ ITEM_SWORD_BGS,
    /* 0x3E */ ITEM_SHIELD_DEKU,
    /* 0x3F */ ITEM_SHIELD_HYLIAN,
    /* 0x40 */ ITEM_SHIELD_MIRROR,
    /* 0x41 */ ITEM_TUNIC_KOKIRI,
    /* 0x42 */ ITEM_TUNIC_GORON,
    /* 0x43 */ ITEM_TUNIC_ZORA,
    /* 0x44 */ ITEM_BOOTS_KOKIRI,
    /* 0x45 */ ITEM_BOOTS_IRON,
    /* 0x46 */ ITEM_BOOTS_HOVER,
    /* 0x47 */ ITEM_BULLET_BAG_30,
    /* 0x48 */ ITEM_BULLET_BAG_40,
    /* 0x49 */ ITEM_BULLET_BAG_50,
    /* 0x4A */ ITEM_QUIVER_30,
    /* 0x4B */ ITEM_QUIVER_40,
    /* 0x4C */ ITEM_QUIVER_50,
    /* 0x4D */ ITEM_BOMB_BAG_20,
    /* 0x4E */ ITEM_BOMB_BAG_30,
    /* 0x4F */ ITEM_BOMB_BAG_40,
    /* 0x50 */ ITEM_BRACELET,
    /* 0x51 */ ITEM_GAUNTLETS_SILVER,
    /* 0x52 */ ITEM_GAUNTLETS_GOLD,
    /* 0x53 */ ITEM_SCALE_SILVER,
    /* 0x54 */ ITEM_SCALE_GOLDEN,
    /* 0x55 */ ITEM_SWORD_KNIFE,
    /* 0x56 */ ITEM_WALLET_ADULT,
    /* 0x57 */ ITEM_WALLET_GIANT,
    /* 0x58 */ ITEM_SEEDS,
    /* 0x59 */ ITEM_FISHING_POLE,
    /* 0x5A */ ITEM_SONG_MINUET,
    /* 0x5B */ ITEM_SONG_BOLERO,
    /* 0x5C */ ITEM_SONG_SERENADE,
    /* 0x5D */ ITEM_SONG_REQUIEM,
    /* 0x5E */ ITEM_SONG_NOCTURNE,
    /* 0x5F */ ITEM_SONG_PRELUDE,
    /* 0x60 */ ITEM_SONG_LULLABY,
    /* 0x61 */ ITEM_SONG_EPONA,
    /* 0x62 */ ITEM_SONG_SARIA,
    /* 0x63 */ ITEM_SONG_SUN,
    /* 0x64 */ ITEM_SONG_TIME,
    /* 0x65 */ ITEM_SONG_STORMS,
    /* 0x66 */ ITEM_MEDALLION_FOREST,
    /* 0x67 */ ITEM_MEDALLION_FIRE,
    /* 0x68 */ ITEM_MEDALLION_WATER,
    /* 0x69 */ ITEM_MEDALLION_SPIRIT,
    /* 0x6A */ ITEM_MEDALLION_SHADOW,
    /* 0x6B */ ITEM_MEDALLION_LIGHT,
    /* 0x6C */ ITEM_KOKIRI_EMERALD,
    /* 0x6D */ ITEM_GORON_RUBY,
    /* 0x6E */ ITEM_ZORA_SAPPHIRE,
    /* 0x6F */ ITEM_STONE_OF_AGONY,
    /* 0x70 */ ITEM_GERUDO_CARD,
    /* 0x71 */ ITEM_SKULL_TOKEN,
    /* 0x72 */ ITEM_HEART_CONTAINER,
    /* 0x73 */ ITEM_HEART_PIECE,
    /* 0x74 */ ITEM_KEY_BOSS,
    /* 0x75 */ ITEM_COMPASS,
    /* 0x76 */ ITEM_DUNGEON_MAP,
    /* 0x77 */ ITEM_KEY_SMALL,
    /* 0x78 */ ITEM_MAGIC_SMALL,
    /* 0x79 */ ITEM_MAGIC_LARGE,
    /* 0x7A */ ITEM_HEART_PIECE_2,
    /* 0x7B */ ITEM_INVALID_1,
    /* 0x7C */ ITEM_INVALID_2,
    /* 0x7D */ ITEM_INVALID_3,
    /* 0x7E */ ITEM_INVALID_4,
    /* 0x7F */ ITEM_INVALID_5,
    /* 0x80 */ ITEM_INVALID_6,
    /* 0x81 */ ITEM_INVALID_7,
    /* 0x82 */ ITEM_MILK,
    /* 0x83 */ ITEM_HEART,
    /* 0x84 */ ITEM_RUPEE_GREEN,
    /* 0x85 */ ITEM_RUPEE_BLUE,
    /* 0x86 */ ITEM_RUPEE_RED,
    /* 0x87 */ ITEM_RUPEE_PURPLE,
    /* 0x88 */ ITEM_RUPEE_GOLD,
    /* 0x89 */ ITEM_INVALID_8,
    /* 0x8A */ ITEM_STICKS_5,
    /* 0x8B */ ITEM_STICKS_10,
    /* 0x8C */ ITEM_NUTS_5,
    /* 0x8D */ ITEM_NUTS_10,
    /* 0x8E */ ITEM_BOMBS_5,
    /* 0x8F */ ITEM_BOMBS_10,
    /* 0x90 */ ITEM_BOMBS_20,
    /* 0x91 */ ITEM_BOMBS_30,
    /* 0x92 */ ITEM_ARROWS_SMALL,
    /* 0x93 */ ITEM_ARROWS_MEDIUM,
    /* 0x94 */ ITEM_ARROWS_LARGE,
    /* 0x95 */ ITEM_SEEDS_30,
    /* 0x96 */ ITEM_BOMBCHUS_5,
    /* 0x97 */ ITEM_BOMBCHUS_20,
    /* 0x98 */ ITEM_STICK_UPGRADE_20,
    /* 0x99 */ ITEM_STICK_UPGRADE_30,
    /* 0x9A */ ITEM_NUT_UPGRADE_30,
    /* 0x9B */ ITEM_NUT_UPGRADE_40,
    /* 0xFF */ ITEM_NONE = 0xFF
} ItemID;

// Get Item result may vary depending on context (chest/shop/scrub/drop)
typedef enum {
    /* 0x00 */ GI_INVALID, // Link picks up chest and it sends him flying upwards
    /* 0x01 */ GI_BOMBS_5,
    /* 0x02 */ GI_NUTS_5,
    /* 0x03 */ GI_BOMBCHUS_10,
    /* 0x04 */ GI_BOW,
    /* 0x05 */ GI_SLINGSHOT,
    /* 0x06 */ GI_BOOMERANG,
    /* 0x07 */ GI_STICKS_1,
    /* 0x08 */ GI_HOOKSHOT,
    /* 0x09 */ GI_LONGSHOT,
    /* 0x0A */ GI_LENS,
    /* 0x0B */ GI_LETTER_ZELDA,
    /* 0x0C */ GI_OCARINA_OOT,
    /* 0x0D */ GI_HAMMER,
    /* 0x0E */ GI_COJIRO,
    /* 0x0F */ GI_BOTTLE,
    /* 0x10 */ GI_POTION_RED,
    /* 0x11 */ GI_POTION_GREEN,
    /* 0x12 */ GI_POTION_BLUE,
    /* 0x13 */ GI_FAIRY,
    /* 0x14 */ GI_MILK_BOTTLE,
    /* 0x15 */ GI_LETTER_RUTO,
    /* 0x16 */ GI_BEAN,
    /* 0x17 */ GI_MASK_SKULL,
    /* 0x18 */ GI_MASK_SPOOKY,
    /* 0x19 */ GI_CHICKEN, // uses bean message ID
    /* 0x1A */ GI_MASK_KEATON,
    /* 0x1B */ GI_MASK_BUNNY,
    /* 0x1C */ GI_MASK_TRUTH,
    /* 0x1D */ GI_POCKET_EGG,
    /* 0x1E */ GI_POCKET_CUCCO, // uses bean message ID
    /* 0x1F */ GI_ODD_MUSHROOM,
    /* 0x20 */ GI_ODD_POTION,
    /* 0x21 */ GI_SAW,
    /* 0x22 */ GI_SWORD_BROKEN,
    /* 0x23 */ GI_PERSCRIPTION,
    /* 0x24 */ GI_FROG,
    /* 0x25 */ GI_EYEDROPS,
    /* 0x26 */ GI_CLAIM_CHECK,
    /* 0x27 */ GI_SWORD_KOKIRI,
    /* 0x28 */ GI_SWORD_KNIFE,
    /* 0x29 */ GI_SHIELD_DEKU,   // or blue rupee if you have the shield
    /* 0x2A */ GI_SHIELD_HYLIAN, // or blue rupee if you have the shield
    /* 0x2B */ GI_SHIELD_MIRROR,
    /* 0x2C */ GI_TUNIC_GORON, // or blue rupee if you have the tunic
    /* 0x2D */ GI_TUNIC_ZORA,  // or blue rupee if you have the tunic
    /* 0x2E */ GI_BOOTS_IRON,
    /* 0x2F */ GI_BOOTS_HOVER,
    /* 0x30 */ GI_QUIVER_40,
    /* 0x31 */ GI_QUIVER_50,
    /* 0x32 */ GI_BOMB_BAG_20,
    /* 0x33 */ GI_BOMB_BAG_30,
    /* 0x34 */ GI_BOMB_BAG_40,
    /* 0x35 */ GI_GAUNTLETS_SILVER,
    /* 0x36 */ GI_GAUNTLETS_GOLD,
    /* 0x37 */ GI_SCALE_SILVER,
    /* 0x38 */ GI_SCALE_GOLD,
    /* 0x39 */ GI_STONE_OF_AGONY,
    /* 0x3A */ GI_GERUDO_CARD,
    /* 0x3B */ GI_OCARINA_FAIRY, // uses Ocarina of Time message ID
    /* 0x3C */ GI_SEEDS_5,
    /* 0x3D */ GI_HEART_CONTAINER,
    /* 0x3E */ GI_HEART_PIECE,
    /* 0x3F */ GI_KEY_BOSS,
    /* 0x40 */ GI_COMPASS,
    /* 0x41 */ GI_MAP,
    /* 0x42 */ GI_KEY_SMALL,
    /* 0x43 */ GI_MAGIC_SMALL, // or blue rupee if not from a drop
    /* 0x44 */ GI_MAGIC_LARGE, // or blue rupee if not from a drop
    /* 0x45 */ GI_WALLET_ADULT,
    /* 0x46 */ GI_WALLET_GIANT,
    /* 0x47 */ GI_WEIRD_EGG,
    /* 0x48 */ GI_HEART,
    /* 0x49 */ GI_ARROWS_SMALL,  // amount changes depending on context
    /* 0x4A */ GI_ARROWS_MEDIUM, // amount changes depending on context
    /* 0x4B */ GI_ARROWS_LARGE,  // amount changes depending on context
    /* 0x4C */ GI_RUPEE_GREEN,
    /* 0x4D */ GI_RUPEE_BLUE,
    /* 0x4E */ GI_RUPEE_RED,
    /* 0x4F */ GI_HEART_CONTAINER_2,
    /* 0x50 */ GI_MILK,
    /* 0x51 */ GI_MASK_GORON,
    /* 0x52 */ GI_MASK_ZORA,
    /* 0x53 */ GI_MASK_GERUDO,
    /* 0x54 */ GI_BRACELET,
    /* 0x55 */ GI_RUPEE_PURPLE,
    /* 0x56 */ GI_RUPEE_GOLD,
    /* 0x57 */ GI_SWORD_BGS,
    /* 0x58 */ GI_ARROW_FIRE,
    /* 0x59 */ GI_ARROW_ICE,
    /* 0x5A */ GI_ARROW_LIGHT,
    /* 0x5B */ GI_SKULL_TOKEN,
    /* 0x5C */ GI_DINS_FIRE,
    /* 0x5D */ GI_FARORES_WIND,
    /* 0x5E */ GI_NAYRUS_LOVE,
    /* 0x5F */ GI_BULLET_BAG_30,
    /* 0x60 */ GI_BULLET_BAG_40,
    /* 0x61 */ GI_STICKS_5,
    /* 0x62 */ GI_STICKS_10,
    /* 0x63 */ GI_NUTS_5_2,
    /* 0x64 */ GI_NUTS_10,
    /* 0x65 */ GI_BOMBS_1,
    /* 0x66 */ GI_BOMBS_10,
    /* 0x67 */ GI_BOMBS_20,
    /* 0x68 */ GI_BOMBS_30,
    /* 0x69 */ GI_SEEDS_30,
    /* 0x6A */ GI_BOMBCHUS_5,
    /* 0x6B */ GI_BOMBCHUS_20,
    /* 0x6C */ GI_FISH,
    /* 0x6D */ GI_BUGS,
    /* 0x6E */ GI_BLUE_FIRE,
    /* 0x6F */ GI_POE,
    /* 0x70 */ GI_BIG_POE,
    /* 0x71 */ GI_DOOR_KEY,          // specific to chest minigame
    /* 0x72 */ GI_RUPEE_GREEN_LOSE,  // specific to chest minigame
    /* 0x73 */ GI_RUPEE_BLUE_LOSE,   // specific to chest minigame
    /* 0x74 */ GI_RUPEE_RED_LOSE,    // specific to chest minigame
    /* 0x75 */ GI_RUPEE_PURPLE_LOSE, // specific to chest minigame
    /* 0x76 */ GI_HEART_PIECE_WIN,   // specific to chest minigame
    /* 0x77 */ GI_STICK_UPGRADE_20,
    /* 0x78 */ GI_STICK_UPGRADE_30,
    /* 0x79 */ GI_NUT_UPGRADE_30,
    /* 0x7A */ GI_NUT_UPGRADE_40,
    /* 0x7B */ GI_BULLET_BAG_50,
    /* 0x7C */ GI_ICE_TRAP, // freezes link when opened from a chest
    /* 0x7D */ GI_TEXT_0,   // no model appears over Link, shows text id 0 (pocket egg)

    // The following values are custom items added by the randomizer

    /* 0x7E */ GI_SWORD_MASTER,

    /* 0x7F */ GI_7F, // unused

    /* 0x80 */ GI_PROG_HOOKSHOT,
    /* 0x81 */ GI_PROG_STRENGTH,
    /* 0x82 */ GI_PROG_BOMB_BAG,
    /* 0x83 */ GI_PROG_BOW,
    /* 0x84 */ GI_PROG_SLINGSHOT,
    /* 0x85 */ GI_PROG_WALLET,
    /* 0x86 */ GI_PROG_SCALE,
    /* 0x87 */ GI_PROG_NUT_UPGRADE,
    /* 0x88 */ GI_PROG_STICK_UPGRADE,
    /* 0x89 */ GI_PROG_BOMBCHUS,
    /* 0x8A */ GI_PROG_MAGIC_METER,
    /* 0x8B */ GI_PROG_OCARINA,

    /* 0x8C */ GI_BOTTLE_RED_POTION,
    /* 0x8D */ GI_BOTTLE_GREEN_POTION,
    /* 0x8E */ GI_BOTTLE_BLUE_POTION,
    /* 0x8F */ GI_BOTTLE_FAIRY,
    /* 0x90 */ GI_BOTTLE_FISH,
    /* 0x91 */ GI_BOTTLE_BLUE_FIRE,
    /* 0x92 */ GI_BOTTLE_BUGS,
    /* 0x93 */ GI_BOTTLE_BIG_POE,
    /* 0x94 */ GI_BOTTLE_POE,

    /* 0x95 */ GI_FOREST_BOSS_KEY,
    /* 0x96 */ GI_FIRE_BOSS_KEY,
    /* 0x97 */ GI_WATER_BOSS_KEY,
    /* 0x98 */ GI_SPIRIT_BOSS_KEY,
    /* 0x99 */ GI_SHADOW_BOSS_KEY,
    /* 0x9A */ GI_GANON_BOSS_KEY,

    /* 0x9B */ GI_DEKU_COMPASS,
    /* 0x9C */ GI_DODONGO_COMPASS,
    /* 0x9D */ GI_JABU_COMPASS,
    /* 0x9E */ GI_FOREST_COMPASS,
    /* 0x9F */ GI_FIRE_COMPASS,
    /* 0xA0 */ GI_WATER_COMPASS,
    /* 0xA1 */ GI_SPIRIT_COMPASS,
    /* 0xA2 */ GI_SHADOW_COMPASS,
    /* 0xA3 */ GI_BOTW_COMPASS,
    /* 0xA4 */ GI_ICE_CAVERN_COMPASS,

    /* 0xA5 */ GI_DEKU_MAP,
    /* 0xA6 */ GI_DODONGO_MAP,
    /* 0xA7 */ GI_JABU_MAP,
    /* 0xA8 */ GI_FOREST_MAP,
    /* 0xA9 */ GI_FIRE_MAP,
    /* 0xAA */ GI_WATER_MAP,
    /* 0xAB */ GI_SPIRIT_MAP,
    /* 0xAC */ GI_SHADOW_MAP,
    /* 0xAD */ GI_BOTW_MAP,
    /* 0xAE */ GI_ICE_CAVERN_MAP,

    /* 0xAF */ GI_FOREST_SMALL_KEY,
    /* 0xB0 */ GI_FIRE_SMALL_KEY,
    /* 0xB1 */ GI_WATER_SMALL_KEY,
    /* 0xB2 */ GI_SPIRIT_SMALL_KEY,
    /* 0xB3 */ GI_SHADOW_SMALL_KEY,
    /* 0xB4 */ GI_BOTW_SMALL_KEY,
    /* 0xB5 */ GI_GTG_SMALL_KEY,
    /* 0xB6 */ GI_FORTRESS_SMALL_KEY,
    /* 0xB7 */ GI_GANON_SMALL_KEY,

    /* 0xB8 */ GI_DOUBLE_DEFENSE,
    /* 0xB9 */ GI_MAGIC_METER,
    /* 0xBA */ GI_DOUBLE_MAGIC,

    /* 0xBB */ GI_MINUET,
    /* 0xBC */ GI_BOLERO,
    /* 0xBD */ GI_SERENADE,
    /* 0xBE */ GI_REQUIEM,
    /* 0xBF */ GI_NOCTURNE,
    /* 0xC0 */ GI_PRELUDE,
    /* 0xC1 */ GI_ZELDA_LULLABY,
    /* 0xC2 */ GI_EPONA_SONG,
    /* 0xC3 */ GI_SARIA_SONG,
    /* 0xC4 */ GI_SUN_SONG,
    /* 0xC5 */ GI_SONG_OF_TIME,
    /* 0xC6 */ GI_SONG_OF_STORMS,

    /* 0xC7 */ GI_TYCOON_WALLET,
    /* 0xC8 */ GI_LETTER_RUTO_2,
    /* 0xC9 */ GI_MAGIC_BEAN_PACK,
    /* 0xCA */ GI_TRIFORCE_PIECE, // unused

    /* 0xCB */ GI_KOKIRI_EMERALD,
    /* 0xCC */ GI_GORON_RUBY,
    /* 0xCD */ GI_ZORA_SAPPHIRE,

    /* 0xCE */ GI_FOREST_MEDALLION,
    /* 0xCF */ GI_FIRE_MEDALLION,
    /* 0xD0 */ GI_WATER_MEDALLION,
    /* 0xD1 */ GI_SPIRIT_MEDALLION,
    /* 0xD2 */ GI_SHADOW_MEDALLION,
    /* 0xD3 */ GI_LIGHT_MEDALLION,

    /* 0xD4 */ GI_PROG_GORON_SWORD,

    /* 0xD5 */ GI_FOREST_KEY_RING,
    /* 0xD6 */ GI_FIRE_KEY_RING,
    /* 0xD7 */ GI_WATER_KEY_RING,
    /* 0xD8 */ GI_SPIRIT_KEY_RING,
    /* 0xD9 */ GI_SHADOW_KEY_RING,
    /* 0xDA */ GI_BOTW_KEY_RING,
    /* 0xDB */ GI_GTG_KEY_RING,
    /* 0xDC */ GI_FORTRESS_KEY_RING,
    /* 0xDD */ GI_GANON_KEY_RING,
    /* 0xDE */ GI_CHEST_GAME_KEY,

    /* 0xDF */  GI_SOUL_POE,
    /* 0xE0 */  GI_SOUL_OCTOROK,
    /* 0xE1 */  GI_SOUL_WALLMASTER,
    /* 0xE2 */  GI_SOUL_KEESE,
    /* 0xE3 */  GI_SOUL_TEKTITE,
    /* 0xE4 */  GI_SOUL_LEEVER,
    /* 0xE5 */  GI_SOUL_PEAHAT,
    /* 0xE6 */  GI_SOUL_LIZALFOS,
    /* 0xE7 */  GI_SOUL_SHABOM,
    /* 0xE8 */  GI_SOUL_BIRI_BARI,
    /* 0xE9 */  GI_SOUL_TAILPASARAN,
    /* 0xEA */  GI_SOUL_SKULLTULA,
    /* 0xEB */  GI_SOUL_TORCH_SLUG,
    /* 0xEC */  GI_SOUL_STINGER,
    /* 0xED */  GI_SOUL_MOBLIN,
    /* 0xEE */  GI_SOUL_ARMOS,
    /* 0xEF */  GI_SOUL_DEKU_BABA,
    /* 0xF0 */  GI_SOUL_BUBBLE,
    /* 0xF1 */  GI_SOUL_FLYING_POT,
    /* 0xF2 */  GI_SOUL_FLYING_TILE,
    /* 0xF3 */  GI_SOUL_BEAMOS,
    /* 0xF4 */  GI_SOUL_FLOORMASTER,
    /* 0xF5 */  GI_SOUL_REDEAD_GIBDO,
    /* 0xF6 */  GI_SOUL_SHELL_BLADE,
    /* 0xF7 */  GI_SOUL_LIKE_LIKE,
    /* 0xF8 */  GI_SOUL_TENTACLE,
    /* 0xF9 */  GI_SOUL_ANUBIS,
    /* 0xFA */  GI_SOUL_SPIKE,
    /* 0xFB */  GI_SOUL_SKULL_KID,
    /* 0xFC */  GI_SOUL_FREEZARD,
    /* 0xFD */  GI_SOUL_DEKU_SCRUB,
    /* 0xFE */  GI_SOUL_WOLFOS,
    /* 0xFF */  GI_SOUL_STALCHILD,
    /* 0x100 */ GI_SOUL_GUAY,
    /* 0x101 */ GI_SOUL_DOOR_MIMIC,
    /* 0x102 */ GI_SOUL_STALFOS,
    /* 0x103 */ GI_SOUL_DARK_LINK,
    /* 0x104 */ GI_SOUL_FLARE_DANCER,
    /* 0x105 */ GI_SOUL_DEAD_HAND,
    /* 0x106 */ GI_SOUL_GERUDO,
    /* 0x107 */ GI_SOUL_GOHMA,
    /* 0x108 */ GI_SOUL_DODONGO,
    /* 0x109 */ GI_SOUL_BARINADE,
    /* 0x10A */ GI_SOUL_PHANTOM_GANON,
    /* 0x10B */ GI_SOUL_VOLVAGIA,
    /* 0x10C */ GI_SOUL_MORPHA,
    /* 0x10D */ GI_SOUL_BONGO_BONGO,
    /* 0x10E */ GI_SOUL_TWINROVA,
    /* 0x10F */ GI_SOUL_GANON,

} GetItemID;

typedef enum {
    /* 0x00 */ EXCH_ITEM_NONE,
    /* 0x01 */ EXCH_ITEM_LETTER_ZELDA,
    /* 0x02 */ EXCH_ITEM_WEIRD_EGG,
    /* 0x03 */ EXCH_ITEM_CHICKEN,
    /* 0x04 */ EXCH_ITEM_BEAN,
    /* 0x05 */ EXCH_ITEM_POCKET_EGG,
    /* 0x06 */ EXCH_ITEM_POCKET_CUCCO,
    /* 0x07 */ EXCH_ITEM_COJIRO,
    /* 0x08 */ EXCH_ITEM_ODD_MUSHROOM,
    /* 0x09 */ EXCH_ITEM_ODD_POTION,
    /* 0x0A */ EXCH_ITEM_SAW,
    /* 0x0B */ EXCH_ITEM_SWORD_BROKEN,
    /* 0x0C */ EXCH_ITEM_PRESCRIPTION,
    /* 0x0D */ EXCH_ITEM_FROG,
    /* 0x0E */ EXCH_ITEM_EYEDROPS,
    /* 0x0F */ EXCH_ITEM_CLAIM_CHECK,
    /* 0x10 */ EXCH_ITEM_MASK_SKULL,
    /* 0x11 */ EXCH_ITEM_MASK_SPOOKY,
    /* 0x12 */ EXCH_ITEM_MASK_KEATON,
    /* 0x13 */ EXCH_ITEM_MASK_BUNNY,
    /* 0x14 */ EXCH_ITEM_MASK_TRUTH,
    /* 0x15 */ EXCH_ITEM_MASK_GORON,
    /* 0x16 */ EXCH_ITEM_MASK_ZORA,
    /* 0x17 */ EXCH_ITEM_MASK_GERUDO,
    /* 0x18 */ EXCH_ITEM_FISH,
    /* 0x19 */ EXCH_ITEM_BLUE_FIRE,
    /* 0x1A */ EXCH_ITEM_BUG,
    /* 0x1B */ EXCH_ITEM_POE,
    /* 0x1C */ EXCH_ITEM_BIG_POE,
    /* 0x1D */ EXCH_ITEM_LETTER_RUTO,
    /* 0x1E */ EXCH_ITEM_MAX
} ExchangeItemID;

#endif //_Z3D_ITEM_H_
