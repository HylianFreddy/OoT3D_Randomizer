#include "peahat.h"
#include "settings.h"

#define EnPeehat_Update ((ActorFunc)GAME_ADDR(0x167644))

void EnPeehat_rUpdate(Actor* thisx, GlobalContext* globalCtx) {
    EnPeehat_Update(thisx, globalCtx);

    if (gSettingsContext.enemizer == ON && thisx->params == (s16)0xFFFF) { // Grounded Peahat
        f32 yWaterSurface;
        void* waterBox;
        s32 waterBoxFound = WaterBox_GetSurfaceImpl(gGlobalContext, &gGlobalContext->colCtx, thisx->world.pos.x,
                                                    thisx->world.pos.z, &yWaterSurface, &waterBox);

        // Make Peahats float on water so they can work as aquatic plants.
        if (waterBoxFound && thisx->world.pos.y < yWaterSurface) {
            thisx->world.pos.y = yWaterSurface;
        }
    }
}
