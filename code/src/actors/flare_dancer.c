#include "flare_dancer.h"
#include "settings.h"

#define EnFd_Update ((ActorFunc)GAME_ADDR(0x1B004C))

#define EnFd_Reappear ((EnFdActionFunc)GAME_ADDR(0x117D98))
#define EnFd_JumpToGround ((EnFdActionFunc)GAME_ADDR(0x3ACD84))

void EnFd_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnFd* this = (EnFd*)thisx;

    EnFd_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON) {
        Actor_UpdateBgCheckInfo(globalCtx, thisx, 26.0f, 6.0f, 0.0f, UPDBGCHECKINFO_WALL);

        if (this->actionFunc == EnFd_JumpToGround && thisx->bgCheckFlags & BGCHECKFLAG_WALL) {
            // Prevent Flare Dancer from going through walls when jumping off.
            thisx->world.pos.x = thisx->prevPos.x;
            thisx->world.pos.z = thisx->prevPos.z;
        }

        CollisionPoly floorPoly;
        Vec3f actorPos = (Vec3f){
            .x = thisx->world.pos.x,
            .y = thisx->world.pos.y + 10,
            .z = thisx->world.pos.z,
        };
        f32 yGroundIntersect    = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &actorPos);
        SurfaceType surfaceType = gGlobalContext->colCtx.stat.colHeader->surfaceTypeList[floorPoly.type];
        u8 isInvalidGround      = yGroundIntersect < -30000.0 || SurfaceType_IsLoadingZoneOrVoidPlane(surfaceType);

        if (isInvalidGround && thisx->world.pos.y < thisx->home.pos.y - 200.0) {
            // If Flare Dancer falls out of bounds, make it respawn at its home.
            this->actionFunc = EnFd_Reappear;
        }
    }
}
