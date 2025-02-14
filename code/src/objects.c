#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include "custom_models.h"
#include "3ds/svc.h"
#include <stddef.h>

/* TODO:
Object_Spawn is already synchronous, it waits for the object to load before returning.
Find equivalent of func_800982FC from oot and use that to load asynchronously on room change (enemies / ice traps / ...)
Always keep custom assets object loaded in slot 1: reimplement Object_Clear and only delete other objects
*/

static ExtendedObjectContext rExtendedObjectCtx = { 0 };

s32 ExtendedObject_Spawn(s16 objectId) {
    return Object_Spawn(&rExtendedObjectCtx, objectId) + OBJECT_SLOT_MAX;
}

void ExtendedObject_Clear(void) {
    Object_Clear(gGlobalContext, &rExtendedObjectCtx);
}

void ExtendedObject_UpdateEntries(void) {
    Object_UpdateEntries(&rExtendedObjectCtx);
}

s32 ExtendedObject_GetSlot(s16 objectId) {
    // CitraPrint("ExtendedObject_GetSlot: %X", objectId);
    for (s32 i = 0; i < rExtendedObjectCtx.numEntries; ++i) {
        s32 id = ABS(rExtendedObjectCtx.status[i].id);
        if (id == objectId) {
            return i + OBJECT_SLOT_MAX;
        }
    }
    return -1;
}

ObjectEntry* Object_GetEntry(s16 slot) {
    // CitraPrint("Object_GetEntry: %X %X", slot,
    //            rExtendedObjectCtx.status[slot - OBJECT_SLOT_MAX].id);
    if (slot >= OBJECT_SLOT_MAX) {
        return &rExtendedObjectCtx.status[slot - OBJECT_SLOT_MAX];
    }
    if (slot >= 0) {
        return &gGlobalContext->objectCtx.status[slot];
    }
    // CitraPrint("Object_GetEntry failed: %X", objectId);
    return NULL;
}

ObjectEntry* Object_FindOrSpawnEntry(s16 objectId) {
    // CitraPrint("Object_FindOrSpawnEntry %X", objectId);
    ObjectEntry* obj;
    s32 slot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (slot >= 0) {
        if (slot >= OBJECT_SLOT_MAX) {
            obj = &rExtendedObjectCtx.status[slot - OBJECT_SLOT_MAX];
        } else {
            obj = &gGlobalContext->objectCtx.status[slot];
        }
        // Wait for the object to be loaded. TODO: this gets stuck infinitely, find another way?
        // while (obj->id <= 0) {
        //     CitraPrint("Object_FindOrSpawnEntry: waiting for object 0x%X...", objectId);
        //     svcSleepThread(1000 * 1000LL); // Sleep 1 ms
        // }
        return obj;
    } else {
        // CitraPrint("Object_FindOrSpawnEntry failed, trying to spawn object 0x%X...", objectId);
        slot = Object_Spawn(&rExtendedObjectCtx, objectId);
        return &rExtendedObjectCtx.status[slot];
    }
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s16 slot) {
    if (slot < OBJECT_SLOT_MAX) {
        return (objectCtx->status[slot].id > 0);
    }

    // CitraPrint("Object_IsLoaded %X", rExtendedObjectCtx.status[slot - OBJECT_SLOT_MAX].id);
    return (rExtendedObjectCtx.status[slot - OBJECT_SLOT_MAX].id > 0);
}

void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    ObjectEntry* obj = Object_FindOrSpawnEntry(objectId);
    return ZAR_GetCMABByIndex(&obj->zarInfo, objectAnimIdx);
}
