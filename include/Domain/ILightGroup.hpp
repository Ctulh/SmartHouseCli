
#pragma once

#include "ILightingDevice.hpp"

class ILightGroup: public ILightingDevice {
public:
    virtual ~ILightGroup() = default;
public:
    virtual void add(ILightingDevicePtr) = 0;
    virtual ILightingDevicePtr remove(std::string const& deviceName) = 0;
    virtual DevicesInfo getDevicesInfo() const = 0;
};
