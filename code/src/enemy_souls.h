#ifndef _ENEMYSOULS_H_
#define _ENEMYSOULS_H_

#include "s_enemy_souls.h"

#include "z3D/z3D.h"

EnemySoulId EnemySouls_GetSoulId(s16 actorId);
u8 EnemySouls_GetSoulFlag(EnemySoulId soulId);
void EnemySouls_OnCollect(EnemySoulId soulId);
u8 EnemySouls_CheckSoulForActor(Actor* actor);
u8 EnemySouls_ShouldDrawSoulless(Actor* actor);
void EnemySouls_DrawEffects(void);
void SoullessDarkness_ModifyCmb(CmbManager* cmbMan, s16 objectId, s32 cmbIdx /*to delete*/);
u8 SoullessDarkness_RestoreCmb(CmbManager* cmbMan, s16 objectId);

#endif //_ENEMYSOULS_H_
