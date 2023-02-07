
#pragma once

#include <gtest/gtest.h>
#include <memory>

#include "Domain/IDeviceContainer.hpp"
#include "Domain/Impl/DeviceContainer.hpp"

namespace {
    constexpr char const* deviceAddrFirst = "127.0.0.1";
    constexpr char const* deviceAddrSecond = "127.0.0.2";
    constexpr char const* deviceNameFirst = "testDevice1";
    constexpr char const* deviceNameSecond = "testDevice2";
}

class TestDevice final : public IBasicDevice {
public:
    TestDevice(BasicDeviceInfo const& deviceInfo): m_basicDeviceInfo(deviceInfo) {}
    TestDevice(std::string const& deviceAddr, std::string const& deviceName) {
        m_basicDeviceInfo.deviceAddr = deviceAddr;
        m_basicDeviceInfo.deviceName = deviceName;
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

private:
    BasicDeviceInfo m_basicDeviceInfo;
};

TEST(ContainerTest, TestAddDeviceToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);
}

TEST(ContainerTest, TestAddDevicesWithEqualAdressesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceAddrFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameSecond)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);
}

TEST(ContainerTest, TestAddDevicesWithEqualNamesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrSecond, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);

    auto devices = container->getDevices();
    const auto expectedDeviceName = std::string(::deviceNameFirst) + "_1";
    ASSERT_EQ(devices[1].deviceName, expectedDeviceName);
}

TEST(ContainerTest, TestAddMoreDevicesWithEqualNamesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    constexpr auto amountOfRepeats = 10;
    for(int i = 0; i < amountOfRepeats; i++) {
        ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(std::to_string(i), ::deviceNameFirst)));
        ASSERT_NO_THROW(result = container->getDevices());
        ASSERT_EQ(result.size(), i + 1);
    }

    auto devices = container->getDevices();
    for(int i = 0; i < amountOfRepeats; i++) {
        if(i == 0) {
            ASSERT_EQ(devices[i].deviceName, ::deviceNameFirst);
            continue;
        }
        const auto expectedDeviceName = std::string(::deviceNameFirst) + "_" + std::to_string(i);
        ASSERT_EQ(devices[i].deviceName, expectedDeviceName);
    }
}

TEST(ContainerTest, TestAddDevicesWithDifferentAdressesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrSecond, ::deviceNameSecond)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);
}

TEST(ContainerTest, TestDeleteDeviceByAddressFromContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    BasicDeviceInfo deviceInfo {.deviceAddr = ::deviceAddrFirst};

    ASSERT_NO_THROW(container->deleteDevice(deviceInfo));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 0);

    ASSERT_NO_THROW(container->deleteDevice(deviceInfo));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 0);
}

TEST(ContainerTest, TestDeleteDeviceByNameFromContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst, ::deviceNameFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    BasicDeviceInfo deviceInfo {.deviceName = ::deviceNameFirst};

    ASSERT_NO_THROW(container->deleteDevice(deviceInfo));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 0);

    ASSERT_NO_THROW(container->deleteDevice(deviceInfo));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 0);
}

TEST(ContainerTest, TestSwapDevices) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    BasicDeviceInfo firstDevice {.deviceName = ::deviceNameFirst, .deviceAddr = ::deviceAddrFirst};
    BasicDeviceInfo secondDevice {.deviceName = ::deviceNameSecond, .deviceAddr = ::deviceAddrSecond};

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(firstDevice)));
    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(secondDevice)));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceNameFirst);

    ASSERT_EQ(result[1].deviceAddr, ::deviceAddrSecond);
    ASSERT_EQ(result[1].deviceName, ::deviceNameSecond);

    ASSERT_NO_THROW(container->swap(firstDevice, secondDevice));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);

    ASSERT_EQ(result[1].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[1].deviceName, ::deviceNameFirst);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrSecond);
    ASSERT_EQ(result[0].deviceName, ::deviceNameSecond);
}

TEST(ContainerTest, TestSwapDevicesWithOneDevice) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    BasicDeviceInfo firstDevice {.deviceName = ::deviceNameFirst, .deviceAddr = ::deviceAddrFirst};
    BasicDeviceInfo secondDevice {.deviceName = ::deviceNameSecond, .deviceAddr = ::deviceAddrSecond};

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(firstDevice)));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceNameFirst);

    ASSERT_NO_THROW(container->swap(firstDevice, secondDevice));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceNameFirst);
}