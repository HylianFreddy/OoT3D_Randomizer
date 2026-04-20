#include "z3D/z3D.h"
#include "z3D/z3Dcmb.h"
#include "actor.h"
#include "settings.h"
#include "objects.h"
#include "common.h"
#include "oot_malloc.h"

#include <string.h>

#define GET_STRUCT_FIELD(structPointer, type, offset) (*(type*)((u32)structPointer + offset))

// static u32 sOrigTextureMappersUsed[10];
// static u32 sOrigBlendMode[10];
// static u8 sOrigAlphaTestEnabled[10];

static u8 black = 1;

void CmbManager_BeforeInit(CmbManager* cmbMan) {
    // if (!gIsForSoullessActor || gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK) {
    //     return;
    // }

    // CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    // for (size_t i = 0; i < cmbMats->materialCount; i++) {
    //     Material* mat = &cmbMats->materials[i];

    //     // sOrigTextureMappersUsed[i] = mat->textureMappersUsed;
    //     // sOrigAlphaTestEnabled[i] = mat->alphaTestEnabled;
    //     // sOrigBlendMode[i] = mat->blendMode;

    //     if (black) {
    //         mat->textureMappersUsed = 0;
    //         mat->alphaTestEnabled = 0x0;
    //         mat->blendMode        = 0x0;
    //     } else if (mat->textureMappersUsed == 0) {
    //         mat->textureMappersUsed = 1;
    //         mat->alphaTestEnabled = 0x1;
    //         mat->blendMode        = 0x1;
    //     }

    //     // mat->textureMappersUsed = 0; // good for black

    //     // // All transparent
    //     // mat->alphaTestEnabled = 0x0; // good for black
    //     // mat->blendMode        = 0x0; // good for black
    // }
}

void CmbManager_AfterInit(CmbManager* cmbMan) {
    // if (!gIsForSoullessActor || gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK) {
    //     return;
    // }

    // CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    // for (size_t i = 0; i < cmbMats->materialCount; i++) {
    //     Material* mat = &cmbMats->materials[i];

    //     mat->textureMappersUsed = sOrigTextureMappersUsed[i];
    //     mat->alphaTestEnabled = sOrigAlphaTestEnabled[i];
    //     mat->blendMode = sOrigBlendMode[i];
    // }
}

void CmbManager_Log(CmbManager* cmbMan) {
    CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat = &cmbMats->materials[i];
        CitraPrint("textureMappersUsed = %X", mat->textureMappersUsed);
        CitraPrint("alphaTestEnabled = %X", mat->alphaTestEnabled);
        CitraPrint("blendMode = %X", mat->blendMode);
    }
}

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

void CmbManager_ReInitTektite(void) {
    ObjectEntry* obj   = Object_FindEntryOrSpawn(0x16);
    ZARInfo* zarInfo   = &obj->zarInfo;
    CmbManager* cmbMan = ZAR_GetCMBByIndex(zarInfo, 0);
    CMB_MATS* cmbMats  = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat = &cmbMats->materials[i];

        CitraPrint("black %X", black);
        if (black) {
            mat->textureMappersUsed = 0;
            mat->alphaTestEnabled   = 0x0;
            mat->blendMode          = 0x0;
        } else if (mat->textureMappersUsed == 0) {
            mat->textureMappersUsed = 1;
            mat->alphaTestEnabled   = 0x1;
            mat->blendMode          = 0x1;
        }
    }
    black ^= 1;
    return;
    // Store addresses of CMB Managers to later identify the correct cmbIndex to use for actor models.
    u32 numCMBs = 0;
    if (zarInfo->fileTypeMap[0] != -1) {
        numCMBs = zarInfo->fileTypes[zarInfo->fileTypeMap[0]].numFiles;
    }
    CmbManager* oldCmbMans[numCMBs];
    memcpy(&oldCmbMans, zarInfo->cmbMans, sizeof(oldCmbMans));

    // Re-initialize ZarInfo, keeping same buffer and size. This destroys all CMB Managers.
    ZAR_Destroy(zarInfo);
    ZAR_SetupZARInfo(zarInfo, obj->buf, obj->size, 0);
    // Re-initialize CMB Manager.
    black ^= 1;
    gIsForSoullessActor = 1;
    ZAR_GetCMBByIndex(zarInfo, 0);
    gIsForSoullessActor = 0;

    // ZARInfo* zarInfo = &Object_FindEntryOrSpawn(0x16)->zarInfo;
    // CitraPrint("zarInfo->cmbMans[0] = %X", zarInfo->cmbMans[0]);
    // CmbManager_Log(zarInfo->cmbMans[0]);
    // FUN_002da0e4(zarInfo->cmbMans[0]);
    // zarInfo->cmbMans[0]   = NULL;
    // CmbManager* newCmbMan = ZAR_GetCMBByIndex(zarInfo, 0);
    // void* buf = zarInfo->buf;
    // s32 size  = zarInfo->size;
    // ZAR_Destroy(zarInfo);
    // SystemArena_Free(buf);
    // buf = SystemArena_Malloc(size);
    // ZAR_SetupZARInfo(zarInfo, buf, size, 0);
    // CitraPrint("zarInfo->cmbMans[0] = %X", zarInfo->cmbMans[0]);

    for (Actor* actor = gGlobalContext->actorCtx.actorList[ACTORTYPE_ENEMY].first; actor != NULL; actor = actor->next) {
        if (actor->id == ACTOR_TEKTITE) {
            // CitraPrint("((EnTite*)actor)->skelAnime.cmbMan = %X", ((EnTite*)actor)->skelAnime.cmbMan);
            // ((EnTite*)actor)->skelAnime.cmbMan = newCmbMan;
            // EnTite_Init(((EnTite*)actor), gGlobalContext);

            SkelAnime* anime = &((EnTite*)actor)->skelAnime;
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
            s32 cmbIndex = 0;
            for (s32 i = 0; i < numCMBs; i++) {
                if (oldCmbMans[i] == anime->cmbMan) {
                    cmbIndex = i;
                    break;
                }
            }

            SkelAnime_Destroy(anime);
            SkelAnime_Init(actor, gGlobalContext, anime, cmbIndex, animIndex, jointTable, morphTable, 0);
            // Animation_ChangeImpl(anime, 0, 1.0, 1.0, 1.0, 0, 4.0, 0);
            // EnTite_Init(((EnTite*)actor), gGlobalContext);

            // Animation_PlayLoop(anime, 1);
            Animation_ChangeImpl(anime, animIndex, playSpeed, startFrame, endFrame, animMode, 0.0, 0);
            // GET_STRUCT_FIELD(actor, u32, 0x63c) = 0x284724;
            anime->curFrame = curFrame;

            // CitraPrint("((EnTite*)actor)->skelAnime.cmbMan = %X", ((EnTite*)actor)->skelAnime.cmbMan);
        }
    }
    // CmbManager_Log(zarInfo->cmbMans[0]);
}

