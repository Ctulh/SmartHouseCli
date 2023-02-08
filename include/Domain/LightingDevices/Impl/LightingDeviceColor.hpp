
#pragma once

#include "Domain/LightingDevices/ILightingDeviceColor.hpp"
#include "LightingDevice.hpp"

class LightingDeviceColor final: public virtual ILightingDeviceColor, public LightingDevice {
public:
    explicit LightingDeviceColor(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo);
public:
    ResultObject setColor(uint8_t red, uint8_t green, uint8_t blue) override;
};
