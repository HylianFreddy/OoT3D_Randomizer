#include "biri.h"
#include "actor.h"

/*-------------------------------
|             EnBili            |
-------------------------------*/

void EnBili_ReinitModels(EnBili* this) {
    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);

    FaceAnim_Destroy(&this->faceAnim);
    FaceAnim_Init(&this->faceAnim, &this->anime, 0, -1, -1);
}

/*-------------------------------
|             EnVali            |
-------------------------------*/

void EnVali_Destroy(Actor* thisx, GlobalContext* globalCtx);

void EnVali_rDestroy(Actor* thisx, GlobalContext* globalCtx) {
    ExtraActorFields* thisExtras = (ExtraActorFields*)thisx;

    EnVali_Destroy(thisx, globalCtx);

    // Transfer actor entry representation to a child Biri.
    Actor* enemy = globalCtx->actorCtx.actorList[ACTORTYPE_ENEMY].first;
    while (enemy != NULL) {
        ExtraActorFields* enemyExtras = (ExtraActorFields*)enemy;
        if (enemy->id == ACTOR_BIRI && enemyExtras->representsActorEntry == FALSE) {
            enemyExtras->representsActorEntry = TRUE;
            enemyExtras->actorEntryIndex      = thisExtras->actorEntryIndex;
            thisExtras->representsActorEntry  = FALSE;
            break;
        }
        enemy = enemy->next;
    }
}

void EnVali_ReinitModels(EnVali* this) {
    Actor_DestroySkelModels(&this->actor, &this->tentaclesModel, &this->innerBellModel, &this->outerBellModel,
                            &this->purpleSphereModel_1, &this->purpleSphereModel_2, &this->purpleSphereModel_3, NULL);
    ZARInfo* zarInfo = Actor_CreateSkelModels(
        &this->actor, gGlobalContext, &this->tentaclesModel, 0, &this->innerBellModel, 2, &this->outerBellModel, 1,
        &this->purpleSphereModel_1, 3, &this->purpleSphereModel_2, 3, &this->purpleSphereModel_3, 3, NULL);

    Actor_ReinitSkelAnime(&this->actor, &this->anime, 0);

    MatAnim_Destroy(&this->matAnim);
    void* cmabMan          = ZAR_GetCMABByIndex(zarInfo, 0);
    this->matAnim.subSAM10 = this->innerBellModel->subSAM10;
    MatAnim_Init(&this->matAnim, cmabMan);
    this->matAnim.animMode  = 1;
    this->matAnim.animSpeed = 1.0;
}
