#pragma once

#include "keys.hpp"

#include <3ds.h>
#include <string>
#include <vector>

enum class SearchMode {
    ReachabilitySearch,
    GeneratePlaythrough,
    CheckBeatable,
    AllLocationsReachable,
    ValidateWorld,
    TimePassAccess,
    TempleOfTimeAccess,
    ValidStartingRegion,
    PoeCollectorAccess,
};

void ClearProgress();
void VanillaFill();
int Fill();

std::vector<LocationKey> GetAccessibleLocations(const std::vector<LocationKey>& allowedLocations,
                                                SearchMode mode    = SearchMode::ReachabilitySearch,
                                                std::string ignore = "", bool checkPoeCollectorAccess = false,
                                                bool checkOtherEntranceAccess = false);
