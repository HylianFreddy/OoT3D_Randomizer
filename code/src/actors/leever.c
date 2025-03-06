#include "leever.h"
#include "settings.h"

#define EnReeba_SetupSurface ((EnReebaActionFunc)GAME_ADDR(0x181394))

s32 Leever_ShouldSurviveOutsideSand(Actor* actor) {
    // Single enemies, or children of spawners outside Desert Colossus and Haunted Wasteland
    return gSettingsContext.enemizer == ON &&
           (actor->parent == NULL || (gGlobalContext->sceneNum != 92 && gGlobalContext->sceneNum != 94));
}

void Leever_AfterSink(Actor* actor) {
    if (gSettingsContext.enemizer == ON && actor->parent == NULL) {
        actor->world.pos              = actor->home.pos;
        ((EnReeba*)actor)->actionFunc = EnReeba_SetupSurface;
    } else {
        Actor_Kill(actor);
    }
}

void Leever_AfterDie(Actor* actor) {
    if (gSettingsContext.enemizer == ON && actor->parent == NULL && actor->colChkInfo.health == 0) {
        Actor_Kill(actor);
    }
}
