#ifndef _GANONDORF_ORGAN_H_
#define _GANONDORF_ORGAN_H_

#include "z3D/z3D.h"

typedef struct BossGanon {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0xDE8];
    /* 0x0F8C */ ColliderCylinder collider;
} BossGanon;

void EnGanonOrgan_rInit(Actor* organ, GlobalContext* globalCtx);

#endif //_GANONDORF_ORGAN_H_
