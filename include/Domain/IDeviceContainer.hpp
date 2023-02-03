
#pragma once

#include "BasicDeviceInfo.hpp"

class IDeviceContainer {
public:
    virtual ~IDeviceContainer() = default;

public:
    virtual void addDevice(IBasicDevicePtr) = 0;
    virtual void deleteDevice(BasicDeviceInfo const&) = 0;
    virtual DevicesInfo getDevices() const = 0;
    virtual void swap(BasicDeviceInfo const&, BasicDeviceInfo const&) = 0;
};
