#ifndef _OCARINA_NOTES_H_
#define _OCARINA_NOTES_H_

#include "z3D/z3D.h"

typedef enum OcarinaNoteButton {
    OCARINA_BUTTON_L,
    OCARINA_BUTTON_R,
    OCARINA_BUTTON_X,
    OCARINA_BUTTON_Y,
    OCARINA_BUTTON_A,
} OcarinaNoteButton;

s32 OcarinaNotes_IsButtonOwned(OcarinaNoteButton button);
void OcarinaNotes_RegisterButtonOwned(OcarinaNoteButton button);

#endif //_OCARINA_NOTES_H_
