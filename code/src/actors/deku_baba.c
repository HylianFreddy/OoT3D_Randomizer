#include "deku_baba.h"
#include "actor.h"
#include "settings.h"
#include "enemizer.h"

/*-------------------------------
|           EnDekubaba          |
-------------------------------*/

void EnDekubaba_ReinitModels(EnDekubaba* this) {
    Actor_DestroySkelModels(&this->actor, &this->stalkModel_1, &this->stalkModel_2, &this->stalkModel_3,
                            &this->leavesModel, &this->stickModel, NULL);
    Actor_CreateSkelModels(&this->actor, gGlobalContext, &this->stalkModel_1, 1, &this->stalkModel_2, 2,
                           &this->stalkModel_3, 3, &this->leavesModel, 4, &this->stickModel, 5, NULL);

    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);
}

/*-------------------------------
|           EnKarebaba          |
-------------------------------*/

void EnKarebaba_Update(Actor* thisx, GlobalContext* globalCtx);

void EnKarebaba_Dead(EnKarebaba* this, GlobalContext* globalCtx);

void EnKarebaba_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnKarebaba* this              = (EnKarebaba*)thisx;
    ExtraActorFields* actorExtras = (ExtraActorFields*)thisx;

    EnKarebaba_Update(thisx, globalCtx);

    if (actorExtras->representsActorEntry && gSettingsContext.enemyPermadeath && this->actionFunc == EnKarebaba_Dead) {
        // Don't kill the actor to keep the leaves on the ground.
        Enemizer_OnEnemyDefeat(actorExtras->actorEntryIndex);
        thisx->update = Actor_DoNothing;
    }
}

void EnKarebaba_ReinitModels(EnKarebaba* this) {
    Actor_DestroySkelModels(&this->actor, &this->stalkModel_1, &this->stalkModel_2, &this->stalkModel_3,
                            &this->leavesModel, &this->stickModel, NULL);
    Actor_CreateSkelModels(&this->actor, gGlobalContext, &this->stalkModel_1, 1, &this->stalkModel_2, 2,
                           &this->stalkModel_3, 3, &this->leavesModel, 4, &this->stickModel, 5, NULL);

    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);
}
