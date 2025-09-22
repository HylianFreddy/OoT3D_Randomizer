#include "z3D/z3D.h"
#include "objects.h"
#include "common.h"
#include "models.h"
#include "custom_models.h"
#include "3ds/svc.h"
#include "oot_malloc.h"
#include "enemizer.h"
#include "effects.h"

#include <stddef.h>

/* TODO:
Object_Spawn is already synchronous, it waits for the object to load before returning.
Find equivalent of func_800982FC from oot and use that to load asynchronously on room change (enemies / ice traps / ...)
Always keep custom assets object loaded in slot 1: reimplement Object_Clear and only delete other objects

keep track of persistent objects. on room change clear others like in Object_Clear.
when spawning persistent, shift all non-persistent ones.
add function to spawn new non-persistent object (adding slot with negative objId).
*/

#define EXTENDED_OBJECT_SLOT_MAX 30

// Copy of ObjectContext with more object slots.
typedef struct ExtendedObjectContext {
    /* 0x000 */ u8 numEntries;           // total amount of used entries
    /* 0x001 */ u8 numPersistentEntries; // amount of entries that won't be reused when loading a new room
    /* 0x002 */ u8 unused_02;
    /* 0x003 */ u8 unused_03;
    /* 0x004 */ ObjectEntry slots[EXTENDED_OBJECT_SLOT_MAX];
} ExtendedObjectContext;

static ExtendedObjectContext rExtendedObjectCtx = { 0 };

void ExtendedObject_UpdateEntries(void) {
    Object_UpdateEntries((ObjectContext*)&rExtendedObjectCtx);
}

void ExtendedObject_Clear(void) {
    CitraPrint("ExtendedObject_Clear");
    Object_Clear(gGlobalContext, (ObjectContext*)&rExtendedObjectCtx);
}

// Copy of Object_Clear but only for non-persistent objects.
void ExtendedObject_ClearNonPersistent(void) {
    // CitraPrint("ExtendedObject_ClearNonPersistent enter %d", rExtendedObjectCtx.numPersistentEntries);
    for (s32 i = rExtendedObjectCtx.numPersistentEntries; i < OBJECT_SLOT_MAX; i++) {
        ObjectEntry* entry = &rExtendedObjectCtx.slots[i];
        if (entry->id > 0) {
            // CitraPrint("deleting object %X", entry->id);
            if (entry->size != 0) {
                ZAR_Destroy(&entry->zarInfo);
                entry->size = 0;
            }
            SystemArena_Free(entry->buf);
            entry->buf = NULL;
            entry->id  = 0;
        }
    }
    rExtendedObjectCtx.numEntries = rExtendedObjectCtx.numPersistentEntries;
}

void ExtendedObject_AfterObjectListCommand(void) {
    CitraPrint("ExtendedObject_AfterObjectListCommand");
    if (gGlobalContext->state.running == 1) { // Loading scene
        // Spawn objects that will not unload on room transitions.
        // Note: Player_Init has already run by this point, so whatever objects it
        // spawned in the extended context will also be marked as persistent here.
        CitraPrint("_ persistent start", rExtendedObjectCtx.numEntries);
        Object_FindSlotOrSpawn(OBJECT_CUSTOM_GENERAL_ASSETS);
        Object_FindSlotOrSpawn(3); // zelda_dangeon_keep (main dungeon object)
        CitraPrint("_ persistent end", rExtendedObjectCtx.numEntries);
        rExtendedObjectCtx.numPersistentEntries = rExtendedObjectCtx.numEntries;
    }
}

// Called from Scene_CommandObjectList, after the object slots from the vanilla ObjectContext
// have been invalidated and before new ones get loaded.
void ExtendedObject_InvalidateRoomObjects(void) {
    if (gGlobalContext->state.running == 2) { // Loading room
        ExtendedObject_ClearNonPersistent();
        Actor_KillAllWithMissingObject(gGlobalContext, &gGlobalContext->actorCtx);
        EffectSs_ClearAllWithMissingObject();
        Model_DestroyAll();
    }
}

