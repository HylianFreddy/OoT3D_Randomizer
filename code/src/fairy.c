#include "z3D/z3D.h"
#include "fairy.h"
#include "settings.h"
#include "objects.h"
#include "common.h"
#include "colors.h"
#include "item_override.h"

#define NAVI_COLORS_ARRAY ((Color_RGBA8*)GAME_ADDR(0x50C998))

#define NAVI_CYCLE_FRAMES_OUTER 18
#define NAVI_CYCLE_FRAMES_INNER 21

static u8 lastTargetActorType = 0;
// Data to manage the rainbow colors
static void* staticRainbowPointerCMAB = 0;
static void* staticRainbowReticleCMAB = 0;
static Color_RGBA8 staticRainbowColor = { 0 };

void Fairy_StoreTargetActorType(u8 targetActorType) {
    lastTargetActorType = targetActorType;
}

u8 Fairy_IsNaviInnerRainbowForActorType(u8 type) {
    switch (type) {
        case ACTORTYPE_PLAYER:
            return gSettingsContext.rainbowIdleNaviInnerColor;
        case ACTORTYPE_NPC:
            return gSettingsContext.rainbowNPCNaviInnerColor;
        case ACTORTYPE_ENEMY:
        case ACTORTYPE_BOSS:
            return gSettingsContext.rainbowEnemyNaviInnerColor;
        default:
            return gSettingsContext.rainbowPropNaviInnerColor;
    }
}

u8 Fairy_IsNaviOuterRainbowForActorType(u8 type) {
    switch (type) {
        case ACTORTYPE_PLAYER:
            return gSettingsContext.rainbowIdleNaviOuterColor;
        case ACTORTYPE_NPC:
            return gSettingsContext.rainbowNPCNaviOuterColor;
        case ACTORTYPE_ENEMY:
        case ACTORTYPE_BOSS:
            return gSettingsContext.rainbowEnemyNaviOuterColor;
        default:
            return gSettingsContext.rainbowPropNaviOuterColor;
    }
}

void Fairy_ApplyColorToTargetCMAB(void* cmab, Color_RGBA8 color8) {
    Color_RGBAf colorF = {
        .r = color8.r / 255.0f,
        .g = color8.g / 255.0f,
        .b = color8.b / 255.0f,
        .a = color8.a / 255.0f,
    };

    // keyframe 1
    *(f32*)(cmab + 0x6C) = colorF.r;
    *(f32*)(cmab + 0xAC) = colorF.g;
    *(f32*)(cmab + 0xEC) = colorF.b;
    // keyframe 2
    *(f32*)(cmab + 0x7C) = colorF.r;
    *(f32*)(cmab + 0xBC) = colorF.g;
    *(f32*)(cmab + 0xFC) = colorF.b;
    // keyframe 3
    *(f32*)(cmab + 0x8C)  = colorF.r;
    *(f32*)(cmab + 0xCC)  = colorF.g;
    *(f32*)(cmab + 0x10C) = colorF.b;
}

void Fairy_UpdateRainbowNaviColors(EnElf* navi) {
    if (Fairy_IsNaviInnerRainbowForActorType(lastTargetActorType)) {
        Color_RGBA8 newColor = Colors_GetRainbowColor(rGameplayFrames, NAVI_CYCLE_FRAMES_INNER);
        staticRainbowColor   = newColor;
        // Navi color components go up to 255.0f instead of 1.0f
        navi->innerColor.r = newColor.r / 1.0f;
        navi->innerColor.g = newColor.g / 1.0f;
        navi->innerColor.b = newColor.b / 1.0f;
    }
    if (Fairy_IsNaviOuterRainbowForActorType(lastTargetActorType)) {
        Color_RGBA8 newColor = Colors_GetRainbowColor(rGameplayFrames, NAVI_CYCLE_FRAMES_OUTER);
        navi->outerColor.r   = newColor.r / 1.0f;
        navi->outerColor.g   = newColor.g / 1.0f;
        navi->outerColor.b   = newColor.b / 1.0f;
    }

    // Handle target pointer color
    if (staticRainbowPointerCMAB != 0) {
        Fairy_ApplyColorToTargetCMAB(staticRainbowPointerCMAB, staticRainbowColor);
    }
    if (staticRainbowReticleCMAB != 0) {
        Fairy_ApplyColorToTargetCMAB(staticRainbowReticleCMAB, staticRainbowColor);
    }
}

