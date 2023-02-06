
#pragma once

#include <string>

#include "Domain/ResultObject.hpp"
#include "Domain/BasicDeviceInfo.hpp"

class IPerformer {
public:
    virtual ~IPerformer() = default;

public:
    virtual ResultObject turnOn(BasicDeviceInfo const&) = 0;
    virtual ResultObject turnOff(BasicDeviceInfo const&) = 0;
    virtual ResultObject toggle(BasicDeviceInfo const&) = 0;
    virtual ResultObject setBrightness(BasicDeviceInfo const&, int) = 0;
    virtual ResultObject setColorTemperature(BasicDeviceInfo const&, int) = 0;
    virtual ResultObject setColor(BasicDeviceInfo const&, int, int, int) = 0;
};

using IPerformerPtr = std::unique_ptr<IPerformer>;
