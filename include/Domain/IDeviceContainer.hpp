
#pragma once

#include "BasicDeviceInfo.hpp"

class IDeviceContainer {
public:
    virtual ~IDeviceContainer() = default;

public:
    virtual void addDevice(BasicDeviceInfo const&) = 0;
    virtual void deleteDevice(BasicDeviceInfo const&) = 0;
    virtual Devices getDevices() const = 0;
};
