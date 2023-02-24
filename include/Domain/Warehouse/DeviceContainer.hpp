
#pragma once

#include <vector>

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"
#include "Domain/IDeviceContainer.hpp"

class DeviceContainer final : public IDeviceContainer {
public:
    DeviceContainer();
    ~DeviceContainer() override;

public:
    void addDevice(IBasicDevicePtr) override;
    void deleteDevice(BasicDeviceInfo const&) override;
    void swap(BasicDeviceInfo const&, BasicDeviceInfo const&) override;
    IBasicDevicePtr getDevice(std::string const& deviceName) override;
    DevicesInfo getDevices() const override;

private:
    std::string generateUniqueNameForDevice(std::string const& deviceName);

public:
    std::vector<IBasicDevicePtr> m_devices;
};
