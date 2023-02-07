
#pragma once

#include "Domain/ILightGroup.hpp"
#include "Domain/Impl/LightGroupImpl.hpp"
#include "Domain/ILightingDevice.hpp"
#include "Domain/ILightingDeviceColor.hpp"
#include <gtest/gtest.h>

class LightingDeviceTest final: public ILightingDeviceColor {
public:
    LightingDeviceTest(std::string const& name, std::string const& addr) {
        m_info.deviceName = name;
        m_info.deviceAddr = addr;
        m_info.deviceType = DeviceType::XIAOMI_LIGHTING_DEVICE;
    }
public:
    void setDeviceName(std::string const& deviceName) override {
        m_info.deviceName = deviceName;
    }
    ResultObject turnOn() override {
        m_info.deviceName = "turnedOn";
        return ResultObject(true);
    }
    ResultObject turnOff() override {
        m_info.deviceName = "turnedOff";
        return ResultObject(true);
    }
    ResultObject toggle() override {
        m_info.deviceName = "toggled";
        return ResultObject(true);
    }
    ResultObject setBrightness(int brightnessPercents) override {
        m_info.deviceName = "brightnessSetTo" + std::to_string(brightnessPercents);
        return ResultObject(true);
    }
    ResultObject setColor(uint8_t red, uint8_t green, uint8_t blue) override {
        m_info.deviceName = "ColorSetTo"
                                        + std::to_string(red) + "_"
                                        + std::to_string(green) + "_"
                                        + std::to_string(blue);
        return ResultObject(true);
    }
    ResultObject setColorTemperature(int colorTemperature) override{
        m_info.deviceName = "ColorTemperatureSetTo"
                            + std::to_string(colorTemperature);
        return ResultObject(true);
    }
    BasicDeviceInfo getInfo() override {
        return m_info;
    }
    DeviceMethods getSupportedMethods() {
        return DeviceMethods();
    }

private:
    BasicDeviceInfo m_info;
};


class LightGroupFixture: public ::testing::Test {
public:
    void SetUp() override {
        m_lightGroup = std::make_unique<LightGroupImpl>();

        constexpr auto nameFirst = "TestLightingDevice1";
        constexpr auto nameSecond = "TestLightingDevice2";
        constexpr auto addr = "127.0.0.1";

        m_lightGroup->add(std::make_unique<LightingDeviceTest>(nameFirst, addr));
        m_lightGroup->add(std::make_unique<LightingDeviceTest>(nameSecond, addr));
    }

    void TearDown() override {

    }

protected:
    std::unique_ptr<ILightGroup> m_lightGroup;
};

TEST(LightGroupTest, TestAddDeviceToLightGroup) {
    constexpr auto name = "TestLightingDevice1";
    constexpr auto addr = "127.0.0.1";

    std::unique_ptr<ILightGroup> lightGroup = std::make_unique<LightGroupImpl>();
    ASSERT_EQ(lightGroup->getInfo().deviceType, DeviceType::LIGHT_GROUP);
    ASSERT_NO_THROW(lightGroup = std::make_unique<LightGroupImpl>());

    ASSERT_TRUE(lightGroup->getDevicesInfo().empty());

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(name, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 1);

    auto device = lightGroup->getDevicesInfo()[0];

    ASSERT_EQ(device.deviceName, name);
    ASSERT_EQ(device.deviceAddr, addr);
    ASSERT_EQ(device.deviceType, DeviceType::XIAOMI_LIGHTING_DEVICE);
}

TEST(LightGroupTest, TestAddDevicesWithSameName) {
    constexpr auto name = "TestLightingDevice1";
    constexpr auto addr = "127.0.0.1";

    std::unique_ptr<ILightGroup> lightGroup;
    ASSERT_NO_THROW(lightGroup = std::make_unique<LightGroupImpl>());

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(name, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 1);

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(name, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 1);

    auto device = lightGroup->getDevicesInfo()[0];

    ASSERT_EQ(device.deviceName, name);
    ASSERT_EQ(device.deviceAddr, addr);
    ASSERT_EQ(device.deviceType, DeviceType::XIAOMI_LIGHTING_DEVICE);
}

TEST(LightGroupTest, TestAddDevicesWithDifferentNames) {
    constexpr auto nameFirst = "TestLightingDevice1";
    constexpr auto nameSecond = "TestLightingDevice2";
    constexpr auto addr = "127.0.0.1";

    std::unique_ptr<ILightGroup> lightGroup;
    ASSERT_NO_THROW(lightGroup = std::make_unique<LightGroupImpl>());

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(nameFirst, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 1);

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(nameSecond, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 2);

    auto deviceFirst = lightGroup->getDevicesInfo()[0];
    ASSERT_EQ(deviceFirst.deviceName, nameFirst);
    ASSERT_EQ(deviceFirst.deviceAddr, addr);
    ASSERT_EQ(deviceFirst.deviceType, DeviceType::XIAOMI_LIGHTING_DEVICE);

    auto deviceSecond = lightGroup->getDevicesInfo()[1];
    ASSERT_EQ(deviceSecond.deviceName, nameSecond);
    ASSERT_EQ(deviceSecond.deviceAddr, addr);
    ASSERT_EQ(deviceSecond.deviceType, DeviceType::XIAOMI_LIGHTING_DEVICE);
}

