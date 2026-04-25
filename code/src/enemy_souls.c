#include "z3D/z3Dcmb.h"
#include "enemy_souls.h"
#include "savefile.h"
#include "settings.h"
#include "armos.h"
#include "actor.h"
#include "common.h"
#include "flying_traps.h"
#include "objects.h"
#include "shabom.h"

// Variadic arguments are pairs of a model and a CMB index; last argument must always be NULL.
struct ZARInfo* Actor_CreateSkelModels(Actor* actor, struct GlobalContext* globalCtx,
                                       SkeletonAnimationModel** firstSAModel, u32 firstCmbIndex, ...);
// Variadic arguments are models; last argument must always be NULL.
struct ZARInfo* Actor_DestroySkelModels(Actor* actor, SkeletonAnimationModel** firstSAModel, ...);
struct ZARInfo* Actor_CreateSkelModelsArray(Actor* actor, struct GlobalContext* globalCtx, s32 modelCount,
                                            SkeletonAnimationModel** models, s32* cmbIndices);
struct ZARInfo* Actor_DestroySkelModelsArray(Actor* actor, s32 modelCount, SkeletonAnimationModel** models,
                                             s32* cmbIndices);

static void SoullessDarkness_RestoreSoul(EnemySoulId soulId);

// clang-format off
EnemySoulId EnemySouls_GetSoulId(s16 actorId) {
    switch (actorId) {
        case ACTOR_POE:                    return SOUL_POE;
        case ACTOR_BIG_POE:                return SOUL_POE;
        case ACTOR_POE_SISTER:             return SOUL_POE;
        case ACTOR_OCTOROK:                return SOUL_OCTOROK;
        case ACTOR_BIG_OCTO:               return SOUL_OCTOROK;
        case ACTOR_KEESE:                  return SOUL_KEESE;
        case ACTOR_TEKTITE:                return SOUL_TEKTITE;
        case ACTOR_LEEVER:                 return SOUL_LEEVER;
        case ACTOR_PEAHAT:                 return SOUL_PEAHAT;
        case ACTOR_LIZALFOS:               return SOUL_LIZALFOS;
        case ACTOR_SHABOM:                 return SOUL_SHABOM;
        case ACTOR_BIRI:                   return SOUL_BIRI_BARI;
        case ACTOR_BARI:                   return SOUL_BIRI_BARI;
        case ACTOR_TAILPASARAN:            return SOUL_TAILPASARAN;
        case ACTOR_SKULLTULA:              return SOUL_SKULLTULA;
        case ACTOR_SKULLWALLTULA:          return SOUL_SKULLTULA;
        case ACTOR_TORCH_SLUG:             return SOUL_TORCH_SLUG;
        case ACTOR_STINGER_FLOOR:          return SOUL_STINGER;
        case ACTOR_STINGER_WATER:          return SOUL_STINGER;
        case ACTOR_MOBLIN:                 return SOUL_MOBLIN;
        case ACTOR_ARMOS:                  return SOUL_ARMOS;
        case ACTOR_DEKU_BABA:              return SOUL_DEKU_BABA;
        case ACTOR_WITHERED_DEKU_BABA:     return SOUL_DEKU_BABA;
        case ACTOR_BUBBLE:                 return SOUL_BUBBLE;
        case ACTOR_FLYING_POT:             return SOUL_FLYING_TRAP;
        case ACTOR_FLYING_FLOOR_TILE:      return SOUL_FLYING_TRAP;
        case ACTOR_BEAMOS:                 return SOUL_BEAMOS;
        case ACTOR_WALLMASTER:             return SOUL_WALLMASTER;
        case ACTOR_FLOORMASTER:            return SOUL_WALLMASTER;
        case ACTOR_REDEAD:                 return SOUL_REDEAD_GIBDO;
        case ACTOR_SHELL_BLADE:            return SOUL_SHELL_BLADE;
        case ACTOR_LIKE_LIKE:              return SOUL_LIKE_LIKE;
        case ACTOR_PARASITIC_TENTACLE:     return SOUL_TENTACLE;
        case ACTOR_ANUBIS:                 return SOUL_ANUBIS;
        case ACTOR_SPIKE:                  return SOUL_SPIKE;
        case ACTOR_SKULL_KID:              return SOUL_SKULL_KID;
        case ACTOR_FREEZARD:               return SOUL_FREEZARD;
        case ACTOR_HINT_DEKU_SCRUB:        return SOUL_DEKU_SCRUB;
        case ACTOR_MAD_SCRUB:              return SOUL_DEKU_SCRUB;
        case ACTOR_BUSINESS_SCRUB:         return SOUL_DEKU_SCRUB;
        case ACTOR_WOLFOS:                 return SOUL_WOLFOS;
        case ACTOR_STALCHILD:              return SOUL_STALCHILD;
        case ACTOR_GUAY:                   return SOUL_GUAY;
        case ACTOR_DOOR_MIMIC:             return SOUL_DOOR_MIMIC;
        case ACTOR_STALFOS:                return SOUL_STALFOS;
        case ACTOR_DARK_LINK:              return SOUL_DARK_LINK;
        case ACTOR_FLARE_DANCER:           return SOUL_FLARE_DANCER;
        case ACTOR_FLARE_DANCER_CORE:      return SOUL_FLARE_DANCER;
        case ACTOR_DEAD_HAND:              return SOUL_DEAD_HAND;
        case ACTOR_DEAD_HAND_HAND:         return SOUL_DEAD_HAND;
        case ACTOR_GERUDO_GUARD:           return SOUL_GERUDO;
        case ACTOR_GERUDO_FIGHTER:         return SOUL_GERUDO;
        case ACTOR_IRON_KNUCKLE:           return SOUL_GERUDO;
        case ACTOR_GOHMA:                  return SOUL_GOHMA;
        case ACTOR_GOHMA_LARVA:            return SOUL_GOHMA;
        case ACTOR_DODONGO:                return SOUL_DODONGO;
        case ACTOR_BABY_DODONGO:           return SOUL_DODONGO;
        case ACTOR_KING_DODONGO:           return SOUL_DODONGO;
        case ACTOR_BARINADE:               return SOUL_BARINADE;
        case ACTOR_PHANTOM_GANON:          return SOUL_PHANTOM_GANON;
        case ACTOR_PG_HORSE:               return SOUL_PHANTOM_GANON;
        case ACTOR_VOLVAGIA_FLYING:        return SOUL_VOLVAGIA;
        case ACTOR_VOLVAGIA_HOLE:          return SOUL_VOLVAGIA;
        case ACTOR_MORPHA:                 return SOUL_MORPHA;
        case ACTOR_BONGO_BONGO:            return SOUL_BONGO_BONGO;
        case ACTOR_TWINROVA:               return SOUL_TWINROVA;
        case ACTOR_GANONDORF:              return SOUL_GANON;
        case ACTOR_GANON:                  return SOUL_GANON;
    }

    return SOUL_NONE;
}
// clang-format on

