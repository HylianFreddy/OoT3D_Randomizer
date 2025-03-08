#pragma once

#include "../code/src/enemizer.h"

#include <string>
#include <functional>

#include "debug.hpp"

namespace Enemizer {

// Conditions used for the logic to place enemies.
enum class LocationType {
    ABOVE_GROUND, // Location is on or above walkable ground.
    ABOVE_VOID,   // Location is over a void plane. Enemy must be able to fly.
    UNDERWATER,   // Location is underwater. Enemy must be defeatable with hookshot and iron boots.
    ABOVE_WATER,  // Location is in the air above a water surface. Enemy must be able to float or fly.
    SPAWNER,      // Location is a grounded enemy spawner (stalchildren, leevers)
};

class EnemyType {
  public:
    EnemyType() = default;
    EnemyType(std::string _name, u16 _actorId, std::vector<u16> _possibleParams,
              std::vector<LocationType> _validLocationTypes)
        : name(std::move(_name)), actorId(_actorId), possibleParams(_possibleParams),
          validLocationTypes(std::move(_validLocationTypes)) {
    }

    std::string name;
    u16 actorId;
    std::vector<u16> possibleParams; // Values to randomly select as actor params, without affecting the logic.
    std::vector<LocationType> validLocationTypes;
};

class EnemyLocation {
  public:
    EnemyLocation() = default;
    EnemyLocation(u16 _vanillaActorId, LocationType _type) : vanillaActorId(_vanillaActorId), type(std::move(_type)) {
    }

    u16 vanillaActorId;
    LocationType type;
    EnemyType randomizedEnemy;
    u16 randomizedParams;
};

using EnemyLocationsMap_Room  = std::unordered_map<u8, EnemyLocation>;
using EnemyLocationsMap_Layer = std::unordered_map<u8, EnemyLocationsMap_Room>;
using EnemyLocationsMap_Scene = std::unordered_map<u8, EnemyLocationsMap_Layer>;
using EnemyLocationsMap       = std::unordered_map<u8, EnemyLocationsMap_Scene>;

// Possible enemies to choose from for randomization.
extern std::vector<EnemyType> enemyTypes;
// Map of enemy locations that will be randomized. Indices are [scene][layer][room][actorEntry].
// To override dynamic enemy spawners, actorEntry is set to 0xFF.
extern EnemyLocationsMap enemyLocations;

void EnemyLocations_Init(void);
void AddDuplicateLocations(void);
void RandomizeEnemies(void);
void FillPatchOverrides(std::vector<EnemyOverride>& enemyOverrides);

} // namespace Enemizer
