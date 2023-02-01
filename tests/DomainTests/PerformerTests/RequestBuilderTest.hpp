
#pragma once

#include <gtest/gtest.h>

#include "Domain/Performer/RequestCreator.hpp"

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