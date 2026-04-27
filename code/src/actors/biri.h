#ifndef _BIRI_H_
#define _BIRI_H_

#include "z3D/z3D.h"

typedef struct EnBili {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
    /* 0x228 */ char jointTable[0x138];
    /* 0x360 */ char morphTable[0x138];
    /* 0x498 */ FaceAnimation faceAnim;
    /* 0x664 */ char unk_664[0x064];
} EnBili;
_Static_assert(sizeof(EnBili) == 0x6C8, "EnBili size");

void EnBili_ReinitModels(EnBili* this);

#endif //_BIRI_H_
