#pragma once

#include "keys.hpp"

#include <3ds.h>
#include <vector>

extern std::vector<ItemKey> StartingInventory;
extern u8 AdditionalHeartContainers;

void GenerateStartingInventory();
bool StartingInventoryHasBottle();
void ApplyStartingInventory();