u8 EnemySouls_GetSoulFlag(EnemySoulId soulId) {
    if (soulId == SOUL_NONE) {
        return 1;
    }
    return gExtSaveData.extInf.enemySouls[(soulId >> 3)] & (1 << (soulId & 0b111));
}

static void EnemySouls_SetSoulFlag(EnemySoulId soulId) {
    if (soulId == SOUL_NONE) {
        return;
    }
    gExtSaveData.extInf.enemySouls[(soulId >> 3)] |= (1 << (soulId & 0b111));
}

u8 EnemySouls_CheckSoulForActor(Actor* actor) {
    if ((gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_OFF) ||
        (gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_BOSSES && !Actor_IsBoss(actor)) ||
        // Armos statues and asleep Armos enemies, included so it can be hit and woken up even while soulless
        (actor->id == ACTOR_ARMOS && ((EnAm*)actor)->textureBlend == 0) ||
        // Hidden flying traps will appear normal; in this state they already ignore collider hits
        FlyingTraps_IsHiddenTrap(actor)) {
        return TRUE;
    }

    EnemySoulId soulId = EnemySouls_GetSoulId(actor->id);
    return soulId == SOUL_NONE || EnemySouls_GetSoulFlag(soulId);
}

void EnemySouls_OnCollect(EnemySoulId soulId) {
    if (EnemySouls_GetSoulFlag(soulId)) {
        return;
    }

    EnemySouls_SetSoulFlag(soulId);

    if (gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
        SoullessDarkness_RestoreSoul(soulId);
    }
}

/*-------------------------------
|    Soulless Flames effect     |
-------------------------------*/

