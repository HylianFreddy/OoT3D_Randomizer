#include "enemy_spawner.h"
#include "settings.h"
#include "enemizer.h"
#include "actor.h"
#include "shabom.h"
#include "gohma.h"
#include "dodongos.h"

void EnEncount1_Init(Actor* thisx, GlobalContext* globalCtx);
void EnEncount1_Update(Actor* thisx, GlobalContext* globalCtx);

void EnemySpawner_OverrideSpawnedActor(EnEncount1* this, s16* actorId, s16* params) {
    if (gSettingsContext.enemizer == OFF || this->rExt.spawnedActorId == 0) {
        return;
    }

    if (actorId != NULL) {
        *actorId = this->rExt.spawnedActorId;
    }
    if (params != NULL) {
        *params = this->rExt.spawnedActorParams;
    }
}

void EnEncount1_rInit(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount1* this = (EnEncount1*)thisx;

    EnEncount1_Init(thisx, globalCtx);

    EnemyOverride enemyOverride   = Enemizer_GetSpawnerOverride();
    this->rExt.spawnedActorId     = gEnemyTable[enemyOverride.enemyId].actorId;
    this->rExt.spawnedActorParams = gEnemyTable[enemyOverride.enemyId].possibleParams[enemyOverride.paramsIdx];

    if (this->rExt.spawnedActorId == ACTOR_STALFOS) {
        // Only use "rising from ground" stalfos type, and not the "falling from above" type.
        this->rExt.spawnedActorParams = 0x0002;
    }
}

void EnEncount1_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnEncount1* this       = (EnEncount1*)thisx;
    Actor* prevEnemiesHead = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;

    EnEncount1_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON && this->rExt.spawnedActorId != 0) {
        // Kill spawned enemies that are culled and far away from the player.
        for (s32 i = 0; i < ARRAY_SIZE(this->rExt.spawnedEnemies); i++) {
            Actor* spawnedEnemy = this->rExt.spawnedEnemies[i];
            if (spawnedEnemy != NULL && !(spawnedEnemy->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) &&
                spawnedEnemy->xzDistToPlayer > 1000.0) {
                Actor_Kill(spawnedEnemy);
            }
        }

        // Remove enemies from the array if they've been killed (either by the loop above or by something else).
        for (s32 i = 0; i < ARRAY_SIZE(this->rExt.spawnedEnemies); i++) {
            Actor* spawnedEnemy = this->rExt.spawnedEnemies[i];
            if (spawnedEnemy != NULL && spawnedEnemy->update == NULL && spawnedEnemy->draw == NULL) {
                // Decrease the spawner's counter, unless the enemy already handles it in its own destroy function.
                if (this->curNumSpawn > 0 && spawnedEnemy->id != ACTOR_STALCHILD && spawnedEnemy->id != ACTOR_LEEVER &&
                    spawnedEnemy->id != ACTOR_TEKTITE && spawnedEnemy->id != ACTOR_WOLFOS) {
                    this->curNumSpawn--;
                }
                // Increase kill counter if enemy is dead.
                if (spawnedEnemy->colChkInfo.health == 0 ||
                    (spawnedEnemy->id == ACTOR_BABY_DODONGO &&
                     ((EnDodojr*)spawnedEnemy)->actionFunc == EnDodojr_DropItem) ||
                    (spawnedEnemy->id == ACTOR_SHABOM && ((EnBubble*)spawnedEnemy)->actionFunc == EnBubble_Pop)) {
                    this->rExt.killCount++;
                }
                this->rExt.spawnedEnemies[i] = NULL;
            }
        }

        // Add newly spawned enemies from this update cycle
        Actor* enemy = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;
        s32 i        = 0;
        while (enemy != prevEnemiesHead && i < ARRAY_SIZE(this->rExt.spawnedEnemies)) {
            if (this->rExt.spawnedEnemies[i] != NULL) {
                i++;
                continue;
            }
            this->rExt.spawnedEnemies[i] = enemy;
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
            // The kill count is handled with a custom field so base game actors can't mess with it.
            // Keep the base field at 0 so the spawner won't try to spawn a big leever.
            this->killCount = 0;
            // Use different delay and required kill count for easy and hard enemies.
            s16 delaySeconds  = 30;
            s16 requiredKills = 10;
            if (this->rExt.spawnedActorId == ACTOR_STALFOS ||
                (this->rExt.spawnedActorId == ACTOR_LEEVER && this->rExt.spawnedActorParams == 1)) {
                delaySeconds  = 60;
                requiredKills = 5;
            }
            if (this->rExt.killCount >= requiredKills) {
                this->rExt.delayTimer = delaySeconds * 30;
                this->rExt.killCount  = 0;
            }
            // Wait for all spawned enemies to despawn before starting the countdown.
            if (this->curNumSpawn == 0 && this->rExt.delayTimer > 0) {
                this->rExt.delayTimer--;
            }
            this->timer = this->rExt.delayTimer;
        }
    }

    Bool swarmDefeated = this->curNumSpawn == 0 && this->timer > 100;
    if (gSettingsContext.enemyPermadeath == ON && swarmDefeated) {
        ExtraActorFields* actorExtras     = (ExtraActorFields*)this;
        actorExtras->representsActorEntry = TRUE;
        actorExtras->actorEntryIndex      = 0xFF;
        Actor_Kill(thisx);
    }
}
