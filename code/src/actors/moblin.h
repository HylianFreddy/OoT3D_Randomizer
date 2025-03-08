#ifndef _MOBLIN_H_
#define _MOBLIN_H_

#include "z3D/z3D.h"

struct EnMb;

typedef void (*EnMbActionFunc)(struct EnMb*, GlobalContext*);

typedef struct EnMb {
    /* 0x0000 */ Actor actor;
    /* 0x01A4 */ char unk_1A4[0x74C];
    /* 0x08F0 */ EnMbActionFunc actionFunc;
    /* 0x08F4 */ char unk_8F4[0x2B8];
} EnMb; // size = 0xBAC
_Static_assert(sizeof(EnMb) == 0xBAC, "EnMb size");

void EnMb_rUpdate(Actor* thisx, GlobalContext* globalCtx);

#endif //_MOBLIN_H_
