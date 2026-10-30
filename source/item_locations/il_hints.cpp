#include "item_location.hpp"

#include "s_scene_id.h"

void ItemLocation::InitTable_Hints() {
    // These are not actual locations, but are filler spots used for hint reachability. - OoT Randomizer
    // flag + 0x400 = message ID
    HintStone(DMC_GOSSIP_STONE, 0x05, "DMC Gossip Stone");
    HintStone(DMT_GOSSIP_STONE, 0x04, "DMT Gossip Stone");
    HintStone(COLOSSUS_GOSSIP_STONE, 0x1A, "Colossus Gossip Stone");
    HintStone(DODONGOS_CAVERN_GOSSIP_STONE, 0x14, "Dodongo's Cavern Gossip Stone");
    HintStone(GV_GOSSIP_STONE, 0x11, "GV Gossip Stone");
    HintStone(GC_MAZE_GOSSIP_STONE, 0x15, "GC Maze Gossip Stone");
    HintStone(GC_MEDIGORON_GOSSIP_STONE, 0x19, "GC Medigoron Gossip Stone");
    HintStone(GRAVEYARD_GOSSIP_STONE, 0x0A, "GY Gossip Stone");
    HintStone(HC_MALON_GOSSIP_STONE, 0x12, "HC Malon Gossip Stone");
    HintStone(HC_ROCK_WALL_GOSSIP_STONE, 0x0B, "HC Rock Wall Gossip Stone");
    HintStone(HC_STORMS_GROTTO_GOSSIP_STONE, 0x13, "HC Storms Grotto Gossip Stone");
    HintStone(KF_DEKU_TREE_GOSSIP_STONE_LEFT, 0x1F, "KF Deku Tree Left Gossip Stone");
    HintStone(KF_DEKU_TREE_GOSSIP_STONE_RIGHT, 0x20, "KF Deku Tree Right Gossip Stone");
    HintStone(KF_GOSSIP_STONE, 0x1E, "KF Gossip Stone");
    HintStone(LH_LAB_GOSSIP_STONE, 0x03, "LH Lab Gossip Stone");
    HintStone(LH_GOSSIP_STONE_SOUTHEAST, 0x0F, "LH Southeast Gossip Stone");
    HintStone(LH_GOSSIP_STONE_SOUTHWEST, 0x08, "LH Southwest Gossip Stone");
    HintStone(LW_GOSSIP_STONE, 0x1D, "LW Gossip Stone");
    HintStone(SFM_MAZE_GOSSIP_STONE_LOWER, 0x16, "SFM Maze Lower Gossip Stone");
    HintStone(SFM_MAZE_GOSSIP_STONE_UPPER, 0x17, "SFM Maze Upper Gossip Stone");
    HintStone(SFM_SARIA_GOSSIP_STONE, 0x1C, "SFM Saria Gossip Stone");
    HintStone(TOT_GOSSIP_STONE_LEFT, 0x06, "ToT Left Gossip Stone");
    HintStone(TOT_GOSSIP_STONE_RIGHT, 0x07, "ToT Left Center Gossip Stone");
    HintStone(TOT_GOSSIP_STONE_RIGHT_CENTER, 0x10, "ToT Right Center Gossip Stone");
    HintStone(TOT_GOSSIP_STONE_LEFT_CENTER, 0x0E, "ToT Right Gossip Stone");
    HintStone(ZD_GOSSIP_STONE, 0x09, "ZD Gossip Stone");
    HintStone(ZF_FAIRY_GOSSIP_STONE, 0x01, "Fairy Gossip Stone");
    HintStone(ZF_JABU_GOSSIP_STONE, 0x02, "Jabu Gossip Stone");
    HintStone(ZR_NEAR_GROTTOS_GOSSIP_STONE, 0x0D, "ZR Near Grottos Gossip Stone");
    HintStone(ZR_NEAR_DOMAIN_GOSSIP_STONE, 0x0C, "ZR Near Domain Gossip Stone");
    HintStone(HF_COW_GROTTO_GOSSIP_STONE, 0x1B, "HF Cow Grotto Gossip Stone");

    HintStone(HF_NEAR_MARKET_GROTTO_GOSSIP_STONE, 0x30, "HF Near Market Gossip Stone");
    HintStone(HF_SOUTHEAST_GROTTO_GOSSIP_STONE, 0x32, "HF Southeast Gossip Stone");
    HintStone(HF_OPEN_GROTTO_GOSSIP_STONE, 0x33, "HF Open Grotto Gossip Stone");
    HintStone(KAK_OPEN_GROTTO_GOSSIP_STONE, 0x38, "Kak Open Grotto Gossip Stone");
    HintStone(ZR_OPEN_GROTTO_GOSSIP_STONE, 0x39, "ZR Open Grotto Gossip Stone");
    HintStone(KF_STORMS_GROTTO_GOSSIP_STONE, 0x3C, "KF Storms Gossip Stone");
    HintStone(LW_NEAR_SHORTCUTS_GROTTO_GOSSIP_STONE, 0x34, "LW Near Shortcuts Gossip Stone");
    HintStone(DMT_STORMS_GROTTO_GOSSIP_STONE, 0x37, "DMT Storms Grotto Gossip Stone");
    HintStone(DMC_UPPER_GROTTO_GOSSIP_STONE, 0x3A, "DMC Upper Grotto Gossip Stone");

    OtherHint(GANONDORF_HINT, 0x00, "Ganondorf Hint");
}
