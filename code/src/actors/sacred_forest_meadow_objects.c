#include "z3D/z3D.h"
#include "sacred_forest_meadow_objects.h"
#include "settings.h"
#include "common.h"

// Used for Enemy Randomizer to track when the gate should open
static Actor* sWolfosEnemy;

void BgSpot05Soko_rInit(Actor* thisx, GlobalContext* play) {
    BgSpot05Soko_Init(thisx, play);

    BgSpot05Soko* this = (BgSpot05Soko*)thisx;
    if (thisx->params == 0x0001) { // gate
        Actor* enemy = play->actorCtx.actorList[ACTORTYPE_ENEMY].first;
        while (enemy != NULL) {
            if (enemy->world.pos.z > 1600.0) {
                sWolfosEnemy = enemy;
                break;
            }
            enemy = enemy->next;
        }

        if (Flags_GetSwitch(play, this->switchFlag) && sWolfosEnemy != NULL) {
            Actor_Kill(sWolfosEnemy);
        }
    }
}

void BgSpot05Soko_rUpdate(Actor* thisx, GlobalContext* play) {
    BgSpot05Soko_Update(thisx, play);

    BgSpot05Soko* this = (BgSpot05Soko*)thisx;
    if (gSettingsContext.enemizer == ON && thisx->params == 0x0001 && sWolfosEnemy != NULL &&
        sWolfosEnemy->update == NULL && sWolfosEnemy->draw == NULL) {
        Flags_SetSwitch(play, this->switchFlag);
    }
}

void BgSpot05Soko_rDestroy(Actor* thisx, GlobalContext* play) {
    BgSpot05Soko_Destroy(thisx, play);

    if (thisx->params == 0x0001) {
        sWolfosEnemy = NULL;
    }
}
