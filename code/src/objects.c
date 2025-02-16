#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include "models.h"
#include "custom_models.h"
#include <stddef.h>

static ExtendedObjectContext rExtendedObjectCtx = { 0 };

static s32 ExtendedObject_Spawn(s16 objectId) {
    return Object_Spawn(&rExtendedObjectCtx, objectId) + OBJECT_SLOT_MAX;
}

void ExtendedObject_UpdateEntries(void) {
    Object_UpdateEntries(&rExtendedObjectCtx);
}

s32 ExtendedObject_GetSlot(s16 objectId) {
    for (s32 i = 0; i < rExtendedObjectCtx.numEntries; ++i) {
        s32 id = ABS(rExtendedObjectCtx.slots[i].id);
        if (id == objectId) {
            return i + OBJECT_SLOT_MAX;
        }
    }
    return -1;
}

void ExtendedObject_Reset(void) {
    Object_Clear(gGlobalContext, &rExtendedObjectCtx);
    Actor_KillAllWithMissingObject(gGlobalContext, &gGlobalContext->actorCtx);
    Model_DestroyAll();
    // Even though the custom tunics depend on this object, everything seems to still work
    // if it's reloaded immediately so that it's always in the first slot.
    ExtendedObject_Spawn(OBJECT_CUSTOM_GENERAL_ASSETS);
}

ObjectEntry* Object_GetEntry(s16 slot) {
    if (slot >= OBJECT_SLOT_MAX) {
        return &rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX];
    }
    if (slot >= 0) {
        return &gGlobalContext->objectCtx.slots[slot];
    }
    return NULL;
}

ObjectEntry* Object_FindOrSpawnEntry(s16 objectId) {
    ObjectEntry* obj;
    s32 slot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (slot >= 0) {
        if (slot >= OBJECT_SLOT_MAX) {
            obj = &rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX];
        } else {
            obj = &gGlobalContext->objectCtx.slots[slot];
        }
        return obj;
    } else {
        slot = Object_Spawn(&rExtendedObjectCtx, objectId);
        return &rExtendedObjectCtx.slots[slot];
    }
}

s32 Object_FindOrSpawnSlot(s16 objectId) {
    s32 objectSlot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (objectSlot < 0) {
        objectSlot = ExtendedObject_Spawn(objectId);
    }
    return objectSlot;
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s16 slot) {
    if (slot < OBJECT_SLOT_MAX) {
        return (objectCtx->slots[slot].id > 0);
    }

    return (rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX].id > 0);
}

void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    ObjectEntry* obj = Object_FindOrSpawnEntry(objectId);
    return ZAR_GetCMABByIndex(&obj->zarInfo, objectAnimIdx);
}
