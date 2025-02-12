#ifndef _ENEMIZER_H_
#define _ENEMIZER_H_

#include "../include/z3D/z3D.h"

typedef struct EnemyData {
    u16 actorId;
    u16 params;
    u16 objectId;
} EnemyData;

#define ENEMY_DATA_SIZE 31
extern EnemyData sEnemyData[ENEMY_DATA_SIZE];

#endif // _ENEMIZER_H_
