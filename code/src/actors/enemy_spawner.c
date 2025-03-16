#include "enemy_spawner.h"
#include "settings.h"
#include "enemizer.h"
#include "common.h"
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
            Actor* spawnedEnemy = this->spawnedEnemies[i];
            if (spawnedEnemy != NULL && !(spawnedEnemy->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) &&
                spawnedEnemy->xzDistToPlayer > 1000.0) {
                Actor_Kill(spawnedEnemy);
            }
        }

        // Remove enemies from the array if they've been killed (either by the loop above or by something else).
        // Also decrease the spawner's counter, unless the enemy already handles it in its own destroy function.
        for (s32 i = 0; i < ARRAY_SIZE(this->spawnedEnemies); i++) {
            Actor* spawnedEnemy = this->spawnedEnemies[i];
            if (spawnedEnemy != NULL && spawnedEnemy->update == NULL && spawnedEnemy->draw == NULL) {
                if (this->curNumSpawn > 0 && spawnedEnemy->id != ACTOR_STALCHILD && spawnedEnemy->id != ACTOR_LEEVER &&
                    spawnedEnemy->id != ACTOR_TEKTITE && spawnedEnemy->id != ACTOR_WOLFOS) {
                    this->curNumSpawn--;
                }
                if (spawnedEnemy->colChkInfo.health == 0) {
                    this->rDefeatCount++;
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
                    enemy->gravity               = -1.3;
                    break;
            }

            enemy = enemy->next;
            i++;
        }

        // Handle delay between spawning swarms.
        if (this->spawnType == SPAWNER_LEEVER) {
            this->killCount = 0; // This will be handled with a custom field so base game actors can't mess with it.
            if (this->rDefeatCount >= 10) {
                // this->rTimer = 450; // Like base game when a big leever spawns
                this->rTimer       = 900; // Like base game when a big leever is defeated
                this->rDefeatCount = 0;
            }
            if (this->rTimer > 0) {
                this->rTimer--;
            }
            this->timer = this->rTimer;
        }
        CitraPrint("this->timer=%d", this->timer);
    }
}