#define SOULLESS_EFFECT_DURATION 8
#define SOULLESS_EFFECT_INTERVAL 3

static void SoullessFlames_Draw(Vec3f pos, f32 xRange, f32 yRange, f32 zRange, s16 scale) {
    pos.x += xRange * (Rand_ZeroOne() - 0.5);
    pos.y += yRange * (Rand_ZeroOne() - 0.5) + scale / 10;
    pos.z += zRange * (Rand_ZeroOne() - 0.5);
    Vec3f nullVec         = { 0 };
    Color_RGBA8 primColor = {
        .r = 0x6E,
        .g = 0x05,
        .b = 0xFF,
        .a = 0xFF,
    };
    Color_RGBA8 envColor = {
        .r = 0x28,
        .g = 0x00,
        .b = 0xFF,
        .a = 0xFF,
    };
    EffectSsDeadDb_Spawn(gGlobalContext, &pos, &nullVec, &nullVec, scale, -1, primColor.r, primColor.g, primColor.b,
                         primColor.a, envColor.r, envColor.g, envColor.b, 1, SOULLESS_EFFECT_DURATION, 0);
}

static void SoullessFlames_ParseCollider(Collider* collider) {
    if (collider == NULL || collider->actor == NULL || !(collider->actor->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) ||
        (collider->actor->scale.x == 0 && collider->actor->scale.y == 0 && collider->actor->scale.z == 0) ||
        EnemySouls_CheckSoulForActor(collider->actor)) {
        return;
    }

    u8 isBoss = collider->actor->type == ACTORTYPE_BOSS;
    switch (collider->shape) {
        case COLSHAPE_JNTSPH:
            ColliderJntSph* jntSphCol = (ColliderJntSph*)collider;
            for (s32 j = 0; j < jntSphCol->count; j++) {
                ColliderJntSphElement* elem = &jntSphCol->elements[j];
                Spheref worldSphere         = elem->dim.worldSphere;
                s16 scale                   = isBoss ? 150 : worldSphere.radius > 10.0f ? 100 : 50;
                SoullessFlames_Draw(worldSphere.center, worldSphere.radius, worldSphere.radius, worldSphere.radius,
                                    scale);
            }
            break;
        case COLSHAPE_CYLINDER:
            ColliderCylinder* cylCol = (ColliderCylinder*)collider;
            s16 scale                = isBoss ? 150 : cylCol->dim.radius > 10.0f ? 100 : 50;
            SoullessFlames_Draw(cylCol->dim.position, cylCol->dim.radius, cylCol->dim.height, cylCol->dim.radius,
                                scale);
            break;
    }
}

void EnemySouls_DrawEffects(void) {
    if ((gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_PURPLE_FLAMES || PauseContext_GetState() != 0) ||
        rGameplayFrames % SOULLESS_EFFECT_INTERVAL != 0) {
        return;
    }

    // Parse all colliders subscribed to AC
    for (s32 i = 0; i < gGlobalContext->colChkCtx.colAcCount; i++) {
        Collider* collider = gGlobalContext->colChkCtx.colAc[i];
        SoullessFlames_ParseCollider(collider);
    }

    // Parse all colliders subscribed to OC
    for (s32 i = 0; i < gGlobalContext->colChkCtx.colOcCount; i++) {
        Collider* collider = gGlobalContext->colChkCtx.colOc[i];
        SoullessFlames_ParseCollider(collider);
    }
}

/*-------------------------------
|   Soulless Darkness effect    |
-------------------------------*/

typedef struct CmbOriginalData {
    char status;
    struct {
        u8 textureMappersUsed : 5;
        u8 alphaTestEnabled : 1; // boolean
        u8 blendMode : 2;        // values 0-3
    } mats[15];
} CmbOriginalData;
_Static_assert(sizeof(CmbOriginalData) == sizeof(((CMB_HEAD*)0)->name), "CmbOriginalData size");

#define CMBSTATUS_MODIFIED '-'
#define CMBSTATUS_RESTORED '^'

// Use CMB name field as a buffer to store original values for overwritten data
static CmbOriginalData* Cmb_GetOrigDataBuffer(CmbManager* cmbMan) {
    return (CmbOriginalData*)&((CMB_HEAD*)cmbMan->cmbChunk)->name;
}

