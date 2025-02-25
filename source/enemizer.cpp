#include "../../code/include/actor_id.h"
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

    CitraPrint("Randomizing Enemies");
    for (auto& scene : Enemizer::enemyLocations) {
        for (auto& layer : scene.second) {
            for (auto& room : layer.second) {
                for (auto& entry : room.second) {
                    AssignRandomEnemy(entry.second);
                }
            }
        }
    }
    CitraPrint("Randomized Enemies");
}

} // namespace Enemizer
