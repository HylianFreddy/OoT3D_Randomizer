#ifndef _EN_RD_H_
#define _EN_RD_H_

#include "z3D/z3D.h"

typedef struct EnRd {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x03C];
    /* 0x1E0 */ SkelAnime skelAnime;
    /* 0x264 */ char unk_264[0x768];
} EnRd;
_Static_assert(sizeof(EnRd) == 0x9CC, "EnRd size");

#endif //_EN_RD_H_
