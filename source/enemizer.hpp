#pragma once

#include "location_access.hpp"

namespace Enemizer {

// Conditions used for the logic to place enemies.
enum class LocationType {
    ABOVE_GROUND, // Location is on or above walkable ground.
    ABOVE_VOID,   // Location is over a pit.
    UNDERWATER,   // Location is underwater - generally an enemy that requires hookshot + iron boots.
    ABOVE_WATER,  // Location is in the air above a water surface.
};

// Enemy requirements to pass to the patch to edit the ActorEntry at runtime.
enum class EnemyRequirement {
    ON_GROUND,        // Ground-based enemy that doesn't work in mid-air, it should be spawned at ground level.
    AT_WATER_SURFACE, // Water-based enemy that doesn't work in mid-air, it should be spawned at water surface.
    IN_MID_AIR,       // Flying enemy that doesn't work at ground level, it should be spawned up in the air.
};

class Enemy {
    public:
    Enemy(std::string _name, u16 _actorId, u16 _params, ConditionFn _killLogic,
          std::vector<LocationType> _validLocationTypes)
        : name(std::move(_name)), actorId(std::move(_actorId)), params(std::move(_params)),
          killLogic(std::move(_killLogic)), validLocationTypes(std::move(_validLocationTypes)) {
    }

    std::string name;
    u16 actorId;
    u16 params;
    // std::string filter_func;
    ConditionFn killLogic;
    std::vector<LocationType> validLocationTypes;
    // std::vector<LocationType> acceptableLocationConditions;
    // std::vector<LocationType> requiredLocationConditions;
    // std::string weight;
    // std::string drop_logic;
    // std::string soulName;
};

} // namespace Enemizer
