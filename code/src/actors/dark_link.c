#include "dark_link.h"
#include "settings.h"
#include "common.h"
#include "input.h"

#define EnTorch2_Update ((ActorFunc)GAME_ADDR(0x22F0C8))

#define DarkLink_PlayVoiceSfx ((void (*)(Vec3f * pos, u16 sfxId))0x36AEB4)

void DarkLink_MoveToPlayer(EnTorch2* this) {
    this->darkPlayer.actor.world.pos.y = PLAYER->actor.world.pos.y + 40.0f;
    this->darkPlayer.actor.world.pos.x = (Math_SinS(PLAYER->actor.shape.rot.y) * -120.0f) + PLAYER->actor.world.pos.x;
    this->darkPlayer.actor.world.pos.z = (Math_CosS(PLAYER->actor.shape.rot.y) * -120.0f) + PLAYER->actor.world.pos.z;

    this->darkPlayer.actor.home.pos = this->darkPlayer.actor.world.pos;
}

void EnTorch2_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnTorch2* this = (EnTorch2*)thisx;
    // static u8 sPrevActionState = ENTORCH2_WAIT;

    EnTorch2_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON && this->actionState == ENTORCH2_ATTACK) {
        CollisionPoly floorPoly;
        Vec3f actorPos = (Vec3f){
            .x = thisx->world.pos.x,
            .y = thisx->world.pos.y + 10,
            .z = thisx->world.pos.z,
        };
        f32 yGroundIntersect    = BgCheck_RaycastDown1(&globalCtx->colCtx, &floorPoly, &actorPos);
        SurfaceType surfaceType = globalCtx->colCtx.stat.colHeader->surfaceTypeList[floorPoly.type];
        u8 isInvalidGround = yGroundIntersect <= BGCHECK_Y_MIN || SurfaceType_IsLoadingZoneOrVoidPlane(surfaceType);
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLOOR_WATER);

        CitraPrint("Dark Link ground check %X %X", isInvalidGround, thisx->bgCheckFlags & BGCHECKFLAG_GROUND);
        if ((isInvalidGround && (thisx->bgCheckFlags & BGCHECKFLAG_GROUND)) || thisx->world.pos.y < -4000.0) {
            if (thisx->colChkInfo.health <= 2) {
                thisx->colChkInfo.health = 0;
            } else {
                thisx->colChkInfo.health -= 2;
            }
            DarkLink_MoveToPlayer(this);
        }

        if (distXZ(this->darkPlayer.actor.world.pos, PLAYER->actor.world.pos) < 100.0 &&
            ABS(this->darkPlayer.actor.world.pos.y - PLAYER->actor.world.pos.y) > 500.0) {
            DarkLink_MoveToPlayer(this);
        }
    }

    // sPrevActionState = this->actionState;
}
