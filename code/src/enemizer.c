#include "enemizer.h"
#include "objects.h"
#include "common.h"

static EnemyData sEnemyData[] = {
    { .actorId = 0x00D, .params = 0x0000 }, // Poe
    { .actorId = 0x00E, .params = 0x0000 }, // Octorok [requires water]
    { .actorId = 0x011, .params = 0x0000 }, // Wallmaster
    { .actorId = 0x012, .params = 0x0000 }, // Dodongo [gets stuck in mid-air]
    { .actorId = 0x013, .params = 0x0002 }, // Keese
    { .actorId = 0x013, .params = 0x0001 }, //  Fire Keese
    { .actorId = 0x013, .params = 0x0004 }, //  Ice Keese
    { .actorId = 0x01B, .params = 0xFFFF }, // Tektite (Red) [doesn't float in water]
    { .actorId = 0x01B, .params = 0xFFFE }, //  Tektite (Blue)
    { .actorId = 0x01C, .params = 0x0000 }, // Leever [doesn't spawn]
    { .actorId = 0x01D, .params = 0xFFFF }, // Peahat
    { .actorId = 0x01D, .params = 0x0001 }, //  Peahat Larva [insta die if on floor]
    { .actorId = 0x025, .params = 0xFF80 }, // Lizalfos
    { .actorId = 0x025, .params = 0xFFFF }, //  Lizalfos (drops)
    { .actorId = 0x025, .params = 0xFFFE }, //  Dinolfos
    { .actorId = 0x02B, .params = 0x0007 }, // Gohma Egg
    { .actorId = 0x02D, .params = 0x0000 }, // Shabom
    { .actorId = 0x02F, .params = 0x0000 }, // Baby Dodongo [burrows immediately in water, doesn't spawn in mid-air]
    { .actorId = 0x034, .params = 0xFFFF }, // Biri
    { .actorId = 0x035, .params = 0xFFFF }, // Tailpasaran [weird in mid-air]
    { .actorId = 0x037, .params = 0x0000 }, // Skulltula [works, but maybe should move up a bit?]
    { .actorId = 0x037, .params = 0x0001 }, //  Skulltula (Big)
    { .actorId = 0x038, .params = 0xFFFF }, // Torch Slug [works, but doesn't look good in water]
    { .actorId = 0x03A, .params = 0x000A }, // Stinger (Land) [works, but doesn't look good in water]
    { .actorId = 0x04B, .params = 0x0000 }, // Moblin (club) [doesn't turn]
    // { .actorId = 0x04B, .params = 0x00FF }, //  Moblin (spear) [follows broken path, can crash]
    { .actorId = 0x054, .params = 0xFFFF }, // Armos (Enemy)
    { .actorId = 0x055, .params = 0x0000 }, // Deku Baba [doesn't fall]
    { .actorId = 0x055, .params = 0x0001 }, //  Deku Baba (Big)
    { .actorId = 0x060, .params = 0x0300 }, // Mad Scrub [flower doesn't fall]
    { .actorId = 0x063, .params = 0xFFFF }, // Bari [doesn't spawn if underground]
    { .actorId = 0x069, .params = 0xFFFF }, // Bubble (blue)
    { .actorId = 0x069, .params = 0xFFFE }, //  Bubble (fire)
    { .actorId = 0x06B, .params = 0x0000 }, // Flying Floor Tile [spawns a ton of particles, causing soft-crashes]
    { .actorId = 0x08A, .params = 0x0501 }, // Beamos [doesn't fall]
    { .actorId = 0x08A, .params = 0x0500 }, //  Beamos (big)
    { .actorId = 0x08E, .params = 0x0000 }, // Floormaster
    { .actorId = 0x090, .params = 0x7F01 }, // Redead [doesn't fall]
    { .actorId = 0x090, .params = 0x7FFE }, //  Gibdo
    { .actorId = 0x0C5, .params = 0x0000 }, // Shell Blade
    { .actorId = 0x0C7, .params = 0x0000 }, // Withered Deku Baba [doesn't fall]
    { .actorId = 0x0DD, .params = 0x0000 }, // Like Like
    { .actorId = 0x0E0, .params = 0x0000 }, // Anubis [stuck waiting for flame circle?]
    { .actorId = 0x0EC, .params = 0x0000 }, // Spike
    { .actorId = 0x115, .params = 0xFFFF }, // Skull Kid (Hostile) [despawns before poacher saw, is hostile as child too]
    { .actorId = 0x11D, .params = 0x0000 }, // Flying Pot [doesn't fall]
    { .actorId = 0x121, .params = 0x0000 }, // Freezard
    { .actorId = 0x121, .params = 0xFFFF }, //  Freezard (mobile) [spawns in mid-air before falling]
    { .actorId = 0x18C, .params = 0xFFFF }, // Stinger (Water) [doesn't spawn outside water?]
    { .actorId = 0x1AF, .params = 0xFF00 }, // Wolfos [spawns in mid-air before falling]
    { .actorId = 0x1AF, .params = 0xFF01 }, //  White Wolfos
    { .actorId = 0x1B0, .params = 0x0000 }, // Stalchild [burrows immediately]
    { .actorId = 0x1B0, .params = 0x0005 }, //  Stalchild (20 kills)
    { .actorId = 0x1C0, .params = 0x0000 }, // Guay [doesn't actually die so can't clear rooms]

    { .actorId = 0x002, .params = 0x0002 }, // Stalfos [doesn't fall]
    { .actorId = 0x002, .params = 0x0003 }, //  Stalfos (falls from above)
    // { .actorId = 0x033, .params = 0xFFFF }, // Dark Link
    // { .actorId = 0x091, .params = 0x0300 }, // Poe Sisters [meg and amy work, the others move to default Forest Temple pos]
    // { .actorId = 0x099, .params = 0x0000 }, // Flare Dancer [should limit count, too many will crash]
    // { .actorId = 0x0A4, .params = 0x0000 }, // Dead Hand
    { .actorId = 0x0A5, .params = 0x0000 }, // Dead Hand's Hands [doesn't actually die so can't clear rooms]
    // { .actorId = 0x0C6, .params = 0x0001 }, // Big Octo
    { .actorId = 0x113, .params = 0xFF02 }, // Iron Knuckle [killing one seems to set clear flag or something]
    { .actorId = 0x113, .params = 0xFF03 }, //  Iron Knuckle (white)
    // { .actorId = 0x197, .params = 0x0000 }, // Gerudo Fighter [weird flag isues, only one spawns]

    // { .actorId = 0x095, .params = 0x0000 }, // Skullwalltula
    // { .actorId = 0x0DE, .params = 0x0000 }, // Parasitic Tentacle
};

