#ifndef _ACTORS_TMP_H_
#define _ACTORS_TMP_H_

#include "z3D/z3D.h"

typedef struct EnFirefly {
    Actor actor;
    Vec3f bodyPartsPos[3];
    SkelAnime skelAnime;
} EnFirefly;

typedef struct EnTp {
    Actor actor;
    s32 actionIndex;
    s32 unk;
    void* actionFunc;
    SkelAnime skelAnime;
} EnTp;

#endif //_ACTORS_TMP_H_
