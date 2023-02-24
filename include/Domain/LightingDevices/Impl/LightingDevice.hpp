
#pragma once

#include <concepts>

#include "Domain/LightingDevices/ILightingDevice.hpp"
#include "Domain/Warehouse/IPerformer.hpp"


class LightingDevice: public virtual ILightingDevice {
public:
    explicit LightingDevice(IPerformerPtr performer, BasicDeviceInfo const& deviceInfo);
public:
    LightingDeviceState getDeviceState() override;
    void setDeviceName(std::string const& deviceName) override;
    virtual DeviceMethods getSupportedMethods() override;
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    ResultObject toggle() override;
    BasicDeviceInfo getInfo() override;

    ResultObject setColorTemperature(int colorTemperature) override;
    ResultObject setBrightness(int brightnessPercents) override;

protected:
    LightingDeviceState m_state;
    BasicDeviceInfo m_info;
    IPerformerPtr m_performer;
};
