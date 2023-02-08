//
// Created by ctuh on 1/31/23.
//

#include "Domain/LightingDevices/Impl/LightingDevice.hpp"

LightingDevice::LightingDevice(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo): m_performer(std::move(performer)),
                                                                                            m_info(deviceInfo) {}


LightingDeviceState LightingDevice::getDeviceState() {
    auto deviceState = m_performer->getDeviceState(m_info, {
            DeviceProperty::POWER,
            DeviceProperty::BRIGHT,
            DeviceProperty::COLOR_TEMPERATURE,
            DeviceProperty::COLOR
    });
    m_state = LightingDeviceState(deviceState);
    m_info.isTurnedOn = m_state.isTurnedOn;
    return m_state;
}

void LightingDevice::setDeviceName(std::string const& deviceName) {
    m_info.deviceName = deviceName;
}

ResultObject LightingDevice::turnOn() {
    return m_performer->turnOn(m_info);
}

ResultObject LightingDevice::turnOff() {
    return m_performer->turnOff(m_info);
}

ResultObject LightingDevice::toggle() {
    return m_performer->toggle(m_info);
}

ResultObject LightingDevice::setBrightness(int brightnessPercents) {
    return m_performer->setBrightness(m_info, brightnessPercents);
}

ResultObject LightingDevice::setColorTemperature(int colorTemperature) {
    return m_performer->setColorTemperature(m_info, colorTemperature);
}

BasicDeviceInfo LightingDevice::getInfo() {
    return m_info;
}

DeviceMethods LightingDevice::getSupportedMethods() {
    return DeviceMethods();
}
