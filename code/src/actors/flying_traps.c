#include "z3D/z3D.h"
#include "flying_traps.h"
#include "enemy_souls.h"
#include "settings.h"
#include "enemizer.h"
#include "common.h"
#include "objects.h"

#include "input.h"

/*-------------------------------
|           EnTuboTrap          |
-------------------------------*/

#define THIS ((EnTuboTrap*)thisx)

#define POT_CMB_INDEX 13

void EnTuboTrap_Init(Actor* thisx, GlobalContext* globalCtx);
void EnTuboTrap_Destroy(Actor* thisx, GlobalContext* globalCtx);
// void EnTuboTrap_Update(Actor* thisx, GlobalContext* globalCtx);//2848d8

void EnTuboTrap_WaitForProximity(EnTuboTrap* this, GlobalContext* globalCtx);

s32 EnTuboTrap_OnImpact(EnTuboTrap* this) {
    if (this->base.bgCheckFlags & 0x1) { // Standing on the ground
        this->actionFunc   = EnTuboTrap_WaitForProximity;
        this->base.gravity = 0;
        this->base.speedXZ = 0;
        this->base.flags &= ~1; // remove targetable flag
    }

    return EnemySouls_CheckSoulForActor(&this->base);
}

static CmbManager* sCmbMan = NULL;

extern u8 EnemySouls_GlobalObjectModEnabled;
void SoullessDarkness_RestoreObject(u16 objectId);
void SkeletonAnimationModel_Draw(SkeletonAnimationModel* glModel, s32 param_2);

void EnTuboTrap_rInit(Actor* thisx, GlobalContext* globalCtx) {
    if (sCmbMan == NULL) {
        ObjectEntry* obj = Object_FindEntryOrSpawn(OBJECT_GAMEPLAY_DUNGEON_KEEP);
        // Init normally
        ZAR_GetCMBByIndex(&obj->zarInfo, POT_CMB_INDEX);
        CmbManager* origCmbMan              = obj->zarInfo.cmbMans[POT_CMB_INDEX];
        obj->zarInfo.cmbMans[POT_CMB_INDEX] = NULL;
        EnemySouls_GlobalObjectModEnabled   = TRUE;
        // Init modded
        ZAR_GetCMBByIndex(&obj->zarInfo, POT_CMB_INDEX);
        EnemySouls_GlobalObjectModEnabled   = FALSE;
        sCmbMan                             = obj->zarInfo.cmbMans[POT_CMB_INDEX];
        obj->zarInfo.cmbMans[POT_CMB_INDEX] = origCmbMan;

        CitraPrint("pot %X %X", obj->zarInfo.cmbMans[POT_CMB_INDEX], sCmbMan);
        SoullessDarkness_RestoreObject(OBJECT_GAMEPLAY_DUNGEON_KEEP);
    }

    // ObjectEntry* obj                    = Object_FindEntryOrSpawn(OBJECT_GAMEPLAY_DUNGEON_KEEP);
    // CmbManager* origCmbMan              = obj->zarInfo.cmbMans[POT_CMB_INDEX];
    // obj->zarInfo.cmbMans[POT_CMB_INDEX] = sCmbMan;

    EnTuboTrap_Init(thisx, globalCtx);

    // obj->zarInfo.cmbMans[POT_CMB_INDEX] = origCmbMan;

    // SkeletonAnimationModel_Draw(THIS->saModel, 0);
    // THIS->saModel->vtbl->draw(THIS->saModel);
    // ((ActorFunc)0x28488c)(thisx, globalCtx);
}

