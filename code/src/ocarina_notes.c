#include "ocarina_notes.h"
#include "savefile.h"
#include "settings.h"

s32 OcarinaNotes_IsButtonOwned(OcarinaNoteButton button) {
    return (gSettingsContext.shuffleOcarinaButtons == OFF) ||
            (gExtSaveData.extInf[EXTINF_OCARINA_BUTTONS] & (1 << button));
}

void OcarinaNotes_RegisterButtonOwned(OcarinaNoteButton button) {
    gExtSaveData.extInf[EXTINF_OCARINA_BUTTONS] |= (1 << button);
}
