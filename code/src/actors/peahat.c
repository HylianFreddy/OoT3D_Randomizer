#include "peahat.h"
#include "settings.h"
#include "enemy_souls.h"

#define EnPeehat_Update ((ActorFunc)GAME_ADDR(0x167644))

#define EnPeehat_StateAttackRecoil ((EnPeehatActionFunc)GAME_ADDR(0x2B2CC0))
#define EnPeehat_Larva_StateSeekPlayer ((EnPeehatActionFunc)GAME_ADDR(0x391588))

#define STATE_SEEK_PLAYER 14

void EnPeehat_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat* this = (EnPeehat*)thisx;

    EnPeehat_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON && thisx->params == (s16)0xFFFF) { // Grounded Peahat
        f32 yWaterSurface;
        void* waterBox;
        s32 waterBoxFound = WaterBox_GetSurfaceImpl(gGlobalContext, &gGlobalContext->colCtx, thisx->world.pos.x,
                                                    thisx->world.pos.z, &yWaterSurface, &waterBox);

        // Float on water to work as an aquatic plant.
        if (waterBoxFound && thisx->world.pos.y < yWaterSurface - 10.0) {
            thisx->world.pos.y = yWaterSurface - 10.0;
        }

        // Fly at player's height.
        if (this->state == STATE_SEEK_PLAYER && thisx->world.pos.y < PLAYER->actor.world.pos.y) {
            Math_SmoothStepToF(&thisx->world.pos.y, PLAYER->actor.world.pos.y, 3, 5.0, 0);
        }

        // Vanilla code doesn't check for ceilings.
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 25.0f, 30.0f, 100.0f,
                                UPDBGCHECKINFO_WALL | UPDBGCHECKINFO_CEILING | UPDBGCHECKINFO_FLOOR_WATER);
    }

    if (!EnemySouls_CheckSoulForActor(thisx) && thisx->params == 1) { // Peahat Larva
        // Prevent death when hitting player's shield.
        if (this->actionFunc == EnPeehat_StateAttackRecoil) {
            this->actionFunc = EnPeehat_Larva_StateSeekPlayer;
            this->state      = STATE_SEEK_PLAYER;
            this->colliderQuadBase.atFlags &= ~(1 << 2); // AT_BOUNCED
        }

        // Prevent death when hitting ground.
        CollisionPoly floorPoly;
        f32 yGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &thisx->world.pos);

        if (thisx->world.pos.y < yGroundIntersect + 10) {
            thisx->world.pos.y = yGroundIntersect + 10;
        }
    }
}
