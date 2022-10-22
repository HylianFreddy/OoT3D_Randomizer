#include "rHeap.h"
#include "item_override.h"
#include "actor.h"
#include "input.h"
#include "models.h"
#include "entrance.h"
#include "settings.h"
//#include "3ds/svc.h"
//#include <unistd.h>

#include "z3D/z3D.h"
#include "3ds/extdata.h"

GlobalContext* gGlobalContext;
static u8 rRandomizerInit = 0;
//static u64 initialTime = 0;

void set_GlobalContext(GlobalContext* globalCtx) {
    gGlobalContext = globalCtx;
}

void Randomizer_Init() {
    rHeap_Init();
    Actor_Init();
    Entrance_Init();
    ItemOverride_Init();
    extDataInit();
}

void before_GlobalContext_Update(GlobalContext* globalCtx) {
    if (!rRandomizerInit) {
        Randomizer_Init();
        set_GlobalContext(globalCtx);
        rRandomizerInit = 1;
    }
    ItemOverride_Update();
    Model_UpdateAll(globalCtx);
    Input_Update();

    Settings_SkipSongReplays();
}

void after_GlobalContext_Update() {
}

/*void startSceneLoad() {
    //if (!rRandomizerInit) return;
    initialTime = svcGetSystemTick();
    gGlobalContext->csCtx.frames = 128;
}

void endSceneLoad() {
    //if (!rRandomizerInit) return;
    if (gSettingsContext.playOption == PLAY_ON_CITRA) {
        s64 ns = (svcGetSystemTick() - initialTime) * 4;
        if (ns < 0 || ns > 1500000000) return;
        s64 nsToWait = 1500000000 - ns;
        gSaveContext.ammo[2] = (u8)(nsToWait/100000000);
        svcSleepThread(800000000);
        //if (svcGetSystemTick() < initialTime + 268123480 / 2) gSaveContext.ammo[3] = 34;
    }

    //gGlobalContext->csCtx.frames = 65;
}*/
