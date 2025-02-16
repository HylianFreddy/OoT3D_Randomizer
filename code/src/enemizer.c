#include "enemizer.h"
#include "objects.h"
#include "common.h"

// todo armos

static EnemyData sEnemyData[] = {
    { .actorId = 0x00D, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Poe
    // { .actorId = 0x00E, .params = 0x0000, .requirements = REQ_WATER }, // Octorok [requires water and snaps to surface]
    { .actorId = 0x011, .params = 0x0000, .requirements = 0 }, // Wallmaster
    { .actorId = 0x012, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Dodongo [gets stuck in mid-air]
    { .actorId = 0x013, .params = 0x0002, .requirements = REQ_NO_WATER }, // Keese
    { .actorId = 0x013, .params = 0x0001, .requirements = REQ_NO_WATER }, //  Fire Keese
    { .actorId = 0x013, .params = 0x0004, .requirements = REQ_NO_WATER }, //  Ice Keese
    { .actorId = 0x01B, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Tektite (Red) [doesn't float in water]
    { .actorId = 0x01B, .params = 0xFFFE, .requirements = REQ_ABOVE_GROUND }, //  Tektite (Blue)
    // { .actorId = 0x01C, .params = 0x0000, .requirements = 0 }, // Leever [doesn't spawn]
    { .actorId = 0x01D, .params = 0xFFFF, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Peahat [doesn't fall]
    { .actorId = 0x01D, .params = 0x0001, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER }, //  Peahat Larva [insta die if on floor]
    { .actorId = 0x025, .params = 0xFF80, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER}, // Lizalfos
    { .actorId = 0x025, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER}, //  Lizalfos (drops)
    { .actorId = 0x025, .params = 0xFFFE, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Dinolfos
    { .actorId = 0x02B, .params = 0x0007, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Gohma Egg
    { .actorId = 0x02D, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Shabom
    { .actorId = 0x02F, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Baby Dodongo [burrows immediately in water, doesn't spawn in mid-air]
    { .actorId = 0x034, .params = 0xFFFF, .requirements = 0 }, // Biri
    { .actorId = 0x035, .params = 0xFFFF, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Tailpasaran [weird in mid-air]
    { .actorId = 0x037, .params = 0x0000, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER }, // Skulltula [works, but maybe should move up a bit?]
    { .actorId = 0x037, .params = 0x0001, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER }, //  Skulltula (Big)
    { .actorId = 0x038, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Torch Slug [works, but doesn't look good in water]
    { .actorId = 0x03A, .params = 0x000A, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Stinger (Land) [works, but doesn't look good in water]
    { .actorId = 0x04B, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Moblin (club) [doesn't turn]
    // { .actorId = 0x04B, .params = 0x00FF, .requirements = 0 }, //  Moblin (spear) [follows broken path, can crash]
    { .actorId = 0x054, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Armos (Enemy)
    { .actorId = 0x055, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Deku Baba [doesn't fall]
    { .actorId = 0x055, .params = 0x0001, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, //  Deku Baba (Big)
    { .actorId = 0x060, .params = 0x0300, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Mad Scrub [flower doesn't fall]
    { .actorId = 0x063, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND_IN_AIR }, // Bari [doesn't spawn if underground]
    { .actorId = 0x069, .params = 0xFFFF, .requirements = REQ_NO_WATER }, // Bubble (blue)
    { .actorId = 0x069, .params = 0xFFFE, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, //  Bubble (fire)
    { .actorId = 0x06B, .params = 0x0000, .requirements = REQ_ON_GROUND }, // Flying Floor Tile [spawns a ton of particles, causing soft-crashes]
    { .actorId = 0x08A, .params = 0x0501, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Beamos [doesn't fall]
    { .actorId = 0x08A, .params = 0x0500, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, //  Beamos (big)
    { .actorId = 0x08E, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Floormaster
    { .actorId = 0x090, .params = 0x7F01, .requirements = REQ_ON_GROUND | REQ_NO_WATER  }, // Redead [doesn't fall]
    { .actorId = 0x090, .params = 0x7FFE, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, //  Gibdo
    { .actorId = 0x0C5, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Shell Blade
    { .actorId = 0x0C7, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Withered Deku Baba [doesn't fall]
    { .actorId = 0x0DD, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Like Like
    // { .actorId = 0x0E0, .params = 0x0000, .requirements = 0 }, // Anubis [stuck waiting for flame circle?]
    { .actorId = 0x0EC, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Spike
    { .actorId = 0x115, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Skull Kid (Hostile) [despawns before poacher saw, is hostile as child too]
    { .actorId = 0x11D, .params = 0x0000, .requirements = REQ_ON_GROUND }, // Flying Pot [doesn't fall]
    { .actorId = 0x121, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Freezard
    { .actorId = 0x121, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND }, //  Freezard (mobile) [spawns in mid-air before falling]
    { .actorId = 0x18C, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_WATER }, // Stinger (Water) [doesn't spawn outside water?]
    { .actorId = 0x1AF, .params = 0xFF00, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Wolfos [spawns in mid-air before falling]
    { .actorId = 0x1AF, .params = 0xFF01, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  White Wolfos
    { .actorId = 0x1B0, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Stalchild [burrows immediately]
    { .actorId = 0x1B0, .params = 0x0005, .requirements = REQ_ABOVE_GROUND }, //  Stalchild (20 kills)
    { .actorId = 0x1C0, .params = 0x0000, .requirements = REQ_NO_WATER }, // Guay [doesn't actually die so can't clear rooms]

    { .actorId = 0x002, .params = 0x0002, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Stalfos [doesn't fall]
    { .actorId = 0x002, .params = 0x0003, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Stalfos (falls from above)
    // { .actorId = 0x033, .params = 0xFFFF, .requirements = 0 }, // Dark Link
    // { .actorId = 0x091, .params = 0x0300, .requirements = 0 }, // Poe Sisters [meg and amy work, the others move to default Forest Temple pos]
    { .actorId = 0x099, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Flare Dancer [should limit count, too many will crash]
    // { .actorId = 0x0A4, .params = 0x0000, .requirements = 0 }, // Dead Hand
    { .actorId = 0x0A5, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Dead Hand's Hands [doesn't actually die so can't clear rooms]
    // { .actorId = 0x0C6, .params = 0x0001, .requirements = 0 }, // Big Octo
    { .actorId = 0x113, .params = 0xFF02, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Iron Knuckle [killing one seems to set clear flag or something]
    { .actorId = 0x113, .params = 0xFF03, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Iron Knuckle (white)
    // { .actorId = 0x197, .params = 0x0000, .requirements = 0 }, // Gerudo Fighter [weird flag isues, only one spawns]

    // { .actorId = 0x095, .params = 0x0000, .requirements = 0 }, // Skullwalltula
    // { .actorId = 0x0DE, .params = 0x0000, .requirements = 0 }, // Parasitic Tentacle
};

s32 mockIndex = ARRAY_SIZE(sEnemyData) - 1;

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

    if (!isRandomizedEnemy) {
        return;
    }

    f32 yGroundIntersect;
    f32 yWaterSurface;
    void* throwawayPointer;
    Vec3f actorPos = (Vec3f){
        .x = actorEntry->pos.x,
        .y = actorEntry->pos.y,
        .z = actorEntry->pos.z,
    };

    yGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, (CollisionPoly**)&throwawayPointer, &actorPos);
    WaterBox_GetSurfaceImpl(gGlobalContext, &gGlobalContext->colCtx, actorPos.x, actorPos.z, &yWaterSurface, &throwawayPointer);

    CitraPrint("yGroundIntersect=%f; yWaterSurface=%f", yGroundIntersect, yWaterSurface);

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
    // actorEntry->pos.y += 150;
    Object_FindOrSpawnEntry(gActorOverlayTable[randomEnemy.actorId].initInfo->objectId);

    for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
        if (actorEntry->id == sEnemyObjectDeps[i].actorId) {
            Object_FindOrSpawnEntry(sEnemyObjectDeps[i].objectId);
        }
    }
}
