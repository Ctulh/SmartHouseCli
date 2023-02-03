
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "DeviceType.hpp"

struct BasicDeviceInfo {
    DEVICE_TYPE deviceType;
    std::string deviceName;
    std::string deviceAddr;
};

using DevicesInfo = std::vector<BasicDeviceInfo>;
