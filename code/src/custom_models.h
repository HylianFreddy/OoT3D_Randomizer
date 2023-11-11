#ifndef _CUSTOM_MODELS_H_
#define _CUSTOM_MODELS_H_

void CustomModel_EditLinkToCustomTunic(void* linkCMB);
void CustomModel_EditChildLinkToCustomTunic(void* linkCMB);
void CustomModel_EditTitleScreenLogo(void* titleScreenZAR);
void CustomModel_Update(void);
void CustomModels_EditItemCMB(void* ZARBuf, u16 objectId, s8 special);
void CustomModels_ApplyItemCMAB(SkeletonAnimationModel* model, u16 objectId, s8 special);

#define OBJECT_CUSTOM_DOUBLE_DEFENSE 4
#define OBJECT_CUSTOM_CHILD_SONGS 5
#define OBJECT_CUSTOM_ADULT_SONGS 16
#define OBJECT_CUSTOM_SMALL_KEY_FOREST 17
#define OBJECT_CUSTOM_SMALL_KEY_FIRE 58
#define OBJECT_CUSTOM_SMALL_KEY_WATER 120
#define OBJECT_CUSTOM_SMALL_KEY_SHADOW 121
#define OBJECT_CUSTOM_SMALL_KEY_BOTW 122
#define OBJECT_CUSTOM_SMALL_KEY_SPIRIT 123
#define OBJECT_CUSTOM_SMALL_KEY_FORTRESS 125
#define OBJECT_CUSTOM_SMALL_KEY_GTG 126
#define OBJECT_CUSTOM_SMALL_KEY_GANON 127
#define OBJECT_CUSTOM_BOSS_KEYS 128
#define OBJECT_CUSTOM_GENERAL_ASSETS 182
#define OBJECT_CUSTOM_OCARINA_BUTTON 291

typedef enum {
    TEXANIM_COPY_NINTENDO,
    TEXANIM_LINK_BODY,
    TEXANIM_TITLE_LOGO_US,
    TEXANIM_ADULT_SONG,
    TEXANIM_CHILD_SONG,
    TEXANIM_CHILD_LINK_BODY,
    TEXANIM_BOSS_KEY,
    TEXANIM_GOLD_CHEST,
    TEXANIM_KEY_CHEST,
    TEXANIM_HEART_CHEST,
    TEXANIM_SKULL_CHEST,
    TEXANIM_OCARINA_NOTE_BUTTON,
} CustomGeneralAssetsTexAnims;

typedef enum {
    TEXANIMFRAME_ZELDAS_LULLABY,
    TEXANIMFRAME_EPONAS_SONG,
    TEXANIMFRAME_SARIAS_SONG,
    TEXANIMFRAME_SONG_STORMS,
    TEXANIMFRAME_SUNS_SONG,
    TEXANIMFRAME_SONG_TIME
} ChildSongTexAnimFrames;

typedef enum {
    TEXANIMFRAME_BOLERO,
    TEXANIMFRAME_MINUET,
    TEXANIMFRAME_NOCTURNE,
    TEXANIMFRAME_PRELUDE,
    TEXANIMFRAME_REQUIEM,
    TEXANIMFRAME_SERENADE
} AdultSongTexAnimFrames;

typedef enum {
    TEXANIMFRAME_FOREST,
    TEXANIMFRAME_FIRE,
    TEXANIMFRAME_WATER,
    TEXANIMFRAME_SHADOW,
    TEXANIMFRAME_SPIRIT,
    TEXANIMFRAME_GANON
} BossKeyTexAnimFrames;

#endif //_CUSTOM_MODELS_H_
