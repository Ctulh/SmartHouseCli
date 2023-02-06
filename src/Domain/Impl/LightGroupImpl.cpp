//
// Created by ctuh on 2/3/23.
//

#include "Domain/Impl/LightGroupImpl.hpp"

#include <algorithm>
#include <future>
#include "Domain/ILightingDeviceColor.hpp"

LightGroupImpl::LightGroupImpl() {
    m_info.deviceName = "LightGroup";
    m_info.deviceType = DEVICE_TYPE::LIGHT_GROUP;
}

ResultObject LightGroupImpl::launchAsyncForEach(std::function<ResultObject(ILightingDevicePtr&)> func) {
    std::vector<std::future<ResultObject>> results;
    for(auto& device: m_devices) {
        auto res = std::async(std::launch::async, [&device, &func]() {
            return func(device);
        });
        results.push_back(std::move(res));
    }

    ResultObject output;
    for(auto& result: results) {
        output = result.get();
    }
    return output;
}

void LightGroupImpl::add(ILightingDevicePtr device) {
    auto deviceName = device->getInfo().deviceName;
    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&deviceName](auto const& device){
        return device->getInfo().deviceName == deviceName;
    });
    if(it == m_devices.end())
        m_devices.push_back(std::move(device));
}

ILightingDevicePtr LightGroupImpl::remove(std::string const& deviceName) {
    auto it = std::find_if(m_devices.begin(), m_devices.end(), [&deviceName](auto const& el) {
        return (el->getInfo().deviceName == deviceName);
    });
    if(it == m_devices.end())
        return nullptr;
    auto retValue = std::move(*it);
    m_devices.erase(it);
    return std::move(retValue);
}

DevicesInfo LightGroupImpl::getDevicesInfo() const {
    DevicesInfo output;
    output.reserve(m_devices.size());

    for(auto const& device: m_devices) {
        output.push_back(device->getInfo());
    }
    return output;
}

ResultObject LightGroupImpl::turnOn() {
    auto result = launchAsyncForEach(&ILightingDevice::turnOn);
    return result;
}

ResultObject LightGroupImpl::turnOff() {
    auto result = launchAsyncForEach(&ILightingDevice::turnOff);
    return result;
}

ResultObject LightGroupImpl::toggle() {
    auto result = launchAsyncForEach(&ILightingDevice::toggle);
    return result;
}

ResultObject LightGroupImpl::setBrightness(int brightnessPercents) {
    auto result = launchAsyncForEach([brightnessPercents](ILightingDevicePtr& lightingDevice) -> ResultObject {
        return lightingDevice->setBrightness(brightnessPercents);
    });
    return result;
}

ResultObject LightGroupImpl::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    auto result = launchAsyncForEach([red, green, blue](ILightingDevicePtr& lightingDevice) -> ResultObject {
        auto lightingDeviceColor = dynamic_cast<ILightingDeviceColor*>(lightingDevice.get());
        if(lightingDeviceColor)
            return lightingDeviceColor->setColor(red, green, blue);
        return ResultObject(false, "Can't cast bulb to color bulb");
    });
    return result;
}

ResultObject LightGroupImpl::setColorTemperature(int colorTemperature) {
    auto result = launchAsyncForEach([colorTemperature](ILightingDevicePtr& lightingDevice) -> ResultObject {
        return lightingDevice->setColorTemperature(colorTemperature);
    });
    return result;
}

BasicDeviceInfo LightGroupImpl::getInfo() {
    return m_info;
}

DeviceMethods LightGroupImpl::getSupportedMethods() {
    return DeviceMethods();
}

