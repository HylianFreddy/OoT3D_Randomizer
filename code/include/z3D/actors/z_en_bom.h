#ifndef _EN_BOM_H_
#define _EN_BOM_H_

#include "z3D/z3D.h"

struct EnBom;

typedef void (*EnBomActionFunc)(struct EnBom*, GlobalContext*);

typedef struct EnBom {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ ColliderCylinder bombCollider;
    /* 0x01FC */ u8 explosionCollider[0x20]; // ColliderJntSph
    /* 0x021C */ u8 explosionColliderItems[0x50]; // ColliderJntSphElement
    /* 0x026C */ s16 timer;
    /* 0x026E */ s16 flashSpeedScale;
    /* 0x0270 */ f32 flashIntensity;
    /* 0x0274 */ u8 bumpOn;
    /* 0x0275 */ u8	unk_275[3];
    /* 0x0278 */ SkeletonAnimationModel* model;
    /* 0x027C */ u8 unk_27C[0x14];
    /* 0x0290 */ EnBomActionFunc actionFunc;
} EnBom; // size = 0x0208

#define EnBom_Draw ((ActorFunc)0x1D5260)

#endif //_EN_BOM_H_
