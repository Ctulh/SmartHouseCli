
#pragma once

#include <vector>

enum class DeviceProperty {
    POWER = 1,
    BRIGHT = 2,
    COLOR_TEMPERATURE = 3,
    COLOR = 4,
    HUE = 5,
    SATURATION = 6,
    COLOR_MODE = 7,
};

using DeviceProperties = std::vector<DeviceProperty>;
