#include "z3D/z3D.h"
#include "z3D/z3Dcmb.h"
#include "actor.h"
#include "settings.h"
#include "objects.h"
#include "common.h"
#include "oot_malloc.h"

#define GET_STRUCT_FIELD(structPointer, type, offset) (*(type*)((u32)structPointer + offset))

void CmbManager_BeforeInit(CmbManager* cmbMan) {
    // if (!gIsForSoullessActor || gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK) {
    //     return;
    // }
    if (!IsInGame()) {
        return;
    }
    return;

    CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat = &cmbMats->materials[i];

        if (gIsForSoullessActor) {
            mat->textureMappersUsed = 0;
        } else if (mat->textureMappersUsed == 0) {
            mat->textureMappersUsed = 1;
        }

        // mat->textureMappersUsed = 0; // good for black

        // // All transparent
        // mat->alphaTestEnabled = 0x0; // good for black
        // mat->blendMode        = 0x0; // good for black
    }
}

void CmbManager_Log(CmbManager* cmbMan) {
    CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat = &cmbMats->materials[i];
        CitraPrint("textureMappersUsed = %X", mat->textureMappersUsed);
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
#define SkelAnime_Init                                                                                       \
    ((void (*)(Actor * actor, GlobalContext * globalCtx, SkelAnime * skelAnime, s32 cmbIndex, s32 csabIndex, \
               void* jointTable, void* morphTable, s32 limbCount))0x353c9c)
#define Animation_ChangeImpl                                                                                     \
    ((void (*)(SkelAnime * anime, s32 animation_index, f32 play_speed, f32 start_frame, f32 end_frame, s32 mode, \
               f32 morph_frames, s32 taper))0x35302c)

void CmbManager_ReInitTektite(void) {
    ObjectEntry* obj = Object_FindEntryOrSpawn(0x16);
    ZARInfo* zarInfo = &obj->zarInfo;
    // Re-initialize ZarInfo, keeping same buffer and size. This destroys all CMBManagers
    ZAR_Destroy(zarInfo);
    ZAR_SetupZARInfo(zarInfo, obj->buf, obj->size, 0);
    // Re-initialize CMBManager
    static u8 black = 1;
    black ^= 1;
    gIsForSoullessActor = black;
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
            // f32 curFrame     = anime->curFrame;
            // f32 playSpeed    = anime->playSpeed;
            // f32 startFrame   = anime->startFrame;
            // f32 endFrame     = anime->endFrame;
            // f32 animMode     = anime->animMode;
            SkelAnime_Destroy(anime);
            // EnTite_Init(((EnTite*)actor), gGlobalContext);
            // SkelAnime_Init(actor, gGlobalContext, anime, 0, 0, &GET_STRUCT_FIELD(actor, void*, 0x228),
            //                &GET_STRUCT_FIELD(actor, void*, 0x430), 10);
            // Animation_ChangeImpl(anime, animIndex, playSpeed, startFrame, endFrame, animMode, 0.0, 0);
            Animation_ChangeImpl(anime, animIndex, 1.0, 1.0, 1.0, 0, 4.0, 0);
            GET_STRUCT_FIELD(actor, u32, 0x63c) = 0x284724;
            // anime->curFrame = curFrame;

            // CitraPrint("((EnTite*)actor)->skelAnime.cmbMan = %X", ((EnTite*)actor)->skelAnime.cmbMan);
        }
    }
    // CmbManager_Log(zarInfo->cmbMans[0]);
}
