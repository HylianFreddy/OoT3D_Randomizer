#include "enemizer.h"
#include "objects.h"
#include "common.h"
#include "savefile.h"
#include "actor_id.h"
#include "settings.h"
#include <stddef.h>

static EnemyOverride rEnemyOverrides[700];
static s32 rEnemyOverrides_Count = 0;

static EnemyOverride Enemizer_FindOverride(u8 scene, u8 layer, u8 room, u8 actorEntry);
static void Enemizer_AdjustPosition(ActorEntry* actorEntry);

// Enemies that need to spawn at ground level to work properly.
static EnemyParams sGroundedEnemies[] = {
    { .actorId = ACTOR_DODONGO, .params = 0x0000 },
    { .actorId = ACTOR_PEAHAT, .params = 0xFFFF },
    { .actorId = ACTOR_GOHMA_LARVA, .params = 0x0007 },
    { .actorId = ACTOR_BABY_DODONGO, .params = 0x0000 },
    { .actorId = ACTOR_TAILPASARAN, .params = 0xFFFF },
    { .actorId = ACTOR_STINGER_LAND, .params = 0x000A },
    { .actorId = ACTOR_DEKU_BABA, .params = 0x0000 },
    { .actorId = ACTOR_DEKU_BABA, .params = 0x0001 },
    { .actorId = ACTOR_MAD_SCRUB, .params = 0x0100 },
    { .actorId = ACTOR_MAD_SCRUB, .params = 0x0300 },
    { .actorId = ACTOR_MAD_SCRUB, .params = 0x0500 },
    { .actorId = ACTOR_BUBBLE, .params = 0xFFFE },
    { .actorId = ACTOR_FLYING_FLOOR_TILE, .params = 0x0000 },
    { .actorId = ACTOR_BEAMOS, .params = 0x0501 },
    { .actorId = ACTOR_BEAMOS, .params = 0x0500 },
    { .actorId = ACTOR_REDEAD, .params = 0x7F01 },
    { .actorId = ACTOR_REDEAD, .params = 0x7FFE },
    { .actorId = ACTOR_WITHERED_DEKU_BABA, .params = 0x0000 },
    { .actorId = ACTOR_FLYING_POT, .params = 0x000 },
    { .actorId = ACTOR_STALFOS, .params = 0x0002 },
    { .actorId = ACTOR_DEAD_HAND_HAND, .params = 0x0000 },
};

