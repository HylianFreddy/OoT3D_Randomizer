#include "z3D/z3D.h"
#include "fairy.h"
#include "settings.h"

static u8 lastTargetActorType = 0;

void Fairy_StoreTargetActorType(u8 targetActorType) {
    lastTargetActorType = targetActorType;
}

void Fairy_ChangeRainbowColorRGBAf(Color_RGBAf* color) {
#define COLOR_SPEED 17 // 255 = 3*17*5
    if (color->r == 255.0f && color->g != 255.0f && color->b == 0)
        color->g += COLOR_SPEED;
    else if (color->r != 0 && color->g == 255.0f && color->b == 0)
        color->r -= COLOR_SPEED;
    else if (color->r == 0 && color->g == 255.0f && color->b != 255.0f)
        color->b += COLOR_SPEED;
    else if (color->r == 0 && color->g != 0 && color->b == 255.0f)
        color->g -= COLOR_SPEED;
    else if (color->r != 255.0f && color->g == 0 && color->b == 255.0f)
        color->r += COLOR_SPEED;
    else if (color->r == 255.0f && color->g == 0 && color->b != 0)
        color->b -= COLOR_SPEED;
}

void Fairy_UpdateRainbowNaviColors(EnElf* navi) {

    if (lastTargetActorType == ACTORTYPE_PLAYER) {
        if (gSettingsContext.rainbowIdleNaviInnerColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->innerColor));
        if (gSettingsContext.rainbowIdleNaviOuterColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->outerColor));
    } else if (lastTargetActorType == ACTORTYPE_NPC) {
        if (gSettingsContext.rainbowNPCNaviInnerColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->innerColor));
        if (gSettingsContext.rainbowNPCNaviOuterColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->outerColor));
    } else if (lastTargetActorType == ACTORTYPE_ENEMY || lastTargetActorType == ACTORTYPE_BOSS) {
        if (gSettingsContext.rainbowEnemyNaviInnerColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->innerColor));
        if (gSettingsContext.rainbowEnemyNaviOuterColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->outerColor));
    } else {
        if (gSettingsContext.rainbowPropNaviInnerColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->innerColor));
        if (gSettingsContext.rainbowPropNaviOuterColor)
            Fairy_ChangeRainbowColorRGBAf(&(navi->outerColor));
    }
}
