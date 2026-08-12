#include "z3D/z3D.h"
#include "great_fairy.h"

void BgDyYoseizo_Init(Actor* thisx, GlobalContext* globalCtx);
void BgDyYoseizo_Draw(Actor* thisx, GlobalContext* globalCtx);

void Cutscene_OverrideFairyReward(BgDyYoseizo* fairy);
static void GreatFairy_OverrideReward(BgDyYoseizo* fairy) {
    Cutscene_OverrideFairyReward(fairy);
}

static void GreatFairy_Action_WaitForSong(BgDyYoseizo* this, GlobalContext* globalCtx) {
    if (Flags_GetSwitch(globalCtx, 0x38)) {
        globalCtx->ocarinaMode = 4;
        GreatFairy_OverrideReward(this);
        this->actionFn = NULL;
    }
}

void BgDyYoseizo_rInit(Actor* thisx, GlobalContext* globalCtx) {
    BgDyYoseizo* this = (BgDyYoseizo*)thisx;

    BgDyYoseizo_Init(thisx, globalCtx);

    thisx->scale = (Vec3f){
        .x = 0.035f,
        .y = 0.035f,
        .z = 0.035f,
    };
    Animation_Change(&this->skelAnime, 7, 1.0, 0.0, Animation_GetLastFrame(&this->skelAnime, 7), 0, -10.0);
    thisx->draw    = BgDyYoseizo_Draw;
    this->actionFn = GreatFairy_Action_WaitForSong;
}

void BgDyYoseizo_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    BgDyYoseizo* this = (BgDyYoseizo*)thisx;

    globalCtx->envCtx.lightSettingOverride = PLAYER->actor.world.pos.z < -300 ? 2 : 0xFF;

    SkelAnime_Update(&this->skelAnime);

    if (this->actionFn != NULL) {
        this->actionFn(this, globalCtx);
    }
}
