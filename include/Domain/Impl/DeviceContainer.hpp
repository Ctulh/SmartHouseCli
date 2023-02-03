
#pragma once

#include <vector>

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"
#include "Domain/IDeviceContainer.hpp"

class DeviceContainer final : public IDeviceContainer {
public:
    void addDevice(IBasicDevicePtr) override;
    void deleteDevice(BasicDeviceInfo const&) override;
    void swap(BasicDeviceInfo const&, BasicDeviceInfo const&);
    DevicesInfo getDevices() const override;

public:
    std::vector<IBasicDevicePtr> m_devices;
};
