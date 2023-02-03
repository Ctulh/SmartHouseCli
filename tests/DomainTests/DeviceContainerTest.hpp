
#pragma once

#include <gtest/gtest.h>
#include <memory>

#include "Domain/IDeviceContainer.hpp"
#include "Domain/Impl/DeviceContainer.hpp"

namespace {
    constexpr char const* deviceAddrFirst = "127.0.0.1";
    constexpr char const* deviceAddrSecond = "127.0.0.2";
    constexpr char const* deviceName = "testDevice";
}

class TestDevice final : public IBasicDevice {
public:
    TestDevice(BasicDeviceInfo const& deviceInfo): m_basicDeviceInfo(deviceInfo) {}
    TestDevice(std::string const& deviceAddr) {
        m_basicDeviceInfo.deviceAddr = deviceAddr;
        m_basicDeviceInfo.deviceName = ::deviceName;
    }
public:
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
private:
    BasicDeviceInfo m_basicDeviceInfo;
};

TEST(ContainerTest, TestAddDeviceToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);
}

TEST(ContainerTest, TestAddDevicesWithEqualAdressesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);
}

TEST(ContainerTest, TestAddDevicesWithDifferentAdressesToContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrSecond)));
    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);
}

TEST(ContainerTest, TestDeleteDeviceFromContainer) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(::deviceAddrFirst)));
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

TEST(ContainerTest, TestSwapDevices) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    BasicDeviceInfo firstDevice {.deviceName = ::deviceName, .deviceAddr = ::deviceAddrFirst};
    BasicDeviceInfo secondDevice {.deviceName = ::deviceName, .deviceAddr = ::deviceAddrSecond};

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(firstDevice)));
    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(secondDevice)));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceName);

    ASSERT_EQ(result[1].deviceAddr, ::deviceAddrSecond);
    ASSERT_EQ(result[1].deviceName, ::deviceName);

    ASSERT_NO_THROW(container->swap(firstDevice, secondDevice));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 2);

    ASSERT_EQ(result[1].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[1].deviceName, ::deviceName);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrSecond);
    ASSERT_EQ(result[0].deviceName, ::deviceName);
}

TEST(ContainerTest, TestSwapDevicesWithOneDevice) {
    std::shared_ptr<IDeviceContainer> container = std::make_shared<DeviceContainer>();
    DevicesInfo result;

    BasicDeviceInfo firstDevice {.deviceName = ::deviceName, .deviceAddr = ::deviceAddrFirst};
    BasicDeviceInfo secondDevice {.deviceName = ::deviceName, .deviceAddr = ::deviceAddrSecond};

    ASSERT_NO_THROW(container->addDevice(std::make_unique<TestDevice>(firstDevice)));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceName);

    ASSERT_NO_THROW(container->swap(firstDevice, secondDevice));

    ASSERT_NO_THROW(result = container->getDevices());
    ASSERT_EQ(result.size(), 1);

    ASSERT_EQ(result[0].deviceAddr, ::deviceAddrFirst);
    ASSERT_EQ(result[0].deviceName, ::deviceName);
}