//
// Created by ctuh on 2/6/23.
//

#include "Domain/LightingDevices/Impl/LightingDeviceColor.hpp"

LightingDeviceColor::LightingDeviceColor(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo): LightingDevice(std::move(performer), deviceInfo) {}

ResultObject LightingDeviceColor::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    return m_performer->setColor(m_info, red, green, blue);
}

LightingDeviceState LightingDeviceColor::getDeviceState() {
    auto deviceState = m_performer->getDeviceState(m_info, {
            DeviceProperty::POWER,
            DeviceProperty::BRIGHT,
            DeviceProperty::COLOR_TEMPERATURE,
            DeviceProperty::COLOR
    });

    m_state.brightness = std::stoi(deviceState[DeviceProperty::BRIGHT]);
    m_state.colorTemperature = std::stoi(deviceState[DeviceProperty::COLOR_TEMPERATURE]);
    m_state.color.red = std::stoi(deviceState[DeviceProperty::COLOR]); //TODO fix

    return m_state;
}
