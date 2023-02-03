
#pragma once

#include "Domain/BasicDeviceInfo.hpp"

class IBasicDeviceManager {
public:
    virtual ~IBasicDeviceManager() = default;

public:
    virtual void addNewDevice(BasicDeviceInfo const&) = 0;
    virtual void deleteDevice(BasicDeviceInfo const&) = 0;
    virtual void swapDevices(BasicDeviceInfo const&, BasicDeviceInfo const&) = 0;
    virtual DevicesInfo getDevices() const = 0;
};
