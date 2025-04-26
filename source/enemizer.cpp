#include "enemizer.hpp"
#include "random.hpp"
#include "settings.hpp"

namespace Enemizer {

static void AssignRandomEnemy(EnemyLocation& loc) {
    std::vector<u16> enemyOptions;
    for (u16 enemyId = ENEMY_INVALID + 1; enemyId < ENEMY_MAX; enemyId++) {
        EnemyType& candidate = enemyTypes[enemyId];
        if (enemyId == loc.vanillaEnemyId || candidate.CanBeAtLocTypes(loc.types)) {
            enemyOptions.push_back(enemyId);
        }
    }
    if (enemyOptions.size() > 0) {
        loc.randomizedEnemyId = RandomElement(enemyOptions);
        loc.randomizedParams  = RandomElement(enemyTypes[loc.randomizedEnemyId].possibleParams);
    }
}

void RandomizeEnemies() {
    InitEnemyLocations();

    if (!Settings::Enemizer) {
        return;
    }

    CitraPrint("___________________");
    CitraPrint("Randomizing Enemies...");
    s32 ovrCount = 0;
    for (auto& scene : enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    ovrCount++;
                    AssignRandomEnemy(entry.second);
                }
            }
        }
    }
    CitraPrint("Enemy loc count = " + std::to_string(ovrCount));
    AddDuplicateLocations();
    CitraPrint("Enemies randomization complete!");
}

void FillPatchOverrides(std::vector<EnemyOverride>& enemyOverrides) {
    s32 ovrCount = 0;
    for (auto& scene : enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    ovrCount++;
                }
            }
        }
    }
    CitraPrint("Enemy loc count = " + std::to_string(ovrCount));
    CitraPrint("Filling enemy overrides...");
    for (auto& scene : enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    EnemyType& enemyType = enemyTypes[entry.second.randomizedEnemyId];
                    if (enemyType.actorId != 0) {
                        EnemyOverride ovr;
                        ovr.scene      = scene.first;
                        ovr.layer      = layer.first;
                        ovr.room       = room.first;
                        ovr.actorEntry = entry.first;
                        ovr.actorId    = enemyType.actorId;
                        ovr.params     = entry.second.randomizedParams;
                        enemyOverrides.push_back(ovr);
                    }
                }
            }
        }
    }

    CitraPrint("Sorting enemy overrides...");
    std::sort(enemyOverrides.begin(), enemyOverrides.end(),
              [](const EnemyOverride& a, const EnemyOverride& b) { return a.key < b.key; });

    if (enemyOverrides.size() > ENEMY_OVERRIDES_MAX) {
        printf("ENEMIZER ERROR!");
        CitraPrint("ENEMIZER ERROR: Too many Enemy Overrides (" + std::to_string(enemyOverrides.size()) + ")");
        enemyOverrides.clear();
    }

    CitraPrint("Enemy overrides done!");
    // CitraPrint("enemyOverrides[0]" + std::to_string(enemyOverrides[0].key));
    // CitraPrint("enemyOverrides[1]" + std::to_string(enemyOverrides[1].key));
    CitraPrint("enemyLocations[15][0][0][4] is " + (enemyTypes[enemyLocations[15][0][0][4].randomizedEnemyId].name));
    // CitraPrint("OVR 0 " + std::to_string(enemyOverrides[0].scene) + " " + std::to_string(enemyOverrides[0].layer) +
    //            " " + std::to_string(enemyOverrides[0].room) + " " + std::to_string(enemyOverrides[0].actorEntry) +
    //            " " + std::to_string(enemyOverrides[0].actorId) + " " + std::to_string(enemyOverrides[0].params));
    // CitraPrint("OVR 1 " + std::to_string(enemyOverrides[1].scene) + " " + std::to_string(enemyOverrides[1].layer) +
    //            " " + std::to_string(enemyOverrides[1].room) + " " + std::to_string(enemyOverrides[1].actorEntry) +
    //            " " + std::to_string(enemyOverrides[1].actorId) + " " + std::to_string(enemyOverrides[1].params));
}

} // namespace Enemizer
