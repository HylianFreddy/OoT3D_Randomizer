#include "enemizer.h"

EnemyData sEnemyData[ENEMY_DATA_SIZE] = {
    { .actorId = 0x00D, .params = 0x0000, .objectId = 0x009 }, // Poe & Composer Brothers
    { .actorId = 0x00E, .params = 0x0000, .objectId = 0x007 }, // Octorok
    { .actorId = 0x011, .params = 0x0000, .objectId = 0x00B }, // Wallmaster
    { .actorId = 0x012, .params = 0x0000, .objectId = 0x00C }, // Dodongo
    { .actorId = 0x013, .params = 0x0002, .objectId = 0x00D }, // Keese
    { .actorId = 0x013, .params = 0x0001, .objectId = 0x00D }, //  Fire Keese
    { .actorId = 0x013, .params = 0x0004, .objectId = 0x00D }, //  Ice Keese
    { .actorId = 0x01B, .params = 0xFFFF, .objectId = 0x016 }, // Tektite (Red)
    { .actorId = 0x01B, .params = 0xFFFE, .objectId = 0x016 }, //  Tektite (Blue)
    { .actorId = 0x01C, .params = 0x0000, .objectId = 0x017 }, // Leever
    { .actorId = 0x01D, .params = 0xFFFF, .objectId = 0x018 }, // Peahat
    { .actorId = 0x01D, .params = 0x0001, .objectId = 0x018 }, //  Peahat Larva
    { .actorId = 0x025, .params = 0xFFFF, .objectId = 0x01B }, // Lizalfos
    { .actorId = 0x025, .params = 0xFFFE, .objectId = 0x01B }, //  Dinolfos
    { .actorId = 0x02B, .params = 0x0007, .objectId = 0x01E }, // Gohma Egg
    { .actorId = 0x02D, .params = 0x0000, .objectId = 0x012 }, // Shabom
    { .actorId = 0x02F, .params = 0x0000, .objectId = 0x01F }, // Baby Dodongo
    { .actorId = 0x034, .params = 0xFFFF, .objectId = 0x021 }, // Biri
    { .actorId = 0x035, .params = 0xFFFF, .objectId = 0x022 }, // Tailpasaran
    { .actorId = 0x037, .params = 0x0000, .objectId = 0x024 }, // Skulltula
    { .actorId = 0x037, .params = 0x0001, .objectId = 0x024 }, //  Skulltula (Big)
    { .actorId = 0x038, .params = 0xFFFF, .objectId = 0x025 }, // Torch Slug
    { .actorId = 0x03A, .params = 0x000A, .objectId = 0x026 }, // Stinger (Land)
    { .actorId = 0x04B, .params = 0x0000, .objectId = 0x030 }, // Moblin (club)
    { .actorId = 0x04B, .params = 0x00FF, .objectId = 0x030 }, //  Moblin (spear)
    { .actorId = 0x054, .params = 0xFFFF, .objectId = 0x038 }, // Armos (Enemy)
    { .actorId = 0x055, .params = 0x0000, .objectId = 0x039 }, // Deku Baba
    { .actorId = 0x055, .params = 0x0001, .objectId = 0x039 }, //  Deku Baba (Big)
    { .actorId = 0x060, .params = 0x0300, .objectId = 0x04A }, // Mad Scrub
    { .actorId = 0x063, .params = 0xFFFF, .objectId = 0x056 }, // Bari

    // { .actorId = 0x069, .params = 0x0000, .objectId = 0x000 }, // Bubble
    // { .actorId = 0x06B, .params = 0x0000, .objectId = 0x000 }, // Flying Floor Tile
    // { .actorId = 0x08A, .params = 0x0000, .objectId = 0x000 }, // Beamos
    // { .actorId = 0x08E, .params = 0x0000, .objectId = 0x000 }, // Floormaster
    // { .actorId = 0x090, .params = 0x0000, .objectId = 0x000 }, // Redead & Gibdo
    // { .actorId = 0x095, .params = 0x0000, .objectId = 0x000 }, // Skullwalltula
    // { .actorId = 0x0C5, .params = 0x0000, .objectId = 0x000 }, // Shell Blade
    // { .actorId = 0x0C7, .params = 0x0000, .objectId = 0x000 }, // Wilted Deku Baba
    // { .actorId = 0x0DD, .params = 0x0000, .objectId = 0x000 }, // Like Like
    // { .actorId = 0x0DE, .params = 0x0000, .objectId = 0x000 }, // Parasitic Tentacle
    // { .actorId = 0x0E0, .params = 0x0000, .objectId = 0x000 }, // Anubis
    // { .actorId = 0x0E1, .params = 0x0000, .objectId = 0x000 }, // Anubis Fire
    // { .actorId = 0x0EC, .params = 0x0000, .objectId = 0x000 }, // Spike Trap
    // { .actorId = 0x115, .params = 0x0000, .objectId = 0x000 }, // Skull Kid (Hostile)
    // { .actorId = 0x116, .params = 0x0000, .objectId = 0x000 }, // Skull Kid's Needle
    // { .actorId = 0x11D, .params = 0x0000, .objectId = 0x000 }, // Flying Pot
    // { .actorId = 0x121, .params = 0x0000, .objectId = 0x000 }, // Freezard
    // { .actorId = 0x175, .params = 0x0000, .objectId = 0x000 }, // Big Poe
    { .actorId = 0x18C, .params = 0xFFFF, .objectId = 0x026 }, // Stinger (Water)
    // { .actorId = 0x192, .params = 0x0000, .objectId = 0x000 }, // Deku Scrub (Deku Tree)
    // { .actorId = 0x193, .params = 0x0000, .objectId = 0x000 }, // Deku Scrub Projectile
    // { .actorId = 0x195, .params = 0x0000, .objectId = 0x000 }, // Business Scrub (Hostile)
    // { .actorId = 0x1AF, .params = 0x0000, .objectId = 0x000 }, // Wolfos
    // { .actorId = 0x1B0, .params = 0x0000, .objectId = 0x000 }, // Stalchild
    // { .actorId = 0x1C0, .params = 0x0000, .objectId = 0x000 }, // Guay
    // { .actorId = 0x1C1, .params = 0x0000, .objectId = 0x000 }, // Door Mimic
};
