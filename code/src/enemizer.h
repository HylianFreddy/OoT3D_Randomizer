#ifndef _ENEMIZER_H_
#define _ENEMIZER_H_

#include "../include/z3D/z3D.h"

#define ENEMY_OVERRIDES_MAX 700

typedef struct EnemyActorData {
    u16 actorId;
    u16 actorParams;
    u8 anyParams;
} EnemyActorData;

typedef struct EnemyObjectDependency {
    EnemyActorData key;
    u16 objectId;
} EnemyObjectDependency;

typedef struct EnemyOverride {
    union {
        s32 key;
        struct {
            u8 actorEntry;
            u8 room;
            u8 layer;
            u8 scene;
        };
    };
    u16 actorId;
    u16 params;
} EnemyOverride;

extern u8 Enemizer_RoomLoadSignal;

void Enemizer_Init(void);
void Enemizer_Update(void);
void Enemizer_OverrideActorEntry(ActorEntry* entry, s32 actorEntryIndex);
void Enemizer_ActorSetupExtra(void);
EnemyOverride Enemizer_GetSpawnerOverride(void);

#endif // _ENEMIZER_H_
