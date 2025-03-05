#include "z3D/z3D.h"
#include "settings.h"
#include "enemizer.h"

void EnemySpawner_OverrideSpawnedActor(s16* actorId, s16* params) {
    if (gSettingsContext.enemizer == OFF) {
        return;
    }

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
