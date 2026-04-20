#include "z3D/z3D.h"
#include "z3D/z3Dcmb.h"
#include "actor.h"
#include "settings.h"
#include "objects.h"
#include "common.h"
#include "oot_malloc.h"
#include "enemy_souls.h"

#include <string.h>

#define GET_STRUCT_FIELD(structPointer, type, offset) (*(type*)((u32)structPointer + offset))

typedef struct CmbOriginalData {
    char magic;
    struct {
        u8 textureMappersUsed : 5;
        u8 alphaTestEnabled : 1; // boolean
        u8 blendMode : 2;        // values 0-3
    } mats[15];
} CmbOriginalData;
_Static_assert(sizeof(CmbOriginalData) == sizeof(((CMB_HEAD*)0)->name), "CmbOriginalData size");


void CmbManager_BeforeInit(CmbManager* cmbMan) {
}

void CmbManager_AfterInit(CmbManager* cmbMan) {
}

// void CmbManager_Log(CmbManager* cmbMan) {
//     CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
//     for (size_t i = 0; i < cmbMats->materialCount; i++) {
//         Material* mat = &cmbMats->materials[i];
//         CitraPrint("textureMappersUsed = %X", mat->textureMappersUsed);
//         CitraPrint("alphaTestEnabled = %X", mat->alphaTestEnabled);
//         CitraPrint("blendMode = %X", mat->blendMode);
//     }
// }

typedef struct EnTite {
    Actor actor;
    SkelAnime skelAnime;
} EnTite;

#define FUN_002da0e4 ((void* (*)(CmbManager * cmbMan))0x2da0e4)
#define EnTite_Init ((void (*)(EnTite * this, GlobalContext * global_ctx))0x1BBC0C)
#define ZAR_SetupZARInfo ((void (*)(ZARInfo * zarInfo, void* buf, s32 size, s8 param_4))0x31B124)
#define SkelAnime_Destroy ((void (*)(SkelAnime * anime))0x350be0)
// limbCount param is ignored, the function takes the value from the cmb
#define SkelAnime_Init                                                                                       \
    ((void (*)(Actor * actor, GlobalContext * globalCtx, SkelAnime * skelAnime, s32 cmbIndex, s32 csabIndex, \
               void* jointTable, void* morphTable, s32 limbCount))0x353c9c)
typedef void (*Foo)(SkelAnime* anime, s32 animation_index, f32 play_speed, f32 start_frame, f32 end_frame, s32 mode,
                    f32 morph_frames, s32 taper) __attribute__((pcs("aapcs-vfp")));
#define Animation_ChangeImpl ((Foo)0x35302c)
#define Animation_PlayLoop ((void (*)(SkelAnime * anime, s32 animation_index))0x36e734)

void SkelAnime_BeforeInit(CmbManager* cmbMan, Actor* actor) {
    if (!EnemySouls_CheckSoulForActor(actor) && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
        CmbOriginalData* origDataBuf = (CmbOriginalData*)&((CMB_HEAD*)cmbMan->cmbChunk)->name;
        if (origDataBuf->magic != '-') {
            origDataBuf->magic = '-';
            CMB_MATS* cmbMats  = Cmb_GetMatsChunk(cmbMan->cmbChunk);
            for (s32 i = 0; i < cmbMats->materialCount; i++) {
                Material* mat                           = &cmbMats->materials[i];
                origDataBuf->mats[i].textureMappersUsed = mat->textureMappersUsed;
                origDataBuf->mats[i].alphaTestEnabled   = mat->alphaTestEnabled;
                origDataBuf->mats[i].blendMode          = mat->blendMode;
                mat->textureMappersUsed                 = 0;
                mat->alphaTestEnabled                   = 0;
                mat->blendMode                          = 0;
            }
        }
    }
}

