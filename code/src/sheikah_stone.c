#include "z3D/z3D.h"

void SheikahStone_Enter(void) {
        gGlobalContext->nextEntranceIndex = 0x003F;
        gGlobalContext->sceneLoadFlag = 0x14;
        gGlobalContext->fadeOutTransition = 5; // TO DO: use the black one instead
        gSaveContext.respawn[RESPAWN_MODE_RETURN].data = 0x5E; // gold rupee chest, inaccessible chest flag
}
