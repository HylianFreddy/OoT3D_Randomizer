#include "rHeap.h"
#include "item_override.h"
#include "actor.h"
#include "input.h"
#include "models.h"
#include "entrance.h"
#include "settings.h"
#include "title_screen.h"
#include "draw.h"
#include "common.h"
#include "savefile.h"
#include "multiplayer.h"
#include "grotto.h"
#include "item_effect.h"
#include "triforce.h"
#include "ocarina_notes.h"
#include "objects.h"

#include "z3D/z3D.h"
#include "3ds/extdata.h"
#include "3ds/services/irrst.h"
#include "3ds/svc.h"

GlobalContext* gGlobalContext = NULL;
static u8 rRandomizerInit     = 0;
u32 rGameplayFrames           = 0;

void set_GlobalContext(GlobalContext* globalCtx) {
    gGlobalContext = globalCtx;
}

void Randomizer_Init() {
    rHeap_Init();
    Actor_Init();
    Entrance_Init();
    ItemOverride_Init();
    OcarinaNotes_UpdateSongs();
    extDataInit();
    irrstInit();
}

void autoLoadSaveFile();

void before_GlobalContext_Update(GlobalContext* globalCtx) {
    if (!rRandomizerInit) {
        Randomizer_Init();
        set_GlobalContext(globalCtx);
        rRandomizerInit = 1;

        s64 output = 0;
        svcGetSystemInfo(&output, 0x20000, 0);
        playingOnCitra = (output != 0);
    }
    rGameplayFrames++;
    ItemOverride_Update();
    ActorSetup_Extra();
    Model_UpdateAll(globalCtx);
    Input_Update();
    autoLoadSaveFile();
    SaveFile_EnforceHealthLimit();

    Settings_SkipSongReplays();

    Multiplayer_Run();

    ItemEffect_RupeeAmmo(&gSaveContext);

    Triforce_HandleCreditsWarp();
}

void autoLoadSaveFile() {
    if (gSaveContext.entranceIndex == 0x629 && gSaveContext.cutsceneIndex == 0xFFF3 &&
        rInputCtx.cur.l && rInputCtx.cur.r) {

        Load_Savefiles_Buffer();
        FileSelect_LoadGame(&gGlobalContext->state, 0);
        if (gSaveContext.saveCount > 0) {
            gGlobalContext->linkAgeOnLoad = gSaveContext.linkAge;
            if (gSaveContext.masterQuestFlag) {
                // These static variables are used at some point during the load to overwrite the MQ flag.
                // Setting them like this is kind of broken (saving the game will save onto MQ slot 1),
                // but the autoloaded file shouldn't be MQ anyway.
                *(u8*)0x587934 = 0xBE; // Enable quest type buttons on title screen
                *(u8*)0x587953 = 0xEF; // Pressed the MQ button
            }
        }
    }
}

s32 checkFastForward(void) {
    static u32 updateCycleCounter = 0;
    return rInputCtx.cur.zl && (++updateCycleCounter % 20 != 0);
}

void after_GlobalContext_Update() {
    // The alert is always displayed on the Title Screen, and for 10 seconds after opening a save file.
    if (missingRomfsAlert && romfsAlertFrames > 0) {
        Draw_DrawFormattedStringTop(75, 180, COLOR_WHITE,
                                    "WARNING: THE ROMFS FOLDER IS MISSING!\nCOPY IT FROM AND TO THE SAME "
                                    "LOCATIONS\nUSED FOR CODE.IPS AND EXHEADER.BIN");
        if (IsInGame()) {
            romfsAlertFrames--;
        }
    }

    Multiplayer_Sync_Update();

    if (gGlobalContext->state.running == 0) {
        Model_DestroyAll();
    }
}
