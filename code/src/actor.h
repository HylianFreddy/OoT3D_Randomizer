#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "z3D/z3D.h"

void Actor_Init();
void ActorSetup_Extra();
s32 Actor_CollisionATvsAC(Collider* at, Collider* ac);
void Actor_SetEnemySoulFlag(s16 actorId);
u8 Actor_GetEnemySoulFlag(s16 actorId);

enum {
    DEKU_BABA = 0x55,
} ActorId;

#endif //_ACTOR_H_
