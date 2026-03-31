#ifndef _FAIRY_H_
#define _FAIRY_H_

#include "z3D/z3D.h"
#include "actors/z_bg_dy_yoseizo.h"

typedef struct EnElf {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ char unk_1A4[0x784];
    /* 0x928 */ Color_RGBAf innerColor;
    /* 0x938 */ Color_RGBAf outerColor;
} EnElf;

void Fairy_UpdateRainbowNaviColors(EnElf* navi);
void Fairy_ResetRainbowCMABs(void);

/* Great Fairy */

void BgDyYoseizo_rInit(Actor* thisx, GlobalContext* globalCtx);
void BgDyYoseizo_rUpdate(Actor* thisx, GlobalContext* globalCtx);

#endif //_FAIRY_H_
