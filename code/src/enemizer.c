#include "enemizer.h"
#include "objects.h"
#include "common.h"

static EnemyData sEnemyData[] = {
    { .actorId = 0x00D, .params = 0x0000 }, // Poe & Composer Brothers
    { .actorId = 0x00E, .params = 0x0000 }, // Octorok
    { .actorId = 0x011, .params = 0x0000 }, // Wallmaster
    { .actorId = 0x012, .params = 0x0000 }, // Dodongo
    { .actorId = 0x013, .params = 0x0002 }, // Keese
    { .actorId = 0x013, .params = 0x0001 }, //  Fire Keese
    { .actorId = 0x013, .params = 0x0004 }, //  Ice Keese
    { .actorId = 0x01B, .params = 0xFFFF }, // Tektite (Red)
    { .actorId = 0x01B, .params = 0xFFFE }, //  Tektite (Blue)
    { .actorId = 0x01C, .params = 0x0000 }, // Leever
    { .actorId = 0x01D, .params = 0xFFFF }, // Peahat
    { .actorId = 0x01D, .params = 0x0001 }, //  Peahat Larva
    { .actorId = 0x025, .params = 0xFFFF }, // Lizalfos
    { .actorId = 0x025, .params = 0xFFFE }, //  Dinolfos
    { .actorId = 0x02B, .params = 0x0007 }, // Gohma Egg
    { .actorId = 0x02D, .params = 0x0000 }, // Shabom
    { .actorId = 0x02F, .params = 0x0000 }, // Baby Dodongo
    { .actorId = 0x034, .params = 0xFFFF }, // Biri
    { .actorId = 0x035, .params = 0xFFFF }, // Tailpasaran
    { .actorId = 0x037, .params = 0x0000 }, // Skulltula
    { .actorId = 0x037, .params = 0x0001 }, //  Skulltula (Big)
    { .actorId = 0x038, .params = 0xFFFF }, // Torch Slug
    { .actorId = 0x03A, .params = 0x000A }, // Stinger (Land)
    { .actorId = 0x04B, .params = 0x0000 }, // Moblin (club)
    { .actorId = 0x04B, .params = 0x00FF }, //  Moblin (spear)
    { .actorId = 0x054, .params = 0xFFFF }, // Armos (Enemy)
    { .actorId = 0x055, .params = 0x0000 }, // Deku Baba
    { .actorId = 0x055, .params = 0x0001 }, //  Deku Baba (Big)
    { .actorId = 0x060, .params = 0x0300 }, // Mad Scrub
    { .actorId = 0x063, .params = 0xFFFF }, // Bari
    { .actorId = 0x069, .params = 0xFFFF }, // Bubble (blue)
    { .actorId = 0x069, .params = 0xFFFE }, //  Bubble (fire)
    { .actorId = 0x06B, .params = 0x0000 }, // Flying Floor Tile
    { .actorId = 0x08A, .params = 0x0500 }, // Beamos
    { .actorId = 0x08A, .params = 0x0501 }, // Beamos
    { .actorId = 0x08E, .params = 0x0000 }, // Floormaster
    { .actorId = 0x090, .params = 0x7F01 }, // Redead
    { .actorId = 0x090, .params = 0x7FFE }, //  Gibdo
    { .actorId = 0x0C5, .params = 0x0000 }, // Shell Blade
    { .actorId = 0x0C7, .params = 0x0000 }, // Withered Deku Baba
    { .actorId = 0x0DD, .params = 0x0000 }, // Like Like
    { .actorId = 0x0E0, .params = 0x0000 }, // Anubis
    { .actorId = 0x0EC, .params = 0x0000 }, // Spike
    { .actorId = 0x115, .params = 0x0000 }, // Skull Kid (Hostile)
    { .actorId = 0x11D, .params = 0x0000 }, // Flying Pot
    { .actorId = 0x121, .params = 0x0000 }, // Freezard
    { .actorId = 0x121, .params = 0xFFFF }, //  Freezard (mobile)
    { .actorId = 0x18C, .params = 0xFFFF }, // Stinger (Water)
    { .actorId = 0x1AF, .params = 0xFF00 }, // Wolfos
    { .actorId = 0x1AF, .params = 0xFF01 }, //  White Wolfos
    { .actorId = 0x1B0, .params = 0x0000 }, // Stalchild
    { .actorId = 0x1B0, .params = 0x0005 }, //  Stalchild (20 kills)
    { .actorId = 0x1C0, .params = 0x0000 }, // Guay

    { .actorId = 0x095, .params = 0x0000 }, // Skullwalltula
    { .actorId = 0x0DE, .params = 0x0000 }, // Parasitic Tentacle

};

static EnemyObjectDependency sEnemyObjectDeps[] = {
    { .actorId = 0x00D, .objectId = 0x009 }, // Poe
    { .actorId = 0x063, .objectId = 0x021 }, // Bari -> Biri
};

void Enemizer_OverrideActorEntry(ActorEntry* actorEntry) {
    u8 isRandomizedEnemy = FALSE;
    for (u32 i = 0; i < ARRAY_SIZE(sEnemyData); i++) {
        if (actorEntry->id == sEnemyData[i].actorId) {
            isRandomizedEnemy = TRUE;
            break;
        }
    }

    if (isRandomizedEnemy) {
        u32 seed = (u16)actorEntry->id + (u16)actorEntry->params + actorEntry->pos.x + actorEntry->pos.y +
                   actorEntry->pos.z + actorEntry->rot.x + actorEntry->rot.y + actorEntry->rot.z;
        u32 index             = Hash(seed) % ARRAY_SIZE(sEnemyData);
        EnemyData randomEnemy = sEnemyData[index];
        actorEntry->id        = randomEnemy.actorId;
        actorEntry->params    = randomEnemy.params;
        Object_FindOrSpawnEntry(gActorOverlayTable[randomEnemy.actorId].initInfo->objectId);

        for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
            if (actorEntry->id == sEnemyObjectDeps[i].actorId) {
                Object_FindOrSpawnEntry(sEnemyObjectDeps[i].objectId);
            }
        }
    }
}
