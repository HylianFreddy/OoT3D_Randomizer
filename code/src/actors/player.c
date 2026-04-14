#include "z3D/z3D.h"
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
#include "gloom.h"
#include "savefile.h"

void PlayerActor_Init(Actor* thisx, GlobalContext* globalCtx);
void PlayerActor_Update(Actor* thisx, GlobalContext* globalCtx);
void PlayerActor_Destroy(Actor* thisx, GlobalContext* globalCtx);
void PlayerActor_Draw(Actor* thisx, GlobalContext* globalCtx);

void Player_Action_Running(Player* player, GlobalContext* globalCtx);

extern struct Unknown PlayerDListGroup_EmptySheathAdult;
extern struct Unknown PlayerDListGroup_EmptySheathChildWithHylianShield;

#define OBJECT_LINK_OPENING 0x19F

u16 healthDecrement = 0;
u8 storedMask       = 0;

static u32 sLastHitFrame = 0;
static s16 sPrevHealth   = INT16_MAX;

static f32 sSpeedMultiplier = 1.0;
static u8 swimBoostTimer    = 0;
#define SWIM_BOOST_POWER 3.0f
#define SWIM_BOOST_DURATION 40
void Player_Action_Running(Player* player, GlobalContext* globalCtx);
void Player_Action_Swimming(Player* player, GlobalContext* globalCtx);
void Player_Action_Rolling(Player* player, GlobalContext* globalCtx);

void Player_ComputeSpeedBoosts(void);

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
    TexAnim_Spawn(PLAYER->skelAnime.saModel->unk_0C, cmabMan);
}

void PlayerActor_rInit(Actor* thisx, GlobalContext* globalCtx) {
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
        gActorOverlayTable[ACTOR_HOOKSHOT].initInfo->objectId = (gSaveContext.linkAge == 1 ? 0x1 : 0x14);
    }

    sPrevHealth = gSaveContext.health;
}

void PlayerActor_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    Player* this = (Player*)thisx;

    Player_ComputeSpeedBoosts();

    if (this->actionFunc == Player_Action_Running && sSpeedMultiplier > 2.99f) {
        CollisionPoly floorPoly;
        Vec3f actorPos = (Vec3f){
            .x = thisx->world.pos.x,
            .y = thisx->world.pos.y + 100,
            .z = thisx->world.pos.z,
        };

        f32 yGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &actorPos);
        thisx->world.pos.y   = yGroundIntersect;
        thisx->home.pos.y    = yGroundIntersect;
    }

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

    if (healthDecrement > 0) {
        if (gSaveContext.health > 4) {
            gSaveContext.health--;
            healthDecrement--;
        } else {
            healthDecrement = 0;
        }
    }

    // Handle hit/damage counters
    s16 lostHealth = sPrevHealth - gSaveContext.health;
    if (lostHealth > 0) {
        gExtSaveData.damageReceived += (sPrevHealth - gSaveContext.health);
    }
    // Don't count hits for single units of elemental damage
    if (lostHealth > 1) {
        Player_OnHit();
    }
    sPrevHealth = gSaveContext.health;
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
            PLAYER->sheathDLists = &PlayerDListGroup_EmptySheathAdult;
        } else if ((gSaveContext.equips.equipment & 0x00F0) >= 0x0020) { // Hylian or Mirror shield
            PLAYER->sheathDLists = &PlayerDListGroup_EmptySheathChildWithHylianShield;
        }
    }

    Player_UpdateRainbowTunic();

    static Vec3f vecAcc = { 0 };
    static Vec3f vecVel = { 0 };
    static Vec3f vecPos = { 0 };
    Player* this        = (Player*)thisx;

    s32 prevSaModelsCount1 = gMainClass.sub180.saModelsCount1;

    PlayerActor_Draw(thisx, globalCtx);

    if (!gExtSaveData.option_FireballLink) {
        return;
    }

    if (gMainClass.sub180.saModelsCount1 > prevSaModelsCount1) {
        // Make player model invisible
        gMainClass.sub180.saModelsList1[prevSaModelsCount1] = (SAModelListEntry){ 0 };
    }

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

    if (PLAYER->actionFunc == Player_Action_Rolling) {
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

void Player_ComputeSpeedBoosts(void) {
    sSpeedMultiplier = 1.0f;

    if (gSettingsContext.fastBunnyHood && PLAYER->currentMask == 4 && PLAYER->actionFunc == Player_Action_Running) {
        sSpeedMultiplier *= 1.5;
    }

    if (gExtSaveData.option_SpeedBoost) {
        // Constant speed boost
        if (PLAYER->actionFunc == Player_Action_Running && rInputCtx.touchHeld &&
            (rInputCtx.touchX > 0x40 && rInputCtx.touchX < 0x100) &&
            (rInputCtx.touchY > 0x25 && rInputCtx.touchY < 0xC8)) {
            if (rInputCtx.touchY > 145) {
                sSpeedMultiplier *= 1.5;
            } else if (rInputCtx.touchY > 91) {
                sSpeedMultiplier *= 3.0;
            } else {
                sSpeedMultiplier *= 5.0;
            }
        }

        // Swim boost
        if (PLAYER->actionFunc == Player_Action_Swimming) {
            if (rInputCtx.pressed.b) {
                swimBoostTimer = SWIM_BOOST_DURATION;
            }

            sSpeedMultiplier *= 1 + SWIM_BOOST_POWER * ((f32)swimBoostTimer / SWIM_BOOST_DURATION);

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
        sSpeedMultiplier *= 0.75;
    }
}

f32 Player_GetSpeedMultiplier(void) {
    return sSpeedMultiplier;
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
        cmabManager = PLAYER->skelAnime.saModel->unk_0C->cmabManager;
        redOffset   = 0x70;
        greenOffset = 0x88;
        blueOffset  = 0xA0;
    } else { // AGE_ADULT
        if ((currentTunic == 1 && gSettingsContext.rainbowKokiriTunic == OFF) ||
            (currentTunic == 2 && gSettingsContext.rainbowGoronTunic == OFF) ||
            (currentTunic == 3 && gSettingsContext.rainbowZoraTunic == OFF)) {
            return;
        }
        cmabManager = PLAYER->tunicTexAnim.cmabManager;
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

void Player_OnHit(void) {
    if (rGameplayFrames - sLastHitFrame > 5) {
        gExtSaveData.hitCount++;
        Gloom_OnHit();
    }

    sLastHitFrame = rGameplayFrames;
}

void Player_OnBonk(void) {
    gExtSaveData.bonkCount++;

    static const s8 bonkDamageValues[] = {
        [BONKDAMAGE_NONE]    = 0x00, //
        [BONKDAMAGE_QUARTER] = 0x04, //
        [BONKDAMAGE_HALF]    = 0x08, //
        [BONKDAMAGE_ONE]     = 0x10, //
        [BONKDAMAGE_TWO]     = 0x20, //
        [BONKDAMAGE_FOUR]    = 0x40, //
    };

    s16 damage;
    if (gSaveContext.nayrusLoveTimer > 0) {
        damage = 0;
    } else if (gSettingsContext.bonkDamage == BONKDAMAGE_OHKO) {
        damage = gSaveContext.health;
    } else {
        damage = bonkDamageValues[gSettingsContext.bonkDamage];

        if (gSaveContext.doubleDefense) {
            damage /= 2;
        }
    }

    gSaveContext.health -= damage;
    if (gSaveContext.health < 0) {
        gSaveContext.health = 0;
    }
}
