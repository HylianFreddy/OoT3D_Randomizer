#ifndef _VOLVAGIA_H_
#define _VOLVAGIA_H_

#include "z3D/z3D.h"

/*-------------------------------
|             BossFd            |
-------------------------------*/

typedef struct BossFdEffect {
    /* 0x00 */ SkeletonAnimationModel* model;
    /* 0x04 */ char unk_04[0x48];
} BossFdEffect;
_Static_assert(sizeof(BossFdEffect) == 0x4C, "BossFdEffect size");

typedef struct BossFd {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ SkelAnime skelAnimeBody;
    /* 0x0228 */ SkelAnime skelAnimeHead;
    /* 0x02AC */ SkelAnime skelAnimeRightArm;
    /* 0x0330 */ SkelAnime skelAnimeLeftArm;
    /* 0x03B4 */ SkelAnime skelAnimeSkull;
    /* 0x0438 */ ZARInfo* zarInfo;
    /* 0x043C */ char unk_043C[0x0368];
    /* 0x07A4 */ SkeletonAnimationModel* ribcageModels[18];
    /* 0x07EC */ SkeletonAnimationModel* hairModels[30];
    /* 0x0864 */ void* cmabManagers[3];
    /* 0x0870 */ MaterialAnimation* matAnims[2];
    /* 0x0878 */ char unk_0878[0x20AC];
    /* 0x2924 */ BossFdEffect effects[110];
    /* 0x49CC */ char unk_49CC[0x0014];
} BossFd;
_Static_assert(sizeof(BossFd) == 0x49E0, "BossFd size");

void BossFd_ReinitModels(BossFd* this);

#endif //_VOLVAGIA_H_
