
#pragma once

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"
#include "Domain/DeviceFamily.hpp"

#include <memory>

class IApplication {
public:
    ~IApplication() = default;

public:
    virtual void addNewDevice(BasicDeviceInfo const&, DeviceFamily deviceFamily, DeviceType deviceType) = 0;
    virtual void deleteDevice(BasicDeviceInfo const&) = 0;
    virtual void swapDevices(BasicDeviceInfo const&, BasicDeviceInfo const&) = 0;
    virtual DevicesInfo getDevices() const = 0;
    virtual IBasicDevicePtr getDevice(std::string const& deviceName) = 0;
    virtual void createLightGroup(std::vector<std::string> const& names) = 0;
};

using IApplicationPtr = std::shared_ptr<IApplication>;