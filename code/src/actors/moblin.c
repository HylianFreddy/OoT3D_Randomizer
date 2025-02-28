#include "z3D/z3D.h"
#include "moblin.h"
#include "settings.h"
#include "common.h"

#define EnMb_Update ((ActorFunc)GAME_ADDR(0x1B6D80))
#define EnMb_ClubWaitPlayerNear ((EnMbActionFunc)GAME_ADDR(0x10B5D0))

void EnMb_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    if (gSettingsContext.enemizer == ON) {
        // Rotate towards player
        Math_SmoothStepToS(&thisx->world.rot.y, thisx->yawTowardsPlayer, 3, 0x100, 0);
        thisx->shape.rot.y = thisx->world.rot.y;
    }
    EnMb_Update(thisx, globalCtx);
}
