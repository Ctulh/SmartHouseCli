//
// Created by ctuh on 1/31/23.
//

#include <algorithm>
#include <functional>

#include "Domain/Impl/DeviceContainer.hpp"

void DeviceContainer::addDevice(IBasicDevicePtr devicePtr) {
    auto deviceAddr = devicePtr->getDeviceInfo().deviceAddr;

    auto it = std::find_if(m_devices.begin(), m_devices.end(), [deviceAddr](auto const& el) -> bool {
        return deviceAddr == el->getDeviceInfo().deviceAddr;
    });

    if(it == m_devices.end()) {
        m_devices.push_back(std::move(devicePtr));
    }
}

void DeviceContainer::deleteDevice(BasicDeviceInfo const& deviceInfo) {
    std::erase_if(m_devices, [&deviceInfo](auto const& el) -> bool {
        return (el->getDeviceInfo().deviceAddr == deviceInfo.deviceAddr);
    });
}

void DeviceContainer::swap(BasicDeviceInfo const& firstDevice, BasicDeviceInfo const& secondDevice) {
    auto findIfSameAddr = [](auto deviceAddr, auto const& el) -> bool {
        return el->getDeviceInfo().deviceAddr == deviceAddr;
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

Devices DeviceContainer::getDevices() const {
    Devices output;
    output.reserve(m_devices.size());
    for(auto const& el: m_devices) {
        output.push_back(el->getDeviceInfo());
    }
    return output;
}
