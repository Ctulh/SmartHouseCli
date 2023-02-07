
#pragma once

#include <gtest/gtest.h>

#include "Domain/CastOrNullptr.hpp"

#include "Domain/BasicDeviceInfo.hpp"
#include "Domain/IBasicDevice.hpp"

namespace {
    constexpr char const* deviceName = "127.0.0.1";
    constexpr char const* deviceAddr = "127.0.0.2";
}

class LightingTestDevice: public ILightingDevice {
public:
    LightingTestDevice() {
        m_basicDeviceInfo.deviceAddr = ::deviceAddr;
        m_basicDeviceInfo.deviceName = ::deviceName;
    }
public:
    void setDeviceName(const std::string &deviceName) override {
        m_basicDeviceInfo.deviceName = deviceName;
    }
    ResultObject turnOn() override {
        return ResultObject(true);
    }
    ResultObject turnOff() override {
        return ResultObject(true);
    }
    ResultObject toggle() override {
        return ResultObject(true);
    }
    BasicDeviceInfo getInfo() override {
        return m_basicDeviceInfo;
    }
    DeviceMethods getSupportedMethods() override {
        return DeviceMethods();
    }
    ResultObject setBrightness(int brightnessPercents) override {
        return ResultObject(true);
    }
    ResultObject setColorTemperature(int colorTemperature) override {
        return ResultObject(true);
    }
    LightingDeviceState getDeviceState() override {
        return LightingDeviceState();
    }

private:
    BasicDeviceInfo m_basicDeviceInfo;
};

class VacuumCleanerTestDevice: public IBasicDevice {};

TEST(CastOrNullptrTest, TestSuccessfulCast) {
    std::shared_ptr<IBasicDevice> device = std::make_shared<LightingTestDevice>();

    std::shared_ptr<ILightingDevice> lightingDevice;
    ASSERT_NO_THROW(lightingDevice = CastOrNullptr<ILightingDevice>(std::move(device)));
    ASSERT_TRUE(lightingDevice != nullptr);
}

TEST(CastOrNullptrTest, TestFailCast) {
    std::shared_ptr<IBasicDevice> device = std::make_shared<LightingTestDevice>();

    std::shared_ptr<VacuumCleanerTestDevice> testDevice;
    ASSERT_NO_THROW(testDevice = CastOrNullptr<VacuumCleanerTestDevice>(std::move(device)));
    ASSERT_TRUE(testDevice == nullptr);
}