TEST(LightGroupTest, TestRemoveDeviceToLightGroup) {
    constexpr auto name = "TestLightingDevice1";
    constexpr auto addr = "127.0.0.1";

    std::unique_ptr<ILightGroup> lightGroup;
    ASSERT_NO_THROW(lightGroup = std::make_unique<LightGroupImpl>());

    ASSERT_NO_THROW(lightGroup->add(std::make_unique<LightingDeviceTest>(name, addr)));
    ASSERT_EQ(lightGroup->getDevicesInfo().size(), 1);

    ILightingDevicePtr lightingDevice = nullptr;
    ASSERT_NO_THROW(lightingDevice = lightGroup->remove(name));

    ASSERT_TRUE(lightingDevice != nullptr);
    ASSERT_TRUE(lightGroup->getDevicesInfo().empty());

    ASSERT_EQ(lightingDevice->getInfo().deviceName, name);
    ASSERT_EQ(lightingDevice->getInfo().deviceAddr, addr);
    ASSERT_EQ(lightingDevice->getInfo().deviceType, DeviceType::XIAOMI_LIGHTING_DEVICE);
}

TEST_F(LightGroupFixture, TestTurnOn) {
    constexpr auto expectedResult = "turnedOn";

    DevicesInfo devicesInfo;
    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_TRUE(devicesInfo[0].deviceName != expectedResult);
    ASSERT_TRUE(devicesInfo[1].deviceName != expectedResult);

    ASSERT_NO_THROW(m_lightGroup->turnOn());

    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_EQ(devicesInfo[0].deviceName, expectedResult);
    ASSERT_EQ(devicesInfo[1].deviceName, expectedResult);
}

TEST_F(LightGroupFixture, TestTurnOff) {
    constexpr auto expectedResult = "turnedOff";

    DevicesInfo devicesInfo;
    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_TRUE(devicesInfo[0].deviceName != expectedResult);
    ASSERT_TRUE(devicesInfo[1].deviceName != expectedResult);

    ASSERT_NO_THROW(m_lightGroup->turnOff());

    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_EQ(devicesInfo[0].deviceName, expectedResult);
    ASSERT_EQ(devicesInfo[1].deviceName, expectedResult);
}

TEST_F(LightGroupFixture, TestToggle) {
    constexpr auto expectedResult = "toggled";

    DevicesInfo devicesInfo;
    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_TRUE(devicesInfo[0].deviceName != expectedResult);
    ASSERT_TRUE(devicesInfo[1].deviceName != expectedResult);

    ASSERT_NO_THROW(m_lightGroup->toggle());

    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_EQ(devicesInfo[0].deviceName, expectedResult);
    ASSERT_EQ(devicesInfo[1].deviceName, expectedResult);
}

TEST_F(LightGroupFixture, TestSetBrightness) {
    constexpr int brightnessValue = 11;
    const auto expectedResult = "brightnessSetTo" + std::to_string(brightnessValue);

    DevicesInfo devicesInfo;
    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_TRUE(devicesInfo[0].deviceName != expectedResult);
    ASSERT_TRUE(devicesInfo[1].deviceName != expectedResult);

    ASSERT_NO_THROW(m_lightGroup->setBrightness(brightnessValue));

    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_EQ(devicesInfo[0].deviceName, expectedResult);
    ASSERT_EQ(devicesInfo[1].deviceName, expectedResult);
}

TEST_F(LightGroupFixture, TestSetColor) {
    constexpr int redColorValue = 111;
    constexpr int greenColorValue = 112;
    constexpr int blueColorValue = 113;

    const auto expectedResult = "ColorSetTo"
                                + std::to_string(redColorValue) + "_"
                                + std::to_string(greenColorValue) + "_"
                                + std::to_string(blueColorValue);

    DevicesInfo devicesInfo;
    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_TRUE(devicesInfo[0].deviceName != expectedResult);
    ASSERT_TRUE(devicesInfo[1].deviceName != expectedResult);

    ASSERT_NO_THROW(m_lightGroup->setColor(redColorValue, greenColorValue, blueColorValue));

    devicesInfo = m_lightGroup->getDevicesInfo();

    ASSERT_EQ(devicesInfo[0].deviceName, expectedResult);
    ASSERT_EQ(devicesInfo[1].deviceName, expectedResult);
}