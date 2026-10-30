#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Shops() {
    /*-------------------------------
              --- SHOPS ---
      8     6               2     4

      7     5               1     3
      -------------------------------*/

    Base(KF_SHOP_ITEM_1, SCENE_KOKIRI_SHOP, 0x30, //
        "KF Shop Item 1", BUY_DEKU_SHIELD, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 0), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_2, SCENE_KOKIRI_SHOP, 0x31, //
        "KF Shop Item 2", BUY_DEKU_NUT_5, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 1), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_3, SCENE_KOKIRI_SHOP, 0x32, //
        "KF Shop Item 3", BUY_DEKU_NUT_10, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 2), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_4, SCENE_KOKIRI_SHOP, 0x33, //
        "KF Shop Item 4", BUY_DEKU_STICK_1, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 3), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_5, SCENE_KOKIRI_SHOP, 0x34, //
        "KF Shop Item 5", BUY_DEKU_SEEDS_30, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 4), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_6, SCENE_KOKIRI_SHOP, 0x35, //
        "KF Shop Item 6", BUY_ARROWS_10, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 5), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_7, SCENE_KOKIRI_SHOP, 0x36, //
        "KF Shop Item 7", BUY_ARROWS_30, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 6), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);
    Base(KF_SHOP_ITEM_8, SCENE_KOKIRI_SHOP, 0x37, //
        "KF Shop Item 8", BUY_HEART, //
        { Category::cKokiriForest, Category::cForest, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2D, 7), SpoilerCollectionCheckGroup::GROUP_KOKIRI_FOREST);

    Base(KAK_POTION_SHOP_ITEM_1, SCENE_POTION_SHOP_KAKARIKO, 0x30, //
        "Kak Potion Shop Item 1", BUY_DEKU_NUT_5, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 0), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_2, SCENE_POTION_SHOP_KAKARIKO, 0x31, //
        "Kak Potion Shop Item 2", BUY_FISH, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 1), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_3, SCENE_POTION_SHOP_KAKARIKO, 0x32, //
        "Kak Potion Shop Item 3", BUY_RED_POTION_30, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 2), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_4, SCENE_POTION_SHOP_KAKARIKO, 0x33, //
        "Kak Potion Shop Item 4", BUY_GREEN_POTION, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 3), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_5, SCENE_POTION_SHOP_KAKARIKO, 0x34, //
        "Kak Potion Shop Item 5", BUY_BLUE_FIRE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 4), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_6, SCENE_POTION_SHOP_KAKARIKO, 0x35, //
        "Kak Potion Shop Item 6", BUY_BOTTLE_BUG, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 5), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_7, SCENE_POTION_SHOP_KAKARIKO, 0x36, //
        "Kak Potion Shop Item 7", BUY_POE, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 6), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_POTION_SHOP_ITEM_8, SCENE_POTION_SHOP_KAKARIKO, 0x37, //
        "Kak Potion Shop Item 8", BUY_FAIRYS_SPIRIT, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x30, 7), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    Base(MARKET_BOMBCHU_SHOP_ITEM_1, SCENE_BOMBCHU_SHOP, 0x30, //
        "MK Bombchu Shop Item 1", BUY_BOMBCHU_5, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 0), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_2, SCENE_BOMBCHU_SHOP, 0x31, //
        "MK Bombchu Shop Item 2", BUY_BOMBCHU_10, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 1), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_3, SCENE_BOMBCHU_SHOP, 0x32, //
        "MK Bombchu Shop Item 3", BUY_BOMBCHU_10, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 2), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_4, SCENE_BOMBCHU_SHOP, 0x33, //
        "MK Bombchu Shop Item 4", BUY_BOMBCHU_10, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 3), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_5, SCENE_BOMBCHU_SHOP, 0x34, //
        "MK Bombchu Shop Item 5", BUY_BOMBCHU_20, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 4), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_6, SCENE_BOMBCHU_SHOP, 0x35, //
        "MK Bombchu Shop Item 6", BUY_BOMBCHU_20, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 5), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_7, SCENE_BOMBCHU_SHOP, 0x36, //
        "MK Bombchu Shop Item 7", BUY_BOMBCHU_20, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 6), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BOMBCHU_SHOP_ITEM_8, SCENE_BOMBCHU_SHOP, 0x37, //
        "MK Bombchu Shop Item 8", BUY_BOMBCHU_20, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x32, 7), SpoilerCollectionCheckGroup::GROUP_MARKET);

    Base(MARKET_POTION_SHOP_ITEM_1, SCENE_POTION_SHOP_MARKET, 0x30, //
        "MK Potion Shop Item 1", BUY_GREEN_POTION, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 0), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_2, SCENE_POTION_SHOP_MARKET, 0x31, //
        "MK Potion Shop Item 2", BUY_BLUE_FIRE, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 1), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_3, SCENE_POTION_SHOP_MARKET, 0x32, //
        "MK Potion Shop Item 3", BUY_RED_POTION_30, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 2), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_4, SCENE_POTION_SHOP_MARKET, 0x33, //
        "MK Potion Shop Item 4", BUY_FAIRYS_SPIRIT, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 3), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_5, SCENE_POTION_SHOP_MARKET, 0x34, //
        "MK Potion Shop Item 5", BUY_DEKU_NUT_5, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 4), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_6, SCENE_POTION_SHOP_MARKET, 0x35, //
        "MK Potion Shop Item 6", BUY_BOTTLE_BUG, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 5), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_7, SCENE_POTION_SHOP_MARKET, 0x36, //
        "MK Potion Shop Item 7", BUY_POE, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 6), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_POTION_SHOP_ITEM_8, SCENE_POTION_SHOP_MARKET, 0x37, //
        "MK Potion Shop Item 8", BUY_FISH, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x31, 7), SpoilerCollectionCheckGroup::GROUP_MARKET);

    Base(MARKET_BAZAAR_ITEM_1, SCENE_BAZAAR, 0x30, //
        "MK Bazaar Item 1", BUY_HYLIAN_SHIELD, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 0), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_2, SCENE_BAZAAR, 0x31, //
        "MK Bazaar Item 2", BUY_BOMBS_535, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 1), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_3, SCENE_BAZAAR, 0x32, //
        "MK Bazaar Item 3", BUY_DEKU_NUT_5, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 2), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_4, SCENE_BAZAAR, 0x33, //
        "MK Bazaar Item 4", BUY_HEART, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 3), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_5, SCENE_BAZAAR, 0x34, //
        "MK Bazaar Item 5", BUY_ARROWS_10, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 4), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_6, SCENE_BAZAAR, 0x35, //
        "MK Bazaar Item 6", BUY_ARROWS_50, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 5), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_7, SCENE_BAZAAR, 0x36, //
        "MK Bazaar Item 7", BUY_DEKU_STICK_1, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 6), SpoilerCollectionCheckGroup::GROUP_MARKET);
    Base(MARKET_BAZAAR_ITEM_8, SCENE_BAZAAR, 0x37, //
        "MK Bazaar Item 8", BUY_ARROWS_30, //
        { Category::cInnerMarket, Category::cMarket, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2C, 7), SpoilerCollectionCheckGroup::GROUP_MARKET);

    Base(KAK_BAZAAR_ITEM_1, SCENE_BAZAAR, 0x38, //
        "Kak Bazaar Item 1", BUY_HYLIAN_SHIELD, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 0), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_2, SCENE_BAZAAR, 0x39, //
        "Kak Bazaar Item 2", BUY_BOMBS_535, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 1), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_3, SCENE_BAZAAR, 0x3A, //
        "Kak Bazaar Item 3", BUY_DEKU_NUT_5, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 2), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_4, SCENE_BAZAAR, 0x3B, //
        "Kak Bazaar Item 4", BUY_HEART, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 3), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_5, SCENE_BAZAAR, 0x3C, //
        "Kak Bazaar Item 5", BUY_ARROWS_10, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 4), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_6, SCENE_BAZAAR, 0x3D, //
        "Kak Bazaar Item 6", BUY_ARROWS_50, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 5), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_7, SCENE_BAZAAR, 0x3E, //
        "Kak Bazaar Item 7", BUY_DEKU_STICK_1, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 6), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);
    Base(KAK_BAZAAR_ITEM_8, SCENE_BAZAAR, 0x3F, //
        "Kak Bazaar Item 8", BUY_ARROWS_30, //
        { Category::cKakarikoVillage, Category::cKakariko, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x33, 7), SpoilerCollectionCheckGroup::GROUP_KAKARIKO);

    Base(ZD_SHOP_ITEM_1, SCENE_ZORA_SHOP, 0x30, //
        "ZD Shop Item 1", BUY_ZORA_TUNIC, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 0), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_2, SCENE_ZORA_SHOP, 0x31, //
        "ZD Shop Item 2", BUY_ARROWS_10, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 1), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_3, SCENE_ZORA_SHOP, 0x32, //
        "ZD Shop Item 3", BUY_HEART, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 2), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_4, SCENE_ZORA_SHOP, 0x33, //
        "ZD Shop Item 4", BUY_ARROWS_30, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 3), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_5, SCENE_ZORA_SHOP, 0x34, //
        "ZD Shop Item 5", BUY_DEKU_NUT_5, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 4), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_6, SCENE_ZORA_SHOP, 0x35, //
        "ZD Shop Item 6", BUY_ARROWS_50, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 5), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_7, SCENE_ZORA_SHOP, 0x36, //
        "ZD Shop Item 7", BUY_FISH, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 6), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);
    Base(ZD_SHOP_ITEM_8, SCENE_ZORA_SHOP, 0x37, //
        "ZD Shop Item 8", BUY_RED_POTION_50, //
        { Category::cZorasDomain, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2F, 7), SpoilerCollectionCheckGroup::GROUP_ZORAS_DOMAIN);

    Base(GC_SHOP_ITEM_1, SCENE_GORON_SHOP, 0x30, //
        "GC Shop Item 1", BUY_BOMBS_525, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 0), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_2, SCENE_GORON_SHOP, 0x31, //
        "GC Shop Item 2", BUY_BOMBS_10, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 1), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_3, SCENE_GORON_SHOP, 0x32, //
        "GC Shop Item 3", BUY_BOMBS_20, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 2), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_4, SCENE_GORON_SHOP, 0x33, //
        "GC Shop Item 4", BUY_BOMBS_30, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 3), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_5, SCENE_GORON_SHOP, 0x34, //
        "GC Shop Item 5", BUY_GORON_TUNIC, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 4), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_6, SCENE_GORON_SHOP, 0x35, //
        "GC Shop Item 6", BUY_HEART, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 5), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_7, SCENE_GORON_SHOP, 0x36, //
        "GC Shop Item 7", BUY_RED_POTION_40, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 6), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
    Base(GC_SHOP_ITEM_8, SCENE_GORON_SHOP, 0x37, //
        "GC Shop Item 8", BUY_HEART, //
        { Category::cGoronCity, Category::cShop }, //
        SpoilerCollectionCheck::ShopItem(0x2E, 7), SpoilerCollectionCheckGroup::GROUP_GORON_CITY);
}
