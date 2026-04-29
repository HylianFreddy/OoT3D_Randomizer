#ifndef _GANONDORF_H_
#define _GANONDORF_H_

#include "z3D/z3D.h"

/*-------------------------------
|           BossGanon           |
-------------------------------*/

void BossGanon_rUpdate(Actor* thisx, GlobalContext* globalCtx);

/*-------------------------------
|         BossGanondrof         |
-------------------------------*/

typedef struct BossGanondrof {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
    /* 0x228 */ char unk_228[0x2C4];
} BossGanondrof;
_Static_assert(sizeof(BossGanondrof) == 0x4EC, "BossGanondrof size");

void BossGanondrof_ReinitModels(BossGanondrof* this);

/*-------------------------------
|             EnFHG             |
-------------------------------*/

typedef struct EnFHG {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x0C8];
    /* 0x26C */ SkelAnime anime;
    /* 0x2F0 */ char unk_2F0[0x1FC];
} EnFHG;
_Static_assert(sizeof(EnFHG) == 0x4EC, "EnFHG size");

void EnFHG_ReinitModels(EnFHG* this);

#endif //_GANONDORF_H_