void RestoreActorModel(Actor* actor) {
    if (actor->id != ACTOR_TEKTITE) {
        return;
    }
    SkelAnime* anime = &((EnTite*)actor)->skelAnime;

    CmbOriginalData* origDataBuf = (CmbOriginalData*)&((CMB_HEAD*)anime->cmbMan->cmbChunk)->name;
    if (origDataBuf->magic == '-') {
        origDataBuf->magic = '^';
        CMB_MATS* cmbMats  = Cmb_GetMatsChunk(anime->cmbMan->cmbChunk);
        for (s32 i = 0; i < cmbMats->materialCount; i++) {
            Material* mat           = &cmbMats->materials[i];
            mat->textureMappersUsed = origDataBuf->mats[i].textureMappersUsed;
            mat->alphaTestEnabled   = origDataBuf->mats[i].alphaTestEnabled;
            mat->blendMode          = origDataBuf->mats[i].blendMode;
        }
    }

    u32 numCMBs  = anime->zarInfo->fileTypes[anime->zarInfo->fileTypeMap[0]].numFiles;
    s32 cmbIndex = 0;
    for (s32 i = 0; i < numCMBs; i++) {
        if (anime->zarInfo->cmbMans[i] == anime->cmbMan) {
            cmbIndex = i;
            break;
        }
    }

    s32 animIndex    = anime->animIndex;
    f32 curFrame     = anime->curFrame;
    f32 playSpeed    = anime->playSpeed;
    f32 startFrame   = anime->startFrame;
    f32 endFrame     = anime->endFrame;
    f32 animMode     = anime->animMode;
    void* jointTable = NULL;
    void* morphTable = NULL;
    if (!anime->dynamicTables) {
        jointTable = anime->jointTable;
        morphTable = anime->morphTable;
    }

    SkelAnime_Destroy(anime);
    SkelAnime_Init(actor, gGlobalContext, anime, cmbIndex, animIndex, jointTable, morphTable, 0);
    Animation_ChangeImpl(anime, animIndex, playSpeed, startFrame, endFrame, animMode, 0.0, 0);
    anime->curFrame = curFrame;
}

void AfterSoulObtained(EnemySoulId obtainedSoul) {
    if (gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
        ActorType actorCats[2] = { ACTORTYPE_ENEMY, ACTORTYPE_BOSS };
        for (s32 i = 0; i < ARRAY_SIZE(actorCats); i++) {
            Actor* actor = gGlobalContext->actorCtx.actorList[actorCats[i]].first;
            while (actor != NULL) {
                if (EnemySouls_GetSoulId(actor->id) == obtainedSoul) {
                    RestoreActorModel(actor);
                }
                actor = actor->next;
            }
        }
    }
}

void CmbManager_ReInitTektite(void) {
    AfterSoulObtained(SOUL_TEKTITE);
}

void SkelAnime_DrawOpaImpl(SubMainClass_180* sub180, SkelAnime* skelAnime, nn_math_MTX44* modelMtx,
                           void* overrideLimbDraw, void* postLimbDraw, Actor* actor, s32 unk);
void SkelAnime_rDrawOpaImpl(SubMainClass_180* sub180, SkelAnime* skelAnime, nn_math_MTX44* modelMtx,
                            void* overrideLimbDraw, void* postLimbDraw, Actor* actor, s32 unk) {
    SkelAnime_DrawOpaImpl(sub180, skelAnime, modelMtx, overrideLimbDraw, postLimbDraw, actor, unk);
}

// #define SkeletonAnimationModel_Draw ((void (*)(SkeletonAnimationModel * model))0x3fed90)
void SkeletonAnimationModel_rDraw(SkeletonAnimationModel* model, void (*drawFunc)(SkeletonAnimationModel* model)) {
    drawFunc(model);
}

void SkeletonAnimationModel_Init_3fefec(u32 r0, u32 r1) {
    // CitraPrint("SkeletonAnimationModel_Init_3fefec");
}

void test(u32 r0, u32 r1, u32 r2, u32 r3) {
    // CitraPrint("test r2=%X", r2);
}