void EnemySouls_BeforeSkelAnimeInit(CmbManager* cmbMan, Actor* actor) {
    CitraPrint("BeforeSkelAnimeInit %X", actor->id);
    // return;
    // if (!EnemySouls_CheckSoulForActor(actor) && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
    //     CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
    //     if (origDataBuf->status != CMBSTATUS_MODIFIED) {
    //         origDataBuf->status = CMBSTATUS_MODIFIED;
    //         CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    //         for (s32 i = 0; i < cmbMats->materialCount; i++) {
    //             Material* mat                           = &cmbMats->materials[i];
    //             origDataBuf->mats[i].textureMappersUsed = mat->textureMappersUsed;
    //             origDataBuf->mats[i].alphaTestEnabled   = mat->alphaTestEnabled;
    //             origDataBuf->mats[i].blendMode          = mat->blendMode;
    //             mat->textureMappersUsed                 = 0;
    //             mat->alphaTestEnabled                   = 0;
    //             mat->blendMode                          = 0;
    //         }
    //     }
    // }
}
void EnemySouls_BeforeCmbManagerInit(CmbManager* cmbMan) {
    if (gIsForSoullessActor && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
        CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
        if (origDataBuf->status != CMBSTATUS_MODIFIED) {
            origDataBuf->status = CMBSTATUS_MODIFIED;
            CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
            CitraPrint("BeforeCmbManagerInit %X", cmbMats->materialCount);
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

void EnemySouls_BeforeSkelModelCtor(CmbManager* cmbMan) {
    // if (gIsForSoullessActor && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_BLACK) {
    //     CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
    //     if (origDataBuf->status != CMBSTATUS_MODIFIED) {
    //         origDataBuf->status = CMBSTATUS_MODIFIED;
    //         CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
    //         for (s32 i = 0; i < cmbMats->materialCount; i++) {
    //             CitraPrint("BeforeSkelModelCtor %X", i);
    //             Material* mat                           = &cmbMats->materials[i];
    //             origDataBuf->mats[i].textureMappersUsed = mat->textureMappersUsed;
    //             origDataBuf->mats[i].alphaTestEnabled   = mat->alphaTestEnabled;
    //             origDataBuf->mats[i].blendMode          = mat->blendMode;
    //             mat->textureMappersUsed                 = 0;
    //             mat->alphaTestEnabled                   = 0;
    //             mat->blendMode                          = 0;
    //         }
    //     }
    // }
}

#define ZAR_SetupZARInfo ((void (*)(ZARInfo * zarInfo, void* buf, s32 size, s8 param_4))0x31B124)
#define SkelAnime_Destroy ((void (*)(SkelAnime * anime))0x350be0)
// limbCount param is ignored, the function takes the value from the cmb
#define SkelAnime_Init                                                                                       \
    ((void (*)(Actor * actor, GlobalContext * globalCtx, SkelAnime * skelAnime, s32 cmbIndex, s32 csabIndex, \
               void* jointTable, void* morphTable, s32 limbCount))0x353c9c)
typedef void (*Foo)(SkelAnime* anime, s32 animation_index, f32 play_speed, f32 start_frame, f32 end_frame, s32 mode,
                    f32 morph_frames, s32 taper) __attribute__((pcs("aapcs-vfp")));
#define Animation_ChangeImpl ((Foo)0x35302c)

static void SoullessDarkness_RestoreObject(u16 objectId) {
    if (objectId == OBJECT_INVALID) {
        return;
    }
    s32 slot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (slot < 0 || !Object_IsLoaded(&gGlobalContext->objectCtx, slot)) {
        return;
    }

    ObjectEntry* obj = Object_GetEntry(slot);
    ZARInfo* zarInfo = &obj->zarInfo;

    // Restore original values for each CMB that was modified.
    s32 numCMBs = zarInfo->fileTypes[zarInfo->fileTypeMap[0]].numFiles;
    for (s32 i = 0; i < numCMBs; i++) {
        CmbManager* cmbMan = zarInfo->cmbMans[i];
        if (cmbMan == NULL) {
            continue;
        }
        CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
        if (origDataBuf->status == CMBSTATUS_MODIFIED) {
            origDataBuf->status = CMBSTATUS_RESTORED;
            CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
            for (s32 i = 0; i < cmbMats->materialCount; i++) {
                Material* mat           = &cmbMats->materials[i];
                mat->textureMappersUsed = origDataBuf->mats[i].textureMappersUsed;
                mat->alphaTestEnabled   = origDataBuf->mats[i].alphaTestEnabled;
                mat->blendMode          = origDataBuf->mats[i].blendMode;
            }
        }
    }

    // Reinitialize ZarInfo, keeping same buffer and size. This destroys all CmbManagers.
    ZAR_Destroy(zarInfo);
    ZAR_SetupZARInfo(zarInfo, obj->buf, obj->size, 0);
}

static void SoullessDarkness_ReinitSkelAnime(SkelAnime* anime, Actor* actor) {
    // Find which cmbIndex this SkelAnime uses
    s32 numCMBs  = anime->zarInfo->fileTypes[anime->zarInfo->fileTypeMap[0]].numFiles;
    s32 cmbIndex = 0;
    for (s32 i = 0; i < numCMBs; i++) {
        if (anime->zarInfo->cmbMans[i] == anime->cmbMan) {
            cmbIndex = i;
            break;
        }
    }

    // Temporarily store animation values
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

    // Reinitialize SkelAnime and reload the same animation at the same frame.
    SkelAnime_Destroy(anime);
    SkelAnime_Init(actor, gGlobalContext, anime, cmbIndex, animIndex, jointTable, morphTable, 0);
    Animation_ChangeImpl(anime, animIndex, playSpeed, startFrame, endFrame, animMode, 0.0, 0);
    anime->curFrame = curFrame;
}

typedef struct GenericSkelAnimeActor {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime skelAnime;
} GenericSkelAnimeActor;

#include "z3D/actors/z_actors_tmp.h"
/*
#define REINIT_SKELANIME(anime) SoullessDarkness_ReinitSkelAnime(anime, actor)
#define REINIT_1_MODEL(model1, index1)            \
    Actor_DestroySkelModels(actor, model1, NULL); \
    Actor_CreateSkelModels(actor, gGlobalContext, model1, index1, NULL)
#define REINIT_2_MODELS(model1, index1, model2, index2)   \
    Actor_DestroySkelModels(actor, model1, model2, NULL); \
    Actor_CreateSkelModels(actor, gGlobalContext, model1, index1, model2, index2, NULL)
*/

static void SoullessDarkness_RestoreActor(Actor* actor) {
    switch (actor->id) {
        case ACTOR_POE: // doesnt fade in
            EnPoh* this = (EnPoh*)actor;
            Actor_DestroySkelModels(actor, &this->saModel_1, &this->saModel_2, NULL);
            u32 cmb1Index    = this->infoIdx == 0 ? 1 : this->composerLanternCmbIndex;
            u32 cmb2Index    = this->infoIdx == 0 ? 2 : 1;
            ZARInfo* zarInfo = Actor_CreateSkelModels(actor, gGlobalContext, &this->saModel_1, cmb1Index,
                                                      &this->saModel_2, cmb2Index, NULL);
            void* cmabMan    = ZAR_GetCMABByIndex(zarInfo, 0);
            TexAnim_Spawn(this->saModel_2->matAnim, cmabMan);
            this->saModel_2->matAnim->animMode  = 1;
            this->saModel_2->matAnim->animSpeed = 2.0;
            this->saModel_94C                  = this->saModel_1;
            this->saModel_950                  = this->saModel_2;

            SoullessDarkness_ReinitSkelAnime(&this->anime, actor);
            break;
        case ACTOR_BIG_POE: // doesnt fade in
        case ACTOR_POE_SISTER:
        case ACTOR_OCTOROK: // OK
        case ACTOR_BIG_OCTO:
        case ACTOR_TEKTITE:  // cmab
        case ACTOR_LEEVER:   // OK
        case ACTOR_PEAHAT:   // larva has colored tip
        case ACTOR_LIZALFOS: // OK
        case ACTOR_BIRI:
        case ACTOR_BARI:
        case ACTOR_SKULLTULA:
        case ACTOR_SKULLWALLTULA:
        case ACTOR_TORCH_SLUG:
        case ACTOR_STINGER_FLOOR:
        case ACTOR_STINGER_WATER:
        case ACTOR_ARMOS:
        case ACTOR_WITHERED_DEKU_BABA:
        case ACTOR_BUBBLE:
        case ACTOR_BEAMOS:
        case ACTOR_WALLMASTER:
        case ACTOR_FLOORMASTER:
        case ACTOR_SHELL_BLADE:
        case ACTOR_PARASITIC_TENTACLE:
        case ACTOR_ANUBIS:
        case ACTOR_SKULL_KID:
        case ACTOR_HINT_DEKU_SCRUB:
        case ACTOR_MAD_SCRUB:
        case ACTOR_BUSINESS_SCRUB:
        case ACTOR_STALCHILD:
        case ACTOR_DOOR_MIMIC:
        case ACTOR_FLARE_DANCER:
        case ACTOR_FLARE_DANCER_CORE:
        case ACTOR_DEAD_HAND:
        case ACTOR_DEAD_HAND_HAND:
        case ACTOR_IRON_KNUCKLE:
        case ACTOR_GOHMA:
        case ACTOR_GOHMA_LARVA:
        case ACTOR_DODONGO:
        case ACTOR_BABY_DODONGO:
        case ACTOR_KING_DODONGO:
        case ACTOR_BARINADE:
        case ACTOR_PHANTOM_GANON:
        case ACTOR_VOLVAGIA_FLYING: // missing arms
        case ACTOR_VOLVAGIA_HOLE:
        case ACTOR_BONGO_BONGO:
        case ACTOR_GANON:
            SoullessDarkness_ReinitSkelAnime(&((GenericSkelAnimeActor*)actor)->skelAnime, actor);
            break;
        case ACTOR_KEESE:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1C8), actor);
            break;
            // return &((EnFirefly*)actor)->skelAnime;
        case ACTOR_TAILPASARAN:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1B0), actor);
            break;
            // return &((EnTp*)actor)->skelAnime;
        case ACTOR_MOBLIN:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1E4), actor);
            break;
        case ACTOR_DEKU_BABA:
        case ACTOR_GUAY:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1D4), actor);
            break;
        case ACTOR_REDEAD:
        case ACTOR_WOLFOS:
        case ACTOR_STALFOS:
        case ACTOR_GERUDO_FIGHTER:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1E0), actor);
            break;
        case ACTOR_LIKE_LIKE:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x2438), actor);
            break;
        case ACTOR_DARK_LINK:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x254), actor);
            break;
        case ACTOR_GERUDO_GUARD:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1FC), actor);
            break;
        case ACTOR_PG_HORSE:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x26C), actor);
            break;
        case ACTOR_MORPHA:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x16E0), actor);
            break;
        case ACTOR_TWINROVA:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x5C0), actor);
            break;
        case ACTOR_GANONDORF:
            SoullessDarkness_ReinitSkelAnime((SkelAnime*)(((u32)actor) + 0x1A8), actor);
            break;

        case ACTOR_SHABOM:
            Actor_DestroySkelModels(actor, &((EnBubble*)actor)->saModel, NULL);
            Actor_CreateSkelModels(actor, gGlobalContext, &((EnBubble*)actor)->saModel, 0, NULL);
            break;
        case ACTOR_FLYING_POT:
        case ACTOR_FLYING_FLOOR_TILE:
        case ACTOR_SPIKE:
        case ACTOR_FREEZARD:
            break;
    }
}

static void SoullessDarkness_RestoreSoul(EnemySoulId soulId) {
    if (soulId == SOUL_POE) {
        SoullessDarkness_RestoreObject(OBJECT_POE);
        SoullessDarkness_RestoreObject(OBJECT_POE_COMPOSER);
    } else {
        for (s32 i = 0; i < ACTOR_MAX; i++) {
            ActorInit* profile = gActorOverlayTable[i].initInfo;
            if (profile != NULL && EnemySouls_GetSoulId(profile->id) == soulId) {
                SoullessDarkness_RestoreObject(profile->objectId);
            }
        }
    }

    static ActorType sActorCats[] = { ACTORTYPE_ENEMY, ACTORTYPE_BOSS };
    for (s32 i = 0; i < ARRAY_SIZE(sActorCats); i++) {
        Actor* actor = gGlobalContext->actorCtx.actorList[sActorCats[i]].first;
        while (actor != NULL) {
            if (EnemySouls_GetSoulId(actor->id) == soulId) {
                SoullessDarkness_RestoreActor(actor);
            }
            actor = actor->next;
        }
    }
}
