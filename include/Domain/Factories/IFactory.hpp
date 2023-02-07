
#pragma once

#include <memory>

#include "Domain/IBasicDevice.hpp"
#include "Domain/DeviceType.hpp"

class IFactory {
public:
    virtual ~IFactory() = default;

public:
    virtual IBasicDevicePtr createDevice(DeviceType deviceType, BasicDeviceInfo const& deviceInfo) const = 0;
};

using IFactoryPtr = std::unique_ptr<IFactory>;
