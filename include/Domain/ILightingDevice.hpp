
#pragma once

#include "IBasicDevice.hpp"

class ILightingDevice: public virtual IBasicDevice {
public:
    ~ILightingDevice() override = default;

public:
    virtual ResultObject setBrightness(int brightnessPercents) = 0;
    virtual ResultObject setColorTemperature(int colorTemperature) = 0;
};

using ILightingDevicePtr = std::shared_ptr<ILightingDevice>;
