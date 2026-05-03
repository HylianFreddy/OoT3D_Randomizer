#ifndef _BONGO_BONGO_H_
#define _BONGO_BONGO_H_

#include "z3D/z3D.h"

typedef enum BossSstType {
    /* -1 */ BONGO_HEAD = -1,
    /*  0 */ BONGO_LEFT_HAND,
    /*  1 */ BONGO_RIGHT_HAND,
} BossSstType;

typedef struct BossSst {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ SkelAnime mainSkelAnime;
    /* 0x0228 */ char unk_0228[0x1490];
    /* 0x16B8 */ SkelAnime skelAnimeArr[8];
    /* 0x1AD8 */ char unk_1AD8[0x000C];
} BossSst;
_Static_assert(sizeof(BossSst) == 0x1AE4, "BossSst size");

void BossSst_ReinitModels(BossSst* this);

#endif //_BONGO_BONGO_H_
