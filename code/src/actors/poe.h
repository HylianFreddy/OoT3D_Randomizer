#ifndef _POE_H_
#define _POE_H_

#include "z3D/z3D.h"

typedef struct EnPoh {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
    /* 0x228 */ char unk_228[0x6E8];
    /* 0x910 */ SkeletonAnimationModel* saModel_1;
    /* 0x914 */ SkeletonAnimationModel* saModel_2;
    /* 0x918 */ char unk_918[0x007];
    /* 0x91F */ u8 infoIdx;
    /* 0x920 */ char unk_920[0x02C];
    /* 0x94C */ SkeletonAnimationModel* saModel_94C;
    /* 0x950 */ SkeletonAnimationModel* saModel_950;
    /* 0x954 */ u32 composerLanternCmbIndex;
    /* 0x958 */ char unk_958[0x114];
} EnPoh;
_Static_assert(sizeof(EnPoh) == 0xA6C, "EnPoh size");

void EnPoh_rInit(Actor* thisx, GlobalContext* globalCtx);
void EnPoh_rUpdate(Actor* thisx, GlobalContext* globalCtx);

void Poe_ReinitModels(EnPoh* this);

#endif //_POE_H_
