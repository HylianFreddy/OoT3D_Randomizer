#include "tentacle.h"
#include "actor.h"

void EnBa_ReinitModels(EnBa* this) {
    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);

    this->matAnim = this->anime.saModel->matAnim;
    void* cmabMan = ZAR_GetCMABByIndex(this->anime.zarInfo, 3);
    MatAnim_Init(this->matAnim, cmabMan);
    this->matAnim->animSpeed = 1.0;
    this->matAnim->animMode  = 1;

    FaceAnim_Destroy(&this->faceAnim);
    FaceAnim_Init(&this->faceAnim, &this->anime, 2, -1, -1);
    FaceAnim_SetFrame(&this->faceAnim, 0, this->actor.params);
    FaceAnimation_35E330(&this->faceAnim);
}
