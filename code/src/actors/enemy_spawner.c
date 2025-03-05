#include "enemy_spawner.h"
#include "settings.h"
#include "enemizer.h"
#include "common.h"
#include "actor_id.h"

// #define EnEncount1_Init ((ActorFunc)GAME_ADDR(0x229994))
#define EnEncount1_Update ((ActorFunc)GAME_ADDR(0x2682D0))
// #define EnEncount1_Destroy ((ActorFunc)GAME_ADDR(0x229B50))

void EnemySpawner_OverrideSpawnedActor(s16* actorId, s16* params) {
    if (gSettingsContext.enemizer == OFF) {
        return;
    }

    // CitraPrint("EnemySpawner_OverrideSpawnedActor");
    EnemyOverride enemyOverride = Enemizer_GetSpawnerOverride();

    if (enemyOverride.actorId == 0) {
        return;
    }

    if (actorId != NULL) {
        *actorId = enemyOverride.actorId;
    }
    if (params != NULL) {
        *params = enemyOverride.params;
    }
}

// void EnEncount1_rInit(Actor* thisx, GlobalContext* globalCtx) {
//     EnEncount1_Init(thisx, globalCtx);
// }

// void EnEncount1_rDestroy(Actor* thisx, GlobalContext* globalCtx) {
//     EnEncount1_Destroy(thisx, globalCtx);
// }

void EnEncount1_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount1* this       = (EnEncount1*)thisx;
    Actor* prevEnemiesHead = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;

    EnEncount1_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON) {
        // Remove killed enemies from `spawnedEnemies`
        for (s32 i = 0; i < ARRAY_SIZE(this->spawnedEnemies); i++) {
            if (this->spawnedEnemies[i] != NULL && this->spawnedEnemies[i]->update == NULL &&
                this->spawnedEnemies[i]->draw == NULL) {
                CitraPrint("removing enemy %X, idx=%d, prevnum=%d", this->spawnedEnemies[i], i, this->curNumSpawn);
                if (this->curNumSpawn > 0 && this->spawnedEnemies[i]->id != ACTOR_STALCHILD &&
                    this->spawnedEnemies[i]->id != ACTOR_LEEVER && this->spawnedEnemies[i]->id != ACTOR_TEKTITE &&
                    this->spawnedEnemies[i]->id != ACTOR_WOLFOS) {
                    this->curNumSpawn--;
                }
                this->spawnedEnemies[i] = NULL;
            }
        }

        // Add newly spawned enemies
        Actor* enemy   = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;
        s32 spawnedIdx = 0;
        while (enemy != prevEnemiesHead && spawnedIdx < ARRAY_SIZE(this->spawnedEnemies)) {
            if (this->spawnedEnemies[spawnedIdx] != NULL) {
                spawnedIdx++;
                continue;
            }
            this->spawnedEnemies[spawnedIdx] = enemy;
            CitraPrint("adding enemy %X, idx=%d, num=%d", enemy, spawnedIdx, this->curNumSpawn);

            enemy = enemy->next;
            spawnedIdx++;
        }

        // Detect if the spawned enemies are too far from player
        for (s32 i = 0; i < ARRAY_SIZE(this->spawnedEnemies); i++) {
            if (this->spawnedEnemies[i] != NULL &&
                !(this->spawnedEnemies[i]->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) &&
                this->spawnedEnemies[i]->xzDistToPlayer > 1000.0) {
                CitraPrint("killing enemy %X, idx=%d, num=%d", this->spawnedEnemies[i], i, this->curNumSpawn);
                Actor_Kill(this->spawnedEnemies[i]);
                this->spawnedEnemies[i] = NULL;
                if (this->curNumSpawn > 0) {
                    this->curNumSpawn--;
                }
            }
        }
    }
}