s32 mockIndex = ARRAY_SIZE(sEnemyData) - 6;

static EnemyObjectDependency sEnemyObjectDeps[] = {
    { .actorId = 0x00D, .objectId = 0x009 }, // Poe (actor profile only points to object 1)
    { .actorId = 0x063, .objectId = 0x021 }, // Bari -> Biri
    { .actorId = 0x012, .objectId = 0x003 }, // Dodongo -> dungeon object for fire breath
    { .actorId = 0x02B, .objectId = 0x003 }, // Gohma Egg -> dungeon object for egg fragments
    { .actorId = 0x099, .objectId = 0x003 }, // Flare Dancer -> dungeon object for flames
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
        // u32 seed = (u16)actorEntry->id + (u16)actorEntry->params + actorEntry->pos.x + actorEntry->pos.y +
        //            actorEntry->pos.z + actorEntry->rot.x + actorEntry->rot.y + actorEntry->rot.z;
        // u32 index             = Hash(seed) % ARRAY_SIZE(sEnemyData);
        extern s32 mockIndex;
        EnemyData randomEnemy = sEnemyData[mockIndex];
        // if (actorEntry->id == 0x37) {
        //     CitraPrint("%X", randomEnemy.actorId);
        // }
        actorEntry->id        = randomEnemy.actorId;
        actorEntry->params    = randomEnemy.params;
        // actorEntry->pos.y += 50;
        Object_FindOrSpawnEntry(gActorOverlayTable[randomEnemy.actorId].initInfo->objectId);

        for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
            if (actorEntry->id == sEnemyObjectDeps[i].actorId) {
                Object_FindOrSpawnEntry(sEnemyObjectDeps[i].objectId);
            }
        }
    }
}
