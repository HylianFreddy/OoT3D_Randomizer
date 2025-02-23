#pragma once

#include "../include/actor_id.h"
#include "enemizer.hpp"

using namespace Enemizer;

bool canKillPlaceholder() {
    return true;
}

ConditionFn canKillStalfos       = canKillPlaceholder;
ConditionFn canKillOctorok       = canKillPlaceholder;
ConditionFn canKillWallmaster    = canKillPlaceholder;
ConditionFn canKillDodongo       = canKillPlaceholder;
ConditionFn canKillKeese         = canKillPlaceholder;
ConditionFn canKillKeese         = canKillPlaceholder;
ConditionFn canKillKeese         = canKillPlaceholder;
ConditionFn canKillTektite       = canKillPlaceholder;
ConditionFn canKillTektite       = canKillPlaceholder;
ConditionFn canKillPeahat        = canKillPlaceholder;
ConditionFn canKillPeahatLarva   = canKillPlaceholder;
ConditionFn canKillLizalfos      = canKillPlaceholder;
ConditionFn canKillLizalfos      = canKillPlaceholder;
ConditionFn canKillGohmaLarva    = canKillPlaceholder;
ConditionFn canKillShabom        = canKillPlaceholder;
ConditionFn canKillBabyDodongo   = canKillPlaceholder;
ConditionFn canKillBiri          = canKillPlaceholder;
ConditionFn canKillBiri          = canKillPlaceholder;
ConditionFn canKillTailsparan    = canKillPlaceholder;
ConditionFn canKillSkulltula     = canKillPlaceholder;
ConditionFn canKillTorchSlug     = canKillPlaceholder;
ConditionFn canKillMoblin        = canKillPlaceholder;
ConditionFn canKillMoblin        = canKillPlaceholder;
ConditionFn canKillArmos         = canKillPlaceholder;
ConditionFn canKillDekuBaba      = canKillPlaceholder;
ConditionFn canKillDekuBaba      = canKillPlaceholder;
ConditionFn canKillScrub         = canKillPlaceholder;
ConditionFn canKillBlueBubble    = canKillPlaceholder;
ConditionFn canKillBeamos        = canKillPlaceholder;
ConditionFn canKillBeamos        = canKillPlaceholder;
ConditionFn canKillFloormaster   = canKillPlaceholder;
ConditionFn canKillRedead        = canKillPlaceholder;
ConditionFn canKillRedead        = canKillPlaceholder;
ConditionFn canKillSkullwalltula = canKillPlaceholder;
ConditionFn canKillFlareDancer   = canKillPlaceholder;
ConditionFn canKillShellBlade    = canKillPlaceholder;
ConditionFn canKillLikeLike      = canKillPlaceholder;
ConditionFn canKillSpikeEnemy    = canKillPlaceholder;
ConditionFn canKillAnubis        = canKillPlaceholder;
ConditionFn canKillIronKnuckle   = canKillPlaceholder;
ConditionFn canKillIronKnuckle   = canKillPlaceholder;
ConditionFn canKillSkullKid      = canKillPlaceholder;
ConditionFn canKillFreezard      = canKillPlaceholder;
ConditionFn canKillStinger       = canKillPlaceholder;
ConditionFn canKillStinger       = canKillPlaceholder;
ConditionFn canKillWolfos        = canKillPlaceholder;
ConditionFn canKillBasic         = canKillPlaceholder;
ConditionFn canKillDarkLink      = canKillPlaceholder;
ConditionFn canKillDeadHand      = canKillPlaceholder;

