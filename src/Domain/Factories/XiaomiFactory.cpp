//
// Created by ctuh on 2/6/23.
//

#include "Domain/Factories/XiaomiFactory.hpp"
#include "Domain/Performers/XiaomiPerformer/XiaomiPerformer.hpp"


#include "Domain/LightingDevices/Impl/LightingDeviceColor.hpp"
#include "Domain/LightingDevices/Impl/LightingDevice.hpp"


IBasicDevicePtr XiaomiFactory::createDevice(DeviceType deviceType, BasicDeviceInfo const& deviceInfo) const {
    switch (deviceType) {
        case DeviceType::XIAOMI_LIGHTING_DEVICE:
            return std::make_shared<LightingDevice>(std::make_unique<XiaomiPerformer>(), deviceInfo);
        case DeviceType::XIAOMI_LIGHTING_DEVICE_COLOR:
            return std::make_shared<LightingDeviceColor>(std::make_unique<XiaomiPerformer>(), deviceInfo);
        default:
            return nullptr;
    }
}