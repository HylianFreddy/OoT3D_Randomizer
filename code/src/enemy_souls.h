#ifndef _ENEMYSOULS_H_
#define _ENEMYSOULS_H_

#include "s_enemy_souls.h"

#include "z3D/z3D.h"

extern u8 SoullessModels_CmbRestoreRequest;

EnemySoulId EnemySouls_GetSoulId(s16 actorId);
u8 EnemySouls_GetSoulFlag(EnemySoulId soulId);
void EnemySouls_OnCollect(EnemySoulId soulId);
u8 EnemySouls_CheckSoulForActor(Actor* actor);
u8 EnemySouls_ShouldDrawSoulless(Actor* actor);
void EnemySouls_Update(void);
void SoullessModels_ModifyCmb(CmbManager* cmbMan, s32 newTexMapCount, s32 matToSkip);
u8 SoullessModels_RestoreCmb(CmbManager* cmbMan, s32 matToSkip);

#endif //_ENEMYSOULS_H_
