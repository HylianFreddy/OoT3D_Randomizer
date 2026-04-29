#ifndef _BARINADE_H_
#define _BARINADE_H_

#include "z3D/z3D.h"

typedef enum BossVaParam {
    /* -1 */ BOSSVA_BODY = -1,
    /*  0 */ BOSSVA_SUPPORT_1,
    /*  1 */ BOSSVA_SUPPORT_2,
    /*  2 */ BOSSVA_SUPPORT_3,
    /*  3 */ BOSSVA_ZAPPER_1,
    /*  4 */ BOSSVA_ZAPPER_2,
    /*  5 */ BOSSVA_ZAPPER_3,
    /*  6 */ BOSSVA_BARI_UPPER_1,
    /*  7 */ BOSSVA_BARI_UPPER_2,
    /*  8 */ BOSSVA_BARI_UPPER_3,
    /*  9 */ BOSSVA_BARI_UPPER_4,
    /* 10 */ BOSSVA_BARI_UPPER_5,
    /* 11 */ BOSSVA_BARI_LOWER_1,
    /* 12 */ BOSSVA_BARI_LOWER_2,
    /* 13 */ BOSSVA_BARI_LOWER_3,
    /* 14 */ BOSSVA_BARI_LOWER_4,
    /* 15 */ BOSSVA_BARI_LOWER_5,
    /* 16 */ BOSSVA_STUMP_1,
    /* 17 */ BOSSVA_STUMP_2,
    /* 18 */ BOSSVA_STUMP_3,
    /* 19 */ BOSSVA_DOOR,
} BossVaParam;

typedef struct BossVa {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ SkelAnime anime;
    /* 0x0228 */ char unk_228[0xFB4];
    /* 0x11DC */ SkeletonAnimationModel* jellyfishModel_1;
    /* 0x11E0 */ SkeletonAnimationModel* jellyfishModel_2;
    /* 0x11E4 */ SkeletonAnimationModel* jellyfishModel_3;
    /* 0x11E8 */ SkeletonAnimationModel* jellyfishModel_4;
    /* 0x11EC */ SkeletonAnimationModel* jellyfishModel_5;
    /* 0x11F0 */ SkeletonAnimationModel* jellyfishModel_6;
    /* 0x11F4 */ SkeletonAnimationModel* jellyfishModel_7;
    /* 0x11F8 */ SkeletonAnimationModel* jellyfishModel_8;
    /* 0x11FC */ SkeletonAnimationModel* jellyfishModel_9;
    /* 0x1200 */ SkeletonAnimationModel* jellyfishModel_10;
    /* 0x1204 */ char unk_1204[0x4];
    /* 0x1208 */ MaterialAnimation matAnim;
    /* 0x12A0 */ char unk_12A0[0x4];
} BossVa;
_Static_assert(sizeof(BossVa) == 0x12A4, "BossVa size");

void BossVa_ReinitModels(BossVa* this);

#endif //_BARINADE_H_
