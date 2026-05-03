#include "bongo_bongo.h"
#include "actor.h"

void BossSst_ReinitModels(BossSst* this) {
    if (this->actor.params == BONGO_HEAD) {
        Actor_ReinitSkelAnime(&this->actor, &this->mainSkelAnime, 3);
        return;
    }

    s32 handCmbIndex = this->actor.params == BONGO_LEFT_HAND ? 1 : 2;

    Actor_ReinitSkelAnime(&this->actor, &this->mainSkelAnime, handCmbIndex);
    for (s32 i = 0; i < 8; i++) {
        Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeArr[i], handCmbIndex);
    }
}
