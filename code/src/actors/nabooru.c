#include "z3D/z3D.h"

void NabooruKnuckle_Defeat(Actor* nabooruKnuckle) {
    gSaveContext.eventChkInf[3] |= 0x1000;
    gGlobalContext->actorCtx.flags.swch |= 0x20;
    Actor_Kill(nabooruKnuckle);
}
