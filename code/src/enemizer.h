#ifndef _ENEMIZER_H_
#define _ENEMIZER_H_

#include "../include/z3D/z3D.h"

typedef s32 (*WaterBox_GetSurfaceImpl_proc)(GlobalContext* globalCtx, CollisionContext* colCtx, f32 x, f32 z,
                                            f32* ySurface, void** outWaterBox) __attribute__((pcs("aapcs-vfp")));
// Returns true if point is within the xz boundaries of an active water box, else false
#define WaterBox_GetSurfaceImpl ((WaterBox_GetSurfaceImpl_proc)GAME_ADDR(0x35E8A0))

typedef f32 (*BgCheck_RaycastDown1_proc)(CollisionContext* colCtx, CollisionPoly* outGroundPoly, Vec3f* pos) __attribute__((pcs("aapcs-vfp")));
// Returns the yIntersect of the nearest poly found directly below `pos`, or BGCHECK_Y_MIN if no floor detected
#define BgCheck_RaycastDown1 ((BgCheck_RaycastDown1_proc)GAME_ADDR(0x257054))

#define REQ_ON_GROUND (1 << 0)
#define REQ_ABOVE_GROUND (1 << 1)
#define REQ_ABOVE_GROUND_IN_AIR (1 << 2)
#define REQ_WATER (1 << 3)
#define REQ_WATER_SURFACE (1 << 4)
#define REQ_NO_WATER (1 << 5)
#define REQ_FLYING (1 << 6)

typedef struct EnemyData {
    u16 actorId;
    u16 params;
    u8 requirements;
} EnemyData;

typedef struct EnemyObjectDependency {
    u16 actorId;
    u16 objectId;
} EnemyObjectDependency;

typedef struct EnemyOverride {
    union {
        s32 key;
        struct {
            u8 actorEntry;
            u8 room;
            u8 layer;
            u8 scene;
        };
    };
    u16 actorId;
    u16 params;
} EnemyOverride;

typedef struct EnemyParams {
    u16 actorId;
    u16 params;
} EnemyParams;

void Enemizer_Init(void);
void Enemizer_OverrideActorEntry(ActorEntry* entry, s32 actorEntryIndex);

#endif // _ENEMIZER_H_
