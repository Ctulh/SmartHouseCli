
#pragma once

#include "IFactory.hpp"

class XiaomiFactory final : public IFactory {
public:
    IBasicDevicePtr createDevice(DeviceType deviceType, BasicDeviceInfo const& deviceInfo) const override;
};