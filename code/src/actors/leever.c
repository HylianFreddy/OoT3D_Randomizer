#include "leever.h"
#include "settings.h"
#include "common.h"

#define EnReeba_Init ((ActorFunc)GAME_ADDR(0x1DDF04))
#define EnReeba_Update ((ActorFunc)GAME_ADDR(0x14C184))
#define EnReeba_Draw ((ActorFunc)GAME_ADDR(0x1B878C))

#define EnReeba_SetupSurface ((EnReebaActionFunc)GAME_ADDR(0x181394))
#define EnReeba_SetupSink ((EnReebaActionFunc)GAME_ADDR(0x1754B0))
#define EnReeba_Sink ((EnReebaActionFunc)GAME_ADDR(0x3D6118))
#define EnReeba_Move ((EnReebaActionFunc)GAME_ADDR(0x3DE24C))

void EnReeba_rInit(Actor* thisx, GlobalContext* globalCtx) {
    // EnReeba* this = (EnReeba*)thisx;

    EnReeba_Init(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON && thisx->parent == NULL) {
        // // Undo Actor_Kill to keep Leever alive even outside sandy floors
        // thisx->update = EnReeba_rUpdate;
        // thisx->draw   = EnReeba_Draw;
        // thisx->flags |= 0x1;
        // this->actionFunc = EnReeba_SetupSurface;
    }
}

void EnReeba_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnReeba* this = (EnReeba*)thisx;

    EnReeba_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON) {
        CitraPrint("actionFunc=%X", this->actionFunc);
        // if (this->actionFunc == EnReeba_SetupSink && thisx->speedXZ == 0.0f) {
        //     CitraPrint("restoring EnReeba_Move");
        //     this->actionFunc = EnReeba_Move;
        //     thisx->speedXZ = 8.0;
        // }

        // if (this->actionFunc == EnReeba_Sink && thisx->update == NULL) {
        //     CitraPrint("restoring EnReeba_SetupSurface");
        //     // Undo Actor_Kill
        //     thisx->update = EnReeba_rUpdate;
        //     thisx->draw   = EnReeba_Draw;
        //     thisx->flags |= 0x1;
        //     // Reappear at home position
        //     thisx->world.pos = thisx->home.pos;
        //     this->actionFunc = EnReeba_SetupSurface;
        // }
    }
}

s32 Leever_ShouldSurviveOutsideSand(Actor* actor) {
    CitraPrint("Leever_ShouldSurviveOutsideSand");
    return gSettingsContext.enemizer == ON && actor->parent == NULL;
}

void Leever_AfterSink(Actor* actor) {
    CitraPrint("Leever_AfterSink, health=%d", actor->colChkInfo.health);
    if (gSettingsContext.enemizer == ON && actor->colChkInfo.health != 0) {
        CitraPrint("keep");
        actor->world.pos = actor->home.pos;
        ((EnReeba*)actor)->actionFunc = EnReeba_SetupSurface;
    } else {
        CitraPrint("kill");
        Actor_Kill(actor);
    }
}

void Leever_AfterDie(Actor* actor) {
    if (gSettingsContext.enemizer == ON && actor->parent == NULL && actor->colChkInfo.health == 0) {
        Actor_Kill(actor);
    }
}
