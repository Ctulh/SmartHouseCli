
#pragma once

#include "Adapters/IDeviceManager.hpp"
#include "Application/IApplication.hpp"

class DeviceManager final: public IDeviceManager {
public:
    DeviceManager(IApplicationPtr applicationPtr);
public:
    void addNewDevice(BasicDeviceInfo const& deviceInfo, DEVICE_TYPE deviceType) override;
    void deleteDevice(BasicDeviceInfo const& deviceInfo) override;
    DevicesInfo getDevices() const override;
    IBasicDevicePtr & getDevice(std::string const& deviceName) override;
    void swapDevices(BasicDeviceInfo const&, BasicDeviceInfo const&) override;

private:
    IApplicationPtr m_application;
};