// void Before_SkelAnimeInit(Actor* actor, CmbManager* cmbMan) {
//     if (!gIsForSoullessActor || gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK) {
//         return;
//     }

//     CitraPrint("actor %X", actor->id);
//     CitraPrint("cmbMan before %X", cmbMan);

//     CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
//     for (size_t i = 0; i < cmbMats->materialCount; i++) {
//         Material* mat = &cmbMats->materials[i];

//         if (black) {
//             mat->textureMappersUsed = 0;
//             mat->alphaTestEnabled   = 0x0;
//             mat->blendMode          = 0x0;
//         } else if (mat->textureMappersUsed == 0) {
//             mat->textureMappersUsed = 1;
//             mat->alphaTestEnabled   = 0x1;
//             mat->blendMode          = 0x1;
//         }
//     }
// }

// void After_SkelAnimeInit(CmbManager* cmbMan) {
//     CitraPrint("cmbMan after %X", cmbMan);
// }

static SkelAnime* sSkelAnime;

void SkelAnime_InitImpl(SkelAnime* skelAnime, ZARInfo* zarInfo, GlobalContext* globalCtx, CmbManager* cmbMan, s32 unk,
                        s32 csabIndex, void* jointTable, void* morphTable, s32 limbCount);
void SkelAnime_rInitImpl(SkelAnime* skelAnime, ZARInfo* zarInfo, Actor* actor, CmbManager* cmbMan, s32 unk,
                         s32 csabIndex, void* jointTable, void* morphTable, s32 limbCount) {
    // Actor* actor = skelAnime->sub20->actor;
    // CitraPrint("skelinit: %X, %X", actor, skelAnime->sub20 ? skelAnime->sub20->actor : 0);
    if (actor->id != ACTOR_TEKTITE) {
        return SkelAnime_InitImpl(skelAnime, zarInfo, gGlobalContext, cmbMan, unk, csabIndex, jointTable, morphTable,
                                  limbCount);
    }

    // const u8 isBlack  = gIsForSoullessActor && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK;
    CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);

    SkelAnime_InitImpl(skelAnime, zarInfo, gGlobalContext, cmbMan, unk, csabIndex, jointTable, morphTable, limbCount);
    // CmbManager_Log(skelAnime->cmbMan);
    // if (isBlack) {
    //     CitraPrint("actor %X", actor->id);
    //     CitraPrint("cmbMan before %X", cmbMan);

    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat = &cmbMats->materials[i];

        // origTextureMappersUsed[i] = mat->textureMappersUsed;
        // origAlphaTestEnabled[i]   = mat->alphaTestEnabled;
        // origBlendMode[i]          = mat->blendMode;

        mat->textureMappersUsed = 0;
        mat->alphaTestEnabled   = 0x0;
        mat->blendMode          = 0x0;
    }
    sSkelAnime = skelAnime;
}

