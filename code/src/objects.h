#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "z3D/z3D.h"

typedef s32 (*Object_proc)(ObjectContext* objectCtx, s16 objectId);

#define Object_Spawn ((Object_proc)GAME_ADDR(0x32E21C))

#define Object_GetIndex ((Object_proc)GAME_ADDR(0x363C10))

typedef void (*Object_UpdateBank_proc)(ObjectContext* objectCtx);
#define Object_UpdateBank ((Object_UpdateBank_proc)GAME_ADDR(0x2E4EA0))

typedef void (*Object_Clear_proc)(GlobalContext* globalCtx, ObjectContext* objectCtx);
#define Object_Clear ((Object_Clear_proc)GAME_ADDR(0x45FDA0))

typedef void* (*ZAR_Get_proc)(ZARInfo* zarInfo, u32 index);
#define ZAR_GetCMBByIndex ((ZAR_Get_proc)GAME_ADDR(0x358EF8))

#define ZAR_GetCMABByIndex ((ZAR_Get_proc)GAME_ADDR(0x372F0C))

typedef void (*TexAnim_Spawn_proc)(void*, void*);
#define TexAnim_Spawn ((TexAnim_Spawn_proc)GAME_ADDR(0x372D94))

typedef ObjectContext ExtendedObjectContext;

extern ExtendedObjectContext rExtendedObjectCtx;

// Find an ObjectStatus given the objectId.
ObjectStatus* Object_FindStatus(ObjectContext* objectCtx, s16 objectId);
// Check if the object in the `bankIndex` slot is loaded.
s32 Object_IsLoaded(ObjectContext* objectCtx, s16 bankIndex);
// Get the CMAB manager from this object.
void* Object_GetCMABByIndex(s16 objectId, u32 objectAnimIdx);

// Spawn a new object in the randomizer's extended object context.
s32 ExtendedObject_Spawn(s16 objectId);

#endif //_OBJECTS_H_
