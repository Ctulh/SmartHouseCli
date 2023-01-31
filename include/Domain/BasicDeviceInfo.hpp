
#pragma once

#include <string>
#include <vector>
#include <memory>

enum class DEVICE_TYPE {
    UNDEFINED = 0,
    BULB = 1,
};

struct BasicDeviceInfo {
    std::string deviceName;
    std::string deviceAddr;
};

using Devices = std::vector<BasicDeviceInfo>;
