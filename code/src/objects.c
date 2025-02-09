#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include <stddef.h>

ExtendedObjectContext rExtendedObjectCtx = { 0 };

s32 ExtendedObject_Spawn(s16 objectId) {
    return Object_Spawn(&rExtendedObjectCtx, objectId) + OBJECT_EXCHANGE_BANK_MAX;
}

void ExtendedObject_Clear(GlobalContext* globalCtx) {
    Object_Clear(globalCtx, &rExtendedObjectCtx);
}

s32 ExtendedObject_GetIndex(s16 objectId) {
    // CitraPrint("ExtendedObject_GetIndex: %X", objectId);
    for (s32 i = 0; i < rExtendedObjectCtx.num; ++i) {
        s32 id = ABS(rExtendedObjectCtx.status[i].id);
        if (id == objectId) {
            return i + OBJECT_EXCHANGE_BANK_MAX;
        }
    }
    return -1;
}

ObjectStatus* ExtendedObject_GetStatus(s16 bankIndex) {
    // CitraPrint("ExtendedObject_GetStatus: %X %X", bankIndex,
    //            rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id);
    if (bankIndex >= OBJECT_EXCHANGE_BANK_MAX) {
        return &rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX];
    }
    // CitraPrint("ExtendedObject_GetStatus failed: %X", objectId);
    return NULL;
}

ObjectStatus* ExtendedObject_FindStatus(s16 objectId) {
    // CitraPrint("ExtendedObject_FindStatus");
    s32 bankIndex = ExtendedObject_GetIndex(objectId);
    if (bankIndex >= 0) {
        return ExtendedObject_GetStatus(bankIndex);
    }
    // CitraPrint("ExtendedObject_FindStatus failed: %X", objectId);
    return NULL;
}

ObjectStatus* Object_FindStatus(ObjectContext* objectCtx, s16 objectId) {
    // CitraPrint("Object_FindStatus");
    s32 bankIndex = Object_GetIndex(objectCtx, objectId);
    if (bankIndex >= OBJECT_EXCHANGE_BANK_MAX) {
        return &rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX];
    } else if (bankIndex >= 0) {
        return &objectCtx->status[bankIndex];
    }
    // CitraPrint("Object_FindStatus failed: %X", objectId);
    return NULL;
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s16 bankIndex) {
    if (bankIndex < OBJECT_EXCHANGE_BANK_MAX) {
        return (objectCtx->status[bankIndex].id > 0);
    }

    // CitraPrint("Object_IsLoaded");
    return (rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id >= 0);
}

void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    ObjectStatus* obj = Object_FindStatus(&gGlobalContext->objectCtx, objectId);
    if (obj != NULL) {
        return ZAR_GetCMABByIndex(&obj->zarInfo, objectAnimIdx);
    }

    return NULL;
}
