//
// Created by ctuh on 1/31/23.
//

#include "Domain/Impl/LightingDevice.hpp"

LightingDevice::LightingDevice(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo): m_performer(std::move(performer)),
                                                                                            m_info(deviceInfo) {}

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

BasicDeviceInfo LightingDevice::getDeviceInfo() {
    return m_info;
}