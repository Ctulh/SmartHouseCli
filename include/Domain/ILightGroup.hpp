
#pragma once

#include "Domain/LightingDevices/ILightingDeviceColor.hpp"

class ILightGroup: public ILightingDeviceColor {
public:
    virtual ~ILightGroup() = default;
public:
    virtual void add(ILightingDevicePtr) = 0;
    virtual ILightingDevicePtr remove(std::string const& deviceName) = 0;
    virtual DevicesInfo getDevicesInfo() const = 0;
};
