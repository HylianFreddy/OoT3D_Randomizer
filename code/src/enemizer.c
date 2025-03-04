#include "enemizer.h"
#include "objects.h"
#include "common.h"
#include "savefile.h"
#include "actor_id.h"
#include "settings.h"
#include "scene.h"
#include <stddef.h>

static EnemyOverride rEnemyOverrides[ENEMY_OVERRIDES_MAX];
static s32 rEnemyOverrides_Count = 0;

u8 Enemizer_RoomLoadSignal = FALSE;

// Enemies that need to spawn at ground level to work properly.
static EnemyParams sGroundedEnemies[] = {
    { .actorId = ACTOR_STALFOS, .params = 0x0002 },
    { .actorId = ACTOR_DODONGO, .params = 0x0000 },
    { .actorId = ACTOR_PEAHAT, .params = 0xFFFF },
    { .actorId = ACTOR_GOHMA_LARVA, .params = 0x0007 },
    { .actorId = ACTOR_BABY_DODONGO, .params = 0x0000 },
    { .actorId = ACTOR_TAILPASARAN, .params = 0xFFFF },
    { .actorId = ACTOR_STINGER_FLOOR, .params = 0x000A },
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
    { .actorId = ACTOR_SKULLWALLTULA, .params = 0x0000 },
    { .actorId = ACTOR_DEAD_HAND_HAND, .params = 0x0000 },
    { .actorId = ACTOR_WITHERED_DEKU_BABA, .params = 0x0000 },
    { .actorId = ACTOR_ANUBIS_SPAWNER, .params = 0x0003 },
    { .actorId = ACTOR_FLYING_POT, .params = 0x000 },
    { .actorId = ACTOR_STALCHILD, .params = 0x0000 },
    { .actorId = ACTOR_STALCHILD, .params = 0x0005 },
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
    { .actorId = 0x069, .params = 0x02FC, .requirements = 0 }, //  Bubble (green)
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
    { .actorId = 0x1C0, .params = 0x0001, .requirements = REQ_NO_WATER | REQ_FLYING }, // Guay

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
    { .actorId = 0x113, .params = 0xFF01, .requirements = REQ_ABOVE_GROUND | REQ_NO_WATER }, // Iron Knuckle (silver, sitting)
    // { .actorId = 0x197, .params = 0x0000, .requirements = 0 }, // Gerudo Fighter [weird flag isues, only one spawns]

    { .actorId = 0x095, .params = 0x0000, .requirements = 0 }, // Skullwalltula
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

s32 Enemizer_IsActive(void) {
    return gSettingsContext.enemizer == ON;
}

void Enemizer_Init(void) {
    while (rEnemyOverrides[rEnemyOverrides_Count].actorId != 0) {
        rEnemyOverrides_Count++;
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

static void Enemizer_MoveSpecificLocations(ActorEntry* actorEntry, s32 actorEntryIndex) {
#define isEntry(scene, layer, room, entry)                                                           \
    (gGlobalContext->sceneNum == scene && rSceneLayer == layer && gGlobalContext->roomNum == room && \
     actorEntryIndex == entry)

    if (isEntry(86, 0, 0, 1)) {
        // Move the SFM wolfos more towards the center, some enemies might jump over the fence
        actorEntry->pos.x = -195;
        actorEntry->pos.y = 0;
        actorEntry->pos.z = 1900;
    } else if (isEntry(6, 0, 27, 7) && gSettingsContext.spiritTempleDungeonMode == DUNGEONMODE_MQ) {
        // Move the stalfos in MQ Child spirit down onto the platform
        actorEntry->pos.y = 50;
    } else if (isEntry(2, 0, 11, 5) && gSettingsContext.jabuJabusBellyDungeonMode == DUNGEONMODE_MQ) {
        // Move the left like like in the room in MQ jabu to just spawn on the ground
        actorEntry->pos.x = 827;
        actorEntry->pos.y = -300;
    } else if (isEntry(2, 0, 11, 6) && gSettingsContext.jabuJabusBellyDungeonMode == DUNGEONMODE_MQ) {
        // Move the right like like in the room in MQ jabu to just spawn on the ground
        actorEntry->pos.x = 488;
        actorEntry->pos.y = -300;
    } else if ((isEntry(7, 0, 21, 13) && gSettingsContext.shadowTempleDungeonMode == DUNGEONMODE_VANILLA) ||
               (isEntry(7, 0, 21, 16) && gSettingsContext.shadowTempleDungeonMode == DUNGEONMODE_MQ)) {
        // Move one shadow temple boat stalfos over to the end platform
        actorEntry->pos.x = -2300;
        actorEntry->pos.y = -1360;
        actorEntry->pos.z = -1570;
    } else if ((isEntry(7, 0, 21, 14) && gSettingsContext.shadowTempleDungeonMode == DUNGEONMODE_VANILLA) ||
               (isEntry(7, 0, 21, 17) && gSettingsContext.shadowTempleDungeonMode == DUNGEONMODE_MQ)) {
        // Move the other shadow temple boat stalfos over to the end platform
        actorEntry->pos.x = -2700;
        actorEntry->pos.y = -1360;
        actorEntry->pos.z = -1570;
    } else if (isEntry(8, 0, 3, 2) && gSettingsContext.bottomOfTheWellDungeonMode == DUNGEONMODE_VANILLA) {
        // Move the fire keese in the side room in BOTW before the gate so it doesn't raycast down into the basement
        actorEntry->pos.z = -1075;
    } else if (isEntry(8, 0, 0, 4) && gSettingsContext.bottomOfTheWellDungeonMode == DUNGEONMODE_VANILLA) {
        // Move the wallmaster in the central room of BOTW so it doesn't raycast down into the basement
        actorEntry->pos.z = -950;
    }

#undef isEntry
}

static void Enemizer_MoveSpecificEnemies(ActorEntry* actorEntry) {
    f32 yGroundIntersect;
    f32 yUpperGroundIntersect;
    f32 yMidAirPos;
    s32 waterBoxFound;
    f32 yWaterSurface;
    CollisionPoly floorPoly;
    u8 isInvalidGround;
    void* waterBox;
    Vec3f actorPos = (Vec3f){
        .x = actorEntry->pos.x,
        .y = actorEntry->pos.y + 50, // Check for ground even slightly above the actor entry's real position
        .z = actorEntry->pos.z,
    };

    // Ground height below actor.
    yGroundIntersect        = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &actorPos);
    SurfaceType surfaceType = gGlobalContext->colCtx.stat.colHeader->surfaceTypeList[floorPoly.type];
    isInvalidGround         = yGroundIntersect <= BGCHECK_Y_MIN || SurfaceType_IsLoadingZoneOrVoidPlane(surfaceType);

    Vec3f upperPos = (Vec3f){
        .x = actorEntry->pos.x,
        .y = yGroundIntersect + 200,
        .z = actorEntry->pos.z,
    };
    yUpperGroundIntersect = BgCheck_RaycastDown1(&gGlobalContext->colCtx, &floorPoly, &upperPos);
    // Potential mid-air position to spawn the actor off the ground if needed.
    yMidAirPos = ABS(yUpperGroundIntersect - yGroundIntersect) < 50 ? upperPos.y : yUpperGroundIntersect - 50;

    // If there is a water box, set yWaterSurface.
    waterBoxFound = WaterBox_GetSurfaceImpl(gGlobalContext, &gGlobalContext->colCtx, actorPos.x, actorPos.z,
                                            &yWaterSurface, &waterBox);
    // Ignore water boxes below the ground.
    if (waterBoxFound && yWaterSurface < yGroundIntersect) {
        waterBoxFound = FALSE;
    }

    // Adjust position for certain enemies.
    if (actorEntry->id == ACTOR_OCTOROK && waterBoxFound) {
        // Always at water surface
        actorEntry->pos.y = yWaterSurface;
    } else if (actorEntry->id == ACTOR_SKULLTULA) {
        // In mid-air or near water surface
        if (!waterBoxFound && !isInvalidGround) {
            actorEntry->pos.y = yMidAirPos;
        } else if (waterBoxFound && (actorEntry->pos.y > yWaterSurface)) {
            actorEntry->pos.y = yWaterSurface + 50;
        }
    } else if (actorEntry->id == ACTOR_BARI ||
               (actorEntry->id == ACTOR_PEAHAT && actorEntry->params == 0x0001)) { // Peahat Larva
        // In mid-air
        if (yMidAirPos > actorEntry->pos.y) {
            actorEntry->pos.y = yMidAirPos;
        }
    } else if (actorEntry->id == ACTOR_BUBBLE && (actorEntry->params & 0x00FF) == 0xFC) { // Green Bubble
        // Slightly above the ground so it doesn't go through it while bobbing up and down.
        if (!waterBoxFound && !isInvalidGround && (actorEntry->pos.y - yGroundIntersect < 60)) {
            actorEntry->pos.y = yGroundIntersect + 60;
        }
    } else if (!isInvalidGround) {
        // Snap enemy to the ground if needed
        for (u32 i = 0; i < ARRAY_SIZE(sGroundedEnemies); i++) {
            if (actorEntry->id == sGroundedEnemies[i].actorId && actorEntry->params == sGroundedEnemies[i].params) {
                actorEntry->pos.y = yGroundIntersect;
            }
        }
    }
}

void Enemizer_OverrideActorEntry(ActorEntry* actorEntry, s32 actorEntryIndex) {
    if (gExtSaveData.option_Enemizer == OFF) {
        return;
    }

    // CitraPrint("%d %d %d %d", gGlobalContext->sceneNum, rSceneLayer, gGlobalContext->roomNum, actorEntryIndex);

    EnemyOverride enemyOverride =
        Enemizer_FindOverride(gGlobalContext->sceneNum, rSceneLayer, gGlobalContext->roomNum, actorEntryIndex);

    // Mock
    for (u32 i = 0; i < ARRAY_SIZE(sEnemyData); i++) {
        if (actorEntry->id == sEnemyData[i].actorId) {
            // if (actorEntryIndex != 2) {
            //     enemyOverride.actorId = 0x10;
            //     enemyOverride.params  = 0x0000;
            //     break;
            // }
            enemyOverride.actorId = ACTOR_LEEVER;
            enemyOverride.params  = 0x0000;
            break;
        }
    }

    // Do nothing if the override doesn't exist
    if (enemyOverride.actorId == 0) {
        return;
    }

    actorEntry->id     = enemyOverride.actorId;
    actorEntry->params = enemyOverride.params;

    Enemizer_MoveSpecificLocations(actorEntry, actorEntryIndex);
    Enemizer_MoveSpecificEnemies(actorEntry);

    // Clear X and Z rotation to spawn all enemies upright
    actorEntry->rot.x = 0;
    actorEntry->rot.z = 0;

    // Spawn necessary objects
    Object_FindEntryOrSpawn(gActorOverlayTable[actorEntry->id].initInfo->objectId);

    for (u32 i = 0; i < ARRAY_SIZE(sEnemyObjectDeps); i++) {
        if (actorEntry->id == sEnemyObjectDeps[i].actorId) {
            Object_FindEntryOrSpawn(sEnemyObjectDeps[i].objectId);
        }
    }
}

// Run special checks for certain enemies
void Enemizer_Update(void) {
    static Actor *sSFMWolfos, *sLizalfos1, *sLizalfos2;
    static u8 sDefeated1, sDefeated2;

    if (gSettingsContext.enemizer == OFF) {
        return;
    }

    if (Enemizer_RoomLoadSignal) {
        sSFMWolfos = sLizalfos1 = sLizalfos2 = NULL;
        sDefeated1 = sDefeated2 = FALSE;
    }

    if (gGlobalContext->sceneNum == 86) {
        // Sacred Forest Meadow: open the gate when the enemy is defeated.
        if (Enemizer_RoomLoadSignal) {
            Actor* enemy = gGlobalContext->actorCtx.actorList[ACTORTYPE_ENEMY].first;
            while (enemy != NULL) {
                if (enemy->world.pos.z > 1600.0) {
                    sSFMWolfos = enemy;
                    break;
                }
                enemy = enemy->next;
            }
            if (Flags_GetSwitch(gGlobalContext, 0x1F) && sSFMWolfos != NULL) {
                Actor_Kill(sSFMWolfos);
                sSFMWolfos = NULL;
            }
        }
        if (sSFMWolfos != NULL && sSFMWolfos->update == NULL && sSFMWolfos->draw == NULL) {
            Flags_SetSwitch(gGlobalContext, 0x1F);
            sSFMWolfos = NULL;
        }
    } else if (gGlobalContext->sceneNum == 1 && gGlobalContext->roomNum == 3) {
        // Dodongo's Cavern miniboss room: open the correct doors when the enemies are defeated.
        if (Enemizer_RoomLoadSignal) {
            Actor* enemy = gGlobalContext->actorCtx.actorList[ACTORTYPE_ENEMY].first;
            while (enemy != NULL) {
                if (enemy->room == 0x3) {
                    if (enemy->world.pos.y < 200.0) {
                        if (Flags_GetSwitch(gGlobalContext, 5)) {
                            Actor_Kill(enemy);
                        } else if (sLizalfos1 == NULL) {
                            sLizalfos1 = enemy;
                        } else {
                            sLizalfos2 = enemy;
                        }
                    } else {
                        if (Flags_GetSwitch(gGlobalContext, 6) || !Flags_GetSwitch(gGlobalContext, 5) ||
                            PLAYER->actor.world.pos.y < 200.0) {
                            Actor_Kill(enemy);
                        } else if (sLizalfos1 == NULL) {
                            sLizalfos1 = enemy;
                        } else {
                            sLizalfos2 = enemy;
                        }
                    }
                }
                enemy = enemy->next;
            }
        }

        if (sLizalfos1 != NULL && sLizalfos1->update == NULL && sLizalfos1->draw == NULL) {
            sDefeated1 = TRUE;
            sLizalfos1 = NULL;
        }

        if (sLizalfos2 != NULL && sLizalfos2->update == NULL && sLizalfos2->draw == NULL) {
            sDefeated2 = TRUE;
            sLizalfos2 = NULL;
        }

        if (sDefeated1 && sDefeated2) {
            u32 flag = Flags_GetSwitch(gGlobalContext, 5) ? 6 : 5;
            Flags_SetSwitch(gGlobalContext, flag);
            sDefeated1 = sDefeated2 = FALSE;
        }
    }

    Enemizer_RoomLoadSignal = FALSE;
}
