#include "ganondorf.h"
#include "z3D/z3D.h"
#include "settings.h"

#define ACTOR_BOSS_GANON 0xE8

#define DMG_SLASH_MASTER (1 << 9)
#define DMG_SPIN_MASTER (1 << 24)
#define DMG_JUMP_MASTER (1 << 27)

#define EnGanonOrgan_Init_addr 0x280E0C
#define EnGanonOrgan_Init ((ActorFunc)EnGanonOrgan_Init_addr)

void EnGanonOrgan_rInit(Actor* organ, GlobalContext* globalCtx) {
    gSaveContext.eventChkInf[12] &= ~0x80;
    EnGanonOrgan_Init(organ, globalCtx);
}

void Ganondorf_CreditsWarp(Collider* at, Collider* ac) {
    /*if (gSettingsContext.skipFinalBattles && ac->actor != 0 && ac->actor->id == ACTOR_BOSS_GANON && ac->actor->params == 0xFFFF
        at->actor != 0 && at->actor->id == 0 && PLAYER->heldItemId == 0x60) {

        }*/


    BossGanon* ganon;
    if (ac->actor->id == ACTOR_BOSS_GANON) {
        gSaveContext.ammo[3]++;
        ganon = (BossGanon*)ac->actor;
    }
    gSaveContext.rupees = ganon->collider.info.atHitInfo->toucher.dmgFlags >> 16;
    if (gSettingsContext.skipFinalBattles && ac->actor != 0 && ac->actor->id == ACTOR_BOSS_GANON && ac->actor->params == 0xFFFF &&
        ganon->collider.info.acHitInfo->toucher.dmgFlags & (DMG_SLASH_MASTER | DMG_SPIN_MASTER | DMG_JUMP_MASTER)) {
        PLAYER->stateFlags1 |= 0x20000000;          // Freeze player
        gGlobalContext->nextEntranceIndex = 0x00A0; // cutscene map
        gSaveContext.nextCutsceneIndex    = 0xFFF8; // Ganondorf sealed
        gGlobalContext->fadeOutTransition = 7;      // cutscene fade to white
        gGlobalContext->sceneLoadFlag     = 0x14;
    }
}
