#include "dark_link.h"
#include "settings.h"
#include "common.h"
#include "input.h"

#define EnTorch2_Update ((ActorFunc)GAME_ADDR(0x22F0C8))

void EnTorch2_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnTorch2* this = (EnTorch2*)thisx;

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
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLOOR_WATER);
        u8 isOutOfBounds    = yGroundIntersect <= BGCHECK_Y_MIN;
        u8 isAboveVoidPlane = yGroundIntersect > BGCHECK_Y_MIN && SurfaceType_IsLoadingZoneOrVoidPlane(surfaceType);
        u8 isOnGround       = (thisx->bgCheckFlags & BGCHECKFLAG_GROUND) != 0;
        u8 isBelowLink      = PLAYER->actor.world.pos.y - this->darkPlayer.actor.world.pos.y > 200.0;

        if ((isAboveVoidPlane && isOnGround)) {
            // Take damage when falling into a pit
            if (thisx->colChkInfo.health <= 2) {
                thisx->colChkInfo.health = 0;
            } else {
                thisx->colChkInfo.health -= 2;
            }
        }

        if (isBelowLink && (isOutOfBounds || (isAboveVoidPlane && isOnGround))) {
            // Teleport behind player
            this->darkPlayer.actor.world.pos.y = PLAYER->actor.world.pos.y + 40.0f;
            this->darkPlayer.actor.world.pos.x =
                (Math_SinS(PLAYER->actor.shape.rot.y) * -120.0f) + PLAYER->actor.world.pos.x;
            this->darkPlayer.actor.world.pos.z =
                (Math_CosS(PLAYER->actor.shape.rot.y) * -120.0f) + PLAYER->actor.world.pos.z;

            this->darkPlayer.actor.home.pos = this->darkPlayer.actor.world.pos;
        }
    }
}
