#ifndef _Z3DCMB_H_
#define _Z3DCMB_H_

#include "s_types.h"

typedef struct CMB_HEAD {
    /* 0x00 */ char magic[4];
    /* 0x04 */ u32 filesize;
    /* 0x08 */ u32 version;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ char name[16];
    /* 0x20 */ u32 indicesCount;
    /* 0x24 */ s32 SKLOffset;
    /* 0x28 */ s32 MATSOffset;
    /* 0x2C */ s32 TEXOffset;
    /* 0x30 */ s32 SKLMOffset;
    /* 0x34 */ s32 LUTSOffset;
    /* 0x38 */ s32 VATROffset;
    /* 0x3C */ u32 indicesOffset;
    /* 0x40 */ u32 textureDataOffset;
} CMB_HEAD;

typedef struct TextureEntry {
    /* 0x00 */ u32 dataLength;
    /* 0x04 */ u16 mipMapCount;
    /* 0x06 */ u8 isETC1;
    /* 0x07 */ u8 isCubeMap;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ union {
        u32 textureFormatGL;
        struct {
            u16 imageFormat;
            u16 dataType;
        };
    };
    /* 0x10 */ u32 dataOffset;
    /* 0x14 */ char name[16];
} TextureEntry;

typedef struct TextureMappers {
    char unk_00[0x18];
} TextureMappers;

typedef struct TextureCoords {
    char unk_00[0x18];
} TextureCoords;

typedef struct Fragment {
    char unk_00[0x3C];
} Fragment;

typedef struct Material {
    u8 isFragmentLightingEnabled;
    u8 isVertexLightingEnabled;
    u8 isHemiSphereLightingEnabled;
    u8 isHemiSphereOcclusionEnabled;
    u8 culling;
    u8 isPolygonOffsetEnabled;
    s16 polygonOffsetValue;
    u32 textureMappersUsed;
    u32 textureCoordsUsed;
    TextureMappers textureMapper[3];
    TextureCoords textureCoord[3];
    Vec4b emissionColor;
    Vec4b ambientColor;
    Vec4b diffuse;
    Vec4b specular0;
    Vec4b specular1;
    Vec4b constant0;
    Vec4b constant1;
    Vec4b constant2;
    Vec4b constant3;
    Vec4b constant4;
    Vec4b constant5;
    Vec4i bufferColor;
    u16 bumpTexture;
    u16 bumpMode;
    u8 isBumpRenormalize;
    Fragment fragLighting;
    u32 texEnvStageUsed;
    s16 texEnvStagesIndices[6];
    u8 alphaTestEnabled;
    u8 alphaTestReferenceValue;
    u16 alphaTestFunction;
    u8 depthTestEnabled;
    u8 depthWriteEnabled;
    u16 depthTestFunction;
    u32 blendMode;
    u16 alphaSrcFunc;
    u16 alphaDstFunc;
    u32 alphaEquation;
    u16 colorSrcFunc;
    u16 colorDstFunc;
    u32 colorEquation;
    Vec4i BlendColor;
} Material;

typedef struct Combiner {
    char unk_00[0x28];
} Combiner;

typedef struct CMB_MATS {
    /* 0x00 */ char magic[4];
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 materialCount;
    /* 0x10 */ Material materials[];
    //         Combiner combiners[];
} CMB_MATS;

typedef struct CMB_TEX {
    /* 0x00 */ char magic[4];
    /* 0x04 */ u32 size;
    /* 0x08 */ u32 textureCount;
    /* 0x10 */ TextureEntry entries[];
} CMB_TEX;

enum TextureFormatGL {
    ETC1     = 0x0000675A,
    ETC1A4   = 0x0000675B,
    RGB8     = 0x14016754,
    RGBA8    = 0x14016752,
    RGBA4444 = 0x80336752,
    RGBA5551 = 0x80346752,
    RGB565   = 0x83636754,
    A8       = 0x14016756, // black
    A4       = 0x67616756, // black
    L8       = 0x14016757,
    L4       = 0x67616757,
    LA8      = 0x14016758,
    LA4      = 0x67606758,
    HILO8    = 0x14016759,
};

typedef struct CmbManager {
    /* 0x00 */ void* cmbChunk;
    /* 0x04 */ u32 field_0x4;
    /* 0x08 */ u32 field_0x8;
    /* 0x0C */ u32 field_0xC;
    /* 0x10 */ u32 field_0x10;
    /* 0x14 */ u32 field_0x14;
    /* 0x18 */ u32 field_0x18;
    /* 0x1C */ u32 field_0x1C;
    /* 0x20 */ u32 field_0x20;
    /* 0x24 */ u32 field_0x24;
    /* 0x28 */ u32 field_0x28;
    /* 0x2C */ u32 field_0x2C;
    /* 0x30 */ u32 field_0x30;
    /* 0x34 */ u32 field_0x34;
    /* 0x38 */ u32 field_0x38;
    /* 0x3C */ u32 cmbChunkSize;
    /* 0x40 */ u32 field_0x40;
    /* 0x44 */ u32 field_0x44;
} CmbManager;

#endif //_Z3DCMB_H_
