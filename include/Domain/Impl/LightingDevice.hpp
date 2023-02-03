
#pragma once

#include <concepts>

#include "Domain/ILightingDevice.hpp"
#include "IPerformer.hpp"


class LightingDevice final: public ILightingDevice {
public:
    explicit LightingDevice(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo);
public:
    ResultObject setBrightness(int brightnessPercents) override;
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    ResultObject toggle() override;
    BasicDeviceInfo getInfo() override;
private:
    BasicDeviceInfo m_info;
    IPerformerPtr m_performer;
};
