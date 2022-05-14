#include "menus.h"
#include "z3D/z3D.h"
#include "input.h"
#include "savefile.h"
#include "settings.h"
#include "shops.h"

#define gItemsMenuSpritesManager (*(MenuSpriteManager**)0x506734)
#define gBowMenuSpritesManager (*(MenuSpriteManager**)0x506738)
#define gItemsMenuGlowSpritesManager (*(MenuSpriteManager**)0x50673C)
#define gMenuSpritesManager_506740 (*(MenuSpriteManager**)0x506740)
#define gDungeonMapMenuSpritesManager (*(MenuSpriteManager**)0x506CD0)
#define gGearMenuSpritesManager (*(MenuSpriteManager**)0x50447C)

#define gItemsMenuSelectedSlot (*(s32*)0x506748)

typedef void (*MenuSpritesManager_RegisterItemSprite_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 itemId);
#define MenuSpritesManager_RegisterItemSprite ((MenuSpritesManager_RegisterItemSprite_proc)0x2F8D74)

typedef void (*MenuSpritesManager_SetSpriteAt_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 x, s32 y, s32 width, s32 height);
#define MenuSpritesManager_SetSpriteAt ((MenuSpritesManager_SetSpriteAt_proc)0x2F8D40)

typedef void (*MenuSpritesManager_OffsetSpriteAt_proc)(MenuSpriteManager* menuMan, s32 spriteId, s32 x, s32 y, s32 width, s32 height, s32 xOffset, s32 yOffset);
#define MenuSpritesManager_OffsetSpriteAt ((MenuSpritesManager_OffsetSpriteAt_proc)0x2EB3D8)

void ItemsMenu_Draw(void) {
    s32 selectedItemSlot;
    if (gItemsMenuSelectedSlot != -1) {
        if (gSaveContext.linkAge == 0) {
            selectedItemSlot = gSaveContext.itemMenuAdult[gItemsMenuSelectedSlot];
        } else {
            selectedItemSlot = gSaveContext.itemMenuChild[gItemsMenuSelectedSlot];
        }

        //if (rInputCtx.pressed.strt)
        //    MenuSpritesManager_RegisterItemSprite(gBowMenuSpritesManager, 0, gSaveContext.items[selectedItemSlot]);

        if (selectedItemSlot == SLOT_TRADE_ADULT) {
            u8 startingItem = gSaveContext.items[selectedItemSlot];
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
                MenuSpritesManager_RegisterItemSprite(gItemsMenuSpritesManager, gItemsMenuSelectedSlot, gSaveContext.items[selectedItemSlot]);
                MenuSpritesManager_RegisterItemSprite(gItemsMenuGlowSpritesManager, 0, gSaveContext.items[selectedItemSlot]);
            }
        }

        if (selectedItemSlot == SLOT_TRADE_CHILD && gSaveContext.items[selectedItemSlot] >= ITEM_MASK_KEATON) {
            u8 startingItem = gSaveContext.items[selectedItemSlot];
            u8 potentialItem = startingItem;

            if (rInputCtx.pressed.l) {
                potentialItem = startingItem - 1;
                while ((potentialItem != startingItem) && !SaveFile_IsMaskAvailable(potentialItem)) {
                    potentialItem--;
                    if (potentialItem < ITEM_MASK_KEATON) {
                        potentialItem = ITEM_MASK_TRUTH;
                    }
                }
            } else if (rInputCtx.pressed.r) {
                potentialItem = startingItem + 1;
                while ((potentialItem != startingItem) && !SaveFile_IsMaskAvailable(potentialItem)) {
                    potentialItem++;
                    if (potentialItem > ITEM_MASK_TRUTH) {
                        potentialItem = ITEM_MASK_KEATON;
                    }
                }
            }

            if (rInputCtx.pressed.strt) {gSaveContext.items[selectedItemSlot] = ITEM_LETTER_ZELDA;}

            if (potentialItem != startingItem) {
                gSaveContext.items[selectedItemSlot] = potentialItem;
                MenuSpritesManager_RegisterItemSprite(gItemsMenuSpritesManager, gItemsMenuSelectedSlot, gSaveContext.items[selectedItemSlot]);
                MenuSpritesManager_RegisterItemSprite(gItemsMenuGlowSpritesManager, 0, gSaveContext.items[selectedItemSlot]);

                if (gGlobalContext->sceneNum == 51) { // Happy Mask Shop, redraw items on shelves
                    for (Actor* actor = gGlobalContext->actorCtx.actorList[6].first; actor != 0; actor = actor->next) {
                        if (actor->id != 4) { // En_GirlA, shop item
                            continue;
                        }
                        EnGirlA_InitializeItemAction((EnGirlA*)actor, gGlobalContext);
                    }
                }
            }
        }
    }
}

u16 SaveMenu_IgnoreOpen(void) {
    return (gSettingsContext.menuOpeningButton == 0 && rInputCtx.cur.sel) || (gSettingsContext.menuOpeningButton == 1 && rInputCtx.cur.strt);
}
