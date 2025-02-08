#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include <stddef.h>

ExtendedObjectContext rExtendedObjectCtx = { 0 };

s32 ExtendedObject_Spawn(ObjectContext* objectCtx, s16 objectId) {
    return Object_Spawn(&rExtendedObjectCtx, objectId) + OBJECT_EXCHANGE_BANK_MAX;
}

void ExtendedObject_Clear(GlobalContext* globalCtx, ObjectContext* objectCtx) {
    Object_Clear(globalCtx, &rExtendedObjectCtx);
}

s32 ExtendedObject_GetIndex(ObjectContext* objectCtx, s16 objectId) {
    // CitraPrint("ExtendedObject_GetIndex: %X", objectId);
    for (s32 i = 0; i < OBJECT_EXCHANGE_BANK_MAX; ++i) {
        s32 id = rExtendedObjectCtx.status[i].id;
        id     = (id < 0 ? -id : id);
        if (id == objectId) {
            return i + OBJECT_EXCHANGE_BANK_MAX;
        }
    }
    return -1;
}

s32 ExtendedObject_IsLoaded(ObjectContext* objectCtx, s16 bankIndex) {
    if (bankIndex < OBJECT_EXCHANGE_BANK_MAX) {
        return (objectCtx->status[bankIndex].id > 0);
    }

    // CitraPrint("ExtendedObject_IsLoaded");
    return (rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id >= 0);
}

ObjectStatus* ExtendedObject_GetStatus(s16 objectId) {
    // CitraPrint("ExtendedObject_GetStatus");
    for (s32 i = 0; i < rExtendedObjectCtx.num; ++i) {
        s32 id = rExtendedObjectCtx.status[i].id;
        id     = (id < 0 ? -id : id);
        if (id == objectId)
            return &rExtendedObjectCtx.status[i];
    }
    // CitraPrint("ExtendedObject_GetStatus failed: %X", objectId);
    return NULL;
}

ObjectStatus* ExtendedObject_GetStatus_FromBankIndex(s16 bankIndex) {
    // CitraPrint("ExtendedObject_GetStatus_FromBankIndex: %X", bankIndex);
    if (bankIndex >= OBJECT_EXCHANGE_BANK_MAX) {
        return &rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX];
    }
    // CitraPrint("ExtendedObject_GetStatus_FromBankIndex failed: %X", objectId);
    return NULL;
}

void* ExtendedObject_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    s16 objectBankIdx = ExtendedObject_GetIndex(&gGlobalContext->objectCtx, objectId);
    void* cmabMan;

    if (objectBankIdx < OBJECT_EXCHANGE_BANK_MAX) {
        cmabMan = ZAR_GetCMABByIndex(&gGlobalContext->objectCtx.status[objectBankIdx].zarInfo, objectAnimIdx);
    } else {
        cmabMan = ZAR_GetCMABByIndex(&rExtendedObjectCtx.status[objectBankIdx - OBJECT_EXCHANGE_BANK_MAX].zarInfo,
                                     objectAnimIdx);
    }

    return cmabMan;
}
