#ifndef _DEKU_BABA_H_
#define _DEKU_BABA_H_

#include "z3D/z3D.h"

/*-------------------------------
|           EnKarebaba          |
-------------------------------*/

typedef struct EnKarebaba {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
    /* 0x228 */ char unk_228[0x1F0];
    /* 0x418 */ SkeletonAnimationModel* stalkModel_1;
    /* 0x41C */ SkeletonAnimationModel* stalkModel_2;
    /* 0x420 */ SkeletonAnimationModel* stalkModel_3;
    /* 0x424 */ SkeletonAnimationModel* stickModel;
    /* 0x428 */ SkeletonAnimationModel* leavesModel;
    /* 0x42C */ char unk_42C[0x004];
} EnKarebaba;
_Static_assert(sizeof(EnKarebaba) == 0x430, "EnKarebaba size");

void EnKarebaba_ReinitModels(EnKarebaba* this);

#endif //_DEKU_BABA_H_
