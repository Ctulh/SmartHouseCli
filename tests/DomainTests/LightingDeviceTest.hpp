
#pragma once

#include <gtest/gtest.h>

#include "Domain/IBasicDevice.hpp"
#include "Domain/ILightingDevice.hpp"
#include "Domain/Impl/IPerformer.hpp"

#include "Domain/Impl/LightingDevice.hpp"

namespace {
    constexpr char const* turnOnTest = "turnOnTest";
    constexpr char const* turnOffTest = "turnOffTest";
    constexpr char const* toggleTest = "toggleTest";
    constexpr char const* setBrightnessTest = "setBrightnessTest";
}

class AlwaysSuccessPerformer final: public IPerformer {
public:
    ResultObject turnOn(BasicDeviceInfo const&) override {
        return ResultObject(true, ::turnOnTest);
    }
    ResultObject turnOff(BasicDeviceInfo const&) override {
        return ResultObject(true, ::turnOffTest);
    }
    ResultObject toggle(BasicDeviceInfo const&) override {
        return ResultObject(true, ::toggleTest);
    }
    ResultObject setBrightness(BasicDeviceInfo const&, int) override {
        return ResultObject(true, ::setBrightnessTest);
    }
    ResultObject setColor(const BasicDeviceInfo &, int, int, int) override {
        return ResultObject(true);
    }
    ResultObject setColorTemperature(const BasicDeviceInfo &, int) override {
        return ResultObject(true);
    }
};

class AlwaysFailPerformer final: public IPerformer {
public:
    ResultObject turnOn(BasicDeviceInfo const&) override {
        return ResultObject(false, ::turnOnTest);
    }
    ResultObject turnOff(BasicDeviceInfo const&) override {
        return ResultObject(false, ::turnOffTest);
    }
    ResultObject toggle(BasicDeviceInfo const&) override {
        return ResultObject(false, ::toggleTest);
    }
    ResultObject setBrightness(BasicDeviceInfo const&, int) override {
        return ResultObject(false, ::setBrightnessTest);
    }
    ResultObject setColor(const BasicDeviceInfo &, int, int, int) override {
        return ResultObject(false);
    }
    ResultObject setColorTemperature(const BasicDeviceInfo &, int) override {
        return ResultObject(false);
    }
};

class LightingDeviceAlwaysSuccess: public ::testing::Test {
public:
    void SetUp() override {
        BasicDeviceInfo basicDeviceInfo {.deviceName = "testDevice", .deviceAddr = "127.0.0.1"};
        m_lightingDevice = std::make_unique<LightingDevice>(std::make_unique<AlwaysSuccessPerformer>(), basicDeviceInfo);
    }
    void TearDown() override {

    }
protected:
    std::unique_ptr<ILightingDevice> m_lightingDevice;
};

class LightingDeviceAlwaysFail: public ::testing::Test {
public:
    void SetUp() override {
        BasicDeviceInfo basicDeviceInfo {.deviceName = "testDevice", .deviceAddr = "127.0.0.1"};
        m_lightingDevice = std::make_unique<LightingDevice>(std::make_unique<AlwaysFailPerformer>(), basicDeviceInfo);
    }
    void TearDown() override {

    }
protected:
    std::unique_ptr<ILightingDevice> m_lightingDevice;
};


TEST_F(LightingDeviceAlwaysSuccess, testTurnOnDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->turnOn());
    ASSERT_TRUE(result);
    ASSERT_EQ(result.getMessage(), ::turnOnTest);
};

TEST_F(LightingDeviceAlwaysSuccess, testTurnOffDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->turnOff());
    ASSERT_TRUE(result);
    ASSERT_EQ(result.getMessage(), ::turnOffTest);
};

TEST_F(LightingDeviceAlwaysSuccess, testToggleDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->toggle());
    ASSERT_TRUE(result);
    ASSERT_EQ(result.getMessage(), ::toggleTest);
};

TEST_F(LightingDeviceAlwaysSuccess, testSetBtightnessDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->setBrightness(1));
    ASSERT_TRUE(result);
    ASSERT_EQ(result.getMessage(), ::setBrightnessTest);
};


TEST_F(LightingDeviceAlwaysFail, testTurnOnDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->turnOn());
    ASSERT_FALSE(result);
    ASSERT_EQ(result.getMessage(), ::turnOnTest);
};

TEST_F(LightingDeviceAlwaysFail, testTurnOffDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->turnOff());
    ASSERT_FALSE(result);
    ASSERT_EQ(result.getMessage(), ::turnOffTest);
};

TEST_F(LightingDeviceAlwaysFail, testToggleDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->toggle());
    ASSERT_FALSE(result);
    ASSERT_EQ(result.getMessage(), ::toggleTest);
};

TEST_F(LightingDeviceAlwaysFail, testSetBtightnessDevice) {
    ResultObject result;
    ASSERT_NO_THROW(result = m_lightingDevice->setBrightness(1));
    ASSERT_FALSE(result);
    ASSERT_EQ(result.getMessage(), ::setBrightnessTest);
};