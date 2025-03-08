#ifndef _FLARE_DANCER_H_
#define _FLARE_DANCER_H_

#include "z3D/z3D.h"

struct EnFd;

typedef void (*EnFdActionFunc)(struct EnFd*, GlobalContext*);

typedef struct EnFd {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ SkelAnime skelAnime;
    /* 0x0228 */ char unk_228[0x4];
    /* 0x022C */ EnFdActionFunc actionFunc;
    /* 0x0230 */ char unk_230[0x26BC];
} EnFd;
_Static_assert(sizeof(EnFd) == 0x28EC, "EnFd size");

void EnFd_rUpdate(Actor* thisx, GlobalContext* globalCtx);

#endif //_FLARE_DANCER_H_
