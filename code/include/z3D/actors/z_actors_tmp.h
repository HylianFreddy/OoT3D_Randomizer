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

typedef struct EnPoh {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
    /* 0x228 */ char unk_228[0x6E8];
    /* 0x910 */ SkeletonAnimationModel* saModel_1;
    /* 0x914 */ SkeletonAnimationModel* saModel_2;
    /* 0x918 */ char unk_918[0x034];
    /* 0x94C */ SkeletonAnimationModel* saModel_94C;
    /* 0x950 */ SkeletonAnimationModel* saModel_950;
    /* 0x954 */ char unk_954[0x118];
} EnPoh;
_Static_assert(sizeof(EnPoh) == 0xA6C, "EnPoh size");

#endif //_ACTORS_TMP_H_
