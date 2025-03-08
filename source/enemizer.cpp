#include "enemizer.hpp"
#include "random.hpp"

namespace Enemizer {

void AssignRandomEnemy(EnemyLocation& loc) {
    std::vector<EnemyType> enemyOptions;
    for (EnemyType& candidate : enemyTypes) {
        if (std::find(candidate.validLocationTypes.begin(), candidate.validLocationTypes.end(), loc.type) !=
            candidate.validLocationTypes.end()) {
            enemyOptions.push_back(candidate);
        }
    }
    loc.randomizedEnemy  = RandomElement(enemyOptions);
    loc.randomizedParams = RandomElement(loc.randomizedEnemy.possibleParams);
}

void RandomizeEnemies() {
    EnemyLocations_Init();

    for (auto& scene : enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    AssignRandomEnemy(entry.second);
                }
            }
        }
    }
    AddDuplicateLocations();
}

void FillPatchOverrides(std::vector<EnemyOverride>& enemyOverrides) {
    for (auto& scene : enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    if (entry.second.randomizedEnemy.actorId != 0) {
                        EnemyOverride ovr;
                        ovr.scene      = scene.first;
                        ovr.layer      = layer.first;
                        ovr.room       = room.first;
                        ovr.actorEntry = entry.first;
                        ovr.actorId    = entry.second.randomizedEnemy.actorId;
                        ovr.params     = entry.second.randomizedParams;
                        enemyOverrides.push_back(ovr);
                    }
                }
            }
        }
    }

    std::sort(enemyOverrides.begin(), enemyOverrides.end(),
              [](const EnemyOverride& a, const EnemyOverride& b) { return a.key < b.key; });

    if (enemyOverrides.size() > ENEMY_OVERRIDES_MAX) {
        printf("ENEMIZER ERROR!");
        CitraPrint("ENEMIZER ERROR: Too many Enemy Overrides (" + std::to_string(enemyOverrides.size()) + ")");
        enemyOverrides.clear();
    }
}

} // namespace Enemizer
