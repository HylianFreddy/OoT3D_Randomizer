#ifndef _ENEMYSOULS_H_
#define _ENEMYSOULS_H_

#include "z3D/z3D.h"

typedef enum EnemySoulId {
    SOUL_NONE,
    SOUL_POE,
    SOUL_OCTOROK,
    SOUL_WALLMASTER,
    SOUL_KEESE,
    SOUL_TEKTITE,
    SOUL_LEEVER,
    SOUL_PEAHAT,
    SOUL_LIZALFOS,
    SOUL_SHABOM,
    SOUL_BIRI_BARI,
    SOUL_TAILPASARAN,
    SOUL_SKULLTULA,
    SOUL_TORCH_SLUG,
    SOUL_STINGER,
    SOUL_MOBLIN,
    SOUL_ARMOS,
    SOUL_DEKU_BABA,
    SOUL_BUBBLE,
    SOUL_FLYING_POT,        // remove?
    SOUL_FLYING_TILE, // remove?
    SOUL_BEAMOS,
    SOUL_FLOORMASTER,
    SOUL_REDEAD_GIBDO,
    SOUL_SHELL_BLADE,
    SOUL_LIKE_LIKE,
    SOUL_TENTACLE, // merge with barinade?
    SOUL_ANUBIS,
    SOUL_SPIKE,
    SOUL_SKULL_KID, // not a monster?
    SOUL_FREEZARD,
    SOUL_DEKU_SCRUB,
    SOUL_WOLFOS,
    SOUL_STALCHILD,
    SOUL_GUAY,
    SOUL_DOOR_MIMIC,
    SOUL_STALFOS,
    SOUL_DARK_LINK,
    SOUL_FLARE_DANCER,
    SOUL_DEAD_HAND,
    SOUL_GERUDO,
    SOUL_GOHMA,
    SOUL_DODONGO,
    SOUL_BARINADE,
    SOUL_PHANTOM_GANON,
    SOUL_VOLVAGIA,
    SOUL_MORPHA,
    SOUL_BONGO_BONGO,
    SOUL_TWINROVA,
    SOUL_GANON,
} EnemySoulId;

u16  EnemySouls_GetSoulFlag(EnemySoulId soulId);
void EnemySouls_SetSoulFlag(EnemySoulId soulId);
u8   EnemySouls_CheckSoulForActor(Actor* actor);

extern u8 EnemySouls_DebugToggle;

#endif //_ENEMYSOULS_H_
