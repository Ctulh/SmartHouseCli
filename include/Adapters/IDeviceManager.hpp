
#pragma once

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"
#include "Domain/DeviceType.hpp"

class IDeviceManager {
public:
    virtual ~IDeviceManager() = default;

public:
    virtual void addNewDevice(BasicDeviceInfo const&, DEVICE_TYPE deviceType) = 0;
    virtual void deleteDevice(BasicDeviceInfo const&) = 0;
    virtual void swapDevices(BasicDeviceInfo const&, BasicDeviceInfo const&) = 0;
    virtual DevicesInfo getDevices() const = 0;
    virtual IBasicDevicePtr& getDevice(std::string const& deviceName) = 0;
};
