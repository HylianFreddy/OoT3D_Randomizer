#include "z3D/z3D.h"

#define BgSpot05Soko_Init ((ActorFunc)GAME_ADDR(0x27A8AC))
#define BgSpot05Soko_Update ((ActorFunc)GAME_ADDR(0x29DDB4))
#define BgSpot05Soko_Destroy ((ActorFunc)GAME_ADDR(0x27A9E8))

struct BgSpot05Soko;

typedef void (*BgSpot05SokoActionFunc)(struct BgSpot05Soko*, GlobalContext*);

typedef struct BgSpot05Soko {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x01BC */ BgSpot05SokoActionFunc actionFunc;
    /* 0x01C4 */ s32 switchFlag;
    /* 0x01C8 */ SkeletonAnimationModel* saModel1;
    /* 0x01CC */ SkeletonAnimationModel* saModel2;
} BgSpot05Soko; // size = 0x01CC

void BgSpot05Soko_rInit(Actor* thisx, GlobalContext* play);
void BgSpot05Soko_rUpdate(Actor* thisx, GlobalContext* play);
void BgSpot05Soko_rDestroy(Actor* thisx, GlobalContext* play);
