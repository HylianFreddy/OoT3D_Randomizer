#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "z3D/z3D.h"

extern Actor* gRunningActor;

void Actor_Init();
void ActorSetup_Extra();
s32 Actor_CollisionATvsAC(Collider* at, Collider* ac);
s32 Actor_IsBoss(Actor* actor);
void Actor_ReinitSkelAnime(SkelAnime* anime, Actor* actor);

#endif //_ACTOR_H_
