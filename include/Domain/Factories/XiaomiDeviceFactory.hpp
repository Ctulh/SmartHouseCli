
#pragma once

#include "IFactory.hpp"

class XiaomiDeviceFactory final : public IFactory {
public:
    IBasicDevicePtr createDevice(DeviceType deviceType, BasicDeviceInfo const& deviceInfo) const override;
};