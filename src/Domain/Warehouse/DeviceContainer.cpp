//
// Created by ctuh on 1/31/23.
//

#include <algorithm>
#include <functional>
#include <fstream>

#include "Domain/Warehouse/DeviceContainer.hpp"

#include "Domain/Warehouse/DeviceWriterYaml.hpp"

namespace {
    std::string const file = "/home/output.yaml";
}

DeviceContainer::DeviceContainer() {

}

DeviceContainer::~DeviceContainer() noexcept {
    DeviceWriterYaml yaml;
    std::ofstream output;
    output.open(file);
    yaml.write(m_devices, output);
    output.close();
}

std::string DeviceContainer::generateUniqueNameForDevice(std::string const& deviceName) {
    if(m_devices.empty())
        return deviceName;

    auto newDeviceName = deviceName + '_';
    int counter = 1;

    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&deviceName](auto el) {
        return (deviceName == el->getInfo().deviceName);
    });
    if(it == m_devices.end())
        return deviceName;

    for(auto const& device: m_devices) {
        auto tempDeviceName = newDeviceName + std::to_string(counter);
        it = std::find_if(m_devices.begin(), m_devices.end(), [&tempDeviceName](auto el) {
            return (tempDeviceName == el->getInfo().deviceName);
        });

        if(it == m_devices.end()) {
            return tempDeviceName;
        }
        counter++;
    }
    return deviceName;
}

void DeviceContainer::addDevice(IBasicDevicePtr devicePtr) {
    auto deviceAddr = devicePtr->getInfo().deviceAddr;
    auto deviceName = devicePtr->getInfo().deviceName;

    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&deviceAddr, &deviceName](auto const& el) -> bool {
        return (deviceAddr == el->getInfo().deviceAddr);
    });

    if(it == m_devices.end()) {
        deviceName = generateUniqueNameForDevice(deviceName);
        devicePtr->setDeviceName(deviceName);
        m_devices.push_back(std::move(devicePtr));
    }
}

void DeviceContainer::deleteDevice(BasicDeviceInfo const& deviceInfo) {
    std::erase_if(m_devices, [&deviceInfo](auto const& el) -> bool {
        return (el->getInfo().deviceAddr == deviceInfo.deviceAddr) || (el->getInfo().deviceName == deviceInfo.deviceName);
    });
}

IBasicDevicePtr DeviceContainer::getDevice(std::string const& deviceName) {
    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&deviceName](auto const& el){
        return el->getInfo().deviceName == deviceName;
    });

    return *it;
}

void DeviceContainer::swap(BasicDeviceInfo const& firstDevice, BasicDeviceInfo const& secondDevice) {
    auto findIfSameAddr = [](auto deviceAddr, auto const& el) -> bool {
        return el->getInfo().deviceAddr == deviceAddr;
    };

    auto firstDeviceAddr = firstDevice.deviceAddr;
    auto secondDeviceAddr = secondDevice.deviceAddr;

    auto findFirstDevice = [&firstDeviceAddr, findIfSameAddr](auto const& el) -> bool {
        return findIfSameAddr(firstDeviceAddr, el);
    };
    auto findSecondDevice = [&secondDeviceAddr, findIfSameAddr](auto const& el) -> bool {
        return findIfSameAddr(secondDeviceAddr, el);
    };

    auto firstIt = std::find_if(m_devices.begin(), m_devices.end(), findFirstDevice);
    auto secondIt = std::find_if(m_devices.begin(), m_devices.end(), findSecondDevice);

    if(firstIt != m_devices.end() && secondIt != m_devices.end())
        std::iter_swap(firstIt, secondIt);
}

DevicesInfo DeviceContainer::getDevices() const {
    DevicesInfo output;
    output.reserve(m_devices.size());
    for(auto const& el: m_devices) {
        output.push_back(el->getInfo());
    }
    return output;
}