// clang-format off
std::vector<Enemy> enemyTypes = {
    Enemy("Stalfos",              ACTOR_STALFOS,            0x0003, canKillStalfos,       {LocationType::ABOVE_GROUND}),
    Enemy("Octorok",              ACTOR_OCTOROK,            0x0000, canKillOctorok,       {LocationType::ABOVE_WATER}),
    Enemy("Wallmaster",           ACTOR_WALLMASTER,         0x0000, canKillWallmaster,    {LocationType::ABOVE_GROUND}),
    Enemy("Dodongo",              ACTOR_DODONGO,            0x0000, canKillDodongo,       {LocationType::ABOVE_GROUND}),
    Enemy("Keese",                ACTOR_KEESE,              0x0002, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Fire Keese",           ACTOR_KEESE,              0x0000, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Ice Keese",            ACTOR_KEESE,              0x0004, canKillKeese,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Tektite",              ACTOR_TEKTITE,            0x0000, canKillTektite,       {LocationType::ABOVE_GROUND}),
    Enemy("Tektite (Blue)",       ACTOR_TEKTITE,            0xFFFE, canKillTektite,       {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Peahat",               ACTOR_PEAHAT,             0xFFFF, canKillPeahat,        {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Peahat Larva",         ACTOR_PEAHAT,             0x0000, canKillPeahatLarva,   {LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Lizalfos",             ACTOR_LIZALFOS,           0xFF80, canKillLizalfos,      {LocationType::ABOVE_GROUND}),
    Enemy("Dinolfos",             ACTOR_LIZALFOS,           0xFFFE, canKillLizalfos,      {LocationType::ABOVE_GROUND}),
    Enemy("Gohma Larva",          ACTOR_GOHMA_LARVA,        0x0006, canKillGohmaLarva,    {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Shabom",               ACTOR_SHABOM,             0x0000, canKillShabom,        {LocationType::UNDERWATER, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Baby Dodongo",         ACTOR_BABY_DODONGO,       0x0000, canKillBabyDodongo,   {LocationType::ABOVE_GROUND}),
    Enemy("Biri",                 ACTOR_BIRI,               0x0000, canKillBiri,          {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    Enemy("Bari",                 ACTOR_BARI,               0x0000, canKillBiri,          {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Tailpasaran",          ACTOR_TAILPASARAN,        0xFFFF, canKillTailsparan,    {LocationType::ABOVE_GROUND}),
    Enemy("Skulltula",            ACTOR_SKULLTULA,          0x0000, canKillSkulltula,     {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND}),
    Enemy("Torch Slug",           ACTOR_TORCH_SLUG,         0x0000, canKillTorchSlug,     {LocationType::ABOVE_GROUND}),
    Enemy("Moblin",               ACTOR_MOBLIN,             0x0002, canKillMoblin,        {LocationType::ABOVE_GROUND}),
    Enemy("Moblin (Spear)",       ACTOR_MOBLIN,             0xFFFF, canKillMoblin,        {LocationType::ABOVE_GROUND}),
    Enemy("Armos",                ACTOR_ARMOS,              0xFFFF, canKillArmos,         {LocationType::ABOVE_GROUND}),
    Enemy("Deku Baba",            ACTOR_DEKU_BABA,          0x0000, canKillDekuBaba,      {LocationType::ABOVE_GROUND}),
    Enemy("Whithered Deku Baba",  ACTOR_WITHERED_DEKU_BABA, 0x0000, canKillDekuBaba,      {LocationType::ABOVE_GROUND}),
    Enemy("Mad Scrub",            ACTOR_MAD_SCRUB,          0x0000, canKillScrub,         {LocationType::UNDERWATER}),
    Enemy("Bubble",               ACTOR_BUBBLE,             0xFFFF, canKillBlueBubble,    {LocationType::ABOVE_GROUND}),
    Enemy("Beamos (Large)",       ACTOR_BEAMOS,             0x0500, canKillBeamos,        {LocationType::ABOVE_GROUND}),
    Enemy("Beamos (Small)",       ACTOR_BEAMOS,             0x0501, canKillBeamos,        {LocationType::ABOVE_GROUND}),
    Enemy("Floormaster",          ACTOR_FLOORMASTER,        0x0000, canKillFloormaster,   {LocationType::ABOVE_GROUND}),
    Enemy("Redead",               ACTOR_REDEAD,             0x7F02, canKillRedead,        {LocationType::ABOVE_GROUND}),
    Enemy("Gibdo",                ACTOR_REDEAD,             0x7FFE, canKillRedead,        {LocationType::ABOVE_GROUND}),
    Enemy("Skullwalltula",        ACTOR_SKULLWALLTULA,      0x0000, canKillSkullwalltula, {LocationType::UNDERWATER}),
    Enemy("Flare Dancer",         ACTOR_FLARE_DANCER,       0x0000, canKillFlareDancer,   {LocationType::ABOVE_GROUND}),
    Enemy("Shell Blade",          ACTOR_SHELL_BLADE,        0x0000, canKillShellBlade,    {LocationType::UNDERWATER, LocationType::ABOVE_GROUND}),
    Enemy("Like Like",            ACTOR_LIKE_LIKE,          0x0000, canKillLikeLike,      {LocationType::ABOVE_GROUND}),
    Enemy("Spike Enemy",          ACTOR_SPIKE,              0x0000, canKillSpikeEnemy,    {LocationType::ABOVE_GROUND}),
    Enemy("Anubis Spawner",       ACTOR_ANUBIS_SPAWNER,     0x0003, canKillAnubis,        {LocationType::ABOVE_VOID}),
    Enemy("Iron Knuckle (Black)", ACTOR_IRON_KNUCKLE,       0xFF82, canKillIronKnuckle,   {LocationType::ABOVE_GROUND}),
    Enemy("Iron Knuckle (White)", ACTOR_IRON_KNUCKLE,       0xFF83, canKillIronKnuckle,   {LocationType::ABOVE_GROUND}),
    Enemy("Skull Kid",            ACTOR_SKULL_KID,          0xFFFF, canKillSkullKid,      {LocationType::ABOVE_GROUND}),
    Enemy("Freezard",             ACTOR_FREEZARD,           0x0000, canKillFreezard,      {LocationType::ABOVE_GROUND}),
    Enemy("Stinger",              ACTOR_STINGER_WATER,      0x0000, canKillStinger,       {LocationType::UNDERWATER}),
    Enemy("Stingray",             ACTOR_STINGER_LAND,       0x000A, canKillStinger,       {LocationType::UNDERWATER}),
    Enemy("Wolfos",               ACTOR_WOLFOS,             0xFF00, canKillWolfos,        {LocationType::ABOVE_GROUND}),
    Enemy("Guay",                 ACTOR_GUAY,               0x0000, canKillBasic,         {LocationType::UNDERWATER, LocationType::ABOVE_VOID, LocationType::ABOVE_GROUND, LocationType::ABOVE_WATER}),
    // Enemy("Dark Link",            ACTOR_DARK_LINK,          0x0000, canKillDarkLink,      {LocationType::ABOVE_GROUND}),
    // Enemy("Dead Hand",            ACTOR_DEAD_HAND,          0xFFFF, canKillDeadHand,      {LocationType::ABOVE_GROUND}),
};
// clang-format on
