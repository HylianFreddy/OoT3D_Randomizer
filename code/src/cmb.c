#include "z3D/z3D.h"
#include "actor.h"
#include "settings.h"

void CmbManager_BeforeInit(CmbManager* cmbMan) {
    if (!gIsForSoullessActor || gSettingsContext.soullessEnemiesLook != SOULLESSLOOK_BLACK) {
        return;
    }

    void* cmb = cmbMan->cmbChunk;

    CMB_MATS* cmbMats = (CMB_MATS*)(((u32)cmb) + ((CMB_HEAD*)cmb)->MATSOffset);
    for (size_t i = 0; i < cmbMats->materialCount; i++) {
        Material* mat           = &cmbMats->materials[i];
        mat->textureMappersUsed = 0; // good for black

        // All transparent
        mat->alphaTestEnabled = 0x0; // good for black
        mat->blendMode        = 0x0; // good for black
    }
}