// clang-format off
EnemyData sEnemyData[] = {
    { .actorId = 0x00D, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_FLYING }, // Poe
    { .actorId = 0x00E, .params = 0x0000, .requirements = REQ_WATER_SURFACE }, // Octorok [requires water and snaps to surface]
    { .actorId = 0x011, .params = 0x0000, .requirements = REQ_FLYING }, // Wallmaster
    { .actorId = 0x012, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Dodongo [gets stuck in mid-air]
    { .actorId = 0x013, .params = 0x0002, .requirements = REQ_NO_WATER | REQ_FLYING }, // Keese
    { .actorId = 0x013, .params = 0x0001, .requirements = REQ_NO_WATER | REQ_FLYING }, //  Fire Keese
    { .actorId = 0x013, .params = 0x0004, .requirements = REQ_NO_WATER | REQ_FLYING }, //  Ice Keese
    { .actorId = 0x01B, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Tektite (Red) [doesn't float in water]
    { .actorId = 0x01B, .params = 0xFFFE, .requirements = REQ_ABOVE_GROUND }, //  Tektite (Blue)
    // { .actorId = 0x01C, .params = 0x0000, .requirements = 0 }, // Leever [doesn't spawn]
    { .actorId = 0x01D, .params = 0xFFFF, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Peahat [doesn't fall]
    { .actorId = 0x01D, .params = 0x0001, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER | REQ_FLYING }, //  Peahat Larva [insta die if on floor]
    { .actorId = 0x025, .params = 0xFF80, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER}, // Lizalfos
    { .actorId = 0x025, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER}, //  Lizalfos (drops)
    { .actorId = 0x025, .params = 0xFFFE, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Dinolfos
    { .actorId = 0x02B, .params = 0x0007, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Gohma Egg
    { .actorId = 0x02D, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Shabom
    { .actorId = 0x02F, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Baby Dodongo [burrows immediately in water, doesn't spawn in mid-air]
    { .actorId = 0x034, .params = 0xFFFF, .requirements = 0 }, // Biri
    { .actorId = 0x035, .params = 0xFFFF, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Tailpasaran [weird in mid-air]
    { .actorId = 0x037, .params = 0x0000, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER | REQ_FLYING }, // Skulltula [works, but maybe should move up a bit?]
    { .actorId = 0x037, .params = 0x0001, .requirements = REQ_ABOVE_GROUND_IN_AIR | REQ_NO_WATER | REQ_FLYING }, //  Skulltula (Big)
    { .actorId = 0x038, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Torch Slug [works, but doesn't look good in water]
    { .actorId = 0x03A, .params = 0x000A, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Stinger (Land) [works, but doesn't look good in water]
    { .actorId = 0x04B, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Moblin (club) [doesn't turn]
    { .actorId = 0x04B, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Moblin (spear)
    { .actorId = 0x054, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Armos (Enemy)
    { .actorId = 0x055, .params = 0x0000, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Deku Baba [doesn't fall]
    { .actorId = 0x055, .params = 0x0001, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, //  Deku Baba (Big)
    { .actorId = 0x060, .params = 0x0300, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Mad Scrub [flower doesn't fall]
    { .actorId = 0x063, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND_IN_AIR }, // Bari [doesn't spawn if underground]
    { .actorId = 0x069, .params = 0xFFFF, .requirements = REQ_NO_WATER | REQ_FLYING }, // Bubble (blue)
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
    { .actorId = 0x0EC, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Spike
    { .actorId = 0x0F6, .params = 0x0003, .requirements = 0 }, // Anubis Spawner [need to add patch for flame circles where timer=0 means they're active ]
    { .actorId = 0x115, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Skull Kid (Hostile) [despawns before poacher saw, is hostile as child too]
    { .actorId = 0x11D, .params = 0x0000, .requirements = REQ_ON_GROUND }, // Flying Pot [doesn't fall]
    { .actorId = 0x121, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Freezard
    { .actorId = 0x121, .params = 0xFFFF, .requirements = REQ_ABOVE_GROUND }, //  Freezard (mobile) [spawns in mid-air before falling]
    { .actorId = 0x18C, .params = 0x0000, .requirements = REQ_ABOVE_GROUND | REQ_WATER }, // Stinger (Water) [doesn't spawn outside water?]
    { .actorId = 0x1AF, .params = 0xFF00, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Wolfos [spawns in mid-air before falling]
    { .actorId = 0x1AF, .params = 0xFF01, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  White Wolfos
    { .actorId = 0x1B0, .params = 0x0000, .requirements = REQ_ABOVE_GROUND }, // Stalchild [burrows immediately]
    { .actorId = 0x1B0, .params = 0x0005, .requirements = REQ_ABOVE_GROUND }, //  Stalchild (20 kills)
    { .actorId = 0x1C0, .params = 0x0000, .requirements = REQ_NO_WATER | REQ_FLYING }, // Guay [doesn't actually die so can't clear rooms]

    { .actorId = 0x002, .params = 0x0002, .requirements = REQ_ON_GROUND | REQ_NO_WATER }, // Stalfos [doesn't fall]
    { .actorId = 0x002, .params = 0x0003, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, //  Stalfos (falls from above)
    // { .actorId = 0x033, .params = 0x0000, .requirements = 0 }, // Dark Link
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

static EnemyObjectDependency sEnemyObjectDeps[] = {
    { .actorId = 0x00D, .objectId = 0x009 }, // Poe (actor profile only points to object 1)
    { .actorId = 0x063, .objectId = 0x021 }, // Bari -> Biri
    { .actorId = 0x012, .objectId = 0x003 }, // Dodongo -> dungeon object for fire breath
    { .actorId = 0x02B, .objectId = 0x003 }, // Gohma Egg -> dungeon object for egg fragments
    { .actorId = 0x099, .objectId = 0x003 }, // Flare Dancer -> dungeon object for flames
    { .actorId = 0x0F6, .objectId = 0x0D6 }, // Anubis Spawner -> Anubis object (actor profile only points to object 1)
};
// clang-format on

void Enemizer_Init(void) {
    while (rEnemyOverrides[rEnemyOverrides_Count].actorId != 0) {
        rEnemyOverrides_Count++;
    }
}

void Enemizer_OverrideActorEntry(ActorEntry* actorEntry, s32 actorEntryIndex) {
    if (gExtSaveData.option_Enemizer == OFF) {
        return;
    }

    CitraPrint("%d %d %d %d", gGlobalContext->sceneNum, gSaveContext.sceneLayer, gGlobalContext->roomNum,
               actorEntryIndex);

    EnemyOverride enemyOverride = Enemizer_FindOverride(gGlobalContext->sceneNum, gSaveContext.sceneLayer,
                                                        gGlobalContext->roomNum, actorEntryIndex);

    // Do nothing if the override doesn't exist or is the same as the vanilla location.
    if (enemyOverride.actorId == 0 ||
        (enemyOverride.actorId == actorEntry->id && enemyOverride.params == actorEntry->params)) {
        return;
    }

    actorEntry->id     = enemyOverride.actorId;
    actorEntry->params = enemyOverride.params;

    Enemizer_AdjustPosition(actorEntry);

    // Spawn necessary objects
    Object_FindEntryOrSpawn(gActorOverlayTable[actorEntry->id].initInfo->objectId);

    for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
        if (actorEntry->id == sEnemyObjectDeps[i].actorId) {
            Object_FindEntryOrSpawn(sEnemyObjectDeps[i].objectId);
        }
    }
}

static EnemyOverride Enemizer_FindOverride(u8 scene, u8 layer, u8 room, u8 actorEntry) {
    s32 key   = (scene << 24) | (layer << 16) | (room << 8) | actorEntry;
    s32 start = 0;
    s32 end   = rEnemyOverrides_Count - 1;
    while (start <= end) {
        s32 midIdx           = (start + end) / 2;
        EnemyOverride midOvr = rEnemyOverrides[midIdx];
        if (key < midOvr.key) {
            end = midIdx - 1;
        } else if (key > midOvr.key) {
            start = midIdx + 1;
        } else {
            return midOvr;
        }
    }
    return (EnemyOverride){ 0 };
}

static void Enemizer_AdjustPosition(ActorEntry* actorEntry) {
    f32 yGroundIntersect;
    f32 yUpperGroundIntersect;
    f32 yOffGroundPos;
    s32 waterBoxFound;
    f32 yWaterSurface;
    CollisionPoly floorPoly;
    u8 isAboveVoid;
    void* waterBox;
    Vec3f actorPos = (Vec3f){
        .x = actorEntry->pos.x,
        .y = actorEntry->pos.y + 10,
        .z = actorEntry->pos.z,
    };

    // Ground height below actor.
    yGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &actorPos);
    SurfaceType surfaceType = gGlobalContext->colCtx.stat.colHeader->surfaceTypeList[floorPoly.type];
    isAboveVoid             = (SurfaceType_GetFloorProperty(surfaceType) == 0xC);
    // If there is a water box, set yWaterSurface.
    waterBoxFound = WaterBox_GetSurfaceImpl(gGlobalContext, &gGlobalContext->colCtx, actorPos.x, actorPos.z,
                                            &yWaterSurface, &waterBox);
    // Ignore water boxes below the ground.
    if (waterBoxFound && yWaterSurface < yGroundIntersect) {
        waterBoxFound = FALSE;
    }

    Vec3f upperPos = (Vec3f){
        .x = actorEntry->pos.x,
        .y = yGroundIntersect + 200,
        .z = actorEntry->pos.z,
    };
    yUpperGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &upperPos);
    // Potential mid-air position to spawn the actor off the ground if needed.
    yOffGroundPos = ABS(yUpperGroundIntersect - yGroundIntersect) < 50 ? upperPos.y : yUpperGroundIntersect - 50;

    // Adjust position for certain enemies.
    if (actorEntry->id == ACTOR_OCTOROK && waterBoxFound) {
        // Always at water surface
        actorEntry->pos.y = yWaterSurface;
    } else if (actorEntry->id == ACTOR_SKULLTULA) {
        // Off the ground or at water surface
        if (!waterBoxFound && !isAboveVoid) {
            actorEntry->pos.y = yOffGroundPos;
        } else if (waterBoxFound && (actorEntry->pos.y > yWaterSurface)) {
            actorEntry->pos.y = yWaterSurface + 50;
        }
    } else if (actorEntry->id == ACTOR_BARI || (actorEntry->id == ACTOR_PEAHAT && actorEntry->params == 0x0001)) {
        // Off the ground or even higher
        if (yOffGroundPos > actorEntry->pos.y) {
            actorEntry->pos.y = yOffGroundPos;
        }
    } else {
        // Snap enemy to the ground if needed
        for (u32 i = 0; i < ARRAY_SIZE(sGroundedEnemies); i++) {
            if (actorEntry->id == sGroundedEnemies[i].actorId && actorEntry->params == sGroundedEnemies[i].params) {
                actorEntry->pos.y = yGroundIntersect;
            }
        }
    }
}
