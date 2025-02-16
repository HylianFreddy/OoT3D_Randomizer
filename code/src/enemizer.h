#ifndef _ENEMIZER_H_
#define _ENEMIZER_H_

#include "../include/z3D/z3D.h"

typedef struct EnemyData {
    u16 actorId;
    u16 params;
} EnemyData;

typedef struct EnemyObjectDependency {
    u16 actorId;
    u16 objectId;
} EnemyObjectDependency;

void Enemizer_OverrideActorEntry(ActorEntry* entry);

#endif // _ENEMIZER_H_
