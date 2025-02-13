#include "enemizer.h"
#include "objects.h"
#include "common.h"

static EnemyData sEnemyData[] = {
    { .actorId = 0x00D, .params = 0x0000, .objectId = 0x001 }, // Poe & Composer Brothers
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
    { .actorId = 0x069, .params = 0xFFFF, .objectId = 0x05d }, // Bubble (blue)
    { .actorId = 0x069, .params = 0xFFFE, .objectId = 0x05d }, //  Bubble (fire)
    { .actorId = 0x06B, .params = 0x0000, .objectId = 0x05f }, // Flying Floor Tile
    { .actorId = 0x08A, .params = 0x0500, .objectId = 0x08b }, // Beamos
    { .actorId = 0x08A, .params = 0x0501, .objectId = 0x08b }, // Beamos
    { .actorId = 0x08E, .params = 0x0000, .objectId = 0x00b }, // Floormaster
    { .actorId = 0x090, .params = 0x7F01, .objectId = 0x098 }, // Redead
    { .actorId = 0x090, .params = 0x7FFE, .objectId = 0x098 }, //  Gibdo
    { .actorId = 0x0C5, .params = 0x0000, .objectId = 0x0b5 }, // Shell Blade
    { .actorId = 0x0C7, .params = 0x0000, .objectId = 0x039 }, // Withered Deku Baba
    { .actorId = 0x0DD, .params = 0x0000, .objectId = 0x0d4 }, // Like Like
    { .actorId = 0x0E0, .params = 0x0000, .objectId = 0x0d6 }, // Anubis
    { .actorId = 0x0EC, .params = 0x0000, .objectId = 0x0E5 }, // Spike
    { .actorId = 0x115, .params = 0x0000, .objectId = 0x10A }, // Skull Kid (Hostile)
    { .actorId = 0x11D, .params = 0x0000, .objectId = 0x003 }, // Flying Pot
    { .actorId = 0x121, .params = 0x0000, .objectId = 0x114 }, // Freezard
    { .actorId = 0x121, .params = 0xFFFF, .objectId = 0x114 }, //  Freezard (mobile)
    { .actorId = 0x18C, .params = 0xFFFF, .objectId = 0x026 }, // Stinger (Water)
    { .actorId = 0x1AF, .params = 0xFF00, .objectId = 0x183 }, // Wolfos
    { .actorId = 0x1AF, .params = 0xFF01, .objectId = 0x183 }, //  White Wolfos
    { .actorId = 0x1B0, .params = 0x0000, .objectId = 0x184 }, // Stalchild
    { .actorId = 0x1B0, .params = 0x0005, .objectId = 0x184 }, //  Stalchild (20 kills)
    { .actorId = 0x1C0, .params = 0x0000, .objectId = 0x008 }, // Guay

    { .actorId = 0x095, .params = 0x0000, .objectId = 0x024 }, // Skullwalltula
    { .actorId = 0x0DE, .params = 0x0000, .objectId = 0x0d5 }, // Parasitic Tentacle

};

static EnemyObjectDependency sEnemyObjectDeps[] = {
    { .actorId = 0x00D, .objectId = 0x009 }, // Poe
    { .actorId = 0x063, .objectId = 0x021 }, // Bari -> Biri
};

void Enemizer_OverrideActorEntry(ActorEntry* actorEntry) {

    // TODO: for each actor, check if it's randomized, call Hash to get random index,
    // access some custom table to get object and params

    // if (Object_GetIndex(&gGlobalContext->objectCtx, objId) < 0) {
    //     ExtendedObject_Spawn(objId);
    // }

    u16* actorId = (u16*)&actorEntry->id;
    u16* params  = (u16*)&actorEntry->params;

    u8 isRandomizedEnemy = FALSE;
    for (u32 i = 0; i < ARRAY_SIZE(sEnemyData); i++) {
        if (*actorId == sEnemyData[i].actorId) {
            isRandomizedEnemy = TRUE;
            break;
        }
    }

    if (isRandomizedEnemy) {
        u32 seed = *actorId + *params + actorEntry->pos.x + actorEntry->pos.y + actorEntry->pos.z + actorEntry->rot.x +
                   actorEntry->rot.y + actorEntry->rot.z;
        u32 index             = Hash(seed) % ARRAY_SIZE(sEnemyData);
        EnemyData randomEnemy = sEnemyData[index];
        *actorId              = randomEnemy.actorId;
        *params               = randomEnemy.params;
        Object_FindOrSpawn(gActorOverlayTable[randomEnemy.actorId].initInfo->objectId);

        for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
            if (*actorId == sEnemyObjectDeps[i].actorId) {
                Object_FindOrSpawn(sEnemyObjectDeps[i].objectId);
            }
        }
    }

    // CitraPrint("%4X %4X", *actorId, *params);
    // if (EnemySouls_GetSoulId(*actorId) != SOUL_NONE && *actorId != 0xAB) {
    //     // flare dancer
    //     // *actorId = 0x99;
    //     // *params  = 0x0;
    //     // tektite
    //     // *actorId = 0x1B;
    //     // *params  = 0xFFFE;
    //     // stalfos
    //     // *actorId = 0x2;
    //     // *params  = 0x3;
    //     // octorok
    //     // *actorId = 0x0E;
    //     // *params  = 0xFF00;
    //     // freezard
    //     // *actorId = 0x121;
    //     // *params  = 0x0;
    //     // lizalfos
    //     *actorId = 0x25;
    //     *params  = 0x80;
    // }
}
