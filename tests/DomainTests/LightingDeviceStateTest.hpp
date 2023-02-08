
#pragma once

#include <gtest/gtest.h>

#include "Domain/LightingDevices/LightingDeviceState.hpp"
#include "Utils/RGBOperations.hpp"

TEST(LightingDeviceStateTest, TestConstructor) {
    StateValueType stateValueType = {
            {DeviceProperty::POWER, "on"},
            {DeviceProperty::BRIGHT, "11"},
            {DeviceProperty::COLOR_TEMPERATURE, "2222"},
            {DeviceProperty::COLOR, std::to_string(RGBOperations::RGBToInt(3,4,5))}
    };

    std::unique_ptr<LightingDeviceState> testState;
    ASSERT_NO_THROW(testState = std::make_unique<LightingDeviceState>(stateValueType));

    ASSERT_EQ(testState->isTurnedOn, true);
    ASSERT_EQ(testState->brightness, 11);
    ASSERT_EQ(testState->colorTemperature, 2222);
    ASSERT_EQ(testState->color.red, 3);
    ASSERT_EQ(testState->color.green, 4);
    ASSERT_EQ(testState->color.blue, 5);
}