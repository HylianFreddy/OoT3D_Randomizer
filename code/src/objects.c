#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include "3ds/svc.h"
#include <stddef.h>

/* TODO:
Object_Spawn is already synchronous, it waits for the object to load before returning.
Find equivalent of func_800982FC from oot and use that to load asynchronously on room change (enemies / ice traps / ...)
Always keep custom assets object loaded in slot 1: reimplement Object_Clear and only delete other objects
*/

static ExtendedObjectContext rExtendedObjectCtx = { 0 };

s32 ExtendedObject_Spawn(s16 objectId) {
    return Object_Spawn(&rExtendedObjectCtx, objectId) + OBJECT_EXCHANGE_BANK_MAX;
}

void ExtendedObject_Clear(void) {
    Object_Clear(gGlobalContext, &rExtendedObjectCtx);
}

void ExtendedObject_UpdateBank(void) {
    Object_UpdateBank(&rExtendedObjectCtx);
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

ObjectStatus* Object_GetStatus(s16 bankIndex) {
    // CitraPrint("Object_GetStatus: %X %X", bankIndex,
    //            rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id);
    if (bankIndex >= OBJECT_EXCHANGE_BANK_MAX) {
        return &rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX];
    }
    if (bankIndex >= 0) {
        return &gGlobalContext->objectCtx.status[bankIndex];
    }
    // CitraPrint("Object_GetStatus failed: %X", objectId);
    return NULL;
}

ObjectStatus* Object_FindOrSpawn(s16 objectId) {
    // CitraPrint("Object_FindOrSpawn %X", objectId);
    ObjectStatus* obj;
    s32 bankIndex = Object_GetIndex(&gGlobalContext->objectCtx, objectId);
    if (bankIndex >= 0) {
        if (bankIndex >= OBJECT_EXCHANGE_BANK_MAX) {
            obj = &rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX];
        } else {
            obj = &gGlobalContext->objectCtx.status[bankIndex];
        }
        // Wait for the object to be loaded. TODO: this gets stuck infinitely, find another way?
        // while (obj->id <= 0) {
        //     CitraPrint("Object_FindOrSpawn: waiting for object 0x%X...", objectId);
        //     svcSleepThread(1000 * 1000LL); // Sleep 1 ms
        // }
        return obj;
    } else {
        // CitraPrint("Object_FindOrSpawn failed, trying to spawn object 0x%X...", objectId);
        bankIndex = Object_Spawn(&rExtendedObjectCtx, objectId);
        return &rExtendedObjectCtx.status[bankIndex];
    }
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s16 bankIndex) {
    if (bankIndex < OBJECT_EXCHANGE_BANK_MAX) {
        return (objectCtx->status[bankIndex].id > 0);
    }

    // CitraPrint("Object_IsLoaded %X", rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id);
    return (rExtendedObjectCtx.status[bankIndex - OBJECT_EXCHANGE_BANK_MAX].id > 0);
}

void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    ObjectStatus* obj = Object_FindOrSpawn(objectId);
    return ZAR_GetCMABByIndex(&obj->zarInfo, objectAnimIdx);
}
