#include "z3D/z3D.h"
#include "savefile.h"
#include "objects.h"
#include "custom_models.h"
#include "settings.h"
#include "player.h"
#include "settings.h"
#include "fairy.h"
#include "icetrap.h"
#include "arrow.h"
#include "grotto.h"
#include "item_override.h"
#include "input.h"
#include "colors.h"
#include "common.h"

#define PlayerActor_Init ((ActorFunc)GAME_ADDR(0x191844))

#define PlayerActor_Update ((ActorFunc)GAME_ADDR(0x1E1B54))

#define PlayerActor_Destroy ((ActorFunc)GAME_ADDR(0x19262C))

#define PlayerActor_Draw ((ActorFunc)GAME_ADDR(0x4BF618))

#define Hookshot_ActorInit ((ActorInit*)GAME_ADDR(0x5108E8))

#define PlayerDListGroup_EmptySheathAdult ((void*)GAME_ADDR(0x53C4D8))
#define PlayerDListGroup_EmptySheathChildWithHylianShield ((void*)GAME_ADDR(0x53C4DC))

#define OBJECT_LINK_OPENING 0x19F

u16 healthDecrement = 0;
u8 storedMask       = 0;

void** Player_EditAndRetrieveCMB(ZARInfo* zarInfo, u32 objModelIdx) {
    void** cmbMan = ZAR_GetCMBByIndex(zarInfo, objModelIdx);
    void* cmb     = *cmbMan;

    if (gSettingsContext.customTunicColors == ON) {
        if (gSaveContext.linkAge == AGE_ADULT) {
            CustomModel_EditLinkToCustomTunic(cmb);
        } else {
            CustomModel_EditChildLinkToCustomTunic(cmb);
        }
    }

    if (gSettingsContext.stickAsAdult) {
        // The unused deku stick will use the same materialIndex as the bow, to make it appear brown.
        // This also avoids issues with its combiners being repurposed by the custom tunic patches.
        ((char*)cmb)[0x4C52] = 5;
    }

    return cmbMan;
}

void* Player_GetCustomTunicCMAB(ZARInfo* originalZarInfo, u32 originalIndex) {
    if (gSettingsContext.customTunicColors == OFF || gActorOverlayTable[0].initInfo->objectId == OBJECT_LINK_OPENING) {
        return ZAR_GetCMABByIndex(originalZarInfo, originalIndex);
    }
    return Object_GetCMABByIndex(OBJECT_CUSTOM_GENERAL_ASSETS,
                                 (gSaveContext.linkAge == 0) ? TEXANIM_LINK_BODY : TEXANIM_CHILD_LINK_BODY);
}

void Player_SetChildCustomTunicCMAB(void) {
    if (gSettingsContext.customTunicColors == OFF) {
        return;
    }
    void* cmabMan = Object_GetCMABByIndex(OBJECT_CUSTOM_GENERAL_ASSETS, TEXANIM_CHILD_LINK_BODY);
    TexAnim_Spawn(PLAYER->skelAnime.unk_28->unk_0C, cmabMan);
}

#include "savefile.h"
void PlayerActor_rInit(Actor* thisx, GlobalContext* globalCtx) {
    gSettingsContext.enemizer            = ON;
    gSettingsContext.customTunicColors   = ON;
    gSettingsContext.sheikHints          = ON;
    gSettingsContext.quickText = QUICKTEXT_TURBO;
    gSettingsContext.skipSongReplays = SONGREPLAYS_SKIP_NO_SFX;
    gExtSaveData.option_SkipSongReplays = SONGREPLAYS_SKIP_NO_SFX;
    gSettingsContext.faroresWindAnywhere = ON;
    gSettingsContext.freeCamera = ON;
    if (IceTrap_ActiveCurse == ICETRAP_CURSE_SHIELD) {
        gSaveContext.equips.equipment &= ~0xF0; // unequip shield
    }

    Grotto_SanitizeEntranceType();
    // If the player has started with 0 hearts, some entrances that knock Link down will cause a Game Over.
    // When respawning after the Game Over, change the entrance type to avoid softlocks.
    u8 playerEntranceType = (thisx->params & 0xF00) >> 8;
    if (gSaveContext.healthCapacity == 0 && gSaveContext.respawnFlag == -2 && playerEntranceType == 7) {
        thisx->params = (thisx->params & ~0xF00) | 0xD00; // Link will spawn standing in place
    }

    PlayerActor_Init(thisx, globalCtx);

    if (gSettingsContext.fastBunnyHood) {
        PLAYER->currentMask = storedMask;
    }
    if (gSettingsContext.hookshotAsChild) {
        Hookshot_ActorInit->objectId = (gSaveContext.linkAge == 1 ? 0x1 : 0x14);
    }
}

