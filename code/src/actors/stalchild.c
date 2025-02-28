#include "z3d/z3D.h"
#include "settings.h"

s32 Stalchild_CanDespawn(Actor* stalchild) {
    return gSettingsContext.enemizer == OFF || stalchild->parent != NULL;
}
