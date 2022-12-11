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
#include "objects.h"
#include "string.h"
#include "gfx.h"

#include "z3D/z3D.h"
#include "3ds/extdata.h"

GlobalContext* gGlobalContext = NULL;
static u8 rRandomizerInit     = 0;

//static char staticChildLinkZAR[0x4D25AC] = {0};
//static char staticAdultLinkZAR[0x4F55D8] = {0};

//static char acto_wood_shieldl[10880] = {0};
//static char childlink_v2[214528] = {0};
//static char lc_stick_model[3584] = {0};

//static char chain_model[2432] = {0};
//static char hook_model[7168] = {0};
//static char long_sword_blade_model[2944] = {0};
//static char link_v2[322976] = {0};

void set_GlobalContext(GlobalContext* globalCtx) {
    gGlobalContext = globalCtx;
}

void messWithObjects() {
    //ExtendedObject_Spawn(0, 0x14);
    //s32 childObjectBankIdx = ExtendedObject_Spawn(0, 0x15);

    //value1 = (u32)**(rExtendedObjectCtx.status[1].zarInfo.cmbPtrs);

    //Unmapped reads
    //memcpy(&link_v2,      **(rExtendedObjectCtx.status[1].zarInfo.cmbPtrs), sizeof link_v2);
    //memcpy(&childlink_v2, **(rExtendedObjectCtx.status[childObjectBankIdx].zarInfo.cmbPtrs), sizeof childlink_v2);
}

void Randomizer_Init() {
    rHeap_Init();
    Actor_Init();
    Entrance_Init();
    ItemOverride_Init();
    extDataInit();
    messWithObjects();
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
    SaveFile_EnforceHealthLimit();

    Settings_SkipSongReplays();

    Multiplayer_Run();
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
}
