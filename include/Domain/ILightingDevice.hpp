
#pragma once

#include "IBasicDevice.hpp"

class ILightingDevice: public IBasicDevice {
public:
    ~ILightingDevice() override = default;

public:
    virtual ResultObject setBrightness(int brightnessPercents) = 0;
};
