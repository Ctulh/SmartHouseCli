
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "DeviceType.hpp"
#include "DeviceProperty.hpp"
#include <map>

struct BasicDeviceInfo {
    DeviceType deviceType;
    std::string deviceName;
    std::string deviceAddr;
    bool isTurnedOn;
};

using DevicesInfo = std::vector<BasicDeviceInfo>;
using StateValueType = std::map<DeviceProperty, std::string>;
