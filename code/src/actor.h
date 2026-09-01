#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "z3D/z3D.h"

// Helper struct to manage custom information for each actor instance
// by storing it inside padding bytes of the main Actor struct.
typedef struct ExtraActorFields {
    /* 0x000 */ char _padding[0x01A];
    // padding at end of `PosRot home`
    /* 0x01A */ Bool representsActorEntry;
    /* 0x01B */ u8 actorEntryIndex;
} ExtraActorFields;

// Actor whose init or update function is currently running
extern Actor* gRunningActor;
extern Bool gActorsHidden;

void Actor_Init();
void ActorSetup_Extra();
s32 Actor_CollisionATvsAC(Collider* at, Collider* ac);
s32 Actor_IsBoss(Actor* actor);
void Actor_ReinitSkelAnime(Actor* actor, SkelAnime* anime, s32 cmbIndex);

#endif //_ACTOR_H_
