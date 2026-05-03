#include "barinade.h"
#include "actor.h"

void BossVa_ReinitModels(BossVa* this) {
    BossVaParam part = this->actor.params;
    if (part == BOSSVA_BODY) {
        Actor_DestroySkelModels(&this->actor, &this->jellyfishModel_1, &this->jellyfishModel_2, &this->jellyfishModel_3,
                                &this->jellyfishModel_4, &this->jellyfishModel_5, &this->jellyfishModel_6,
                                &this->jellyfishModel_7, &this->jellyfishModel_8, &this->jellyfishModel_9,
                                &this->jellyfishModel_10, NULL);
        Actor_CreateSkelModels(&this->actor, gGlobalContext, &this->jellyfishModel_1, 12, &this->jellyfishModel_2, 12,
                               &this->jellyfishModel_3, 12, &this->jellyfishModel_4, 12, &this->jellyfishModel_5, 12,
                               &this->jellyfishModel_6, 12, &this->jellyfishModel_7, 12, &this->jellyfishModel_8, 12,
                               &this->jellyfishModel_9, 12, &this->jellyfishModel_10, 12, NULL);

        Actor_ReinitSkelAnime(&this->actor, &this->anime, 3);

        this->anime.saModel->matAnim->subSAM10 = this->anime.saModel->subSAM10;
        MatAnim_Init(this->anime.saModel->matAnim, ZAR_GetCMABByIndex(this->anime.zarInfo, 0));
        this->anime.saModel->matAnim->animSpeed = 1.0;
        this->anime.saModel->matAnim->animMode  = 1;

        this->matAnim.subSAM10 = this->anime.saModel->subSAM10;
        MatAnim_Init(&this->matAnim, ZAR_GetCMABByIndex(this->anime.zarInfo, 4));
        this->matAnim.animSpeed = 1.0;
        this->matAnim.animMode  = 1;
    } else if (part >= BOSSVA_SUPPORT_1 && part <= BOSSVA_SUPPORT_3) {
        Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);

        MatAnim_Init(this->anime.saModel->matAnim, ZAR_GetCMABByIndex(this->anime.zarInfo, 3));
        this->anime.saModel->matAnim->animSpeed = 0.0;
        this->anime.saModel->matAnim->curFrame  = this->actor.params;
    } else if (part >= BOSSVA_ZAPPER_1 && part <= BOSSVA_ZAPPER_3) {
        Actor_ReinitSkelAnime(&this->actor, &this->anime, 4);
    } else if (part >= BOSSVA_BARI_UPPER_1 && part <= BOSSVA_BARI_LOWER_5) {
        Actor_ReinitSkelAnime(&this->actor, &this->anime, 7);
    }
}