s32 Fairy_SetTargetPointerColor(TargetContext* targetCtx, Actor* targetActor) {
    if (gSettingsContext.customNaviColors == OFF) {
        return 0;
    }

    void** cmabManager = ZAR_GetCMABByIndex(targetCtx->zarInfo, 37); // mark_model_white.cmab as base for all colors
    Fairy_ApplyColorToTargetCMAB(*cmabManager, NAVI_COLORS_ARRAY[targetActor->type * 2]); // get inner color
    staticRainbowPointerCMAB = Fairy_IsNaviInnerRainbowForActorType(targetActor->type) ? *cmabManager : 0;

    TexAnim_Spawn(targetCtx->visibleTargetIndicators.pointer->unk_0C, cmabManager);
    TexAnim_Spawn(targetCtx->hiddenTargetIndicators.pointer->unk_0C, cmabManager);
    targetCtx->pointerActorType = targetActor->type;

    return 1;
}

s32 Fairy_SetTargetReticleColor(TargetContext* targetCtx) {
    if (gSettingsContext.customNaviColors == OFF) {
        return 0;
    }

    void** cmabManager = ZAR_GetCMABByIndex(targetCtx->zarInfo, 41); // target_model_white.cmab as base for all colors
    Fairy_ApplyColorToTargetCMAB(*cmabManager, NAVI_COLORS_ARRAY[targetCtx->reticleActorType * 2]); // get inner color
    staticRainbowReticleCMAB = Fairy_IsNaviInnerRainbowForActorType(targetCtx->reticleActorType) ? *cmabManager : 0;

    for (s32 i = 0; i < 4; i++) {
        TexAnim_Spawn(targetCtx->visibleTargetIndicators.reticle[i]->unk_0C, cmabManager);
        TexAnim_Spawn(targetCtx->visibleTargetIndicators.reticleAfterimageOne[i]->unk_0C, cmabManager);
        TexAnim_Spawn(targetCtx->visibleTargetIndicators.reticleAfterimageTwo[i]->unk_0C, cmabManager);
        TexAnim_Spawn(targetCtx->hiddenTargetIndicators.reticle[i]->unk_0C, cmabManager);
        TexAnim_Spawn(targetCtx->hiddenTargetIndicators.reticleAfterimageOne[i]->unk_0C, cmabManager);
        TexAnim_Spawn(targetCtx->hiddenTargetIndicators.reticleAfterimageTwo[i]->unk_0C, cmabManager);
    }

    return 1;
}

void Fairy_ResetRainbowCMABs(void) {
    staticRainbowPointerCMAB = 0;
    staticRainbowReticleCMAB = 0;
}

/* Great Fairy */

#define BgDyYoseizo_Init ((ActorFunc)GAME_ADDR(0x25DD10))
#define BgDyYoseizo_Draw ((ActorFunc)GAME_ADDR(0x289AEC))

static void GreatFairy_OverrideReward(BgDyYoseizo* fairy) {
    s16 fairyIdx = fairy->fountainType;

    if (gGlobalContext->sceneNum == SCENE_GREAT_FAIRYS_FOUNTAIN_SPELLS) {
        if (!(gSaveContext.itemGetInf[1] & (0x100 << fairyIdx))) {
            ItemOverride_PushDelayedOverride(0x10 + fairyIdx);
            gSaveContext.itemGetInf[1] |= (0x100 << fairyIdx);
        }
    } else if (gGlobalContext->sceneNum == SCENE_GREAT_FAIRYS_FOUNTAIN_MAGIC) {
        if (!(gGlobalContext->actorCtx.flags.chest & (0x1 << fairyIdx))) {
            ItemOverride_PushDelayedOverride(0x13 + fairyIdx);
            gGlobalContext->actorCtx.flags.chest |= (0x1 << fairyIdx);
        }
    }

    gSaveContext.healthAccumulator = 0x140;
    gSaveContext.magic             = gSaveContext.magicLevel * 0x30;
}

static void GreatFairy_Action_WaitForSong(BgDyYoseizo* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, 0x38)) {
        globalCtx->ocarinaMode = 4;
        GreatFairy_OverrideReward(this);
        this->actionFn = NULL;
    }
}

void BgDyYoseizo_rInit(Actor* thisx, GlobalContext* globalCtx) {
    BgDyYoseizo* this = (BgDyYoseizo*)thisx;

    BgDyYoseizo_Init(thisx, globalCtx);

    thisx->scale = (Vec3f){
        .x = 0.035f,
        .y = 0.035f,
        .z = 0.035f,
    };
    Animation_Change(&this->skelAnime, 7, 1.0, 0.0, Animation_GetLastFrame(&this->skelAnime, 7), 0, -10.0);
    thisx->draw    = BgDyYoseizo_Draw;
    this->actionFn = GreatFairy_Action_WaitForSong;
}

void BgDyYoseizo_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    BgDyYoseizo* this = (BgDyYoseizo*)thisx;

    globalCtx->envCtx.lightSettingOverride = PLAYER->actor.world.pos.z < -300 ? 2 : 0xFF;

    SkelAnime_Update(&this->skelAnime);

    if (this->actionFn != NULL) {
        this->actionFn(this, globalCtx);
    }
}
