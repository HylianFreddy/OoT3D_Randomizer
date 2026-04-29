#include "volvagia.h"
#include "actor.h"

void BossFd_ReinitModels(BossFd* this) {
    // Actor_DestroySkelModels(&this->actor, &this->shadowModel, NULL);
    // Actor_CreateSkelModels(&this->actor, gGlobalContext, &this->shadowModel, 2, NULL);

    Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeBody, 1);
    MatAnim_Init(this->skelAnimeBody.saModel->matAnim, ZAR_GetCMABByIndex(this->zarInfo, 4));
    this->skelAnimeBody.saModel->matAnim->animMode = 1;

    Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeHead, 3);
    MatAnim_Init(this->skelAnimeHead.saModel->matAnim, ZAR_GetCMABByIndex(this->zarInfo, 6));
    this->skelAnimeHead.saModel->matAnim->animMode = 1;

    Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeSkull, 9);

    Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeRightArm, 5);
    MatAnim_Init(this->skelAnimeRightArm.saModel->matAnim, ZAR_GetCMABByIndex(this->zarInfo, 8));
    this->skelAnimeRightArm.saModel->matAnim->animMode = 1;

    Actor_ReinitSkelAnime(&this->actor, &this->skelAnimeLeftArm, 4);
    MatAnim_Init(this->skelAnimeLeftArm.saModel->matAnim, ZAR_GetCMABByIndex(this->zarInfo, 7));
    this->skelAnimeLeftArm.saModel->matAnim->animMode = 1;
}
