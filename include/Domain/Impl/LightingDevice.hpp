
#pragma once

#include <concepts>

#include "Domain/ILightingDevice.hpp"
#include "IPerformer.hpp"


class LightingDevice: public virtual ILightingDevice {
public:
    explicit LightingDevice(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo);
public:
    virtual DeviceMethods getSupportedMethods() override;
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    ResultObject toggle() override;
    BasicDeviceInfo getInfo() override;

    ResultObject setColorTemperature(int colorTemperature) override;
    ResultObject setBrightness(int brightnessPercents) override;

protected:
    BasicDeviceInfo m_info;
    IPerformerPtr m_performer;
};
