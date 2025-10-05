#ifndef _FAIRY_H_
#define _FAIRY_H_

#include "z3D/z3D.h"

typedef struct EnElf {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x784];
    /* 0x928 */ Color_RGBAf innerColor;
    /* 0x938 */ Color_RGBAf outerColor;
} EnElf;

void Fairy_UpdateRainbowNaviColors(EnElf* navi);
void Fairy_ResetRainbowCMABs(void);

/* Great Fairy */

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

void BgDyYoseizo_rInit(Actor* thisx, GlobalContext* globalCtx);
void BgDyYoseizo_rUpdate(Actor* thisx, GlobalContext* globalCtx);

#endif //_FAIRY_H_