void PlayerActor_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    Player* this = (Player*)thisx;
    PlayerActor_Update(thisx, globalCtx);

    // Restore Randomizer draw function in case something (like Farore's Wind) overwrote it
    if (thisx->draw == PlayerActor_Draw) {
        thisx->draw = PlayerActor_rDraw;
    }

    Arrow_HandleSwap(this, globalCtx);

    if (this->naviActor != 0) {
        Fairy_UpdateRainbowNaviColors((EnElf*)this->naviActor);
    }

    if (IceTrap_ActiveCurse == ICETRAP_CURSE_SWORD && PLAYER->meleeWeaponState != 0 &&
        ((PLAYER->itemActionParam >= 3 && PLAYER->itemActionParam <= 5) ||
         PLAYER->itemActionParam == 35)) { // sword items
        PLAYER->meleeWeaponState = -1;     // slash effect with no hitbox (same as "damageless death ISG")
    }
    if (PLAYER->itemActionParam == 38) { // Blue Potion
        if (IceTrap_ActiveCurse == ICETRAP_CURSE_BLIND)
            gStaticContext.dekuNutFlash = -1;

        IceTrap_DispelCurses();
    }

    if (healthDecrement <= 0) {
        return;
    }

    if (gSaveContext.health > 4) {
        gSaveContext.health--;
        healthDecrement--;
    } else {
        healthDecrement = 0;
    }
}

void PlayerActor_rDestroy(Actor* thisx, GlobalContext* globalCtx) {
    if (gSettingsContext.fastBunnyHood) {
        storedMask = PLAYER->currentMask;
    }
    Fairy_ResetRainbowCMABs();
    PlayerActor_Destroy(thisx, globalCtx);
}

void PlayerActor_rDraw(Actor* thisx, GlobalContext* globalCtx) {
    // Draw empty scabbard if no sword is equipped.
    // For child, do this only with certain shields, because the game already handles the other cases.
    if (!(gSaveContext.equips.equipment & 0x000F)) {
        if (gSaveContext.linkAge == AGE_ADULT) {
            PLAYER->sheathDLists = PlayerDListGroup_EmptySheathAdult;
        } else if ((gSaveContext.equips.equipment & 0x00F0) >= 0x0020) { // Hylian or Mirror shield
            PLAYER->sheathDLists = PlayerDListGroup_EmptySheathChildWithHylianShield;
        }
    }

    Player_UpdateRainbowTunic();

    static Vec3f vecAcc = { 0 };
    static Vec3f vecVel = { 0 };
    static Vec3f vecPos = { 0 };
    Player* this        = (Player*)thisx;

    s32 tempSaModelsCount1 = gMainClass->sub180.saModelsCount1;
    s32 tempSaModelsCount2 = gMainClass->sub180.saModelsCount2;

    PlayerActor_Draw(thisx, globalCtx);

    if (!gExtSaveData.option_FireballLink) {
        return;
    }

    gMainClass->sub180.saModelsCount1 = tempSaModelsCount1; // 3D models
    gMainClass->sub180.saModelsCount2 = tempSaModelsCount2; // 2D billboards

    thisx->shape.shadowDrawFunc = NULL;

    if ((this->stateFlags1 & (1 << 0x14)) || // first person ("return A")
        PauseContext_GetState()) {
        return;
    }

    s32 velFrameIdx = (rGameplayFrames % 16);
    s32 accFrameIdx = (rGameplayFrames % 4);
    vecAcc.y        = 0.12f * accFrameIdx;
    vecVel.x        = 0.5f * Math_SinS(0x1000 * velFrameIdx);
    vecVel.z        = 0.5f * Math_CosS(0x1000 * velFrameIdx);
    s16 scale       = 150;

    // clang-format off
    static s16 colorVals[21][7] = {
        {0xFF, 0xFF, 0xFF, 0x00,    0x00, 0x00, 0x00,},
        {0xFF, 0xFF, 0xFF, 0x08,    0x00, 0x00, 0x00,},
        {0xFF, 0xFF, 0xFF, 0x10,    0x00, 0x00, 0x00,},
        {0xFF, 0xFF, 0xFF, 0x20,    0x00, 0x00, 0x00,},
        {0xFF, 0x80, 0x00, 0x20,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0x20,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0x30,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0x40,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0x70,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0xA0,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0xD0,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0x00, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x00, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x08, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x10, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x18, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x20, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x28, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x30, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x38, 0x00,},
        {0xFF, 0x40, 0x00, 0xFF,    0xFF, 0x40, 0x00,},
    };
    // clang-format on

    s32 index = gSaveContext.health / 16;
    if (index > 20) {
        index = 20;
    }
    s16* currentColors = colorVals[index];

    void* rollingFunc = (void*)(gSettingsContext.region == REGION_NA ? 0x492A3C : 0x492A5C);
    if (PLAYER->stateFuncPtr == rollingFunc) {
        vecPos   = thisx->world.pos;
        vecPos.y = thisx->focus.pos.y;
    } else {
        vecPos = thisx->focus.pos;
    }

    EffectSsDeadDb_Spawn(globalCtx, &vecPos, &vecVel, &vecAcc, scale, -1,                        //
                         currentColors[0], currentColors[1], currentColors[2], currentColors[3], //
                         currentColors[4], currentColors[5], currentColors[6],                   //
                         1, 8, 0);
}

