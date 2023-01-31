
#pragma once

#include <vector>

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"
#include "Domain/IDeviceContainer.hpp"

class DeviceContainer final : public IDeviceContainer {
public:
    void addDevice(const BasicDeviceInfo &) override;
    void deleteDevice(const BasicDeviceInfo &) override;
    Devices getDevices() const override;

public:
    std::vector<IBasicDevicePtr> m_devices;
};
