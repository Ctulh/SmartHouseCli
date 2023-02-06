
#pragma once

#include <vector>

enum class DeviceMethod {
    None = 0,
    SetPower = 1,
    Toggle = 3,
    SetBrightness = 4,
    setColorTemperature = 5,
    SetLightColor = 6,
};

using DeviceMethods = std::vector<DeviceMethod>;
