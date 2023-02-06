
#pragma once

#include "Domain/ResultObject.hpp"
#include "Domain/DeviceMethod.hpp"

class IDeviceManipulator {
public:
    virtual ~IDeviceManipulator() = default;

public:
    virtual ResultObject turnOn() = 0;
    virtual ResultObject turnOff() = 0;
    virtual DeviceMethods getDeviceMethods() = 0;
};
