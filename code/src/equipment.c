#include "z3D/z3D.h"
#include "savefile.h"

s32 Equipment_OverrideDelete(s32 equipType, s32 equipValue) {
    if (equipType == EQUIP_TYPE_SHIELD) {
        switch (equipValue) {
            case EQUIP_VALUE_SHIELD_DEKU:
                return --gExtSaveData.dekuShieldsCount;
            case EQUIP_VALUE_SHIELD_HYLIAN:
                return --gExtSaveData.hylianShieldsCount;
        }
    }
    return FALSE; // No override, proceed with deletion
}
