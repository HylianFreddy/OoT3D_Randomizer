#include "../../code/include/actor_id.h"
#include "enemizer.hpp"
#include "dungeon.hpp"

namespace Enemizer {

EnemyLocationsMap enemyLocations = {};

// clang-format off
std::vector<EnemyType> enemyTypes = {
    EnemyType("Poe", ACTOR_POE, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Stalfos", ACTOR_STALFOS, { 0x0002, 0x0003 }, // rises from ground / drops from above when approached
        { LocationType::ABOVE_GROUND }),
    EnemyType("Octorok", ACTOR_OCTOROK, { 0x0000 },
        { LocationType::ABOVE_WATER }),
    EnemyType("Wallmaster", ACTOR_WALLMASTER, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::ABOVE_WATER }),
    EnemyType("Dodongo", ACTOR_DODONGO, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Keese", ACTOR_KEESE, { 0x0002 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Fire Keese", ACTOR_KEESE, { 0x0001 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::ABOVE_WATER }),
    EnemyType("Ice Keese", ACTOR_KEESE, { 0x0004 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Tektite (Red)", ACTOR_TEKTITE, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Tektite (Blue)", ACTOR_TEKTITE, { 0xFFFE },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER }),
    // EnemyType("Leever", ACTOR_LEEVER, {0x0000},
    //  {LocationType::ABOVE_GROUND}),
    EnemyType("Peahat", ACTOR_PEAHAT, { 0xFFFF },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER }),
    EnemyType("Peahat Larva", ACTOR_PEAHAT, { 0x0001 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Lizalfos", ACTOR_LIZALFOS, { 0xFF80, 0xFFFF }, // normal / drops from above when approached
        { LocationType::ABOVE_GROUND }),
    EnemyType("Dinolfos", ACTOR_LIZALFOS, { 0xFFFE },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Gohma Larva", ACTOR_GOHMA_LARVA, { 0x0000, 0x0007 }, // egg that drops and hatches / normal egg
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Shabom", ACTOR_SHABOM, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Baby Dodongo", ACTOR_BABY_DODONGO, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Biri", ACTOR_BIRI, { 0xFFFF },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Tailpasaran", ACTOR_TAILPASARAN, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Skulltula", ACTOR_SKULLTULA, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Big Skulltula", ACTOR_SKULLTULA, { 0x0001 },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    EnemyType("Torch Slug", ACTOR_TORCH_SLUG, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Stinger (Floor)", ACTOR_STINGER_FLOOR, { 0x000A },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Moblin (Club)", ACTOR_MOBLIN, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Moblin (Spear)", ACTOR_MOBLIN, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Armos", ACTOR_ARMOS, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Deku Baba", ACTOR_DEKU_BABA, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Big Deku Baba", ACTOR_DEKU_BABA, { 0x0001 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Mad Scrub", ACTOR_MAD_SCRUB, { 0x0100, 0x0300, 0x0500 }, // shoots 1, 3 or 5 nuts in a row
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Bari", ACTOR_BARI, { 0xFFFF },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Blue Bubble", ACTOR_BUBBLE, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Fire Bubble", ACTOR_BUBBLE, { 0xFFFE },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Green Bubble", ACTOR_BUBBLE, { 0x02FC },
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::ABOVE_WATER }),
    EnemyType("Flying Floor Tile", ACTOR_FLYING_FLOOR_TILE, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Beamos", ACTOR_BEAMOS, { 0x0500, 0x0501 }, // big / small
        { LocationType::ABOVE_GROUND }),
    EnemyType("Floormaster", ACTOR_FLOORMASTER, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Redead", ACTOR_REDEAD, { 0x7F01, 0x7F02 }, // standing / crouching
        { LocationType::ABOVE_GROUND }),
    EnemyType("Gibdo", ACTOR_REDEAD, { 0x7FFE },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Dead Hand's Hand", ACTOR_DEAD_HAND_HAND, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Skullwalltula", ACTOR_SKULLWALLTULA, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER}),
    EnemyType("Flare Dancer", ACTOR_FLARE_DANCER, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Shell Blade", ACTOR_SHELL_BLADE, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Whithered Deku Baba", ACTOR_WITHERED_DEKU_BABA, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Like Like", ACTOR_LIKE_LIKE, { 0x0000 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Spike", ACTOR_SPIKE, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Anubis Spawner", ACTOR_ANUBIS_SPAWNER, { 0x0003 },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Iron Knuckle", ACTOR_IRON_KNUCKLE, { 0xFF01, 0xFF02, 0xFF03 }, // silver / black / white
        { LocationType::ABOVE_GROUND }),
    EnemyType("Skull Kid", ACTOR_SKULL_KID, { 0xFFFF },
        { LocationType::ABOVE_GROUND }),
    EnemyType("Flying Pot", ACTOR_FLYING_POT, { 0x0000 },
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Freezard", ACTOR_FREEZARD, { 0x0000, 0xFFFF }, // normal / appears and moves when approached
        { LocationType::ABOVE_GROUND, LocationType::UNDERWATER }),
    EnemyType("Stinger (Water)", ACTOR_STINGER_WATER, { 0x0000 },
        { LocationType::UNDERWATER }),
    EnemyType("Wolfos", ACTOR_WOLFOS, { 0xFF00, 0xFF01 }, // normal / white
        { LocationType::ABOVE_GROUND }),
    EnemyType("Stalchild", ACTOR_STALCHILD, { 0x0000, 0x0005 }, // normal / big (20 kills)
        { LocationType::ABOVE_GROUND }),
    EnemyType("Guay", ACTOR_GUAY, { 0x0000, 0x0001 }, // normal / big
        { LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID, LocationType::UNDERWATER, LocationType::ABOVE_WATER }),
    // EnemyType("Dark Link", ACTOR_DARK_LINK, {0x0000},
    //  {LocationType::ABOVE_GROUND}),
    // EnemyType("Dead Hand", ACTOR_DEAD_HAND, {0x0000},
    //  {LocationType::ABOVE_GROUND}),
};
// clang-format on

void AddDuplicateLocations(void) {
    // Peahats in Hyrule Field should stay the same enemies in OoT layer
    enemyLocations[81][1][0][4]  = enemyLocations[81][0][0][8];
    enemyLocations[81][1][0][5]  = enemyLocations[81][0][0][9];
    enemyLocations[81][1][0][6]  = enemyLocations[81][0][0][10];
    enemyLocations[81][1][0][7]  = enemyLocations[81][0][0][11];
    enemyLocations[81][1][0][8]  = enemyLocations[81][0][0][12];
    enemyLocations[81][1][0][9]  = enemyLocations[81][0][0][13];
    enemyLocations[81][1][0][10] = enemyLocations[81][0][0][14];

    // Enemies in Graveyard as adult should stay the same at night
    // enemyLocations[83][3][1][2]  = enemyLocations[83][2][1][2];
    // enemyLocations[83][3][1][3]  = enemyLocations[83][2][1][3];
    // enemyLocations[83][3][1][4]  = enemyLocations[83][2][1][4];
    // enemyLocations[83][3][1][5]  = enemyLocations[83][2][1][5];
    // enemyLocations[83][3][1][6]  = enemyLocations[83][2][1][6];
    // enemyLocations[83][3][1][7]  = enemyLocations[83][2][1][7];
    // enemyLocations[83][3][1][8]  = enemyLocations[83][2][1][8];
    enemyLocations[83][3][1][12] = enemyLocations[83][2][1][12];
    enemyLocations[83][3][1][13] = enemyLocations[83][2][1][13];
    enemyLocations[83][3][1][14] = enemyLocations[83][2][1][14];
}

void EnemyLocations_Init(void) {
    enemyLocations.clear();

    // Overworld locations
    enemyLocations[10][0][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][0][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][2][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][2][6]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][4][1]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][4][2]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][7][7]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[15][0][0][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[23][0][1][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][5]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][6]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][7]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][2][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][2][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][4][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][5][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[62][0][7][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][7][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][8][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][8][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][0][10][2] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[62][0][13][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[63][0][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][1][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][1][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][1][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][3][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][3][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][3][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][3][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[72][0][2][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][0][2][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][0][3][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][0][3][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][8]  = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][9]  = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][10] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][11] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][12] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][13] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][14] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][7]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    // enemyLocations[83][2][1][8]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[83][2][1][12] = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
    enemyLocations[83][2][1][13] = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
    enemyLocations[83][2][1][14] = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
    enemyLocations[84][0][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][0][42] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[84][0][0][43] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[84][2][0][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][6]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][7]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][8]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][2][0][9]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[85][0][1][1]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][1][2]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][1][3]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][1][4]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][1][5]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[85][2][0][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[85][2][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][4]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][5]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][6]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][7]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][8]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][9]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][0][10] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][2]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][6]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][2][1][7]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][5]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][6]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][7]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][8]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][9]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][10] = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][5]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][6]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][7]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][8]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][9]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][2][0][10] = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][0][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][19] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][20] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][21] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[87][2][0][15] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_WATER);
    enemyLocations[87][2][0][16] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_WATER);
    enemyLocations[87][2][0][17] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_WATER);
    enemyLocations[87][2][0][18] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_WATER);
    enemyLocations[87][2][0][22] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][23] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][24] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][25] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][26] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][27] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][28] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][2][0][29] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][18] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][2][0][19] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][2][0][20] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][2][0][21] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][2][0][24] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][25] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][26] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][27] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][28] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][2][0][50] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[90][2][0][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][2][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][2][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][2][0][6]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][2][0][7]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][0][3][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][2][1][1]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[91][2][1][2]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[91][2][3][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][2][9][1]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][7]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][8]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][9]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][2][0][7]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][2][0][8]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][2][0][9]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][2][0][10] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][2][0][11] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][6]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][7]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][8]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][9]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][10] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][11] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][12] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][6]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][7]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][2][0][8]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[97][2][1][8]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
    enemyLocations[97][2][1][9]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
    enemyLocations[97][2][1][10] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
    enemyLocations[97][2][1][11] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
    enemyLocations[97][2][1][12] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
    enemyLocations[99][1][0][10] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][11] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][12] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][13] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][14] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][15] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][16] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][17] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][18] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][19] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][20] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][21] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][22] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][23] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][1][0][24] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);

    // Vanilla dungeons
    if (Dungeon::DekuTree.IsVanilla()) {
        enemyLocations[0][0][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][11] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][12] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][13] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][5][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][1]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][5]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][6]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][7]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][0] = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][4] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::DodongosCavern.IsVanilla()) {
        enemyLocations[1][0][0][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][2]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][3]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][4]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][5]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][6]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][7]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][0]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][1]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][2]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][0]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][1]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][2]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][7][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][7][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][1] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][2] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][3] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][11][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][11][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][11][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][14][0] = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][15][0] = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::JabuJabusBelly.IsVanilla()) {
        enemyLocations[2][0][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][0][1]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][0][3]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][4]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][1][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][1][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][1]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][2]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][5]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][6]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][4][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][5][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][5]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][6][0]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][6][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][0]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][1]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][2]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][3]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][4]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][8][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][8][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][8][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][8][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][9][0]   = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][9][1]   = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][9][2]   = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][2]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][3]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][4]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][5]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][6]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][7]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][8]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][9]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][13][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][14][0]  = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][1]  = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][2]  = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][11] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][12] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][13] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][14] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][15] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][16] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ForestTemple.IsVanilla()) {
        enemyLocations[3][0][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][1][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][3][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][4][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][5][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][6][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][6][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[3][0][7][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[3][0][8][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][10][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][11][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][11][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][11][2] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][17][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][18][0] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][19][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_VOID);
        enemyLocations[3][0][20][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][20][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][20][2] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_VOID);
        enemyLocations[3][0][21][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][21][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::FireTemple.IsVanilla()) {
        enemyLocations[4][0][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][1]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][5]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][8]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][11]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][12]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][13]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][14]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][15]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][16]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][17]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][1][22]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][3][0]   = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][4][0]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][4][3]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][4]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][6]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][11]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][10][14] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][10][25] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][10][44] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][13][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][13][8]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][13][9]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][7]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][5]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][7]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][16][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][16][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][16][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][16][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][16][4]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][1]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][2]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][3]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][4]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][5]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][1]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][2]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][3]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][4]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][5]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][6]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][7]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][8]  = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][21][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][21][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][21][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][21][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][24][0]  = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::WaterTemple.IsVanilla()) {
        // Idk why these exist
        // enemyLocations[5][0][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        // enemyLocations[5][0][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][4]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][0][5]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][0][12] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][13] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][2][0]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][1]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][2]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][3]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][4]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][5]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][2][6]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][0][3][0]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][0][3][2]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][3][3]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][4][1]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::UNDERWATER);
        enemyLocations[5][0][4][2]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::UNDERWATER);
        enemyLocations[5][0][4][3]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::UNDERWATER);
        enemyLocations[5][0][4][4]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::UNDERWATER);
        enemyLocations[5][0][5][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][5][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][1]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][0][6][2]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][0][6][3]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][4]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][5]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][0][8][2]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][8][3]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][9][0]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][10][1] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][0] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][3] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][4] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][5] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][6] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][7] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][12][8] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][0] = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][1] = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][2] = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][3] = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][4] = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][15][0] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][15][1] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][0] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][1] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][2] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][0] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][1] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][2] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][3] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::SpiritTemple.IsVanilla()) {
        enemyLocations[6][0][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][2]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][12]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][13]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][2][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][2][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][2][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][2][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][2][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][2][6]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][3][0]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][3]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][3][4]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][3][5]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][0]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][1]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][2]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][3]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][4]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][5]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][19]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][20]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][4]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][5]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][6]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][10][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][14][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][0]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][1]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][2]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][11] = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][12] = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][16][0]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][0]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][1]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][2]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][3]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][18][0]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][18][1]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][18][2]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        // Leave one armos so we can press the switch
        // enemyLocations[6][0][18][3] =  EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND );
        enemyLocations[6][0][20][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][22][10] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][22][11] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][22][12] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][22][13] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][4]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][5]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][4]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][5]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][6]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][7]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][8]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][25][9]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][4]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][27][0]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ShadowTemple.IsVanilla()) {
        enemyLocations[7][0][0][5]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][2][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][5][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][7][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][7][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][1]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[7][0][9][2]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][5]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][12]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][11][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][11][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][15][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][15][1]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][17][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][18][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][4]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][5]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][13] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][14] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::BottomOfTheWell.IsVanilla()) {
        enemyLocations[8][0][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][4]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][5]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][33] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][13] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][14] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][2][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][4]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][5][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][5][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][0][5][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][0][5][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][0][6][0]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][2]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][3]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][4]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::IceCavern.IsVanilla()) {
        enemyLocations[9][0][1][1]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][1][10] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][1][11] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][1][12] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][3][11] = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][6][17] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][6][18] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][7][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][8][8]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][4]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][13] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][14] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GerudoTrainingGrounds.IsVanilla()) {
        enemyLocations[11][0][1][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][1][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][2][4]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][2][5]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][2]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][4]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][5]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][6][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[11][0][6][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[11][0][7][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][13] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][9][4]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][0][9][5]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][0][9][6]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][0][9][7]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][0][10][0] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][1] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][2] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GanonsCastle.IsVanilla()) {
        enemyLocations[13][0][0][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][1]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][3][6]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][5][0]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][1]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][8][11]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][7]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][8]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][9]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][10][1]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[13][0][12][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][4]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][5]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][6]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][7]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][17][10] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][6]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][7]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][18] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][20] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][22] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
    }

    // MQ dungeons
    if (Dungeon::DekuTree.IsMQ()) {
        enemyLocations[0][0][0][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][1]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][4]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][10]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][11]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][22]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][0][23]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][1][3]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][1][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][1][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][2][0]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][2][1]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][2][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][2][13]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][2][14]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][6]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][7]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][3][8]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][4][4]   = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][4][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][4][6]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][4][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][5][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][5][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][5][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][3]   = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][4]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][6]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][8]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][6][11]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][6]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][7][7]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][2]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][8]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][8][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][6]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][7]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][8]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][9]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][10] = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][0][10][11] = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::DodongosCavern.IsMQ()) {
        enemyLocations[1][0][1][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][5]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][1][6]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][1]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][7]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][2][8]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][1]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][2]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][3]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][3][4]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][0]   = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][1]   = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][4][2]   = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][4]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][5]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][5][6]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][6][1]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][6][2]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][6][3]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][6][4]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][6][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][7][0]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][7][1]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][2]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][3]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][4]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][5]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][6]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][13]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][14]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][8][15]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][8]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][9]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][10][10] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][12][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][12][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][13][2]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][13][3]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][13][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][14][1]  = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][15][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][15][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][15][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][15][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::JabuJabusBelly.IsMQ()) {
        enemyLocations[2][0][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][7]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][8]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][9]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][1][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][1][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][1][16]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][2][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][3][10]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][4][7]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][4]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][5][3]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][6][0]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][7][0]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][11][5]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][11][6]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][1]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][2]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][3]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][9]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][12][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][5]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][13][6]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][0]  = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][1]  = EnemyLocation(ACTOR_STINGER_FLOOR, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][14][4]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ForestTemple.IsMQ()) {
        enemyLocations[3][0][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][1][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][1][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][1][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][5][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][6][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][6][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][7][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][5]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][8][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][10][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][11][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][11][2] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][4] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][5] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][15][6] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][17][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][17][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][18][0] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][19][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][20][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][20][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][20][2] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][21][0] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::FireTemple.IsMQ()) {
        enemyLocations[4][0][3][0]  = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][4][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][6]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][8]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][9]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][10] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][5][11] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][7][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][7][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][14][3] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][15][3] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][17][2] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][0] = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][1] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][2] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][3] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][4] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][18][5] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][0] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][1] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][2] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][3] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][4] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][5] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][6] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][19][7] = EnemyLocation(ACTOR_FLYING_FLOOR_TILE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][24][0] = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][25][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::WaterTemple.IsMQ()) {
        enemyLocations[5][0][2][1]  = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][3][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][3][6]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][2]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][3]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][6][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][10][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][1] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][2] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][3] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][4] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][5] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][6] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][14][7] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][16][1] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][0] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][1] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][18][2] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][0] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][1] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][19][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][20][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][20][1] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::SpiritTemple.IsMQ()) {
        enemyLocations[6][0][1][0]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][1]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][1][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][2][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][2][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][2][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][3][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][0][3][12]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][0]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][1]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][2]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][3]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][4]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][4][11]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][0]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][1]   = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][18]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][19]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][20]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][5][22]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][2]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][3]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][4]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][18]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][8][20]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][9][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][10][5]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][12][8]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][13][1]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][2]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][7]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][9]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][15][11] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][17][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][18][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][18][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][19][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][20][5]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][21][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][22][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][23][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][0]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][6]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][26][7]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][27][7]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ShadowTemple.IsMQ()) {
        enemyLocations[7][0][0][6]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][0][7]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][0][8]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][0][9]   = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][1][3]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][5][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][6][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][6][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][6][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][6][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][7][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][7][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][2]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][8][3]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][5]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][6]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][7]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][9][10]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][11][8]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][11][9]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][13][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][14][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][15][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][15][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][15][2]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][16][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][18][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][19][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][5]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][20][6]  = EnemyLocation(ACTOR_FLYING_POT, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][16] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][0][21][17] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::BottomOfTheWell.IsMQ()) {
        enemyLocations[8][0][0][0] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][1] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][3] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][4] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][4] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][5] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][6] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][7] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][8] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][1][9] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][2][0] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][2][1] = EnemyLocation(ACTOR_POE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][3][1] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][6][4] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::IceCavern.IsMQ()) {
        enemyLocations[9][0][1][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][1][1]   = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][1][2]   = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][3][5]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][3][6]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][3][7]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][3]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][4]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][5][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][6][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][6][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][7][3]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][8][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][8][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][9][5]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][11] = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][12] = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][0][11][13] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GerudoTrainingGrounds.IsMQ()) {
        enemyLocations[11][0][1][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][2][0]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][2][17] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][2][21] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][3][8]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][5][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][6][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][6][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][6][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][3]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][4]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][7][5]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][9][0]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][9][1]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][9][3]  = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][9][4]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][0] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][1] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][2] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][3] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][0][10][4] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GanonsCastle.IsMQ()) {
        enemyLocations[13][0][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][2]   = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][9]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][10]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][0]   = EnemyLocation(ACTOR_DEAD_HAND_HAND, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][2]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][2][3]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][3][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][3][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][3][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][3][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][5][1]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][5][2]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][8]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][9]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][10]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][11]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][12]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][6][13]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][8][3]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][6]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][7]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][9][8]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][10][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][5]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][12][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][14][16] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][17][9]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][17][10] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][17][11] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][17][12] = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][6]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][7]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][8]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][9]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][10] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][18][24] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
    }
}

} // namespace Enemizer
