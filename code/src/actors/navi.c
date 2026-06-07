#include "z3D/z3D.h"
#include "savefile.h"
#include "icetrap.h"

u8 Navi_GetNotificationOption(void) {
    if (IceTrap_ActiveCurse == ICETRAP_CURSE_NAVI) {
        return 0;
    }

    return gExtSaveData.options[OPTION_NAVINOTIFICATIONS];
}
