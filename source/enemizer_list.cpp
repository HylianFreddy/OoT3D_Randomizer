#include "../../code/include/actor_id.h"
#include "enemizer.hpp"
#include "dungeon.hpp"

namespace Enemizer {

bool canKillPlaceholder() {
    return true;
}

ConditionFn canKillPoe           = canKillPlaceholder;
ConditionFn canKillStalfos       = canKillPlaceholder;
ConditionFn canKillOctorok       = canKillPlaceholder;
ConditionFn canKillWallmaster    = canKillPlaceholder;
ConditionFn canKillDodongo       = canKillPlaceholder;
ConditionFn canKillKeese         = canKillPlaceholder;
ConditionFn canKillTektite       = canKillPlaceholder;
ConditionFn canKillPeahat        = canKillPlaceholder;
ConditionFn canKillPeahatLarva   = canKillPlaceholder;
ConditionFn canKillLizalfos      = canKillPlaceholder;
ConditionFn canKillGohmaLarva    = canKillPlaceholder;
ConditionFn canKillShabom        = canKillPlaceholder;
ConditionFn canKillBabyDodongo   = canKillPlaceholder;
ConditionFn canKillBiri          = canKillPlaceholder;
ConditionFn canKillTailsparan    = canKillPlaceholder;
ConditionFn canKillSkulltula     = canKillPlaceholder;
ConditionFn canKillTorchSlug     = canKillPlaceholder;
ConditionFn canKillMoblin        = canKillPlaceholder;
ConditionFn canKillArmos         = canKillPlaceholder;
ConditionFn canKillDekuBaba      = canKillPlaceholder;
ConditionFn canKillScrub         = canKillPlaceholder;
ConditionFn canKillBlueBubble    = canKillPlaceholder;
ConditionFn canKillFlyingTrap    = canKillPlaceholder;
ConditionFn canKillBeamos        = canKillPlaceholder;
ConditionFn canKillFloormaster   = canKillPlaceholder;
ConditionFn canKillRedead        = canKillPlaceholder;
ConditionFn canKillDeadHandHand  = canKillPlaceholder;
ConditionFn canKillSkullwalltula = canKillPlaceholder;
ConditionFn canKillFlareDancer   = canKillPlaceholder;
ConditionFn canKillShellBlade    = canKillPlaceholder;
ConditionFn canKillLikeLike      = canKillPlaceholder;
ConditionFn canKillSpikeEnemy    = canKillPlaceholder;
ConditionFn canKillAnubis        = canKillPlaceholder;
ConditionFn canKillIronKnuckle   = canKillPlaceholder;
ConditionFn canKillSkullKid      = canKillPlaceholder;
ConditionFn canKillFreezard      = canKillPlaceholder;
ConditionFn canKillStinger       = canKillPlaceholder;
ConditionFn canKillWolfos        = canKillPlaceholder;
ConditionFn canKillStalchild     = canKillPlaceholder;
ConditionFn canKillGuay          = canKillPlaceholder;
ConditionFn canKillDarkLink      = canKillPlaceholder;
ConditionFn canKillDeadHand      = canKillPlaceholder;

// clang-format off
std::vector<Enemy> enemyTypes = {
    Enemy("Poe",                  ACTOR_POE,                0x0000, canKillPoe,           {LocationType::ABOVE_GROUND, LocationType::ABOVE_VOID}),
    Enemy("Stalfos",              ACTOR_STALFOS,            0x0002, canKillStalfos,       {LocationType::ABOVE_GROUND}),
    Enemy("Stalfos",              ACTOR_STALFOS,            0x0003, canKillStalfos,       {LocationType::ABOVE_GROUND}),
    Enemy("Octorok",              ACTOR_OCTOROK,            0x0000, canKillOctorok,       {LocationType::ABOVE_WATER}),
    Enemy("Wallmaster",           ACTOR_WALLMASTER,         0x0000, canKillWallmaster,    {LocationType::ABOVE_GROUND}),
    Enemy("Dodongo",              ACTOR_DODONGO,            0x0000, canKillDodongo,       {LocationType::ABOVE_GROUND}),
    Enemy("Keese",                ACTOR_KEESE,              0x0002, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Fire Keese",           ACTOR_KEESE,              0x0001, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Ice Keese",            ACTOR_KEESE,              0x0004, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Tektite (Red)",        ACTOR_TEKTITE,            0xFFFF, canKillTektite,       {LocationType::ABOVE_GROUND}),
    Enemy("Tektite (Blue)",       ACTOR_TEKTITE,            0xFFFE, canKillTektite,       {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    // Enemy("Leever",               ACTOR_LEEVER,             0x0000, canKillLeever,        {LocationType::ABOVE_GROUND}),
    Enemy("Peahat",               ACTOR_PEAHAT,             0xFFFF, canKillPeahat,        {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Peahat Larva",         ACTOR_PEAHAT,             0x0001, canKillPeahatLarva,   {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Lizalfos",             ACTOR_LIZALFOS,           0xFF80, canKillLizalfos,      {LocationType::ABOVE_GROUND}),
    Enemy("Lizalfos",             ACTOR_LIZALFOS,           0xFFFF, canKillLizalfos,      {LocationType::ABOVE_GROUND}),
    Enemy("Dinolfos",             ACTOR_LIZALFOS,           0xFFFE, canKillLizalfos,      {LocationType::ABOVE_GROUND}),
    Enemy("Gohma Larva",          ACTOR_GOHMA_LARVA,        0x0007, canKillGohmaLarva,    {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Shabom",               ACTOR_SHABOM,             0x0000, canKillShabom,        {LocationType::UNDERWATER, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Baby Dodongo",         ACTOR_BABY_DODONGO,       0x0000, canKillBabyDodongo,   {LocationType::ABOVE_GROUND}),
    Enemy("Biri",                 ACTOR_BIRI,               0xFFFF, canKillBiri,          {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Tailpasaran",          ACTOR_TAILPASARAN,        0xFFFF, canKillTailsparan,    {LocationType::ABOVE_GROUND}),
    Enemy("Skulltula",            ACTOR_SKULLTULA,          0x0000, canKillSkulltula,     {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND}),
    Enemy("Skulltula (Big)",      ACTOR_SKULLTULA,          0x0001, canKillSkulltula,     {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND}),
    Enemy("Torch Slug",           ACTOR_TORCH_SLUG,         0xFFFF, canKillTorchSlug,     {LocationType::ABOVE_GROUND}),
    Enemy("Stinger (Land)",       ACTOR_STINGER_LAND,       0x000A, canKillStinger,       {LocationType::UNDERWATER}),
    Enemy("Moblin (Club)",        ACTOR_MOBLIN,             0x0000, canKillMoblin,        {LocationType::ABOVE_GROUND}),
    Enemy("Moblin (Spear)",       ACTOR_MOBLIN,             0xFFFF, canKillMoblin,        {LocationType::ABOVE_GROUND}),
    Enemy("Armos",                ACTOR_ARMOS,              0xFFFF, canKillArmos,         {LocationType::ABOVE_GROUND}),
    Enemy("Deku Baba",            ACTOR_DEKU_BABA,          0x0000, canKillDekuBaba,      {LocationType::ABOVE_GROUND}),
    Enemy("Deku Baba (Big)",      ACTOR_DEKU_BABA,          0x0001, canKillDekuBaba,      {LocationType::ABOVE_GROUND}),
    Enemy("Mad Scrub",            ACTOR_MAD_SCRUB,          0x0300, canKillScrub,         {LocationType::UNDERWATER}), // volley count?
    Enemy("Bari",                 ACTOR_BARI,               0xFFFF, canKillBiri,          {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Bubble (Blue)",        ACTOR_BUBBLE,             0xFFFF, canKillBlueBubble,    {LocationType::ABOVE_GROUND}),
    Enemy("Bubble (Fire)",        ACTOR_BUBBLE,             0xFFFE, canKillBlueBubble,    {LocationType::ABOVE_GROUND}),
    Enemy("Flying Floor Tile",    ACTOR_FLYING_FLOOR_TILE,  0x0000, canKillFlyingTrap,    {LocationType::ABOVE_GROUND}),
    Enemy("Beamos (Big)",         ACTOR_BEAMOS,             0x0500, canKillBeamos,        {LocationType::ABOVE_GROUND}),
    Enemy("Beamos (Small)",       ACTOR_BEAMOS,             0x0501, canKillBeamos,        {LocationType::ABOVE_GROUND}),
    Enemy("Floormaster",          ACTOR_FLOORMASTER,        0x0000, canKillFloormaster,   {LocationType::ABOVE_GROUND}),
    Enemy("Redead",               ACTOR_REDEAD,             0x7F01, canKillRedead,        {LocationType::ABOVE_GROUND}), // crouching?
    Enemy("Gibdo",                ACTOR_REDEAD,             0x7FFE, canKillRedead,        {LocationType::ABOVE_GROUND}),
    Enemy("Dead Hand's Hand",     ACTOR_DEAD_HAND_HAND,     0x0000, canKillDeadHandHand,  {LocationType::ABOVE_GROUND}),
    // Enemy("Skullwalltula",        ACTOR_SKULLWALLTULA,      0x0000, canKillSkullwalltula, {LocationType::UNDERWATER}),
    Enemy("Flare Dancer",         ACTOR_FLARE_DANCER,       0x0000, canKillFlareDancer,   {LocationType::ABOVE_GROUND}),
    Enemy("Shell Blade",          ACTOR_SHELL_BLADE,        0x0000, canKillShellBlade,    {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Whithered Deku Baba",  ACTOR_WITHERED_DEKU_BABA, 0x0000, canKillDekuBaba,      {LocationType::ABOVE_GROUND}),
    Enemy("Like Like",            ACTOR_LIKE_LIKE,          0x0000, canKillLikeLike,      {LocationType::ABOVE_GROUND}),
    Enemy("Spike Enemy",          ACTOR_SPIKE,              0x0000, canKillSpikeEnemy,    {LocationType::ABOVE_GROUND}),
    Enemy("Anubis Spawner",       ACTOR_ANUBIS_SPAWNER,     0x0003, canKillAnubis,        {LocationType::ABOVE_VOID}),
    Enemy("Iron Knuckle (Black)", ACTOR_IRON_KNUCKLE,       0xFF02, canKillIronKnuckle,   {LocationType::ABOVE_GROUND}),
    Enemy("Iron Knuckle (White)", ACTOR_IRON_KNUCKLE,       0xFF03, canKillIronKnuckle,   {LocationType::ABOVE_GROUND}),
    Enemy("Skull Kid",            ACTOR_SKULL_KID,          0xFFFF, canKillSkullKid,      {LocationType::ABOVE_GROUND}),
    Enemy("Flying Pot",           ACTOR_FLYING_POT,         0x0000, canKillFlyingTrap,    {LocationType::ABOVE_GROUND}),
    Enemy("Freezard",             ACTOR_FREEZARD,           0x0000, canKillFreezard,      {LocationType::ABOVE_GROUND}),
    Enemy("Freezard",             ACTOR_FREEZARD,           0xFFFF, canKillFreezard,      {LocationType::ABOVE_GROUND}),
    Enemy("Stinger",              ACTOR_STINGER_WATER,      0x0000, canKillStinger,       {LocationType::UNDERWATER}),
    Enemy("Wolfos",               ACTOR_WOLFOS,             0xFF00, canKillWolfos,        {LocationType::ABOVE_GROUND}),
    Enemy("White Wolfos",         ACTOR_WOLFOS,             0xFF01, canKillWolfos,        {LocationType::ABOVE_GROUND}),
    Enemy("Stalchild",            ACTOR_STALCHILD,          0x0000, canKillStalchild,     {LocationType::ABOVE_GROUND}),
    Enemy("Stalchild (Big)",      ACTOR_STALCHILD,          0x0005, canKillStalchild,     {LocationType::ABOVE_GROUND}),
    Enemy("Guay",                 ACTOR_GUAY,               0x0000, canKillGuay,          {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    // Enemy("Dark Link",            ACTOR_DARK_LINK,          0x0000, canKillDarkLink,      {LocationType::ABOVE_GROUND}),
    // Enemy("Dead Hand",            ACTOR_DEAD_HAND,          0x0000, canKillDeadHand,      {LocationType::ABOVE_GROUND}),
};
// clang-format on

ScenesMap enemyLocations = {};

void EnemyLocations_Init() {
    CitraPrint("EnemyLocations_Init start");
    // Overworld locations
    enemyLocations[10][0][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][0][0][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][2][0][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][2][0][6]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    enemyLocations[10][4][0][1]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[10][4][0][2]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[10][7][0][7]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[15][0][0][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[23][1][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][5]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][6]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[34][0][0][7]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][2][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][2][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[62][4][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][5][0][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[62][7][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[62][7][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[62][8][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][8][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[62][10][0][2] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[62][13][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[63][0][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][0][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[65][1][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][1][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[65][1][0][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][2][0][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][2][0][4]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][3][0][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[72][3][0][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][8]  = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][9]  = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][10] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][11] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][12] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][13] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[81][0][0][14] = EnemyLocation(ACTOR_PEAHAT, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][7]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][2][8]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][7]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[83][1][3][8]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[84][0][2][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][6]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][7]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][8]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][2][9]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[84][0][0][42] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[84][0][0][43] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[85][0][2][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[85][0][2][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][4]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][5]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][6]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][7]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][8]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][9]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][0][2][10] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][2]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][6]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][2][7]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][0][1]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][0][2]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][0][3]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][0][4]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[85][1][0][5]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][5]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][6]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][7]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][8]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][9]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][2][10] = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][5]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][6]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][7]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][8]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][9]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[86][0][0][10] = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][15] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][16] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][17] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][18] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][22] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][23] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][24] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][25] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][26] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][27] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][28] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][2][29] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[87][0][0][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][19] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][20] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[87][0][0][21] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[89][0][2][18] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][0][2][19] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][0][2][20] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][0][2][21] = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[89][0][2][24] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][0][2][25] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][0][2][26] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][0][2][27] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][0][2][28] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[89][0][2][50] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
    enemyLocations[90][0][2][3]  = EnemyLocation(ACTOR_OCTOROK, LocationType::UNDERWATER);
    enemyLocations[90][0][2][4]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][0][2][5]  = EnemyLocation(ACTOR_OCTOROK, LocationType::UNDERWATER);
    enemyLocations[90][0][2][6]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[90][0][2][7]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][1][2][1]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[91][1][2][2]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[91][3][2][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][3][0][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
    enemyLocations[91][9][2][1]  = EnemyLocation(ACTOR_SKULL_KID, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][2][7]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][2][8]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][2][9]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][2][10] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][2][11] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][7]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][8]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[92][0][0][9]  = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][6]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][7]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][2][8]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][6]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][7]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][8]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][9]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][10] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][11] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[96][0][0][12] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
    enemyLocations[97][1][2][8]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    enemyLocations[97][1][2][9]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    enemyLocations[97][1][2][10] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    enemyLocations[97][1][2][11] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    enemyLocations[97][1][2][12] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][10] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][11] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][12] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][13] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][14] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][15] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][16] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][17] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][18] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][19] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][20] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][21] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][22] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][23] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);
    enemyLocations[99][0][1][24] = EnemyLocation(ACTOR_GUAY, LocationType::ABOVE_GROUND);

    // Peahats in Hyrule Field should stay the same enemies in OoT layer
    enemyLocations[81][0][0][8]  = enemyLocations[81][0][1][4];
    enemyLocations[81][0][0][9]  = enemyLocations[81][0][1][5];
    enemyLocations[81][0][0][10] = enemyLocations[81][0][1][6];
    enemyLocations[81][0][0][11] = enemyLocations[81][0][1][7];
    enemyLocations[81][0][0][12] = enemyLocations[81][0][1][8];
    enemyLocations[81][0][0][13] = enemyLocations[81][0][1][9];
    enemyLocations[81][0][0][14] = enemyLocations[81][0][1][10];

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
        enemyLocations[0][3][0][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][5][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][1]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][0]  = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][5]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][6]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][7]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][0] = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][4] = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::DodongosCavern.IsVanilla()) {
        enemyLocations[1][0][0][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][0][0][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][2]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][3]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][4]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][5]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][6]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][7]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][4]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][4][0][0]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][4][0][1]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][4][0][2]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][0]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][1]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][2]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][7][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][7][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][1] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][2] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][3] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][11][0][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][11][0][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][11][0][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][14][0][0] = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][15][0][0] = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::JabuJabusBelly.IsVanilla()) {
        enemyLocations[2][0][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][0][1]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][0][0][3]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][4]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][1][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][1][0][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][1]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][2]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][5]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][6]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][4][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][5][0][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][5]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][6][0][0]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][6][0][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][0]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][1]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][2]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][3]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][4]   = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][8][0][1]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][8][0][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][8][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][8][0][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][9][0][0]   = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][9][0][1]   = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][9][0][2]   = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][9][0][3]   = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][2]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][3]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][4]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][5]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][6]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][7]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][8]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][9]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][13][0][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[2][14][0][0]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][1]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][2]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][11] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][12] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][13] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][14] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][15] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][16] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ForestTemple.IsVanilla()) {
        enemyLocations[3][0][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][1][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][3][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][4][0][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][5][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][6][0][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][6][0][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[3][7][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_WATER);
        enemyLocations[3][8][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][10][0][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][11][0][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][11][0][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][11][0][2] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][17][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][18][0][0] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][19][0][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_VOID);
        enemyLocations[3][20][0][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][20][0][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][20][0][2] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_VOID);
        enemyLocations[3][21][0][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][21][0][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::FireTemple.IsVanilla()) {
        enemyLocations[4][0][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][0][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][1]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][5]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][8]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][11]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][12]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][13]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][14]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][15]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][16]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][17]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][1][0][22]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][3][0][0]   = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][4][0][0]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][4][0][3]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][4]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][6]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][11]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][10][0][14] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][10][0][25] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][10][0][44] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][13][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][13][0][8]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][13][0][9]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][7]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][5]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][6]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][7]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][16][0][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][16][0][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][16][0][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][16][0][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][16][0][4]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][18][0][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][19][0][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][21][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][21][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][21][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][21][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][24][0][0]  = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::WaterTemple.IsVanilla()) {
        enemyLocations[5][0][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][4]  = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][5]  = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][12] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][0][0][13] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][2][0][0]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][1]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][2]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][3]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][4]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][5]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][2][0][6]  = EnemyLocation(ACTOR_SPIKE, LocationType::UNDERWATER);
        enemyLocations[5][3][0][0]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[5][3][0][2]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][3][0][3]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][4][0][1]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::UNDERWATER);
        enemyLocations[5][4][0][2]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::UNDERWATER);
        enemyLocations[5][4][0][3]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::UNDERWATER);
        enemyLocations[5][4][0][4]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::UNDERWATER);
        enemyLocations[5][5][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][5][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][1]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][6][0][2]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][6][0][3]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][4]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][5]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_WATER);
        enemyLocations[5][8][0][2]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][8][0][3]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][9][0][0]  = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][10][0][1] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][0] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][3] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][4] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][5] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][6] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][7] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][12][0][8] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][0] = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][1] = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][2] = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][3] = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][4] = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[5][15][0][0] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][15][0][1] = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][0] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][1] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][2] = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][0] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][1] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][2] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][3] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::SpiritTemple.IsVanilla()) {
        enemyLocations[6][0][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][0][0][2]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][2][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][2][0][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][2][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][2][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][2][0][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][2][0][6]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][3][0][0]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][3]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][0]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][1]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][2]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][3]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][4]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][5]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][5][0][11]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][4]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][5]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][6]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][10][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][0]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][14][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][8]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][9]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][12] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][16][0][0]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][0]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][1]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][2]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][3]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][18][0][0]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][18][0][1]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][18][0][2]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        // Leave one armos so we can press the switch
        // enemyLocations[6][18][0][3] =  EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND );
        enemyLocations[6][20][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][22][0][10] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][22][0][11] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][22][0][12] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][22][0][13] = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][4]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][5]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][4]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][27][0][0]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ShadowTemple.IsVanilla()) {
        enemyLocations[7][1][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][1][0][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][1][0][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][2][0][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][5][0][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][7][0][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][7][0][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][1]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[7][9][0][2]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][5]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][12]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][11][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][11][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][15][0][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][15][0][1]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][17][0][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[7][18][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][20][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][20][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][13] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][14] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::BottomOfTheWell.IsVanilla()) {
        enemyLocations[8][0][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][4]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][5]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][33] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][13] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][14] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][2][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][4]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[8][5][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][5][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][5][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][5][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[8][6][0][0]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::IceCavern.IsVanilla()) {
        enemyLocations[9][1][0][1]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][1][0][10] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][1][0][11] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][1][0][12] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][6][0][17] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][6][0][18] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][7][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][8][0][8]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][4]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][13] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][14] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GerudoTrainingGrounds.IsVanilla()) {
        enemyLocations[11][1][0][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][1][0][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][2][0][4]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][2][0][5]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][2]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][4]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][5]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[11][6][0][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[11][6][0][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[11][7][0][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][13] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][9][0][4]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][9][0][5]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][9][0][6]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][9][0][7]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::UNDERWATER);
        enemyLocations[11][10][0][0] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][1] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][2] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GanonsCastle.IsVanilla()) {
        enemyLocations[13][0][0][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][1]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][2][0][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][2][0][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][3][0][6]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][5][0][0]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][1]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][8][0][11]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][7]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][8]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][9]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[13][10][0][1]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_VOID);
        enemyLocations[13][12][0][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][4]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][5]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][6]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][7]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][17][0][10] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][6]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][7]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][18] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][20] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][22] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
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
        enemyLocations[0][1][0][3]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][1][0][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][1][0][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][2][0][0]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][2][0][1]   = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][2][0][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][2][0][13]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][2][0][14]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][6]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][7]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][3][0][8]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][4][0][4]   = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[0][4][0][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][4][0][6]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][4][0][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][5][0][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][5][0][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[0][5][0][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][3]   = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][4]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][6]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][8]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][6][0][11]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][0]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][6]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][7][0][7]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][2]   = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][7]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][8]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][9]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][8][0][10]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][6]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][7]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][8]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][9]  = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][10] = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[0][10][0][11] = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::DodongosCavern.IsMQ()) {
        enemyLocations[1][1][0][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][5]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][1][0][6]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][1]   = EnemyLocation(ACTOR_WITHERED_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][7]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][2][0][8]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][1]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][2]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][3]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][3][0][4]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][4]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][5]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][5][0][6]   = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][6][0][1]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][6][0][2]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][6][0][3]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][6][0][4]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][6][0][5]   = EnemyLocation(ACTOR_GOHMA_LARVA, LocationType::ABOVE_GROUND);
        enemyLocations[1][7][0][0]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][7][0][1]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][2]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][3]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][4]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][5]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][6]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][13]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][14]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][8][0][15]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][8]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][9]  = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][10][0][10] = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[1][12][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][12][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][13][0][2]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[1][13][0][3]  = EnemyLocation(ACTOR_MAD_SCRUB, LocationType::ABOVE_GROUND);
        enemyLocations[1][13][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[1][15][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][15][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][15][0][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[1][15][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::JabuJabusBelly.IsMQ()) {
        enemyLocations[2][0][0][0]   = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][7]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][8]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][0][0][9]   = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][1][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][1][0][4]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][1][0][16]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][2]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][2][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][3]   = EnemyLocation(ACTOR_BIRI, LocationType::ABOVE_GROUND);
        enemyLocations[2][3][0][10]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][4][0][7]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][4]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][5][0][5]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][6][0][0]   = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[2][7][0][0]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[2][11][0][5]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][11][0][6]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][1]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][2]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][3]  = EnemyLocation(ACTOR_TAILPASARAN, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][9]  = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][12][0][10] = EnemyLocation(ACTOR_SHABOM, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][5]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[2][13][0][6]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][0]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][1]  = EnemyLocation(ACTOR_STINGER_WATER, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[2][14][0][4]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ForestTemple.IsMQ()) {
        enemyLocations[3][0][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][1]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][0][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][1][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][1][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][1][0][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][5][0][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][6][0][0]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][6][0][1]  = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][2]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][3]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][4]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][7][0][5]  = EnemyLocation(ACTOR_DEKU_BABA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][0]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][1]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][2]  = EnemyLocation(ACTOR_OCTOROK, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][4]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][5]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][8][0][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][10][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][11][0][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][11][0][2] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][4] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][5] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][15][0][6] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][17][0][0] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][17][0][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[3][18][0][0] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[3][19][0][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][20][0][0] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][20][0][1] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[3][20][0][2] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[3][21][0][0] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::FireTemple.IsMQ()) {
        enemyLocations[4][3][0][0]  = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][4][0][3]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][6]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][8]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][9]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][10] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][5][0][11] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][7][0][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][7][0][3]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][14][0][3] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][15][0][3] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[4][17][0][2] = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[4][18][0][0] = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[4][24][0][0] = EnemyLocation(ACTOR_FLARE_DANCER, LocationType::ABOVE_GROUND);
        enemyLocations[4][25][0][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::WaterTemple.IsMQ()) {
        enemyLocations[5][2][0][1]  = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][3][0][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][3][0][6]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][2]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][3]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][6][0][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][10][0][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][1] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][2] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][3] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][4] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][5] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][6] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][14][0][7] = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[5][16][0][1] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][0] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][1] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][18][0][2] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][0] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][1] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][19][0][2] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][20][0][0] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[5][20][0][1] = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::SpiritTemple.IsMQ()) {
        enemyLocations[6][1][0][0]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][1]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][1][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][2][0][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][2][0][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][2][0][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][3][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][1]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][2]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_VOID);
        enemyLocations[6][3][0][12]  = EnemyLocation(ACTOR_ANUBIS_SPAWNER, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][0]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][1]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][2]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][3]   = EnemyLocation(ACTOR_BABY_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][4]   = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[6][4][0][11]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][5][0][0]   = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][5][0][1]   = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][5][0][20]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][2]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][3]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][4]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][18]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][8][0][20]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][9][0][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][10][0][5]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][1]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][2]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][3]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][12][0][8]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][13][0][1]  = EnemyLocation(ACTOR_MOBLIN, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][0]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][1]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][2]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][7]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][9]  = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][15][0][11] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][17][0][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][18][0][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][18][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][19][0][0]  = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[6][20][0][5]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][21][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[6][22][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][0]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][4]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][23][0][5]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][0]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][6]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][26][0][7]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[6][27][0][7]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::ShadowTemple.IsMQ()) {
        enemyLocations[7][1][0][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][1][0][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][1][0][2]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][1][0][3]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][5][0][0]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][6][0][0]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][6][0][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][6][0][2]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][6][0][3]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][7][0][0]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][7][0][1]   = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][1]   = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][2]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][8][0][3]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][5]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][6]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][7]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][9][0][10]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][11][0][8]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][11][0][9]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][3]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][5]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][13][0][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][14][0][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][15][0][0]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][15][0][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[7][15][0][2]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][0]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][1]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][2]  = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[7][16][0][3]  = EnemyLocation(ACTOR_LIKE_LIKE, LocationType::ABOVE_GROUND);
        enemyLocations[7][18][0][0]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][2]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][19][0][3]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][20][0][0]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][20][0][1]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][4]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][16] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[7][21][0][17] = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::BottomOfTheWell.IsMQ()) {
        enemyLocations[8][0][0][0] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][1] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][3] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][0][0][4] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][1] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][2] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][4] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][5] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][6] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][7] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][8] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][1][0][9] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][2][0][0] = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][0] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][3][0][1] = EnemyLocation(ACTOR_FLOORMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[8][6][0][0] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][6][0][1] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][6][0][2] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[8][6][0][3] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[8][6][0][4] = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::IceCavern.IsMQ()) {
        enemyLocations[9][1][0][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][1][0][1]   = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[9][1][0][2]   = EnemyLocation(ACTOR_TEKTITE, LocationType::ABOVE_GROUND);
        enemyLocations[9][3][0][5]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][3][0][6]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][3][0][7]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][3]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][4]   = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][5][0][6]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][6][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][6][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[9][7][0][3]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][8][0][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][8][0][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][0]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][9][0][5]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][11] = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][12] = EnemyLocation(ACTOR_WOLFOS, LocationType::ABOVE_GROUND);
        enemyLocations[9][11][0][13] = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GerudoTrainingGrounds.IsMQ()) {
        enemyLocations[11][1][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][2][0][0]  = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][2][0][17] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][2][0][21] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][4]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][5]  = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][6]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][7]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][3][0][8]  = EnemyLocation(ACTOR_SKULLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][0]  = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][5][0][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[11][6][0][1]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][6][0][2]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][6][0][3]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][0]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][1]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][2]  = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][3]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][4]  = EnemyLocation(ACTOR_DODONGO, LocationType::ABOVE_GROUND);
        enemyLocations[11][7][0][5]  = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[11][9][0][0]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[11][9][0][1]  = EnemyLocation(ACTOR_STINGER_LAND, LocationType::ABOVE_GROUND);
        enemyLocations[11][9][0][3]  = EnemyLocation(ACTOR_BARI, LocationType::ABOVE_GROUND);
        enemyLocations[11][9][0][4]  = EnemyLocation(ACTOR_SHELL_BLADE, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][0] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][1] = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][2] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][3] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
        enemyLocations[11][10][0][4] = EnemyLocation(ACTOR_SPIKE, LocationType::ABOVE_GROUND);
    }
    if (Dungeon::GanonsCastle.IsMQ()) {
        enemyLocations[13][0][0][0]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][2]   = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][9]   = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][0][0][10]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][2][0][1]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][2][0][2]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][2][0][3]   = EnemyLocation(ACTOR_FREEZARD, LocationType::ABOVE_GROUND);
        enemyLocations[13][3][0][0]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][3][0][3]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][3][0][4]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][3][0][5]   = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][5][0][1]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][5][0][2]   = EnemyLocation(ACTOR_STALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][1]   = EnemyLocation(ACTOR_ARMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][8]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][9]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][10]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][11]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][12]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][6][0][13]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][8][0][3]   = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][6]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][7]   = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][9][0][8]   = EnemyLocation(ACTOR_LIZALFOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][10][0][3]  = EnemyLocation(ACTOR_SKULLWALLTULA, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][5]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][6]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][7]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][8]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][12][0][9]  = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][1]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][2]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][14][0][16] = EnemyLocation(ACTOR_BEAMOS, LocationType::ABOVE_GROUND);
        enemyLocations[13][17][0][9]  = EnemyLocation(ACTOR_TORCH_SLUG, LocationType::ABOVE_GROUND);
        enemyLocations[13][17][0][10] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][17][0][11] = EnemyLocation(ACTOR_KEESE, LocationType::ABOVE_GROUND);
        enemyLocations[13][17][0][12] = EnemyLocation(ACTOR_IRON_KNUCKLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][6]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][7]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][8]  = EnemyLocation(ACTOR_REDEAD, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][9]  = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][10] = EnemyLocation(ACTOR_BUBBLE, LocationType::ABOVE_GROUND);
        enemyLocations[13][18][0][24] = EnemyLocation(ACTOR_WALLMASTER, LocationType::ABOVE_GROUND);
    }

    CitraPrint("EnemyLocations_Init end");
    CitraPrint("enemyLocations[10][7][0][7] is " + std::to_string(enemyLocations[10][7][0][7].vanillaActorId));
    CitraPrint("enemyLocations[11][7][0][7] is " + std::to_string(enemyLocations[11][7][0][7].vanillaActorId));
}

} // namespace Enemizer