void EnemySouls_BeforeCmbManagerInit(CmbManager* cmbMan, ZARInfo* zarInfo, s32 cmbIdx);
void EnTuboTrap_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    if (rInputCtx.pressed.zr) {
        ObjectEntry* obj                    = Object_FindEntryOrSpawn(OBJECT_GAMEPLAY_DUNGEON_KEEP);
        CmbManager* origCmbMan              = obj->zarInfo.cmbMans[POT_CMB_INDEX];
        obj->zarInfo.cmbMans[POT_CMB_INDEX] = sCmbMan;

        EnemySouls_GlobalObjectModEnabled = TRUE;
        EnemySouls_BeforeCmbManagerInit(sCmbMan, &obj->zarInfo, POT_CMB_INDEX);
        EnemySouls_GlobalObjectModEnabled = FALSE;
        CitraPrint("reiniting pot model");
        Actor_DestroySkelModels(thisx, &THIS->saModel, NULL);
        Actor_CreateSkelModels(thisx, gGlobalContext, &THIS->saModel, POT_CMB_INDEX, NULL);

        obj->zarInfo.cmbMans[POT_CMB_INDEX] = origCmbMan;
    }

    ((ActorFunc)0x2848d8)(thisx, globalCtx);
}

void EnTuboTrap_rDestroy(Actor* thisx, GlobalContext* globalCtx) {
    EnTuboTrap_Destroy(thisx, globalCtx);
    // ObjectEntry* obj                    = Object_FindEntryOrSpawn(OBJECT_GAMEPLAY_DUNGEON_KEEP);
    // obj->zarInfo.cmbMans[POT_CMB_INDEX] = sCmbMan;
}

#undef THIS

/*-------------------------------
|           EnYukabyun          |
-------------------------------*/

void EnYukabyun_Update(Actor* thisx, GlobalContext* globalCtx);

void EnYukabyun_Levitate(EnYukabyun* this, GlobalContext* globalCtx);
void EnYukabyun_Wait(EnYukabyun* this, GlobalContext* globalCtx);

s32 EnYukabyun_OnImpact(EnYukabyun* this) {
    if (!EnemySouls_CheckSoulForActor(&this->base)) {
        this->actionFunc  = EnYukabyun_Levitate;
        this->waitCounter = 0;
        this->base.flags |= 0b101; // keep targetable and hostile flags
        return 0;
    }
    return 1;
}

void EnYukabyun_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnYukabyun* this = (EnYukabyun*)thisx;

    if (Enemizer_IsEnemyRandomized(ENEMY_FLYING_FLOOR_TILE)) {
        Vec3f targetPos = (Vec3f){
            .x = PLAYER->actor.world.pos.x,
            .y = PLAYER->actor.world.pos.y + 20,
            .z = PLAYER->actor.world.pos.z,
        };

        if (this->actionFunc == EnYukabyun_Wait) {
            Vec3f posResult;
            CollisionPoly* outPoly;
            s32 bgId;

            // Wait until player is close enough and there are no obstacles in the way.
            u8 shouldWait = thisx->xzDistToPlayer > 500.0 || ABS(thisx->yDistToPlayer) > 50.0 ||
                            BgCheck_EntityLineTest1(&gGlobalContext->colCtx, &this->base.world.pos, &targetPos,
                                                    &posResult, &outPoly, TRUE, FALSE, FALSE, TRUE, &bgId);
            this->waitCounter = shouldWait ? 10 : 0;
        } else if (this->actionFunc == EnYukabyun_Levitate) {
            Math_SmoothStepToF(&thisx->world.pos.y, targetPos.y, 3, 3.0, 0);
        }
    }

    EnYukabyun_Update(thisx, globalCtx);
}

/*-------------------------------
|            Generic            |
-------------------------------*/

u8 FlyingTraps_IsHiddenTrap(Actor* actor) {
    switch (actor->id) {
        case ACTOR_FLYING_FLOOR_TILE:
            return ((EnYukabyun*)actor)->actionFunc == EnYukabyun_Wait;
        case ACTOR_FLYING_POT:
            return ((EnTuboTrap*)actor)->actionFunc == EnTuboTrap_WaitForProximity;
        default:
            return FALSE;
    }
}
