#include "item_location.hpp"

#include "s_dungeon.h"
#include "s_scene_id.h"

void ItemLocation::InitTable_Misc() {
    Base(NONE, 0xFF, 0xFF, //
        "Invalid Location", NONE, {}, //
        SpoilerCollectionCheck::None());
    Base(TRIFORCE_HUNT_GOAL, 0xFF, 0xFF, //
        "Triforce Hunt Goal", TRIFORCE, {}, //
        SpoilerCollectionCheck::None());

    /*-------------------------------
              --- BOSSES ---
      -------------------------------*/

    Reward(LINKS_POCKET, 0xFF, //
        "Link's Pocket", LIGHT_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::AlwaysCollected(), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Reward(QUEEN_GOHMA, DUNGEON_DEKU_TREE, //
        "Queen Gohma", KOKIRI_EMERALD, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x09), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Reward(KING_DODONGO, DUNGEON_DODONGOS_CAVERN, //
        "King Dodongo", GORON_RUBY, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x25), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Reward(BARINADE, DUNGEON_JABUJABUS_BELLY, //
        "Barinade", ZORA_SAPPHIRE, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x37), SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Reward(PHANTOM_GANON, DUNGEON_FOREST_TEMPLE, //
        "Phantom Ganon", FOREST_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x48), SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Reward(VOLVAGIA, DUNGEON_FIRE_TEMPLE, //
        "Volvagia", FIRE_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x49), SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Reward(MORPHA, DUNGEON_WATER_TEMPLE, //
        "Morpha", WATER_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x4A), SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Reward(TWINROVA, DUNGEON_SPIRIT_TEMPLE, //
        "Twinrova", SPIRIT_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x47), SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Reward(BONGO_BONGO, DUNGEON_SHADOW_TEMPLE, //
        "Bongo Bongo", SHADOW_MEDALLION, //
        { Category::cDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x46), SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);
    Reward(GANON, 0xF0, //
        "Ganon", TRIFORCE, //
        {}, //
        SpoilerCollectionCheck::None(), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);

    /*-------------------------------
          ---HEART CONTAINERS ---
      -------------------------------*/

    Base(DEKU_TREE_QUEEN_GOHMA_HEART, SCENE_DEKU_TREE_BOSS, 0x4F, //
        "Deku Tree Queen Gohma Heart Container", HEART_CONTAINER, //
        { Category::cDekuTree, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x11, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DEKU_TREE);
    Base(DODONGOS_CAVERN_KING_DODONGO_HEART, SCENE_DODONGOS_CAVERN_BOSS, 0x4F, //
        "Dodongos Cavern King Dodongo Heart Container", HEART_CONTAINER, //
        { Category::cDodongosCavern, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x12, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_DODONGOS_CAVERN);
    Base(JABU_JABUS_BELLY_BARINADE_HEART, SCENE_JABU_JABU_BOSS, 0x4F, //
        "Jabu Jabus Belly Barinade Heart Container", HEART_CONTAINER, //
        { Category::cJabuJabusBelly, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x13, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
    Base(FOREST_TEMPLE_PHANTOM_GANON_HEART, SCENE_FOREST_TEMPLE_BOSS, 0x4F, //
        "Forest Temple Phantom Ganon Heart Container", HEART_CONTAINER, //
        { Category::cForestTemple, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x14, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_FOREST_TEMPLE);
    Base(FIRE_TEMPLE_VOLVAGIA_HEART, SCENE_FIRE_TEMPLE_BOSS, 0x4F, //
        "Fire Temple Volvagia Heart Container", HEART_CONTAINER, //
        { Category::cFireTemple, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x15, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_FIRE_TEMPLE);
    Base(WATER_TEMPLE_MORPHA_HEART, SCENE_WATER_TEMPLE_BOSS, 0x4F, //
        "Water Temple Morpha Heart Container", HEART_CONTAINER, //
        { Category::cWaterTemple, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x16, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_WATER_TEMPLE);
    Base(SPIRIT_TEMPLE_TWINROVA_HEART, SCENE_SPIRIT_TEMPLE_BOSS, 0x4F, //
        "Spirit Temple Twinrova Heart Container", HEART_CONTAINER, //
        { Category::cSpiritTemple, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x17, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_SPIRIT_TEMPLE);
    Base(SHADOW_TEMPLE_BONGO_BONGO_HEART, SCENE_SHADOW_TEMPLE_BOSS, 0x4F, //
        "Shadow Temple Bongo Bongo Heart Container", HEART_CONTAINER, //
        { Category::cShadowTemple, Category::cBossHeart, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::Collectable(0x18, 0x1F), SpoilerCollectionCheckGroup::GROUP_DUNGEON_SHADOW_TEMPLE);

    /*-------------------------------
            --- CUTSCENES ---
      -------------------------------*/

    Delayed(TOT_MASTER_SWORD, DLYOVR_MASTER_SWORD, //
        "ToT Master Sword", MASTER_SWORD, //
        { Category::cTempleOfTime, Category::cMarket }, //
        SpoilerCollectionCheck::MasterSword(), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Delayed(TOT_LIGHT_ARROWS_CUTSCENE, DLYOVR_LACS, //
        "ToT Light Arrow Cutscene", LIGHT_ARROWS, //
        { Category::cTempleOfTime, Category::cMarket }, //
        SpoilerCollectionCheck::EventChkInf(0xC4), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Delayed(LW_GIFT_FROM_SARIA, DLYOVR_SARIA_GIFT, //
        "LW Gift From Saria", PROGRESSIVE_OCARINA, //
        { Category::cLostWoods, Category::cForest }, //
        SpoilerCollectionCheck::EventChkInf(0xC1), SpoilerCollectionCheckGroup::GROUP_LOST_WOODS);
    Delayed(HC_ZELDAS_LETTER, DLYOVR_ZELDA_LETTER, //
        "HC Zeldas Letter", ZELDAS_LETTER, //
        { Category::cHyruleCastle, Category::cMarket }, //
        SpoilerCollectionCheck::EventChkInf(0x40), SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    Delayed(ZF_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_ZF, //
        "ZF Great Fairy Reward", FARORES_WIND, //
        { Category::cZorasFountain, Category::cFairies }, //
        SpoilerCollectionCheck::ItemGetInf(16), SpoilerCollectionCheckGroup::GROUP_ZORAS_FOUNTAIN);
    Delayed(HC_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_HC, //
        "HC Great Fairy Reward", DINS_FIRE, //
        { Category::cHyruleCastle, Category::cMarket, Category::cFairies }, //
        SpoilerCollectionCheck::ItemGetInf(17), SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    Delayed(COLOSSUS_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_DC, //
        "Colossus Great Fairy Reward", NAYRUS_LOVE, //
        { Category::cDesertColossus, Category::cFairies }, //
        SpoilerCollectionCheck::ItemGetInf(18), SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    Delayed(DMT_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_DMT, //
        "DMT Great Fairy Reward", PROGRESSIVE_MAGIC_METER, //
        { Category::cDeathMountainTrail, Category::cDeathMountain, Category::cFairies }, //
        SpoilerCollectionCheck::Chest(0x3B, 0x00), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Delayed(DMC_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_DMC, //
        "DMC Great Fairy Reward", PROGRESSIVE_MAGIC_METER, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cFairies }, //
        SpoilerCollectionCheck::Chest(0x3B, 0x01), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Delayed(OGC_GREAT_FAIRY_REWARD, DLYOVR_FAIRY_OGC, //
        "OGC Great Fairy Reward", DOUBLE_DEFENSE, //
        { Category::cOutsideGanonsCastle, Category::cFairies }, //
        SpoilerCollectionCheck::Chest(0x3B, 0x02), SpoilerCollectionCheckGroup::GROUP_DUNGEON_GANONS_CASTLE);

    Delayed(SHEIK_IN_FOREST, DLYOVR_SONG_MINUET, //
        "Sheik in Forest", MINUET_OF_FOREST, //
        { Category::cSacredForestMeadow, Category::cForest, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x50), SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);
    Delayed(SHEIK_IN_CRATER, DLYOVR_SONG_BOLERO, //
        "Sheik in Crater", BOLERO_OF_FIRE, //
        { Category::cDeathMountainCrater, Category::cDeathMountain, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x51), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_CRATER);
    Delayed(SHEIK_IN_ICE_CAVERN, DLYOVR_SONG_SERENADE, //
        "Sheik in Ice Cavern", SERENADE_OF_WATER, //
        { Category::cIceCavern, Category::cSong, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x52), SpoilerCollectionCheckGroup::GROUP_DUNGEON_ICE_CAVERN);
    Delayed(SHEIK_AT_COLOSSUS, DLYOVR_SONG_REQUIEM, //
        "Sheik at Colossus", REQUIEM_OF_SPIRIT, //
        { Category::cDesertColossus, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0xAC), SpoilerCollectionCheckGroup::GROUP_HAUNTED_WASTELAND);
    Delayed(SHEIK_IN_KAKARIKO, DLYOVR_SONG_NOCTURNE, //
        "Sheik in Kakariko", NOCTURNE_OF_SHADOW, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0xAA), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Delayed(SHEIK_AT_TEMPLE, DLYOVR_SONG_PRELUDE, //
        "Sheik at Temple", PRELUDE_OF_LIGHT, //
        { Category::cTempleOfTime, Category::cMarket, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x55), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Delayed(SONG_FROM_IMPA, DLYOVR_SONG_LULLABY, //
        "Song from Impa", ZELDAS_LULLABY, //
        { Category::cHyruleCastle, Category::cMarket, Category::cSong, Category::cSongDungeonReward }, //
        SpoilerCollectionCheck::EventChkInf(0x59), SpoilerCollectionCheckGroup::GROUP_HYRULE_CASTLE);
    Delayed(SONG_FROM_MALON, DLYOVR_SONG_EPONA, //
        "Song from Malon", EPONAS_SONG, //
        { Category::cLonLonRanch, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x58), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Delayed(SONG_FROM_SARIA, DLYOVR_SONG_SARIA, //
        "Song from Saria", SARIAS_SONG, //
        { Category::cSacredForestMeadow, Category::cForest, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x57), SpoilerCollectionCheckGroup::GROUP_SACRED_FOREST_MEADOW);
    Delayed(SONG_FROM_COMPOSERS_GRAVE, DLYOVR_SONG_SUN, //
        "Song from Composers Grave", SUNS_SONG, //
        { Category::cGraveyard, Category::cKakariko, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x5A), SpoilerCollectionCheckGroup::GROUP_GRAVEYARD);
    Delayed(SONG_FROM_OCARINA_OF_TIME, DLYOVR_SONG_TIME, //
        "Song from Ocarina of Time", SONG_OF_TIME, //
        { Category::cHyruleField, Category::cSong, Category::cNeedSpiritualStones }, //
        SpoilerCollectionCheck::EventChkInf(0xA9), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Delayed(SONG_FROM_WINDMILL, DLYOVR_SONG_STORMS, //
        "Song from Windmill", SONG_OF_STORMS, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cSong }, //
        SpoilerCollectionCheck::EventChkInf(0x5B), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    /*-------------------------------
               --- COWS ---
      -------------------------------*/

    Base(KF_LINKS_HOUSE_COW, SCENE_LINKS_HOUSE, 0x15, //
        "KF Links House Cow", MILK, //
        { Category::cForest, Category::cCow, Category::cMinigame }, //
        SpoilerCollectionCheck::Cow(0x34, 0x15), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(HF_COW_GROTTO_COW, SCENE_GROTTOS, 0x16, //
        "HF Cow Grotto Cow", MILK, //
        { Category::cHyruleField, Category::cCow, Category::cGrotto }, //
        SpoilerCollectionCheck::Cow(0x3E, 0x16), SpoilerCollectionCheckGroup::GROUP_HYRULE_FIELD);
    Base(LLR_STABLES_LEFT_COW, SCENE_STABLE, 0x16, //
        "LLR Stables Left Cow", MILK, //
        { Category::cLonLonRanch, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x36, 0x16), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Base(LLR_STABLES_RIGHT_COW, SCENE_STABLE, 0x15, //
        "LLR Stables Right Cow", MILK, //
        { Category::cLonLonRanch, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x36, 0x15), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Base(LLR_TOWER_LEFT_COW, SCENE_LON_LON_BUILDINGS, 0x15, //
        "LLR Tower Left Cow", MILK, //
        { Category::cLonLonRanch, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x4C, 0x16), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Base(LLR_TOWER_RIGHT_COW, SCENE_LON_LON_BUILDINGS, 0x16, //
        "LLR Tower Right Cow", MILK, //
        { Category::cLonLonRanch, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x4C, 0x15), SpoilerCollectionCheckGroup::GROUP_LON_LON_RANCH);
    Base(KAK_IMPAS_HOUSE_COW, SCENE_IMPAS_HOUSE, 0x15, //
        "Kak Impas House Cow", MILK, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x37, 0x15), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(DMT_COW_GROTTO_COW, SCENE_GROTTOS, 0x15, //
        "DMT Cow Grotto Cow", MILK, //
        { Category::cDeathMountainTrail, Category::cDeathMountain, Category::cCow, Category::cGrotto }, //
        SpoilerCollectionCheck::Cow(0x3E, 0x15), SpoilerCollectionCheckGroup::GROUP_DEATH_MOUNTAIN_TRAIL);
    Base(GV_COW, SCENE_GERUDO_VALLEY, 0x15, //
        "GV Cow", MILK, //
        { Category::cGerudoValley, Category::cGerudo, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x5A, 0x15), SpoilerCollectionCheckGroup::GROUP_GERUDO_VALLEY);
    Base(JABU_JABUS_BELLY_MQ_COW, SCENE_JABU_JABU, 0x15, //
        "Jabu Jabus Belly MQ Cow", MILK, //
        { Category::cJabuJabusBelly, Category::cCow }, //
        SpoilerCollectionCheck::Cow(0x02, 0x15), SpoilerCollectionCheckGroup::GROUP_DUNGEON_JABUJABUS_BELLY);
}
