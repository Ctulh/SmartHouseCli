//
// Created by ctuh on 2/6/23.
//

#include "Adapters/Impl/DeviceManagerImpl.hpp"


DeviceManager::DeviceManager(IApplicationPtr applicationPtr): m_application(applicationPtr) {}

void DeviceManager::addNewDevice(BasicDeviceInfo const& deviceInfo, DeviceFamily deviceFamily, DeviceType deviceType) {
    m_application->addNewDevice(deviceInfo, deviceFamily, deviceType);
}

void DeviceManager::deleteDevice(BasicDeviceInfo const& deviceInfo) {
    m_application->deleteDevice(deviceInfo);
}

void DeviceManager::swapDevices(BasicDeviceInfo const& firstDeviceInfo, BasicDeviceInfo const& secondDeviceInfo) {
    m_application->swapDevices(firstDeviceInfo, secondDeviceInfo);
}

DevicesInfo DeviceManager::getDevices() const {
    return m_application->getDevices();
}

IBasicDevicePtr DeviceManager::getDevice(const std::string &deviceName) {
    return m_application->getDevice(deviceName);
}