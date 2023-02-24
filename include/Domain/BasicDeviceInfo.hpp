
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "DeviceType.hpp"
#include "DeviceProperty.hpp"
#include "DeviceFamily.hpp"
#include <map>

struct BasicDeviceInfo {
    DeviceFamily deviceFamily;
    DeviceType deviceType;
    std::string deviceName;
    std::string deviceAddr;
    bool isTurnedOn;

public:
    std::map<std::string, std::string> toMap() const { //TODO tests
        std::map<std::string, std::string> output;

        output["deviceFamily"] = std::to_string(static_cast<int>(deviceFamily));
        output["deviceType"] = std::to_string(static_cast<int>(deviceType));
        output["deviceName"] = deviceName;
        output["deviceAddr"] = deviceAddr;
        output["isTurnedOn"] = std::to_string(isTurnedOn);

        return output;
    }
};

using DevicesInfo = std::vector<BasicDeviceInfo>;
using StateValueType = std::map<DeviceProperty, std::string>;
