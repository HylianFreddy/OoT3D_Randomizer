#pragma once

#include "item_location.hpp"

#include <set>
#include <string>

namespace Playthrough {
int Playthrough_Init(u32 seed);
int Playthrough_Repeat(int count = 1);
} // namespace Playthrough
