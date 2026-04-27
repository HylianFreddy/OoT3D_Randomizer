#include "torch_slug.h"
#include "actor.h"

void EnBw_ReinitModels(EnBw* this) {
    SkelAnime* anime = &this->anime;
    Actor_ReinitSkelAnime(&this->actor, anime, 0);

    this->matAnim = this->anime.saModel->matAnim;
    void* cmabMan = ZAR_GetCMABByIndex(anime->zarInfo, 0);
    MatAnim_Init(this->matAnim, cmabMan);
    this->matAnim->animMode = 1;
}
