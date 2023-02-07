//
// Created by ctuh on 2/6/23.
//

#include "Application/Impl/ApplicationImpl.hpp"
#include "Domain/Factories/AbstractFactory.hpp"
#include "Domain/LightingDevices/Impl/LightGroupImpl.hpp"

ApplicationImpl::ApplicationImpl(IDeviceContainerPtr deviceContainerPtr): m_deviceContainer(std::move(deviceContainerPtr)) {}

void ApplicationImpl::addNewDevice(BasicDeviceInfo const& deviceInfo, DeviceFamily deviceFamily, DeviceType deviceType) {
    auto device = AbstractFactory::createFactory(deviceFamily)->createDevice(deviceType, deviceInfo);
    m_deviceContainer->addDevice(std::move(device));
}

void ApplicationImpl::deleteDevice(BasicDeviceInfo const& deviceInfo) {
    m_deviceContainer->deleteDevice(deviceInfo);
}

void ApplicationImpl::swapDevices(const BasicDeviceInfo &, const BasicDeviceInfo &) {

}

IBasicDevicePtr ApplicationImpl::getDevice(const std::string &deviceName) {
    return m_deviceContainer->getDevice(deviceName);
}

DevicesInfo ApplicationImpl::getDevices() const {
    return m_deviceContainer->getDevices();
}

void ApplicationImpl::createLightGroup(const std::vector<std::string> &names) {
    std::vector<IBasicDevicePtr> devicesToLightGroup;
    for(auto const& deviceName: names) {
        devicesToLightGroup.push_back(m_deviceContainer->getDevice(deviceName));
        m_deviceContainer->deleteDevice(BasicDeviceInfo{.deviceName = deviceName});
    }

    auto lightGroup = std::make_shared<LightGroupImpl>();
    for(auto const& device: devicesToLightGroup) {
        auto devicePtr = std::dynamic_pointer_cast<ILightingDevice>(device);
        if(devicePtr != nullptr)
            lightGroup->add(devicePtr);
    }

    m_deviceContainer->addDevice(lightGroup);
}
