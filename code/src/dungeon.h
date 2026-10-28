#ifndef _DUNGEON_H_
#define _DUNGEON_H_

#include "z3D/z3D.h"

#include "s_dungeon.h"

extern u32 rDungeonRewardOverrides[DUNGEON_REWARDS_COUNT];

u8 Dungeon_KeyAmount(DungeonId id);
u8 Dungeon_FoundSmallKeys(DungeonId id);

#endif //_DUNGEON_H_
