
#pragma once

#include "Domain/ResultObject.hpp"

class IBasicDeviceManipulator {
public:
    virtual ~IBasicDeviceManipulator() = default;

public:
    virtual ResultObject turnOn() = 0;
    virtual ResultObject turnOff() = 0;
    virtual ResultObject toggle() = 0;
};
