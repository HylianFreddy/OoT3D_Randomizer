#include "enemy_souls.h"
#include "savefile.h"
#include "settings.h"
#include "armos.h"
#include "actor.h"
#include "common.h"
#include "flying_traps.h"
#include "objects.h"
#include "shabom.h"
#include "poe.h"
#include "octorok.h"
#include "peahat.h"
#include "tektite.h"
#include "lizalfos.h"
#include "biri.h"
#include "skulltula.h"
#include "torch_slug.h"
#include "stinger.h"
#include "deku_baba.h"
#include "beamos.h"
#include "shabom.h"
#include "wallmaster.h"
#include "tentacle.h"
#include "skull_kid.h"
#include "deku_scrubs.h"
#include "business_scrubs.h"
#include "door.h"
#include "flare_dancer.h"
#include "dead_hand.h"
#include "dodongos.h"
#include "barinade.h"
#include "ganondorf.h"
#include "volvagia.h"
#include "bongo_bongo.h"
#include "tailpasaran.h"
#include "moblin.h"
#include "guay.h"
#include "wolfos.h"
#include "stalfos.h"
#include "gerudos.h"
#include "dark_link.h"
#include "spike.h"
#include "freezard.h"

#include "z3D/actors/z_en_firefly.h"
#include "z3D/actors/z_en_rd.h"
#include "z3D/actors/z_en_rr.h"

static void SoullessDarkness_RestoreSoul(EnemySoulId soulId);