static u8 swimBoostTimer = 0;
#define SWIM_BOOST_POWER (f32)3
#define SWIM_BOOST_DURATION 40

f32 Player_GetSpeedMultiplier(void) {
    f32 speedMultiplier = 1;

    if (gSettingsContext.fastBunnyHood && PLAYER->currentMask == 4 &&
        PLAYER->stateFuncPtr == (void*)GAME_ADDR(0x4BA378)) {
        speedMultiplier *= 1.5;
    }

    if (customSpeedBoost) {
        // Constant speed boost
        if (PLAYER->stateFuncPtr == (void*)0x4BA378 && rInputCtx.touchHeld &&
            (rInputCtx.touchX > 0x40 && rInputCtx.touchX < 0x100) &&
            (rInputCtx.touchY > 0x25 && rInputCtx.touchY < 0xC8)) {
            if (rInputCtx.touchY > 145) {
                speedMultiplier *= 1.5;
            } else if (rInputCtx.touchY > 91) {
                speedMultiplier *= 3.0;
            } else {
                speedMultiplier *= 5.0;
            }
        }

        // Swim boost
        u32 swimFunc = gSettingsContext.region == REGION_EUR ? 0x4A3364 : 0x4A3344;
        if (PLAYER->stateFuncPtr == (void*)swimFunc) {
            if (rInputCtx.pressed.b) {
                swimBoostTimer = SWIM_BOOST_DURATION;
            }

            speedMultiplier *= 1 + SWIM_BOOST_POWER * ((f32)swimBoostTimer / SWIM_BOOST_DURATION);

            if (swimBoostTimer > 0) {
                swimBoostTimer--;
            }
        } else {
            swimBoostTimer = 0;
        }
    } else {
        swimBoostTimer = 0;
    }

    if (IceTrap_ActiveCurse == ICETRAP_CURSE_SLOW) {
        speedMultiplier *= 0.5;
    }

    return speedMultiplier;
}

s32 Player_IsAdult() {
    return gSaveContext.linkAge == AGE_ADULT;
}

s32 Player_ShouldApplyAdultItemsCMABs() {
    return gSaveContext.linkAge == AGE_ADULT || gSettingsContext.hoverbootsAsChild || gSettingsContext.hookshotAsChild;
}

s32 Player_ShouldUseSlingshot() {

    if (PLAYER->heldItemActionParam == 0xF) { // Slingshot
        return gSaveContext.linkAge == 1 || gSettingsContext.slingshotAsAdult;
    } else {
        return gSaveContext.linkAge == 1 && !gSettingsContext.bowAsChild;
    }
}

s32 Player_CanPickUpThisActor(Actor* interactedActor) {
    switch (interactedActor->id) {
        case 0xA: // Chest, can never be picked up
            return 0;
        case 0x6C: // Pedestal of Time, prevent interaction while waiting to get item
            return !ItemOverride_IsAPendingOverride();
        default:
            return 1;
    }
}

#define TUNIC_CYCLE_FRAMES 30
void Player_UpdateRainbowTunic(void) {
    u8 currentTunic = (gSaveContext.equips.equipment >> 8) & 3;
    void* cmabManager;
    char* cmabChunk;
    u8 redOffset, greenOffset, blueOffset;

    if (gSaveContext.linkAge == AGE_CHILD) {
        if (gSettingsContext.rainbowChildTunic == OFF) {
            return;
        }
        cmabManager = Object_GetCMABByIndex(OBJECT_CUSTOM_GENERAL_ASSETS, TEXANIM_CHILD_LINK_BODY);
        redOffset   = 0x70;
        greenOffset = 0x88;
        blueOffset  = 0xA0;
    } else { // AGE_ADULT
        if ((currentTunic == 1 && gSettingsContext.rainbowKokiriTunic == OFF) ||
            (currentTunic == 2 && gSettingsContext.rainbowGoronTunic == OFF) ||
            (currentTunic == 3 && gSettingsContext.rainbowZoraTunic == OFF)) {
            return;
        }
        cmabManager = Object_GetCMABByIndex(OBJECT_CUSTOM_GENERAL_ASSETS, TEXANIM_LINK_BODY);
        redOffset   = 0x70 + 8 * (currentTunic - 1);
        greenOffset = 0x98 + 8 * (currentTunic - 1);
        blueOffset  = 0xC0 + 8 * (currentTunic - 1);
    }

    cmabChunk = *((char**)cmabManager);

    Color_RGBA8 color = Colors_GetRainbowColor(rGameplayFrames, TUNIC_CYCLE_FRAMES);

    *(f32*)(cmabChunk + redOffset)   = color.r / 255.0f;
    *(f32*)(cmabChunk + greenOffset) = color.g / 255.0f;
    *(f32*)(cmabChunk + blueOffset)  = color.b / 255.0f;
}
