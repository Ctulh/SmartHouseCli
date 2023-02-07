
#pragma once

#include "Domain/IBasicDevice.hpp"
#include "LightingDeviceState.hpp"

class ILightingDevice: public virtual IBasicDevice {
public:
    ~ILightingDevice() override = default;

public:
    virtual LightingDeviceState getDeviceState() = 0;
    virtual ResultObject setBrightness(int brightnessPercents) = 0;
    virtual ResultObject setColorTemperature(int colorTemperature) = 0;
};

using ILightingDevicePtr = std::shared_ptr<ILightingDevice>;
