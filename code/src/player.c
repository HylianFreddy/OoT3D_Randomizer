#include "z3D/z3D.h"
#include "objects.h"
#include "custom_models.h"
#include "player.h"
#include "settings.h"

#define PlayerActor_Init_addr 0x191844
#define PlayerActor_Init ((ActorFunc)PlayerActor_Init_addr)

#define PlayerActor_Update_addr 0x1E1B54
#define PlayerActor_Update ((ActorFunc)PlayerActor_Update_addr)

#define PlayerActor_Destroy_addr 0x19262C
#define PlayerActor_Destroy ((ActorFunc)PlayerActor_Destroy_addr)

u16 healthDecrement = 0;
u8  storedMask = 0;
Actor* speedBomb = 0;
u8 speedBombDelay = 0;
#define bombTimer(x) *(((u8*)(x)) + 0x26C)

void* Player_EditAndRetrieveCMB(ZARInfo* zarInfo, u32 objModelIdx) {
    void* cmbMan = ZAR_GetCMBByIndex(zarInfo, objModelIdx);

    if (gSaveContext.linkAge == 0) {
        void* cmb = (void*)(((char*)zarInfo->buf) + 0xDAE8);
        CustomModel_EditLinkToCustomTunic(cmb);
    } else {
        void* cmb = (void*)(((char*)zarInfo->buf) + 0xDACC);
        CustomModel_EditChildLinkToCustomTunic(cmb);
    }

    return cmbMan;
}

void* Player_GetCustomTunicCMAB(void) {
    s16 exObjectBankIdx = Object_GetIndex(&rExtendedObjectCtx, OBJECT_CUSTOM_GENERAL_ASSETS);
    if (exObjectBankIdx < 0) {
        exObjectBankIdx = Object_Spawn(&rExtendedObjectCtx, OBJECT_CUSTOM_GENERAL_ASSETS);
    }
    if (gSaveContext.linkAge == 0) {
        return ZAR_GetCMABByIndex(&rExtendedObjectCtx.status[exObjectBankIdx].zarInfo, TEXANIM_LINK_BODY);
    } else {
        return ZAR_GetCMABByIndex(&rExtendedObjectCtx.status[exObjectBankIdx].zarInfo, TEXANIM_CHILD_LINK_BODY);
    }
}

void Player_SetChildCustomTunicCMAB(void) {
    s16 exObjectBankIdx = Object_GetIndex(&rExtendedObjectCtx, OBJECT_CUSTOM_GENERAL_ASSETS);
    void* cmabMan;
    if (exObjectBankIdx < 0) {
        exObjectBankIdx = Object_Spawn(&rExtendedObjectCtx, OBJECT_CUSTOM_GENERAL_ASSETS);
    }
    cmabMan = ZAR_GetCMABByIndex(&rExtendedObjectCtx.status[exObjectBankIdx].zarInfo, TEXANIM_CHILD_LINK_BODY);
    TexAnim_Spawn(PLAYER->skelAnime.unk_28->unk_0C, cmabMan);
}

void PlayerActor_rInit(Actor* thisx, GlobalContext* globalCtx) {
    gSettingsContext.quickText = 3;
    gSettingsContext.skipSongReplays = 1;
    gSettingsContext.fastBunnyHood = 1;
    PlayerActor_Init(thisx, globalCtx);
    if (gSettingsContext.fastBunnyHood) {
        PLAYER->currentMask = storedMask;
    }
}

void PlayerActor_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    PlayerActor_Update(thisx, globalCtx);

    if (speedBomb != 0) {
        if (bombTimer(speedBomb) > 1 && speedBomb->params != 1)
            bombTimer(speedBomb) = 1;
        else if (speedBombDelay < 1){
            Actor_Kill(speedBomb);
            speedBomb = 0;
        }
    }

    if (thisx->speedXZ > 18) {
        if (speedBombDelay > 0)
            speedBombDelay--;
        else {
            speedBomb = Actor_Spawn(&globalCtx->actorCtx, globalCtx, 0x10, thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z,
                        thisx->world.rot.x, thisx->world.rot.y, thisx->world.rot.z, 0);
            speedBombDelay = 5;
        }
    }
    else {
        speedBombDelay = 0;
    }

    if (gSettingsContext.fastBunnyHood && PLAYER->currentMask == 4 && PLAYER->stateFuncPtr == (void*)0x4BA378) {
        PLAYER->xzSpeed = 20;
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
    PlayerActor_Destroy(thisx, globalCtx);
}

f32 Player_GetSpeedMultiplier(void) {
    f32 speedMultiplier = 1;

    if (gSettingsContext.fastBunnyHood && PLAYER->currentMask == 4 && PLAYER->stateFuncPtr == (void*)0x4BA378) {
        speedMultiplier *= 1.5;
    }

    return speedMultiplier;
}