s32 ExtendedObject_GetSlot(s16 objectId) {
    // CitraPrint("ExtendedObject_GetSlot: %X", objectId);
    for (s32 i = 0; i < rExtendedObjectCtx.numEntries; ++i) {
        s32 id = ABS(rExtendedObjectCtx.slots[i].id);
        if (id == objectId) {
            return i + OBJECT_SLOT_MAX;
        }
    }
    // CitraPrint("Missing object slot! objectId=%X", objectId);
    return -1;
}

ObjectEntry* Object_GetEntry(s16 slot) {
    // CitraPrint("Object_GetEntry: %X %X", slot,
    //            rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX].id);
    if (slot >= OBJECT_SLOT_MAX) {
        return &rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX];
    }
    if (slot >= 0) {
        return &gGlobalContext->objectCtx.slots[slot];
    }
    // CitraPrint("Object_GetEntry failed: %X", objectId);
    return NULL;
}

ObjectEntry* Object_FindEntryOrSpawn(s16 objectId) {
    // CitraPrint("Object_FindEntryOrSpawn %X", objectId);
    ObjectEntry* obj;
    s32 slot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (slot >= 0) {
        if (slot >= OBJECT_SLOT_MAX) {
            obj = &rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX];
        } else {
            obj = &gGlobalContext->objectCtx.slots[slot];
        }
        // Wait for the object to be loaded. TODO: this gets stuck infinitely, find another way?
        // while (obj->id <= 0) {
        //     CitraPrint("Object_FindEntryOrSpawn: waiting for object 0x%X...", objectId);
        //     svcSleepThread(1000 * 1000LL); // Sleep 1 ms
        // }
        return obj;
    } else {
        // CitraPrint("Object_FindEntryOrSpawn failed, trying to spawn object 0x%X...", objectId);
        slot = Object_Spawn((ObjectContext*)&rExtendedObjectCtx, objectId);
        CitraPrint("spawned %X, obj count %d, persistent count %d", objectId, rExtendedObjectCtx.numEntries,
                   rExtendedObjectCtx.numPersistentEntries);
        return &rExtendedObjectCtx.slots[slot];
    }
}

s32 Object_FindSlotOrSpawn(s16 objectId) {
    s32 objectSlot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (objectSlot < 0) {
        objectSlot = Object_Spawn((ObjectContext*)&rExtendedObjectCtx, objectId) + OBJECT_SLOT_MAX;
        CitraPrint("spawned %X, obj count %d, persistent count %d", objectId, rExtendedObjectCtx.numEntries,
                   rExtendedObjectCtx.numPersistentEntries);
    }
    return objectSlot;
}

static s16 Object_GetIdFromSlot(ObjectContext* objectCtx, s16 slot) {
    if (slot < OBJECT_SLOT_MAX) {
        return objectCtx->slots[slot].id;
    }

    // CitraPrint("Object_GetIdFromSlot %X", rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX].id);
    return rExtendedObjectCtx.slots[slot - OBJECT_SLOT_MAX].id;
}

s32 Object_IsLoaded(ObjectContext* objectCtx, s16 slot) {
    return Object_GetIdFromSlot(objectCtx, slot) > 0;
}

// Overrides a function used only at the beginning of Cutscene_SetupScripted.
// It's a copy of Object_IsLoaded that returns true even if id == 0.
s32 Object_IsLoaded_ForCutscenes(ObjectContext* objectCtx, s16 slot) {
    return Object_GetIdFromSlot(objectCtx, slot) >= 0;
}

void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx) {
    ObjectEntry* obj = Object_FindEntryOrSpawn(objectId);
    return ZAR_GetCMABByIndex(&obj->zarInfo, objectAnimIdx);
}

#include "draw.h"
void Object_DrawDebugInfo(void) {
    for (u32 i = 0; i < gGlobalContext->objectCtx.numEntries; i++) {
        s16 id = gGlobalContext->objectCtx.slots[i].id;
        if (id > 0) {
            Draw_DrawFormattedStringTop(10, 15 + 10 * i, COLOR_WHITE, "obj slot %d, id 0x%X", i, id);
        }
    }

    for (u32 i = 0; i < rExtendedObjectCtx.numEntries; i++) {
        s16 id = rExtendedObjectCtx.slots[i].id;
        if (id > 0) {
            Draw_DrawFormattedStringTop(150, 15 + 10 * i, COLOR_WHITE, "ext obj slot %d, id 0x%X", i, id);
        }
    }
}
