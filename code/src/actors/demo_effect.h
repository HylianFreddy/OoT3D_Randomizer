#ifndef _R_DEMO_EFFECT_H_
#define _R_DEMO_EFFECT_H_

#include "z3D/actors/z_demo_effect.h"
#include "z3D/z3D.h"

void DemoEffect_rInit(Actor* thisx, GlobalContext* globalCtx);
void DemoEffect_rDestroy(Actor* thisx, GlobalContext* globalCtx);
void DemoEffect_rUpdate(Actor* thisx, GlobalContext* globalCtx);

#endif //_R_DEMO_EFFECT_H_
