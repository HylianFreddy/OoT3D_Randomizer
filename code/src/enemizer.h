#ifndef _ENEMIZER_H_
#define _ENEMIZER_H_

#include "../include/z3D/z3D.h"

#define ENEMY_OVERRIDES_MAX 700

#define REQ_ON_GROUND (1 << 0)
#define REQ_ABOVE_GROUND (1 << 1)
#define REQ_ABOVE_GROUND_IN_AIR (1 << 2)
#define REQ_WATER (1 << 3)
#define REQ_WATER_SURFACE (1 << 4)
#define REQ_NO_WATER (1 << 5)
#define REQ_FLYING (1 << 6)

typedef struct EnemyData {
    u16 actorId;
    u16 params;
    u8 requirements;
} EnemyData;

typedef struct EnemyParams {
    u16 actorId;
    u16 params;
} EnemyParams;

typedef struct EnemyObjectDependency {
    u16 actorId;
    u16 objectId;
    u16 actorParams;
    u8 requiresParams;
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
