#include "z3D/z3D.h"
#include "common.h"
#include "settings.h"
#include "enemizer.h"
#include "stalfos.h"

u8 ShadowShip_HasActiveStalfos(void) {
    if (gEnemizerLocationFlags.shadowShipStalfos) {
        return FALSE;
    }

    for (Actor* actor = gGlobalContext->actorCtx.actorList[ACTORTYPE_ENEMY].first; actor != 0; actor = actor->next) {
        if (actor->id != 0x2) {
            continue;
        }
        EnTest* stalfos = (EnTest*)actor;
        if (stalfos->actionFunc != EnTest_Wait) {
            return TRUE;
        }
    }
    return FALSE;
}
