#include "gossip_stone.h"
#include "z3D/z3D.h"
#include "settings.h"

#define EnGs_Init_addr 0x16461C
#define EnGs_Init ((ActorFunc)EnGs_Init_addr)

#define NUM_GENERIC_GROTTOS 9

// content fields for generic grottos from the grottoLoadTable. Used to recognize
// if the gossip stone is in a glitched grotto.
static const u8 genericGrottosData[NUM_GENERIC_GROTTOS] = {
    0x00, 0x03, 0x14, 0x22, 0x28, 0x29, 0x2C, 0x57, 0x7A,
};

void EnGs_rInit(Actor* thisx, GlobalContext* globalCtx) {

    // if this is a generic grotto gossip stone then assign it a message ID
    // based off of the current respawn data. This allows these stones to all have
    // unique hints.
    if ((thisx->params & 0xFF) == 0x18) {
        u8 grotto = gSaveContext.respawn[RESPAWN_MODE_RETURN].data;
        u8 id = 0x3F; // default id for glitched grotto

        for (s32 i = 0; i < NUM_GENERIC_GROTTOS; i++) {
            if (genericGrottosData[i] == grotto) {
                id = (grotto & 0xF) + 0x30;
                break;
            }
        }

        thisx->params &= 0x00;
        thisx->params |= id;
    }

    EnGs_Init(thisx, globalCtx);
}

#define EnHintstone_Update_addr 0x281834
#define EnHintstone_Update ((ActorFunc)EnHintstone_Update_addr)

void EnHintstone_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    // Destroy the hintstones on Citra as they cause huge lag when entered
    if (gSettingsContext.playOption == PLAY_ON_CITRA) {
        Actor_Kill(thisx);
        return;
    }
    EnHintstone_Update(thisx, globalCtx);
}
