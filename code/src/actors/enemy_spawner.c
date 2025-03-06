#include "enemy_spawner.h"
#include "settings.h"
#include "enemizer.h"
#include "common.h"
#include "actor_id.h"
#include "shabom.h"
#include "gohma.h"

#define EnEncount1_Update ((ActorFunc)GAME_ADDR(0x2682D0))

void EnemySpawner_OverrideSpawnedActor(s16* actorId, s16* params) {
    if (gSettingsContext.enemizer == OFF) {
        return;
    }

    EnemyOverride enemyOverride = Enemizer_GetSpawnerOverride();

    if (enemyOverride.actorId == 0) {
        return;
    }

    if (enemyOverride.actorId == ACTOR_STALFOS) {
        // Only use "rising from ground" stalfos type, and not the "falling from above" type.
        enemyOverride.params = 0x0002;
    }

    if (actorId != NULL) {
        *actorId = enemyOverride.actorId;
    }
    if (params != NULL) {
        *params = enemyOverride.params;
    }
}

void EnEncount1_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount1* this       = (EnEncount1*)thisx;
    Actor* prevEnemiesHead = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;

    EnEncount1_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON) {
        // Kill spawned enemies that are culled and far away from the player.
        for (s32 i = 0; i < ARRAY_SIZE(this->spawnedEnemies); i++) {
            if (this->spawnedEnemies[i] != NULL &&
                !(this->spawnedEnemies[i]->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) &&
                this->spawnedEnemies[i]->xzDistToPlayer > 1000.0) {
                Actor_Kill(this->spawnedEnemies[i]);
            }
        }

        // Remove enemies from the array if they've been killed (either by the loop above or by something else).
        // Also decrease the spawner's counter, unless the enemy already handles it in its own destroy function.
        for (s32 i = 0; i < ARRAY_SIZE(this->spawnedEnemies); i++) {
            if (this->spawnedEnemies[i] != NULL && this->spawnedEnemies[i]->update == NULL &&
                this->spawnedEnemies[i]->draw == NULL) {
                if (this->curNumSpawn > 0 && this->spawnedEnemies[i]->id != ACTOR_STALCHILD &&
                    this->spawnedEnemies[i]->id != ACTOR_LEEVER && this->spawnedEnemies[i]->id != ACTOR_TEKTITE &&
                    this->spawnedEnemies[i]->id != ACTOR_WOLFOS) {
                    this->curNumSpawn--;
                }
                this->spawnedEnemies[i] = NULL;
            }
        }

        // Add newly spawned enemies from this update cycle
        Actor* enemy = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;
        s32 i        = 0;
        while (enemy != prevEnemiesHead && i < ARRAY_SIZE(this->spawnedEnemies)) {
            if (this->spawnedEnemies[i] != NULL) {
                i++;
                continue;
            }
            this->spawnedEnemies[i] = enemy;
            switch (enemy->id) {
                case ACTOR_SHABOM:
                    ((EnBubble*)enemy)->actionFunc = EnBubble_Disappear;
                    break;
                case ACTOR_GOHMA_LARVA:
                    ((EnGoma*)enemy)->actionFunc = EnGoma_SetupHatch;
                    enemy->gravity = -1.3;
                    break;
            }

            enemy = enemy->next;
            i++;
        }
    }
}