// clang-format off
EnemySoulId EnemySouls_GetSoulId(s16 actorId) {
    switch (actorId) {
        case ACTOR_POE:                    return SOUL_POE;
        case ACTOR_FIELD_POE:              return SOUL_POE;
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
        case ACTOR_SLIMY_THING:            return SOUL_TENTACLE;
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

typedef enum SoulCheck {
    SOULCHECK_BASE,
    SOULCHECK_COLLISION,
    SOULCHECK_DRAW,
} SoulCheck;

static u8 EnemySouls_CheckSoul_Impl(Actor* actor, SoulCheck soulCheck) {
    if (actor == NULL || (gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_OFF) ||
        (gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_BOSSES && !Actor_IsBoss(actor))) {
        return TRUE;
    }

    if (soulCheck >= SOULCHECK_COLLISION &&
        // Armos statues and asleep Armos enemies, included so they can be hit and woken up even while soulless
        actor->id == ACTOR_ARMOS && ((EnAm*)actor)->textureBlend == 0) {
        return TRUE;
    }

    if (soulCheck >= SOULCHECK_DRAW &&
        // If enemy is culled, don't draw soulless effects
        (!(actor->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) ||
         // If scale is zero, enemy is invisible
         (actor->scale.x == 0 && actor->scale.y == 0 && actor->scale.z == 0) ||
         // Hidden flying traps will appear normal
         FlyingTraps_IsHiddenTrap(actor) ||
         // These will just look normal because the flames appear in the wrong place
         (actor->id == ACTOR_SLIMY_THING && gSettingsContext.soullessEnemiesLook == SOULLESSLOOK_PURPLE_FLAMES))) {
        return TRUE;
    }

    EnemySoulId soulId = EnemySouls_GetSoulId(actor->id);
    return soulId == SOUL_NONE || EnemySouls_GetSoulFlag(soulId);
}

u8 EnemySouls_CheckSoulForActor(Actor* actor) {
    return EnemySouls_CheckSoul_Impl(actor, SOULCHECK_COLLISION);
}

u8 EnemySouls_ShouldDrawSoulless(Actor* actor) {
    return !EnemySouls_CheckSoul_Impl(actor, SOULCHECK_DRAW);
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
    if (collider == NULL || !EnemySouls_ShouldDrawSoulless(collider->actor)) {
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
        u8 textureMappersUsed : 4;
        u8 alphaTestEnabled : 1;          // boolean
        u8 blendMode : 2;                 // values 0-3
        u8 isFragmentLightingEnabled : 1; // boolean
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
    CitraPrint("BeforeSkelAnimeInit actorID=%X", actor->id);
}

void SoullessDarkness_ModifyCmb(CmbManager* cmbMan, s32 newTexMapCount, s32 matToSkip) {
    CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
    if (origDataBuf->status != CMBSTATUS_MODIFIED) {
        origDataBuf->status = CMBSTATUS_MODIFIED;
        CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
        for (s32 matIdx = 0; matIdx < cmbMats->materialCount; matIdx++) {
            if (matIdx == matToSkip) {
                continue;
            }

            Material* mat                                       = &cmbMats->materials[matIdx];
            origDataBuf->mats[matIdx].textureMappersUsed        = mat->textureMappersUsed;
            origDataBuf->mats[matIdx].alphaTestEnabled          = mat->alphaTestEnabled;
            origDataBuf->mats[matIdx].blendMode                 = mat->blendMode;
            origDataBuf->mats[matIdx].isFragmentLightingEnabled = mat->isFragmentLightingEnabled;

            if (mat->textureMappersUsed > 15) {
                CitraPrint("!!!!!!!!!!!! textureMappersUsed > 15 !!!!!!!!!!!!!!!!");
            }

            mat->textureMappersUsed        = newTexMapCount;
            mat->alphaTestEnabled          = 0;
            mat->blendMode                 = 0;
            mat->isFragmentLightingEnabled = 0;
        }
    }
};

static s32 SoullessDarkness_GetMatToSkip(s16 objectId) {
    switch (objectId) {
        case OBJECT_ARMOS:
            return 0; // eyes
        case OBJECT_TENTACLE:
            return 1; // electric field (for both models)
    }
    return -1;
}

void EnemySouls_BeforeCmbManagerInit(CmbManager* cmbMan, ZARInfo* zarInfo, s32 cmbIdx) {
    if (gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK ||
        EnemySouls_CheckSoul_Impl(gRunningActor, SOULCHECK_BASE)) {
        return;
    }

    ObjectEntry* obj = Object_FindEntryByZarInfo(zarInfo);

    // Ignore CmbManagers from global "keep" objects, even if this actor is the first one to request them (thus causing
    // them to initialize).
    if (obj == NULL || obj->id <= OBJECT_GAMEPLAY_DUNGEON_KEEP) {
        return;
    }

    // Don't modify certain models
    if ((obj->id == OBJECT_WALLMASTER && cmbIdx == 2)      // hand shadow
        || (obj->id == OBJECT_TENTACLE && cmbIdx == 1)     // dead blob
        || (obj->id == OBJECT_DEAD_HAND && cmbIdx == 2)    // dirt wave
        || (obj->id == OBJECT_KING_DODONGO && cmbIdx != 2) // KD body
        || (obj->id == OBJECT_BARINADE && cmbIdx != 0 && cmbIdx != 3 && cmbIdx != 4 && cmbIdx != 7 &&
            cmbIdx != 12)                                  // arms, body and jellyfish
        || obj->id == OBJECT_FLYING_FLOOR_TILE             // handled in own update function
        || (obj->id == OBJECT_FREEZARD && cmbIdx == 1)     // ice breath
        || (obj->id == OBJECT_GANONDORF && cmbIdx != 2)    // main body
        || (obj->id == OBJECT_GANON && cmbIdx != 0)        // main body
        || (obj->id == OBJECT_POE && cmbIdx != 0)          // main body
        || (obj->id == OBJECT_POE_COMPOSER && cmbIdx != 0) // main body
    ) {
        return;
    }

    { // to delete
        CMB_MATS* cmbMats = Cmb_GetMatsChunk(cmbMan->cmbChunk);
        // poe sisters: 11 mats
        CitraPrint("BeforeCmbManagerInit objectId =%X cmbIdx=%X materialCount=%X", obj->id, cmbIdx,
                   cmbMats->materialCount);
    }

    // Don't modify certain materials
    s32 matToSkip      = SoullessDarkness_GetMatToSkip(obj->id);
    s32 newTexMapCount = 0;
    if (obj->id == OBJECT_ARMOS) {
        newTexMapCount = 1; // remove texture only for "awoken" state
    }

    SoullessDarkness_ModifyCmb(cmbMan, newTexMapCount, matToSkip);
}

void EnemySouls_BeforeSkelModelCtor(CmbManager* cmbMan) {
}

u8 SoullessDarkness_RestoreCmb(CmbManager* cmbMan, s32 matToSkip) {
    u8 materialRestored          = FALSE;
    CmbOriginalData* origDataBuf = Cmb_GetOrigDataBuffer(cmbMan);
    if (origDataBuf->status == CMBSTATUS_MODIFIED) {
        origDataBuf->status = CMBSTATUS_RESTORED;
        CMB_MATS* cmbMats   = Cmb_GetMatsChunk(cmbMan->cmbChunk);
        for (s32 matIdx = 0; matIdx < cmbMats->materialCount; matIdx++) {
            // Skip materials that weren't modified
            if (matIdx == matToSkip) {
                continue;
            }

            Material* mat                  = &cmbMats->materials[matIdx];
            mat->textureMappersUsed        = origDataBuf->mats[matIdx].textureMappersUsed;
            mat->alphaTestEnabled          = origDataBuf->mats[matIdx].alphaTestEnabled;
            mat->blendMode                 = origDataBuf->mats[matIdx].blendMode;
            mat->isFragmentLightingEnabled = origDataBuf->mats[matIdx].isFragmentLightingEnabled;
            materialRestored               = TRUE;
        }
    }
    return materialRestored;
}

static void SoullessDarkness_RestoreObject(u16 objectId) {
    s32 slot = Object_GetSlot(&gGlobalContext->objectCtx, objectId);
    if (slot < 0 || !Object_IsLoaded(&gGlobalContext->objectCtx, slot)) {
        return;
    }

    ObjectEntry* obj = Object_GetEntry(slot);
    ZARInfo* zarInfo = &obj->zarInfo;

    s32 numCMBs = zarInfo->fileTypes[zarInfo->fileTypeMap[0]].numFiles;
    for (s32 cmbIdx = 0; cmbIdx < numCMBs; cmbIdx++) {
        CmbManager* cmbMan = zarInfo->cmbMans[cmbIdx];
        if (cmbMan == NULL) {
            continue;
        }
        // Restore original values for each CMB that was modified.
        s32 matToSkip = SoullessDarkness_GetMatToSkip(objectId);
        u8 modified   = SoullessDarkness_RestoreCmb(cmbMan, matToSkip);
        if (modified) {
            // Destroy CMB Manager so it will be reinitialized the next time it's needed.
            CitraPrint("Restored CMB %X for object %X", cmbIdx, objectId);
            CmbManager_Destroy(cmbMan);
            gStaticClass_55A19C.sub44->vTable->destroyCmb(gStaticClass_55A19C.sub44, cmbMan);
            zarInfo->cmbMans[cmbIdx] = NULL;
        }
    }
}

typedef struct GenericSkelAnimeActor {
    /* 0x000 */ Actor actor;
    /* 0x1A4 */ SkelAnime anime;
} GenericSkelAnimeActor;

static void SoullessDarkness_RestoreActor(Actor* actor) {
    switch (actor->id) {
        case ACTOR_POE: // doesnt fade in
            return EnPoh_ReinitModels((EnPoh*)actor);
        case ACTOR_FIELD_POE: // doesnt fade in
            return EnPoField_ReinitModels((EnPoField*)actor);
        case ACTOR_POE_SISTER:
            return EnPoSisters_ReinitModels((EnPoSisters*)actor);
        case ACTOR_OCTOROK:
            return EnOkuta_ReinitModels((EnOkuta*)actor);
        case ACTOR_TEKTITE:
            return EnTite_ReinitModels((EnTite*)actor);
        case ACTOR_PEAHAT:
            return EnPeehat_ReinitModels((EnPeehat*)actor);
        case ACTOR_LIZALFOS:
            return EnZf_ReinitModels((EnZf*)actor);
        case ACTOR_BIRI:
            return EnBili_ReinitModels((EnBili*)actor);
        case ACTOR_BARI:
            return EnVali_ReinitModels((EnVali*)actor);
        case ACTOR_SKULLWALLTULA:
            return EnSw_ReinitModels((EnSw*)actor);
        case ACTOR_TORCH_SLUG:
            return EnBw_ReinitModels((EnBw*)actor);
        case ACTOR_STINGER_FLOOR:
            return EnEiyer_ReinitModels((EnEiyer*)actor);
        case ACTOR_ARMOS:
            return Actor_ReinitSkelAnime(actor, &((EnAm*)actor)->anime, 0);
        case ACTOR_DEKU_BABA:
            return EnDekubaba_ReinitModels((EnDekubaba*)actor);
        case ACTOR_WITHERED_DEKU_BABA:
            return EnKarebaba_ReinitModels((EnKarebaba*)actor);
        case ACTOR_BEAMOS:
            return EnVm_ReinitModels((EnVm*)actor);
        case ACTOR_WALLMASTER:
            return EnWallmas_ReinitModels((EnWallmas*)actor);
        case ACTOR_PARASITIC_TENTACLE:
            return EnBa_ReinitModels((EnBa*)actor);
        case ACTOR_SLIMY_THING:
            return EnBx_ReinitModels((EnBx*)actor);
        case ACTOR_SKULL_KID:
            return EnSkj_ReinitModels((EnSkj*)actor);
        case ACTOR_HINT_DEKU_SCRUB:
            return EnHintnuts_ReinitModels((EnHintnuts*)actor);
        case ACTOR_MAD_SCRUB:
            return EnDekunuts_ReinitModels((EnDekunuts*)actor);
        case ACTOR_BUSINESS_SCRUB:
            return EnShopnuts_ReinitModels((EnShopnuts*)actor);
        case ACTOR_DOOR_MIMIC:
            return DoorKiller_ReinitModels((DoorKiller*)actor);
        case ACTOR_FLARE_DANCER:
            return EnFd_ReinitModels((EnFd*)actor);
        case ACTOR_DEAD_HAND:
            return EnDh_ReinitModels((EnDh*)actor);
        case ACTOR_KING_DODONGO:
            return BossDodongo_ReinitModels((BossDodongo*)actor);
        case ACTOR_KEESE:
            return Actor_ReinitSkelAnime(actor, &((EnFirefly*)actor)->skelAnime, 0);
        case ACTOR_TAILPASARAN:
            return EnTp_ReinitModels((EnTp*)actor);
        case ACTOR_MOBLIN:
            return EnMb_ReinitModels((EnMb*)actor);
        case ACTOR_GUAY:
            return Actor_ReinitSkelAnime(actor, &((EnCrow*)actor)->skelAnime, 0);
        case ACTOR_REDEAD:
            return Actor_ReinitSkelAnime(actor, &((EnRd*)actor)->skelAnime, actor->params >= -1 ? 0 : 1);
        case ACTOR_WOLFOS:
            return EnWf_ReinitModels((EnWf*)actor);
        case ACTOR_STALFOS:
            return EnTest_ReinitModels((EnTest*)actor);
        case ACTOR_GERUDO_FIGHTER:
            return EnGeldB_ReinitModels((EnGeldB*)actor);
        case ACTOR_LIKE_LIKE:
            return Actor_ReinitSkelAnime(actor, &((EnRr*)actor)->skelAnime, 0);
        case ACTOR_DARK_LINK:
            return EnTorch2_ReinitModels((EnTorch2*)actor);
        case ACTOR_GERUDO_GUARD:
            return EnGe2_ReinitModels((EnGe2*)actor);
        case ACTOR_SHABOM:
            return EnBubble_ReinitModels((EnBubble*)actor);
        case ACTOR_SPIKE:
            return EnNy_ReinitModels((EnNy*)actor);
        case ACTOR_FREEZARD:
            return EnFz_ReinitModels((EnFz*)actor);
        case ACTOR_BIG_OCTO:
        case ACTOR_LEEVER:
        case ACTOR_SKULLTULA:
        case ACTOR_STINGER_WATER:
        case ACTOR_BUBBLE:
        case ACTOR_FLOORMASTER:
        case ACTOR_SHELL_BLADE:
        case ACTOR_ANUBIS:
        case ACTOR_STALCHILD:
        case ACTOR_DEAD_HAND_HAND:
        case ACTOR_IRON_KNUCKLE:
        case ACTOR_GOHMA:
        case ACTOR_GOHMA_LARVA:
        case ACTOR_BABY_DODONGO:
        case ACTOR_DODONGO:
            return Actor_ReinitSkelAnime(actor, &((GenericSkelAnimeActor*)actor)->anime, 0);

        case ACTOR_FLARE_DANCER_CORE:
            // This is ignored because it can't spawn if the player doesn't have the Flare Dancer Soul.

        case ACTOR_FLYING_POT:
        case ACTOR_FLYING_FLOOR_TILE:
            // These are handled in their own update function.

        case ACTOR_BARINADE:
            // return BossVa_ReinitModels((BossVa*)actor);
        case ACTOR_PHANTOM_GANON:
            // return BossGanondrof_ReinitModels((BossGanondrof*)actor);
        case ACTOR_PG_HORSE:
            // return EnFHG_ReinitModels((EnFHG*)actor);
        case ACTOR_VOLVAGIA_FLYING: // broken, transparent
                                    // return BossFd_ReinitModels((BossFd*)actor);
                                    // return Actor_Kill(actor); // TODO
        case ACTOR_VOLVAGIA_HOLE:
            // return Actor_Kill(actor); // TODO
        case ACTOR_MORPHA:
        case ACTOR_BONGO_BONGO: // hands become transparent?
                                // return BossSst_ReinitModels((BossSst*)actor);
        case ACTOR_TWINROVA:
        case ACTOR_GANONDORF:
        case ACTOR_GANON:
            // These are ignored because the player can't get items while they're loaded.
    }
}

static void SoullessDarkness_RestoreSoul(EnemySoulId soulId) {
    for (s32 i = 0; i < ACTOR_MAX; i++) {
        ActorInit* profile = gActorOverlayTable[i].initInfo;
        if (profile != NULL && EnemySouls_GetSoulId(profile->id) == soulId) {
            if (profile->id == ACTOR_POE) {
                SoullessDarkness_RestoreObject(OBJECT_POE);
                SoullessDarkness_RestoreObject(OBJECT_POE_COMPOSER);
            } else if (profile->objectId > OBJECT_GAMEPLAY_DUNGEON_KEEP) {
                SoullessDarkness_RestoreObject(profile->objectId);
            }
        }
    }

    for (s32 catIdx = 0; catIdx < ACTORTYPE_MAX; catIdx++) {
        Actor* actor = gGlobalContext->actorCtx.actorList[catIdx].first;
        while (actor != NULL) {
            if (EnemySouls_GetSoulId(actor->id) == soulId) {
                SoullessDarkness_RestoreActor(actor);
            }
            actor = actor->next;
        }
    }
}
