#ifndef _Z3DENVIRONMENT_H_
#define _Z3DENVIRONMENT_H_

#include "z3Dvec.h"

#define LIGHT_SETTING_OVERRIDE_NONE 0xFF
#define LIGHT_SETTING_OVERRIDE_FULL_CONTROL 0xFE

typedef struct EnvLightSettings {
    f32 unk_00;
    f32 zFar;
    s16 blendRateAndFogNear;
    u8 ambientColor[3];
    s8 light1Dir[3];
    u8 light1Color[3];
    s8 light2Dir[3];
    u8 light2Color[3];
    u8 fogColor[3];
} EnvLightSettings;
_Static_assert(sizeof(EnvLightSettings) == 0x1C, "EnvLightSettings size");

typedef struct CurrentEnvLightSettings {
    /* 0x00 */ u8 ambientColor[3];
    /* 0x03 */ s8 light1Dir[3];
    /* 0x06 */ u8 light1Color[3];
    /* 0x09 */ s8 light2Dir[3];
    /* 0x0C */ u8 light2Color[3];
    /* 0x0F */ u8 fogColor[3];
} CurrentEnvLightSettings;
_Static_assert(sizeof(CurrentEnvLightSettings) == 0x12, "CurrentEnvLightSettings size");

typedef struct EnvironmentContext {
    /* 0x00 */ char unk_00[0x9C];
    /* 0x9C */ u8 numLightSettings;
    /* 0xA0 */ EnvLightSettings* lightSettingsList;
    /* 0xA4 */ u8 lightBlendEnabled;
    /* 0xA5 */ u8 lightSetting;
    /* 0xA6 */ u8 prevLightSetting;
    /* 0xA7 */ u8 lightSettingOverride;
    /* 0xA8 */ f32 unk_A8; // may be related to 3D effect
    /* 0xAC */ f32 zFar;
    /* 0xB0 */ s16 fogNear;
    /* 0xB2 */ CurrentEnvLightSettings lightSettings;
    /* 0xF3 */ char unk_F3[0x38];
} EnvironmentContext; // size = 0xFC
_Static_assert(sizeof(EnvironmentContext) == 0xFC, "EnvironmentContext size");

#endif //_Z3DENVIRONMENT_H_