void SkelAnime_DrawOpaImpl(SubMainClass_180* sub180, SkelAnime* skelAnime, nn_math_MTX44* modelMtx,
                           void* overrideLimbDraw, void* postLimbDraw, Actor* actor, s32 unk);
void SkelAnime_rDrawOpaImpl(SubMainClass_180* sub180, SkelAnime* skelAnime, nn_math_MTX44* modelMtx,
                            void* overrideLimbDraw, void* postLimbDraw, Actor* actor, s32 unk) {
    if (actor->id != ACTOR_TEKTITE) {
        return SkelAnime_DrawOpaImpl(sub180, skelAnime, modelMtx, overrideLimbDraw, postLimbDraw, actor, unk);
    }
    // CitraPrint("skelAnime draw rGameplayFrames: %d", rGameplayFrames);
    // sSkelAnime = skelAnime;
    // const u8 isBlack  = gIsForSoullessActor && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK;
    // CMB_MATS* cmbMats = Cmb_GetMatsChunk(skelAnime->cmbMan->cmbChunk);
    // // u32 origTextureMappersUsed[cmbMats->materialCount];
    // // u32 origBlendMode[cmbMats->materialCount];
    // // u8 origAlphaTestEnabled[cmbMats->materialCount];
    // static s32 flag = 0;
    // flag++;
    // //  0 4 0 512 4
    // // CitraPrint("sub180: %d %d %d %d %d",
    // //     sub180->unk_04, sub180->count_08, sub180->count_0C, sub180->count_14, *sub180->countPointer_18);

    // // CitraPrint("skelAnime->saModel->vtbl: %X", skelAnime->saModel->vtbl);

    // if (flag > 1) {
    //     // CitraPrint("flag=%X, rGameplayFrames=%X", flag, rGameplayFrames);
    //     for (size_t i = 0; i < cmbMats->materialCount; i++) {
    //         Material* mat = &cmbMats->materials[i];

    //         // origTextureMappersUsed[i] = mat->textureMappersUsed;
    //         // origAlphaTestEnabled[i]   = mat->alphaTestEnabled;
    //         // origBlendMode[i]          = mat->blendMode;

    //         mat->textureMappersUsed = 0;
    //         mat->alphaTestEnabled   = 0x0;
    //         mat->blendMode          = 0x0;
    //     }
    // }
    SkelAnime_DrawOpaImpl(sub180, skelAnime, modelMtx, overrideLimbDraw, postLimbDraw, actor, unk);
    // if (flag > 4) {
    //     for (size_t i = 0; i < cmbMats->materialCount; i++) {
    //         Material* mat           = &cmbMats->materials[i];
    //         mat->textureMappersUsed = origTextureMappersUsed[i];
    //         mat->alphaTestEnabled   = origAlphaTestEnabled[i];
    //         mat->blendMode          = origBlendMode[i];
    //     }
    // }
}

// #define SkeletonAnimationModel_Draw ((void (*)(SkeletonAnimationModel * model))0x3fed90)
void SkeletonAnimationModel_rDraw(SkeletonAnimationModel* model, void (*drawFunc)(SkeletonAnimationModel* model)) {
    if (sSkelAnime == NULL || model != sSkelAnime->saModel) {
        return drawFunc(model);
    }

    // CitraPrint("SkeletonAnimationModel_rDraw rGameplayFrames: %d", rGameplayFrames);
    // void* class = model->unk_14->unkAutoClass1;
    // CitraPrint("SkeletonAnimationModel_rDraw; %X", *(u8*)(((u32)class)+0x1B9));
    static s32 flag = 0;
    flag++;
    CMB_MATS* cmbMats = Cmb_GetMatsChunk(sSkelAnime->cmbMan->cmbChunk);
    // if (flag == 1) {
    //     for (size_t i = 0; i < cmbMats->materialCount; i++) {
    //         Material* mat           = &cmbMats->materials[i];
    //         mat->textureMappersUsed = 0;
    //         mat->alphaTestEnabled   = 0x0;
    //         mat->blendMode          = 0x0;
    //     }
    // }
    if (flag > 60) {
        for (size_t i = 0; i < cmbMats->materialCount; i++) {
            Material* mat           = &cmbMats->materials[i];
            mat->textureMappersUsed = 1;
            mat->alphaTestEnabled   = flag % 2;
            mat->blendMode          = 0x0;
        }
    }

    drawFunc(model);
}

void SkeletonAnimationModel_Init_3fefec(u32 r0, u32 r1) {
    // CitraPrint("SkeletonAnimationModel_Init_3fefec");
}

void test(u32 r0, u32 r1, u32 r2, u32 r3) {
    // CitraPrint("test r2=%X", r2);
}
