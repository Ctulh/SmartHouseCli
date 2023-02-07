
#pragma once

#include "ILightingDevice.hpp"

class ILightingDeviceColor: public virtual ILightingDevice {
public:
    ~ILightingDeviceColor() override = default;

public:
    virtual ResultObject setColor(uint8_t  red, uint8_t  green, uint8_t  blue) = 0;
};

using ILightingDeviceColorPtr = std::unique_ptr<ILightingDeviceColor>;
