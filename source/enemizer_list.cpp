#include "enemizer.hpp"
#include "dungeon.hpp"

namespace Enemizer {

std::array<EnemyType, ENEMY_MAX> enemyTypes = {};
EnemyLocationsMap enemyLocations            = {};

// clang-format off
void InitEnemyTypes(void) {
    enemyTypes[ENEMY_POE] = EnemyType("Poe", ACTOR_POE, { 0x0000, 0x0002, 0x0003 }, // normal, Sharp, Flat
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER, LocType::SPAWNER });
    enemyTypes[ENEMY_STALFOS] = EnemyType("Stalfos", ACTOR_STALFOS, { 0x0002, 0x0003 }, // rises from ground / drops from above when approached
        { LocType::ABOVE_GROUND, LocType::SPAWNER });
    enemyTypes[ENEMY_OCTOROK] = EnemyType("Octorok", ACTOR_OCTOROK, { 0x0000 },
        { LocType::ABOVE_WATER });
    enemyTypes[ENEMY_WALLMASTER] = EnemyType("Wallmaster", ACTOR_WALLMASTER, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_DODONGO] = EnemyType("Dodongo", ACTOR_DODONGO, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_KEESE_NORMAL] = EnemyType("Keese", ACTOR_KEESE, { 0x0002 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_KEESE_FIRE] = EnemyType("Fire Keese", ACTOR_KEESE, { 0x0001 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_KEESE_ICE] = EnemyType("Ice Keese", ACTOR_KEESE, { 0x0004 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_TEKTITE_RED] = EnemyType("Tektite (Red)", ACTOR_TEKTITE, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_TEKTITE_BLUE] = EnemyType("Tektite (Blue)", ACTOR_TEKTITE, { 0xFFFE },
        { LocType::ABOVE_GROUND, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_LEEVER] = EnemyType("Leever", ACTOR_LEEVER, { 0x0000, 0x0001 }, // normal / big
        { LocType::ABOVE_GROUND, LocType::SPAWNER });
    enemyTypes[ENEMY_PEAHAT] = EnemyType("Peahat", ACTOR_PEAHAT, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_PEAHAT_LARVA] = EnemyType("Peahat Larva", ACTOR_PEAHAT, { 0x0001 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_LIZALFOS] = EnemyType("Lizalfos", ACTOR_LIZALFOS, { 0xFF80, 0xFFFF }, // normal / drops from above when approached
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_DINOLFOS] = EnemyType("Dinolfos", ACTOR_LIZALFOS, { 0xFFFE },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_GOHMA_LARVA] = EnemyType("Gohma Larva", ACTOR_GOHMA_LARVA, { 0x0000, 0x0007 }, // egg that drops and hatches / normal egg
        { LocType::ABOVE_GROUND, LocType::UNDERWATER, LocType::SPAWNER });
    enemyTypes[ENEMY_SHABOM] = EnemyType("Shabom", ACTOR_SHABOM, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER, LocType::ABOVE_WATER, LocType::SPAWNER });
    enemyTypes[ENEMY_DODONGO_BABY] = EnemyType("Baby Dodongo", ACTOR_BABY_DODONGO, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::SPAWNER });
    enemyTypes[ENEMY_DARK_LINK] = EnemyType("Dark Link", ACTOR_DARK_LINK, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_BIRI] = EnemyType("Biri", ACTOR_BIRI, { 0xFFFF },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_TAILPASARAN] = EnemyType("Tailpasaran", ACTOR_TAILPASARAN, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_SKULLTULA] = EnemyType("Skulltula", ACTOR_SKULLTULA, { 0x0000, 0x0001 },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_TORCH_SLUG] = EnemyType("Torch Slug", ACTOR_TORCH_SLUG, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_STINGER_FLOOR] = EnemyType("Stinger (Floor)", ACTOR_STINGER_FLOOR, { 0x000A },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_MOBLIN_CLUB] = EnemyType("Moblin (Club)", ACTOR_MOBLIN, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_MOBLIN_SPEAR] = EnemyType("Moblin (Spear)", ACTOR_MOBLIN, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_ARMOS] = EnemyType("Armos", ACTOR_ARMOS, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_DEKU_BABA_SMALL] = EnemyType("Deku Baba", ACTOR_DEKU_BABA, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_DEKU_BABA_BIG] = EnemyType("Big Deku Baba", ACTOR_DEKU_BABA, { 0x0001 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_MAD_SCRUB] = EnemyType("Mad Scrub", ACTOR_MAD_SCRUB, { 0x0100, 0x0300, 0x0500 }, // shoots 1, 3 or 5 nuts in a row
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_BARI] = EnemyType("Bari", ACTOR_BARI, { 0xFFFF },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_BUBBLE_BLUE] = EnemyType("Blue Bubble", ACTOR_BUBBLE, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_BUBBLE_FIRE] = EnemyType("Fire Bubble", ACTOR_BUBBLE, { 0xFFFE },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_BUBBLE_GREEN] = EnemyType("Green Bubble", ACTOR_BUBBLE, { 0x02FC },
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::ABOVE_WATER });
    enemyTypes[ENEMY_BUBBLE_WHITE] = EnemyType("White Bubble", ACTOR_BUBBLE, { 0x000D },
        { LocType::NEVER });
    enemyTypes[ENEMY_FLYING_FLOOR_TILE] = EnemyType("Flying Floor Tile", ACTOR_FLYING_FLOOR_TILE, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_BEAMOS] = EnemyType("Beamos", ACTOR_BEAMOS, { 0x0500, 0x0501 }, // big / small
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_FLOORMASTER] = EnemyType("Floormaster", ACTOR_FLOORMASTER, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_REDEAD] = EnemyType("Redead", ACTOR_REDEAD, { 0x7F01, 0x7F02 }, // standing / crouching
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_GIBDO] = EnemyType("Gibdo", ACTOR_REDEAD, { 0x7FFE },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_POE_SISTER] = EnemyType("Poe Sister", ACTOR_POE_SISTER, { 0x0000 },
        { LocType::NEVER });
    enemyTypes[ENEMY_DEAD_HAND_HAND] = EnemyType("Dead Hand's Hand", ACTOR_DEAD_HAND_HAND, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_SKULLWALLTULA] = EnemyType("Skullwalltula", ACTOR_SKULLWALLTULA, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER});
    enemyTypes[ENEMY_FLARE_DANCER] = EnemyType("Flare Dancer", ACTOR_FLARE_DANCER, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_DEAD_HAND] = EnemyType("Dead Hand", ACTOR_DEAD_HAND, { 0x0000 },
        { LocType::NEVER });
    enemyTypes[ENEMY_SHELL_BLADE] = EnemyType("Shell Blade", ACTOR_SHELL_BLADE, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_BIG_OCTO] = EnemyType("Big Octo", ACTOR_BIG_OCTO, { 0x0000 },
        { LocType::NEVER });
    enemyTypes[ENEMY_DEKU_BABA_WITHERED] = EnemyType("Withered Deku Baba", ACTOR_WITHERED_DEKU_BABA, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_LIKE_LIKE] = EnemyType("Like Like", ACTOR_LIKE_LIKE, { 0x0000 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_PARASITIC_TENTACLE] = EnemyType("Parasitic Tentacle", ACTOR_PARASITIC_TENTACLE, { 0x0000 },
        { LocType::NEVER });
    enemyTypes[ENEMY_SPIKE] = EnemyType("Spike", ACTOR_SPIKE, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_ANUBIS] = EnemyType("Anubis Spawner", ACTOR_ANUBIS_SPAWNER, { 0x0003 },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_IRON_KNUCKLE] = EnemyType("Iron Knuckle", ACTOR_IRON_KNUCKLE, { 0xFF01, 0xFF02, 0xFF03 }, // silver / black / white
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_SKULL_KID] = EnemyType("Skull Kid", ACTOR_SKULL_KID, { 0xFFFF },
        { LocType::ABOVE_GROUND });
    enemyTypes[ENEMY_FLYING_POT] = EnemyType("Flying Pot", ACTOR_FLYING_POT, { 0x0000 },
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_FREEZARD] = EnemyType("Freezard", ACTOR_FREEZARD, { 0x0000, 0xFFFF }, // normal / appears and moves when approached
        { LocType::ABOVE_GROUND, LocType::UNDERWATER });
    enemyTypes[ENEMY_STINGER_WATER] = EnemyType("Stinger (Water)", ACTOR_STINGER_WATER, { 0x0000 },
        { LocType::UNDERWATER });
    enemyTypes[ENEMY_GERUDO_FIGHTER] = EnemyType("Gerudo Fighter", ACTOR_GERUDO_FIGHTER, { 0x0000 },
        { LocType::NEVER });
    enemyTypes[ENEMY_WOLFOS] = EnemyType("Wolfos", ACTOR_WOLFOS, { 0xFF00, 0xFF01 }, // normal / white
        { LocType::ABOVE_GROUND, LocType::SPAWNER });
    enemyTypes[ENEMY_STALCHILD] = EnemyType("Stalchild", ACTOR_STALCHILD, { 0x0000, 0x0005 }, // normal / big (20 kills)
        { LocType::ABOVE_GROUND, LocType::SPAWNER });
    enemyTypes[ENEMY_GUAY] = EnemyType("Guay", ACTOR_GUAY, { 0x0000, 0x0001 }, // normal / big
        { LocType::ABOVE_GROUND, LocType::ABOVE_VOID, LocType::UNDERWATER, LocType::ABOVE_WATER });

    for (s32 i = 0; i < ENEMY_MAX; i++) {
        if (enemyTypes[i].actorId == 0) {
            CitraPrint("ERROR: enemyTypes not filled correctly!");
            printf("ERROR ERROR ERROR!");
        }
    }
};

void InitEnemyLocations(void) {
    enemyLocations.clear();

    // Overworld locations
    enemyLocations[10][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
    enemyLocations[10][0][0][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
    enemyLocations[10][0][2][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
    enemyLocations[10][0][2][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
    enemyLocations[10][0][4][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
    enemyLocations[10][0][4][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
    enemyLocations[10][0][7][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[10][0][7][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
    enemyLocations[15][0][0][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[23][0][1][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
    enemyLocations[34][0][0][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[34][0][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[62][0][2][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[62][0][2][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[62][0][4][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[62][0][5][0]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[62][0][7][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
    enemyLocations[62][0][7][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
    enemyLocations[62][0][8][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[62][0][8][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[62][0][10][2]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
    enemyLocations[62][0][13][0]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[63][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[65][0][1][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[65][0][1][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[65][0][1][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[65][0][3][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    enemyLocations[65][0][3][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    enemyLocations[65][0][3][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    enemyLocations[65][0][3][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    enemyLocations[72][0][2][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[72][0][2][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[72][0][3][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[72][0][3][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
    enemyLocations[81][0][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_PEAHAT);
    enemyLocations[81][0][0][0xFF]   = EnemyLocation(LocType::SPAWNER,        ENEMY_STALCHILD);
    // Graveyard: don't randomize enemies that don't appear in the base game due to missing object.
    // enemyLocations[83][2][1][2]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    // enemyLocations[83][2][1][3]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    // enemyLocations[83][2][1][4]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    // enemyLocations[83][2][1][5]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    // enemyLocations[83][2][1][6]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    // enemyLocations[83][2][1][7]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    // enemyLocations[83][2][1][8]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[83][2][1][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
    enemyLocations[83][2][1][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
    enemyLocations[83][2][1][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
    enemyLocations[84][0][0][4]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][0][0][5]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][0][0][42]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[84][0][0][43]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[84][2][0][2]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][3]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][4]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][5]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][6]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][7]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][8]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[84][2][0][9]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[85][0][1][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
    enemyLocations[85][0][1][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
    enemyLocations[85][0][1][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
    enemyLocations[85][0][1][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
    enemyLocations[85][0][1][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
    enemyLocations[85][2][0][1]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[85][2][0][2]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[85][2][0][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[85][2][0][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[85][2][0][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[85][2][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[85][2][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[85][2][1][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
    enemyLocations[86][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
    enemyLocations[86][0][0][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][0][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][0][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][0][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][0][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][0][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
    enemyLocations[86][2][0][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_SPEAR);
    enemyLocations[86][2][0][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_CLUB);
    enemyLocations[87][0][0][3]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[87][0][0][4]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[87][0][0][5]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[87][0][0][19]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
    enemyLocations[87][0][0][20]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
    enemyLocations[87][0][0][21]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][15]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_GUAY);
    enemyLocations[87][2][0][16]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_GUAY);
    enemyLocations[87][2][0][17]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_GUAY);
    enemyLocations[87][2][0][18]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_GUAY);
    enemyLocations[87][2][0][22]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][23]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][24]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][25]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][26]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][27]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][28]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[87][2][0][29]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
    enemyLocations[89][2][0][18]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[89][2][0][19]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[89][2][0][20]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[89][2][0][21]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[89][2][0][24]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[89][2][0][25]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[89][2][0][26]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[89][2][0][27]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[89][2][0][28]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    enemyLocations[89][2][0][50]     = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
    enemyLocations[90][2][0][3]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[90][2][0][4]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[90][2][0][5]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[90][2][0][6]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[90][2][0][7]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    // Lost Woods: don't randomize enemies that don't appear in the base game due to missing object.
    // enemyLocations[91][0][3][2]   = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[91][2][1][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULL_KID);
    enemyLocations[91][2][1][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULL_KID);
    enemyLocations[91][2][3][2]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
    enemyLocations[91][2][9][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULL_KID);
    enemyLocations[92][0][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][0][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][0][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][0][0][0xFF]   = EnemyLocation(LocType::SPAWNER,        ENEMY_LEEVER);
    enemyLocations[92][2][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][2][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][2][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][2][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][2][0][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[92][2][0][0xFF]   = EnemyLocation(LocType::SPAWNER,        ENEMY_LEEVER);
    enemyLocations[94][0][1][0xFF]   = EnemyLocation(LocType::SPAWNER,        ENEMY_LEEVER);
    enemyLocations[96][0][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][0][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][0][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][0][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][0][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][0][0][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][0][0][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][2][0][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][2][0][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][2][0][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    enemyLocations[96][2][0][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][2][0][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[96][2][0][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_RED);
    enemyLocations[97][2][1][8]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
    enemyLocations[97][2][1][9]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
    enemyLocations[97][2][1][10]     = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
    enemyLocations[97][2][1][11]     = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
    enemyLocations[97][2][1][12]     = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
    enemyLocations[99][1][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][15]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][16]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][17]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][18]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][19]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][20]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][21]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][22]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][23]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);
    enemyLocations[99][1][0][24]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GUAY);

    // Vanilla dungeons
    if (Dungeon::DekuTree.IsVanilla()) {
        enemyLocations[0][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][0][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][0][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][0][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][0][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][3][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][7][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][7][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][7][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][7][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][10][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][10][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
    }
    if (Dungeon::DodongosCavern.IsVanilla()) {
        enemyLocations[1][0][0][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][0][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][0][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[1][0][0][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[1][0][0][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[1][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[1][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][5][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][5][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][7][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][10][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][10][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][10][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][11][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][11][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][11][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
    }
    if (Dungeon::JabuJabusBelly.IsVanilla()) {
        enemyLocations[2][0][0][0]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][0][1]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][1][0]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BARI);
        enemyLocations[2][0][2][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BARI);
        enemyLocations[2][0][2][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][2][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][2][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][4][0]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][5][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][5][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][5][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][7][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][7][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][9][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][9][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][9][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][12][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][13][0]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][13][1]      = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[2][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][14][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][14][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][15]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][14][16]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
    }
    if (Dungeon::ForestTemple.IsVanilla()) {
        enemyLocations[3][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[3][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[3][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[3][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[3][0][7][2]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[3][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][7][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[3][0][7][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[3][0][8][0]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_OCTOROK);
        enemyLocations[3][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[3][0][8][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[3][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][11][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][11][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][11][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][17][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[3][0][19][0]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_WALLMASTER);
        enemyLocations[3][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[3][0][20][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[3][0][20][2]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_WALLMASTER);
        enemyLocations[3][0][21][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][21][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
    }
    if (Dungeon::FireTemple.IsVanilla()) {
        enemyLocations[4][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][1][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][1][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][1][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][14]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][15]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][16]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][1][17]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][1][22]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLARE_DANCER);
        enemyLocations[4][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][5][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][5][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][10][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][10][25]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][10][44]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][13][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][13][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][13][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][14][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][14][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][15][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][15][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][15][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[4][0][15][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][16][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][16][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][16][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][16][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][16][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[4][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[4][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[4][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][21][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[4][0][21][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[4][0][21][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[4][0][21][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[4][0][24][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLARE_DANCER);
    }
    if (Dungeon::WaterTemple.IsVanilla()) {
        // Idk why these exist
        // enemyLocations[5][0][0][2]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        // enemyLocations[5][0][0][3]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[5][0][0][4]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][0][5]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][0][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][0][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][2][0]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[5][0][2][1]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[5][0][2][2]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][2][3]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][2][4]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][2][5]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][2][6]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SPIKE);
        enemyLocations[5][0][3][0]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[5][0][3][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][4][1]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_STINGER_WATER);
        enemyLocations[5][0][4][2]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_STINGER_WATER);
        enemyLocations[5][0][4][3]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_STINGER_WATER);
        enemyLocations[5][0][4][4]       = EnemyLocation(LocType::UNDERWATER,     ENEMY_STINGER_WATER);
        enemyLocations[5][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[5][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[5][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[5][0][6][1]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][6][2]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][6][5]       = EnemyLocation(LocType::ABOVE_WATER,    ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][9][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][10][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][12][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][12][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][13][0xFF]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DARK_LINK);
        enemyLocations[5][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[5][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[5][0][14][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[5][0][14][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[5][0][14][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[5][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[5][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][18][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[5][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[5][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[5][0][19][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[5][0][19][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
    }
    if (Dungeon::SpiritTemple.IsVanilla()) {
        enemyLocations[6][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][0][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][0][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][1][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][2][0]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][2][1]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][2][2]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][2][3]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][2][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][2][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][3][0]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_GREEN);
        enemyLocations[6][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[6][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][3][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[6][0][4][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[6][0][5][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][5][19]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][5][20]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][8][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][8][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[6][0][12][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[6][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[6][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[6][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[6][0][15][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][15][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][16][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][17][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ANUBIS);
        enemyLocations[6][0][17][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ANUBIS);
        enemyLocations[6][0][17][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ANUBIS);
        enemyLocations[6][0][17][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][18][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        // Leave one armos so we can press the switch
        // enemyLocations[6][0][18][3]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[6][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[6][0][22][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][22][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][22][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][22][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][23][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][23][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][23][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][23][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][23][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][25][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][25][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][25][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][25][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][25][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][25][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][26][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_WHITE);
        enemyLocations[6][0][26][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_WHITE);
        enemyLocations[6][0][26][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_WHITE);
        enemyLocations[6][0][26][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[6][0][26][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[6][0][27][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ANUBIS);
    }
    if (Dungeon::ShadowTemple.IsVanilla()) {
        enemyLocations[7][0][0][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // Leave Dead Hand and one of its hands to lure it out.
        // enemyLocations[7][0][4][5]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // enemyLocations[7][0][4][6]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND);
        enemyLocations[7][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][9][1]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
        enemyLocations[7][0][9][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[7][0][9][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][9][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[7][0][11][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][11][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][13][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][13][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][14][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[7][0][14][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[7][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[7][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[7][0][16][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[7][0][17][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[7][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][20][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][20][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][20][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][21][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[7][0][21][14]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
    }
    if (Dungeon::BottomOfTheWell.IsVanilla()) {
        enemyLocations[8][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[8][0][0][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[8][0][0][33]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[8][0][1][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][14]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[8][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[8][0][3][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[8][0][3][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[8][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[8][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[8][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[8][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // Leave Dead Hand and one of its hands to lure it out.
        // enemyLocations[8][0][4][3]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // enemyLocations[8][0][4][4]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND);
        enemyLocations[8][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][5][1]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][5][2]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][5][3]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[8][0][6][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[8][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[8][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
    }
    if (Dungeon::IceCavern.IsVanilla()) {
        enemyLocations[9][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][1][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][1][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][1][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][3][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[9][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][5][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][6][17]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][6][18]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][8][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][9][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][9][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][9][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][14]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][11][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[9][0][11][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[9][0][11][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
    }
    if (Dungeon::GerudoTrainingGrounds.IsVanilla()) {
        enemyLocations[11][0][1][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[11][0][1][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        // Don't randomize out of bounds wallmaster, it exists only to prevent setting the clear flag.
        // enemyLocations[11][0][2][4]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[11][0][2][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[11][0][3][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[11][0][3][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[11][0][3][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[11][0][3][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[11][0][5][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[11][0][5][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[11][0][5][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[11][0][5][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[11][0][6][2]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
        enemyLocations[11][0][6][3]      = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_FIRE);
        enemyLocations[11][0][7][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[11][0][7][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[11][0][7][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[11][0][9][4]      = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[11][0][9][5]      = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[11][0][9][6]      = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[11][0][9][7]      = EnemyLocation(LocType::UNDERWATER,     ENEMY_SHELL_BLADE);
        enemyLocations[11][0][10][0]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[11][0][10][1]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[11][0][10][2]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
    }
    if (Dungeon::GanonsCastle.IsVanilla()) {
        enemyLocations[13][0][0][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][2][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[13][0][2][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[13][0][3][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[13][0][5][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[13][0][6][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][8][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[13][0][9][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[13][0][9][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[13][0][9][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[13][0][9][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[13][0][10][1]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[13][0][12][0]     = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][12][3]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[13][0][14][3]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][14][4]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[13][0][14][5]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[13][0][14][6]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[13][0][14][7]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[13][0][17][10]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][18][6]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][18][7]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][18][18]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[13][0][18][20]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[13][0][18][22]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
    }

    // MQ dungeons
    if (Dungeon::DekuTree.IsMQ()) {
        enemyLocations[0][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][0][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][0][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][0][22]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][0][23]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[0][0][1][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][1][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[0][0][2][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][2][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][2][14]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][3][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][3][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][3][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[0][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
        enemyLocations[0][0][4][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][4][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][4][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][5][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[0][0][5][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
        enemyLocations[0][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][6][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[0][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][7][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][7][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[0][0][7][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][7][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[0][0][8][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][8][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][8][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][8][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[0][0][10][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[0][0][10][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
    }
    if (Dungeon::DodongosCavern.IsMQ()) {
        enemyLocations[1][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][1][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][1][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][1][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_WITHERED);
        enemyLocations[1][0][2][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][2][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][2][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[1][0][2][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[1][0][3][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][3][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
        enemyLocations[1][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
        enemyLocations[1][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
        enemyLocations[1][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][5][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][5][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[1][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[1][0][6][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[1][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[1][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[1][0][6][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GOHMA_LARVA);
        enemyLocations[1][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[1][0][8][13]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][8][14]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][8][15]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[1][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][10][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][10][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][10][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][10][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][10][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][10][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][10][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][10][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[1][0][12][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][12][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[1][0][13][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
        enemyLocations[1][0][13][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MAD_SCRUB);
        enemyLocations[1][0][13][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[1][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
        enemyLocations[1][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[1][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[1][0][15][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    }
    if (Dungeon::JabuJabusBelly.IsMQ()) {
        enemyLocations[2][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_OCTOROK);
        enemyLocations[2][0][0][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][0][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][0][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][1][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][1][16]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[2][0][2][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][2][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BIRI);
        enemyLocations[2][0][3][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][4][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[2][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[2][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[2][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BARI);
        enemyLocations[2][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[2][0][11][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[2][0][11][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[2][0][12][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[2][0][12][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][12][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][12][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TAILPASARAN);
        enemyLocations[2][0][12][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][12][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHABOM);
        enemyLocations[2][0][13][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[2][0][13][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[2][0][13][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[2][0][13][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[2][0][13][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[2][0][14][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_FLOOR);
        enemyLocations[2][0][14][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[2][0][14][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
    }
    if (Dungeon::ForestTemple.IsMQ()) {
        enemyLocations[3][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][0][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[3][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[3][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[3][0][7][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_SMALL);
        enemyLocations[3][0][7][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[3][0][7][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEKU_BABA_BIG);
        enemyLocations[3][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_OCTOROK);
        enemyLocations[3][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_OCTOROK);
        enemyLocations[3][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_OCTOROK);
        enemyLocations[3][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[3][0][8][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][11][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][11][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[3][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][15][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][17][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][17][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[3][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[3][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[3][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[3][0][20][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[3][0][20][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[3][0][21][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
    }
    if (Dungeon::FireTemple.IsMQ()) {
        enemyLocations[4][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLARE_DANCER);
        enemyLocations[4][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[4][0][5][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[4][0][5][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[4][0][5][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[4][0][5][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[4][0][5][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[4][0][7][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[4][0][14][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[4][0][14][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[4][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[4][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[4][0][15][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[4][0][17][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[4][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[4][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][18][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][19][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_FLOOR_TILE);
        enemyLocations[4][0][24][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLARE_DANCER);
        enemyLocations[4][0][25][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
    }
    if (Dungeon::WaterTemple.IsMQ()) {
        enemyLocations[5][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[5][0][3][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][3][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][6][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][10][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[5][0][13][0xFF]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DARK_LINK);
        enemyLocations[5][0][14][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][14][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[5][0][16][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[5][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[5][0][18][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[5][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][19][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[5][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[5][0][20][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
    }
    if (Dungeon::SpiritTemple.IsMQ()) {
        enemyLocations[6][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[6][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[6][0][2][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[6][0][3][0]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][3][1]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][3][2]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][3][3]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][3][4]       = EnemyLocation(LocType::ABOVE_VOID,     ENEMY_KEESE_NORMAL);
        enemyLocations[6][0][3][12]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ANUBIS);
        enemyLocations[6][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[6][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[6][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[6][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO_BABY);
        enemyLocations[6][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[6][0][4][11]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][5][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[6][0][5][18]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][5][19]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][5][20]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][5][22]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[6][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[6][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[6][0][8][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[6][0][8][18]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][8][20]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][9][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][10][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[6][0][12][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][12][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[6][0][13][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_MOBLIN_CLUB);
        enemyLocations[6][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[6][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[6][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][15][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][15][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][15][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[6][0][17][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][17][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][17][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][17][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[6][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[6][0][18][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[6][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[6][0][20][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[6][0][21][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        // Don't randomize Iron Knuckle needed to destroy thrones.
        // enemyLocations[6][0][22][0]   = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[6][0][23][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[6][0][23][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][23][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][23][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][23][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][23][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[6][0][26][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[6][0][26][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[6][0][26][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[6][0][26][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[6][0][27][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
    }
    if (Dungeon::ShadowTemple.IsMQ()) {
        enemyLocations[7][0][0][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][0][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][0][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][0][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][4][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[7][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // Leave Dead Hand and one of its hands to lure it out.
        // enemyLocations[7][0][4][5]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // enemyLocations[7][0][4][6]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND);
        enemyLocations[7][0][5][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][6][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][7][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][7][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][8][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][8][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][9][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[7][0][9][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][9][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][9][10]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[7][0][11][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][11][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][13][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][13][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][13][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][13][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][13][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][13][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][13][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][13][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][14][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[7][0][14][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[7][0][15][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[7][0][15][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_BLUE);
        enemyLocations[7][0][15][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[7][0][16][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[7][0][16][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIKE_LIKE);
        enemyLocations[7][0][18][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][19][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][19][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][19][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][19][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[7][0][20][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][20][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[7][0][20][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][20][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLYING_POT);
        enemyLocations[7][0][21][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[7][0][21][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[7][0][21][16]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[7][0][21][17]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
    }
    if (Dungeon::BottomOfTheWell.IsMQ()) {
        enemyLocations[8][0][0][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[8][0][0][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[8][0][0][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][0][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[8][0][0][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][1][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][1][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[8][0][1][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][8]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][1][9]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[8][0][2][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[8][0][2][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_POE);
        enemyLocations[8][0][3][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[8][0][3][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FLOORMASTER);
        enemyLocations[8][0][4][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[8][0][4][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[8][0][4][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // Leave Dead Hand and one of its hands to lure it out.
        // enemyLocations[8][0][4][7]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        // enemyLocations[8][0][4][8]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND);
        enemyLocations[8][0][6][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][6][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][6][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[8][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[8][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
    }
    if (Dungeon::IceCavern.IsMQ()) {
        enemyLocations[9][0][1][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][1][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[9][0][1][2]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TEKTITE_BLUE);
        enemyLocations[9][0][3][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][3][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][3][7]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][5][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][5][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][5][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][5][6]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][6][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][6][4]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[9][0][7][3]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[9][0][8][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][8][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][0]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][1]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][9][5]       = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[9][0][11][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][11][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WOLFOS);
        enemyLocations[9][0][11][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
    }
    if (Dungeon::GerudoTrainingGrounds.IsMQ()) {
        enemyLocations[11][0][1][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[11][0][2][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[11][0][2][17]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[11][0][2][21]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
        enemyLocations[11][0][3][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[11][0][3][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[11][0][3][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[11][0][3][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[11][0][3][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLTULA);
        enemyLocations[11][0][5][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[11][0][5][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[11][0][5][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[11][0][6][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[11][0][6][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[11][0][6][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_FIRE);
        enemyLocations[11][0][7][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[11][0][7][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[11][0][7][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_LIZALFOS);
        enemyLocations[11][0][7][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[11][0][7][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DODONGO);
        enemyLocations[11][0][7][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[11][0][9][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[11][0][9][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STINGER_WATER);
        enemyLocations[11][0][9][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BARI);
        enemyLocations[11][0][9][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SHELL_BLADE);
        enemyLocations[11][0][10][0]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[11][0][10][1]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[11][0][10][2]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[11][0][10][3]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
        enemyLocations[11][0][10][4]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SPIKE);
    }
    if (Dungeon::GanonsCastle.IsMQ()) {
        enemyLocations[13][0][0][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[13][0][0][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[13][0][0][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[13][0][0][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][0][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][2][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DEAD_HAND_HAND);
        enemyLocations[13][0][2][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[13][0][2][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[13][0][2][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_FREEZARD);
        enemyLocations[13][0][3][0]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_ICE);
        enemyLocations[13][0][3][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[13][0][3][4]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_NORMAL);
        enemyLocations[13][0][3][5]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[13][0][5][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[13][0][5][2]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_STALFOS);
        enemyLocations[13][0][6][1]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_ARMOS);
        enemyLocations[13][0][6][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][6][9]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][6][10]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][6][11]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][6][12]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][6][13]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][8][3]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][9][6]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][9][7]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][9][8]      = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_DINOLFOS);
        enemyLocations[13][0][10][3]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_SKULLWALLTULA);
        enemyLocations[13][0][12][5]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][12][6]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][12][7]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][12][8]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][12][9]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][14][1]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][14][2]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][14][16]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BEAMOS);
        enemyLocations[13][0][17][9]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_TORCH_SLUG);
        enemyLocations[13][0][17][10]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        enemyLocations[13][0][17][11]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_KEESE_FIRE);
        // Don't randomize Iron Knuckle needed to destroy thrones.
        // enemyLocations[13][0][17][12] = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_IRON_KNUCKLE);
        enemyLocations[13][0][18][6]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_GIBDO);
        enemyLocations[13][0][18][7]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[13][0][18][8]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_REDEAD);
        enemyLocations[13][0][18][9]     = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][18][10]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_BUBBLE_GREEN);
        enemyLocations[13][0][18][24]    = EnemyLocation(LocType::ABOVE_GROUND,   ENEMY_WALLMASTER);
    }
}

void AddDuplicateLocations(void) {
    // Enemies in Hyrule Field as child should stay the same in OoT layer
    enemyLocations[81][1][0][4]      = enemyLocations[81][0][0][8];
    enemyLocations[81][1][0][5]      = enemyLocations[81][0][0][9];
    enemyLocations[81][1][0][6]      = enemyLocations[81][0][0][10];
    enemyLocations[81][1][0][7]      = enemyLocations[81][0][0][11];
    enemyLocations[81][1][0][8]      = enemyLocations[81][0][0][12];
    enemyLocations[81][1][0][9]      = enemyLocations[81][0][0][13];
    enemyLocations[81][1][0][10]     = enemyLocations[81][0][0][14];
    enemyLocations[81][1][0][0xFF]   = enemyLocations[81][0][0][0xFF];

    // Enemies in Graveyard as adult should stay the same at night
    // enemyLocations[83][3][1][2]   = enemyLocations[83][2][1][2];
    // enemyLocations[83][3][1][3]   = enemyLocations[83][2][1][3];
    // enemyLocations[83][3][1][4]   = enemyLocations[83][2][1][4];
    // enemyLocations[83][3][1][5]   = enemyLocations[83][2][1][5];
    // enemyLocations[83][3][1][6]   = enemyLocations[83][2][1][6];
    // enemyLocations[83][3][1][7]   = enemyLocations[83][2][1][7];
    // enemyLocations[83][3][1][8]   = enemyLocations[83][2][1][8];
    enemyLocations[83][3][1][12]     = enemyLocations[83][2][1][12];
    enemyLocations[83][3][1][13]     = enemyLocations[83][2][1][13];
    enemyLocations[83][3][1][14]     = enemyLocations[83][2][1][14];
}
// clang-format on

} // namespace Enemizer
