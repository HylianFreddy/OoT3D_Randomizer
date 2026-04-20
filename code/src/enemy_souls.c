#include "enemy_souls.h"
#include "savefile.h"
#include "settings.h"
#include "armos.h"
#include "actor.h"
#include "common.h"
#include "flying_traps.h"

// clang-format off
EnemySoulId EnemySouls_GetSoulId(s16 actorId) {
    switch (actorId) {
        case 0x00D: return SOUL_POE; // Small Poe
        case 0x175: return SOUL_POE; // Big Poe
        case 0x091: return SOUL_POE; // Poe Sisters
        case 0x00E: return SOUL_OCTOROK; // Octorok
        case 0x0C6: return SOUL_OCTOROK; // Big Octo
        case 0x013: return SOUL_KEESE;
        case 0x01B: return SOUL_TEKTITE;
        case 0x01C: return SOUL_LEEVER;
        case 0x01D: return SOUL_PEAHAT;
        case 0x025: return SOUL_LIZALFOS;
        case 0x02D: return SOUL_SHABOM;
        case 0x034: return SOUL_BIRI_BARI; // Biri
        case 0x063: return SOUL_BIRI_BARI; // Bari
        case 0x035: return SOUL_TAILPASARAN;
        case 0x037: return SOUL_SKULLTULA; // Normal
        case 0x095: return SOUL_SKULLTULA; // Walltula/Gold
        case 0x038: return SOUL_TORCH_SLUG;
        case 0x03A: return SOUL_STINGER; // Land
        case 0x18C: return SOUL_STINGER; // Water
        case 0x04B: return SOUL_MOBLIN;
        case 0x054: return SOUL_ARMOS;
        case 0x055: return SOUL_DEKU_BABA; // Normal
        case 0x0C7: return SOUL_DEKU_BABA; // Withered
        case 0x069: return SOUL_BUBBLE;
        case 0x11D: return SOUL_FLYING_TRAP; // Flying Pot
        case 0x06B: return SOUL_FLYING_TRAP; // Flying Tile
        case 0x08A: return SOUL_BEAMOS;
        case 0x011: return SOUL_WALLMASTER; // Wallmaster
        case 0x08E: return SOUL_WALLMASTER; // Floormaster
        case 0x090: return SOUL_REDEAD_GIBDO;
        case 0x0C5: return SOUL_SHELL_BLADE;
        case 0x0DD: return SOUL_LIKE_LIKE;
        case 0x0DE: return SOUL_TENTACLE;
        case 0x0E0: return SOUL_ANUBIS;
        case 0x0EC: return SOUL_SPIKE;
        case 0x115: return SOUL_SKULL_KID;
        case 0x121: return SOUL_FREEZARD;
        case 0x192: return SOUL_DEKU_SCRUB; // Normal (green)
        case 0x060: return SOUL_DEKU_SCRUB; // Mad (red)
        case 0x195: return SOUL_DEKU_SCRUB; // Business
        case 0x1AF: return SOUL_WOLFOS;
        case 0x1B0: return SOUL_STALCHILD;
        case 0x1C0: return SOUL_GUAY;
        case 0x1C1: return SOUL_DOOR_MIMIC;
        case 0x002: return SOUL_STALFOS;
        case 0x033: return SOUL_DARK_LINK;
        case 0x099: return SOUL_FLARE_DANCER; // Normal
        case 0x0AB: return SOUL_FLARE_DANCER; // Core
        case 0x0A4: return SOUL_DEAD_HAND; // Body
        case 0x0A5: return SOUL_DEAD_HAND; // Hands
        case 0x186: return SOUL_GERUDO; // Purple Gerudo guards
        case 0x197: return SOUL_GERUDO; // Gerudo fighters
        case 0x113: return SOUL_GERUDO; // Iron Knuckles
        case 0x028: return SOUL_GOHMA; // Queen Gohma
        case 0x02B: return SOUL_GOHMA; // Gohma Larva/Egg
        case 0x012: return SOUL_DODONGO; // Dodongo
        case 0x02F: return SOUL_DODONGO; // Baby Dodongo
        case 0x027: return SOUL_DODONGO; // King Dodongo
        case 0x0BA: return SOUL_BARINADE;
        case 0x052: return SOUL_PHANTOM_GANON; // PG
        case 0x067: return SOUL_PHANTOM_GANON; // Horse
        case 0x096: return SOUL_VOLVAGIA; // Flying
        case 0x0A2: return SOUL_VOLVAGIA; // Hole
        case 0x0C4: return SOUL_MORPHA;
        case 0x0E9: return SOUL_BONGO_BONGO;
        case 0x0DC: return SOUL_TWINROVA;
        case 0x0E8: return SOUL_GANON; // Ganondorf
        case 0x17A: return SOUL_GANON; // Ganon
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

void EnemySouls_SetSoulFlag(EnemySoulId soulId) {
    if (soulId == SOUL_NONE) {
        return;
    }
    gExtSaveData.extInf.enemySouls[(soulId >> 3)] |= (1 << (soulId & 0b111));
}

u8 EnemySouls_CheckSoulForActor(Actor* actor) {
    if ((gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_OFF) ||
        (gSettingsContext.shuffleEnemySouls == SHUFFLEENEMYSOULS_BOSSES && !Actor_IsBoss(actor)) ||
        (actor->id == 0x054 && ((EnAm*)actor)->textureBlend == 0 /* Armos, statue or asleep */)) {
        return TRUE;
    }

    EnemySoulId soulId = EnemySouls_GetSoulId(actor->id);
    return soulId == SOUL_NONE || EnemySouls_GetSoulFlag(soulId);
}

u8 EnemySouls_ShouldDrawSoulless(Actor* actor) {
    return !EnemySouls_CheckSoulForActor(actor) && // soul not owned;
           actor->scale.x != 0 &&                  // if scale is 0, enemy is invisible;
           !FlyingTraps_IsHiddenTrap(actor);       // hidden flying traps will appear normal.
}

#define SOULLESS_EFFECT_DURATION 8
#define SOULLESS_EFFECT_INTERVAL 3

static void SoullessEffect_Draw(Vec3f pos, f32 xRange, f32 yRange, f32 zRange, s16 scale) {
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

static void SoullessEffect_ParseCollider(Collider* collider) {
    if (collider == NULL || collider->actor == NULL) {
        return;
    }

    if (collider->actor->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME && EnemySouls_ShouldDrawSoulless(collider->actor)) {
        u8 isBoss = collider->actor->type == ACTORTYPE_BOSS;
        switch (collider->shape) {
            case COLSHAPE_JNTSPH:
                ColliderJntSph* jntSphCol = (ColliderJntSph*)collider;
                for (s32 j = 0; j < jntSphCol->count; j++) {
                    ColliderJntSphElement* elem = &jntSphCol->elements[j];
                    Spheref worldSphere         = elem->dim.worldSphere;
                    s16 scale                   = isBoss ? 150 : worldSphere.radius > 10.0f ? 100 : 50;
                    SoullessEffect_Draw(worldSphere.center, worldSphere.radius, worldSphere.radius, worldSphere.radius,
                                        scale);
                }
                break;
            case COLSHAPE_CYLINDER:
                ColliderCylinder* cylCol = (ColliderCylinder*)collider;
                s16 scale                = isBoss ? 150 : cylCol->dim.radius > 10.0f ? 100 : 50;
                SoullessEffect_Draw(cylCol->dim.position, cylCol->dim.radius, cylCol->dim.height, cylCol->dim.radius,
                                    scale);
                break;
        }
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
        SoullessEffect_ParseCollider(collider);
    }

    // Parse all colliders subscribed to OC
    for (s32 i = 0; i < gGlobalContext->colChkCtx.colOcCount; i++) {
        Collider* collider = gGlobalContext->colChkCtx.colOc[i];
        SoullessEffect_ParseCollider(collider);
    }
}
