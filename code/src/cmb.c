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
