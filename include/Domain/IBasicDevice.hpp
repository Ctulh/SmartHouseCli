
#pragma once

#include "ResultObject.hpp"
#include "BasicDeviceInfo.hpp"

class IBasicDevice {
public:
    virtual ~IBasicDevice() = default;

public:
    virtual ResultObject turnOn() = 0;
    virtual ResultObject turnOff() = 0;
    virtual ResultObject toggle() = 0;
    virtual BasicDeviceInfo getInfo() = 0;
};

using IBasicDevicePtr = std::unique_ptr<IBasicDevice>;
