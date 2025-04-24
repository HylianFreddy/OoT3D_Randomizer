#include "enemizer.hpp"
#include "logic.hpp"

namespace Logic {

enum class SpaceAroundEnemy {
    WIDE,
    NARROW,
    NONE,
};

bool IsWallmaster(u8 scene, u8 layer, u8 room, u8 actorEntry);
bool CanDefeatEnemy(u16 enemyId);
bool CanDefeatEnemy(u8 scene, u8 layer, u8 room, u8 actorEntry);
bool CanDefeatEnemies(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {});
bool CanPassEnemy(u8 scene, u8 layer, u8 room, u8 actorEntry, SpaceAroundEnemy space = SpaceAroundEnemy::WIDE);
bool CanPassEnemies(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {},
                    SpaceAroundEnemy space = SpaceAroundEnemy::WIDE);
bool CanPassAnyEnemy(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {},
                     SpaceAroundEnemy space = SpaceAroundEnemy::WIDE);
bool CanHookEnemy(u8 scene, u8 layer, u8 room, u8 actorEntry);
bool CanDetonateEnemy(u8 scene, u8 layer, u8 room, u8 actorEntry);
bool CanDetonateAnyEnemy(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {});
bool CanGetDekuBabaSticks(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {});
bool CanGetDekuBabaNuts(u8 scene, u8 layer, u8 room, std::vector<u8> actorEntries = {});

} // namespace Logic
