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

    CitraPrint("___________________");
    CitraPrint("Randomizing Enemies...");
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
    CitraPrint("Enemies randomization complete!");
}

void FillPatchOverrides(std::vector<EnemyOverride>& enemyOverrides) {
    CitraPrint("Filling enemy overrides...");
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

    CitraPrint("Sorting enemy overrides...");
    std::sort(enemyOverrides.begin(), enemyOverrides.end(), [](const EnemyOverride& a, const EnemyOverride& b) {
        return a.key < b.key;
    });

    CitraPrint("Enemy overrides done!");
    // CitraPrint("enemyOverrides[0]" + std::to_string(enemyOverrides[0].key));
    // CitraPrint("enemyOverrides[1]" + std::to_string(enemyOverrides[1].key));
    CitraPrint("enemyLocations[15][0][0][4] is " + (enemyLocations[15][0][0][4].randomizedEnemy.name));
    // CitraPrint("OVR 0 " + std::to_string(enemyOverrides[0].scene) + " " + std::to_string(enemyOverrides[0].layer) +
    //            " " + std::to_string(enemyOverrides[0].room) + " " + std::to_string(enemyOverrides[0].actorEntry) +
    //            " " + std::to_string(enemyOverrides[0].actorId) + " " + std::to_string(enemyOverrides[0].params));
    // CitraPrint("OVR 1 " + std::to_string(enemyOverrides[1].scene) + " " + std::to_string(enemyOverrides[1].layer) +
    //            " " + std::to_string(enemyOverrides[1].room) + " " + std::to_string(enemyOverrides[1].actorEntry) +
    //            " " + std::to_string(enemyOverrides[1].actorId) + " " + std::to_string(enemyOverrides[1].params));
}

} // namespace Enemizer
