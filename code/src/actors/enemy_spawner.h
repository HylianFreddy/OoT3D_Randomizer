#ifndef _ENEMY_SPAWNER_H_
#define _ENEMY_SPAWNER_H_

#include "z3D/z3D.h"

struct EnEncount1;

typedef void (*EnEncount1UpdateFunc)(struct EnEncount1*, GlobalContext*);

typedef struct EnEncount1 {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ EnEncount1UpdateFunc updateFunc;
    /* 0x1A8 */ s16 maxCurSpawns;
    /* 0x1AA */ s16 curNumSpawn;
    /* 0x1AC */ s16 spawnType;
    /* 0x1AE */ s16 maxTotalSpawns;
    /* 0x1B0 */ s16 totalNumSpawn;
    /* 0x1B2 */ s16 outOfRangeTimer;
    /* 0x1B4 */ s16 fieldSpawnTimer;
    /* 0x1B6 */ s16 killCount;
    /* 0x1B8 */ s16 numLeeverSpawns;
    /* 0x1BA */ s16 leeverIndex;
    /* 0x1BC */ s16 timer;
    /* 0x1BE */ u8 reduceLeevers;
    /* 0x1C0 */ f32 spawnRange;
    /* 0x1C4 */ struct EnReeba* bigLeever;
    /* 0x1C8 */ void* unk_1C8;
} EnEncount1;
_Static_assert(sizeof(EnEncount1) == 0x1CC, "EnEncount1 size");

#endif //_ENEMY_SPAWNER_H_
