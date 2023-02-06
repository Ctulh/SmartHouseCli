
#pragma once

#include "Domain/ILightGroup.hpp"
#include <vector>
#include <functional>

class LightGroupImpl final : public ILightGroup {
public:
    LightGroupImpl();

public:
    void add(ILightingDevicePtr) override;
    ILightingDevicePtr remove(const std::string &deviceName) override;
    DevicesInfo getDevicesInfo() const override;

    virtual DeviceMethods getSupportedMethods() override;
    ResultObject turnOn() override;
    ResultObject turnOff() override;
    ResultObject toggle() override;
    BasicDeviceInfo getInfo() override;
    ResultObject setBrightness(int brightnessPercents) override;
    ResultObject setColor(uint8_t red, uint8_t green, uint8_t blue) override;
    ResultObject setColorTemperature(int colorTemperature);

private:
    ResultObject launchAsyncForEach(std::function<ResultObject(ILightingDevicePtr&)>);

private:
    BasicDeviceInfo m_info;
    std::vector<ILightingDevicePtr> m_devices;
};