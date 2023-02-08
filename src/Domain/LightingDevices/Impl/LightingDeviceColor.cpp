//
// Created by ctuh on 2/6/23.
//

#include "Domain/LightingDevices/Impl/LightingDeviceColor.hpp"

LightingDeviceColor::LightingDeviceColor(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo): LightingDevice(std::move(performer), deviceInfo) {}

ResultObject LightingDeviceColor::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    return m_performer->setColor(m_info, red, green, blue);
}
