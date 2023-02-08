
#pragma once

#include <gtest/gtest.h>

#include "Domain/Performers/XiaomiPerformer/RequestCreator.hpp"

TEST(RequestCreatorTest, turnOnTestWithDefaultArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_power\",\"params\":[\"on\", \"smooth\", 500]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::turnOn());
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, turnOnTestWithSpecificArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_power\",\"params\":[\"on\", \"sudden\", 123]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::turnOn("sudden", 123));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, turnOffTestWithDefaultArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_power\",\"params\":[\"off\", \"smooth\", 500]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::turnOff());
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, turnOffTestWithSpecificArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_power\",\"params\":[\"off\", \"sudden\", 123]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::turnOff("sudden", 123));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, toggleTest) {
    std::string const request = "{\"id\":1,\"method\":\"toggle\",\"params\":[]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::toggle());
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, setBrightnessTestWithDefaultArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_bright\",\"params\":[50, \"smooth\", 500]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::setBrightness(50));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, setBrightnessTestWithSpecificArguments) {
    std::string const request = "{\"id\":1,\"method\":\"set_bright\",\"params\":[50, \"sudden\", 123]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::setBrightness(50, "sudden", 123));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, setZeroBrightness) {
    std::string const request = "{\"id\":1,\"method\":\"set_bright\",\"params\":[1, \"smooth\", 500]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::setBrightness(0));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, setNegativeBrightness) {
    std::string const request = "{\"id\":1,\"method\":\"set_bright\",\"params\":[1, \"smooth\", 500]}\r\n";
    std::string requestBuiltByCreator;

    ASSERT_NO_THROW(requestBuiltByCreator = RequestCreator::setBrightness(-1));
    ASSERT_EQ(requestBuiltByCreator, request);
}

TEST(RequestCreatorTest, setColorTemperature) {
    constexpr auto expectedResult = "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[3500, \"smooth\", 500]}\r\n";
    std::string actualResult;

    ASSERT_NO_THROW(actualResult = RequestCreator::setColorTemperature(3500));
    ASSERT_EQ(actualResult, expectedResult);
}

TEST(RequestCreatorTest, setLowColorTemperature) {
    constexpr auto expectedResult = "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[1700, \"smooth\", 500]}\r\n";
    std::string actualResult;

    ASSERT_NO_THROW(actualResult = RequestCreator::setColorTemperature(1000));
    ASSERT_EQ(actualResult, expectedResult);
}

TEST(RequestCreatorTest, setHighColorTemperature) {
    constexpr auto expectedResult = "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[6500, \"smooth\", 500]}\r\n";
    std::string actualResult;

    ASSERT_NO_THROW(actualResult = RequestCreator::setColorTemperature(9000));
    ASSERT_EQ(actualResult, expectedResult);
}

TEST(RequestCreatorTest, setNegativeColorTemperature) {
    constexpr auto expectedResult = "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[1700, \"smooth\", 500]}\r\n";
    std::string actualResult;

    ASSERT_NO_THROW(actualResult = RequestCreator::setColorTemperature(-3500));
    ASSERT_EQ(actualResult, expectedResult);
}

TEST(RequestCreatorTest, buildGetProertiesTest) {
    constexpr auto expectedResult = "{\"id\":1,\"method\":\"get_prop\",\"params\":[\"power\",\"bright\",\"ct\",\"rgb\",\"hue\",\"sat\",\"color_mode\"]}\r\n";

    std::string actualResult;
    ASSERT_NO_THROW(actualResult = RequestCreator::getDeviceProperties({
                                            DeviceProperty::POWER,
                                            DeviceProperty::BRIGHT,
                                            DeviceProperty::COLOR_TEMPERATURE,
                                            DeviceProperty::COLOR,
                                            DeviceProperty::HUE,
                                            DeviceProperty::SATURATION,
                                            DeviceProperty::COLOR_MODE}));

    ASSERT_EQ(actualResult, expectedResult);
}