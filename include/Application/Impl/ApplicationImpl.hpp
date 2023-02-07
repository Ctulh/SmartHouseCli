
#pragma once

#include "Application/IApplication.hpp"
#include "Domain/IDeviceContainer.hpp"
#include "Domain/DeviceFamily.hpp"

class ApplicationImpl final: public IApplication {
public:
    ApplicationImpl(IDeviceContainerPtr deviceContainerPtr);

public:
    void addNewDevice(const BasicDeviceInfo &, DeviceFamily deviceFamily, DeviceType deviceType) override;
    void deleteDevice(const BasicDeviceInfo &) override;
    void swapDevices(const BasicDeviceInfo &, const BasicDeviceInfo &) override;
    IBasicDevicePtr getDevice(const std::string &deviceName) override;
    DevicesInfo getDevices() const override;
    void createLightGroup(const std::vector<std::string> &names) override;

private:
    IDeviceContainerPtr m_deviceContainer;
};
