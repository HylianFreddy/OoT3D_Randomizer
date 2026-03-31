#ifndef _BG_DY_YOSEIZO_H_
#define _BG_DY_YOSEIZO_H_

#include "z3D/z3D.h"

struct BgDyYoseizo;

typedef void (*BgDyYoseizoActionFunc)(struct BgDyYoseizo*, GlobalContext*);

typedef struct BgDyYoseizo {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ BgDyYoseizoActionFunc actionFn;
    /* 0x1A8 */ SkelAnime skelAnime;
    /* 0x22C */ char unk_22C[0x0B00];
    /* 0xD2C */ s16 fountainType;
    /* 0xD2E */ char unk_D2E[0x3D46];
} BgDyYoseizo;
_Static_assert(sizeof(BgDyYoseizo) == 0x4A74, "BgDyYoseizo size");

#endif //_BG_DY_YOSEIZO_H_
