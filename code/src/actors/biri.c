#include "biri.h"
#include "actor.h"

void EnBili_ReinitModels(EnBili* this) {
    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);

    FaceAnim_Destroy(&this->faceAnim);
    FaceAnim_Init(&this->faceAnim, &this->anime, 0, -1, -1);
}
