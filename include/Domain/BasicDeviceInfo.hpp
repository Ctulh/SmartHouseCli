
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "DeviceType.hpp"

struct BasicDeviceInfo {
    DeviceType deviceType;
    std::string deviceName;
    std::string deviceAddr;
};

using DevicesInfo = std::vector<BasicDeviceInfo>;
