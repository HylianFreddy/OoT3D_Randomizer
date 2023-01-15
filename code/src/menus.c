#include "menus.h"
#include "z3D/z3D.h"
#include "input.h"
#include "savefile.h"
#include "settings.h"

#define gItemsMenuSpritesManager (*(MenuSpriteManager**)0x506734)
#define gBowMenuSpritesManager (*(MenuSpriteManager**)0x506738)
#define gItemsMenuGlowSpritesManager (*(MenuSpriteManager**)0x50673C)
#define gMenuSpritesManager_506740 (*(MenuSpriteManager**)0x506740)
#define gDungeonMapMenuSpritesManager (*(MenuSpriteManager**)0x506CD0)
#define gGearMenuSpritesManager (*(MenuSpriteManager**)0x50447C)

#define gItemsMenuSelectedSlot (*(s32*)0x506748)
#define gGearMenuSelectedSlot (*(s32*)0x50448C) // stores cursor position for the Gear menu
#define gGearMenuCurrentSlot (*(s32*)0x50448C) // slot that is currently shown on screen; reset to -1 when closing menu or switching tabs

typedef void (*MenuSpritesManager_RegisterItemSprite_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 itemId);
#define MenuSpritesManager_RegisterItemSprite ((MenuSpritesManager_RegisterItemSprite_proc)0x2F8D74)

typedef void (*MenuSpritesManager_SetSpriteAt_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 x, s32 y, s32 width,
                                                    s32 height);
#define MenuSpritesManager_SetSpriteAt ((MenuSpritesManager_SetSpriteAt_proc)0x2F8D40)

typedef void (*MenuSpritesManager_OffsetSpriteAt_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 x, s32 y,
                                                       s32 width, s32 height, s32 xOffset, s32 yOffset);
#define MenuSpritesManager_OffsetSpriteAt ((MenuSpritesManager_OffsetSpriteAt_proc)0x2EB3D8)

void ItemsMenu_Draw(void) {
    s32 selectedItemSlot;
    if (gItemsMenuSelectedSlot != -1) {
        if (gSaveContext.linkAge == 0) {
            selectedItemSlot = gSaveContext.itemMenuAdult[gItemsMenuSelectedSlot];
        } else {
            selectedItemSlot = gSaveContext.itemMenuChild[gItemsMenuSelectedSlot];
        }

        if (selectedItemSlot == SLOT_TRADE_ADULT) {
            u8 startingItem  = gSaveContext.items[selectedItemSlot];
            u8 potentialItem = startingItem;

            if (rInputCtx.pressed.l) {
                potentialItem = startingItem - 1;
                while ((potentialItem != startingItem) && !SaveFile_TradeItemIsOwned(potentialItem)) {
                    potentialItem--;
                    if (potentialItem < ITEM_POCKET_EGG) {
                        potentialItem = ITEM_CLAIM_CHECK;
                    }
                }
            } else if (rInputCtx.pressed.r) {
                potentialItem = startingItem + 1;
                while ((potentialItem != startingItem) && !SaveFile_TradeItemIsOwned(potentialItem)) {
                    potentialItem++;
                    if (potentialItem > ITEM_CLAIM_CHECK) {
                        potentialItem = ITEM_POCKET_EGG;
                    }
                }
            }

            if (potentialItem != startingItem) {
                gSaveContext.items[selectedItemSlot] = potentialItem;
                MenuSpritesManager_RegisterItemSprite(gItemsMenuSpritesManager, gItemsMenuSelectedSlot,
                                                      gSaveContext.items[selectedItemSlot]);
                MenuSpritesManager_RegisterItemSprite(gItemsMenuGlowSpritesManager, 0,
                                                      gSaveContext.items[selectedItemSlot]);
            }
        }
    }
}

static u16 ownedSongs = 0;
u16 GearMenu_GetInventoryHint(void) {
    if (gGearMenuSelectedSlot == GEARSLOT_OCARINA) {
        ownedSongs =
            (gSaveContext.questItems & 0b111111000000) | ((gSaveContext.questItems >> 12) & 0b111111); // 0xFC0 0x3F
        return 0x86F;
    }
    ownedSongs = 0;

    if (gGearMenuSelectedSlot >= GEARSLOT_KOKIRI_EMERALD && gGearMenuSelectedSlot <= GEARSLOT_ZORA_SAPPHIRE &&
        gExtSaveData.extInf[EXTINF_TOTALTAR_FLAGS] & (1 << AGE_CHILD)) {
        return 0x7300 + gGearMenuSelectedSlot - GEARSLOT_KOKIRI_EMERALD;
    }
    if (gGearMenuSelectedSlot >= GEARSLOT_FOREST_MEDALLION && gGearMenuSelectedSlot <= GEARSLOT_LIGHT_MEDALLION &&
        gExtSaveData.extInf[EXTINF_TOTALTAR_FLAGS] & (1 << AGE_ADULT)) {
        return 0x7303 + gGearMenuSelectedSlot - GEARSLOT_FOREST_MEDALLION;
    }
    return 0;
}

void GearMenu_PrintSongs(void) {
    //gGearMenuSelectedSlot = GEARSLOT_BIGGORON_SWORD;
    return;


    static s32 currentSong = 0;
    if (gGearMenuCurrentSlot != GEARSLOT_OCARINA || ownedSongs == 0) {
        currentSong = 0;
        return;
    }

    //if (ownedSongs & 1 == 1 || !rInputCtx.pressed.a) {} // what???



    for (s32 i = 0; i < 12; i++) {
        currentSong = (currentSong + 1) % 12;
        if (((ownedSongs >> currentSong) & 1) == 1) {
            ContinueTextbox(gGlobalContext, 0x9AD + currentSong);
        }

        u8 shift = (currentSong + i) % 12;
        if (((ownedSongs >> shift) & 1) == 1) {
            currentSong = 0;
            //return 0x9AD + currentSong;
        }
    }
}

u16 SaveMenu_IgnoreOpen(void) {
    return (gSettingsContext.menuOpeningButton == 0 && rInputCtx.cur.sel) ||
           (gSettingsContext.menuOpeningButton == 1 && rInputCtx.cur.strt);
}
