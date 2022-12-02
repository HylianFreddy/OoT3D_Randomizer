#ifndef _GFX_H_
#define _GFX_H_

#include "3ds/types.h"

extern u32 pressed;
extern bool handledInput;

#define ADDITIONAL_FLAG_BUTTON rInputCtx.cur.r
extern u32 value;

void Gfx_Init(void);
void Gfx_Update(void);
extern void Debug_MemoryEditor();
extern void MemoryEditor_EditAddress();
extern void MemoryEditor_EditValue();
extern bool MemoryEditor_ConfirmPermissionOverride();
extern void pushHistory(u32 addr);
void MemoryEditor_GoToPreset(void);
void MemoryEditor_FollowPointer(void);

#endif //_GFX_H_
