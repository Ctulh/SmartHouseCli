
#pragma once

#include <gtest/gtest.h>
#include <tuple>

#include "Utils/RGBOperations.hpp"

TEST(RGBOperationsTest, getIntFromRGBWithAllZeros) {
    constexpr auto expectedResult = 0;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(0, 0, 0));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithOnlyRedColor) {
    constexpr auto expectedResult = 16711680;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(255, 0, 0));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithOnlyGreenColor) {
    constexpr auto expectedResult = 65280;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(0, 255, 0));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithOnlyBlueColor) {
    constexpr auto expectedResult = 255;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(0, 0, 255));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithRedAndGreen) {
    constexpr auto expectedResult = 16776960;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(255, 255, 0));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithGreenAndBlue) {
    constexpr auto expectedResult = 65535;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(0, 255, 255));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithRedAndBlue) {
    constexpr auto expectedResult = 16711935;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(255, 0, 255));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getIntFromRGBWithAllColors) {
    constexpr auto expectedResult = 16777215;

    int actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::RGBToInt(255, 255, 255));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRGBFromZeroIntValue) {
    std::tuple<int,int,int> expectedResult = {0,0,0};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(0));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithOnlyRedColor) {
    std::tuple<int,int,int> expectedResult = {255,0,0};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(16711680));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithOnlyGreenColor) {
    std::tuple<int,int,int> expectedResult = {0,255,0};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(65280));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithOnlyBlueColor) {
    std::tuple<int,int,int> expectedResult = {0,0,255};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(255));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithRedAndGreenColor) {
    std::tuple<int,int,int> expectedResult = {255,255,0};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(16776960));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithGreenAndBlueColor) {
    std::tuple<int,int,int> expectedResult = {0,255,255};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(65535));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithRedAndBlueColor) {
    std::tuple<int,int,int> expectedResult = {255,0,255};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(16711935));
    ASSERT_EQ(expectedResult, actualResult);
}

TEST(RGBOperationsTest, getRgbFromValueWithAllColors) {
    std::tuple<int,int,int> expectedResult = {255,255,255};

    std::tuple<int,int,int> actualResult;
    ASSERT_NO_THROW(actualResult = RGBOperations::IntToRGB(16777215));
    ASSERT_EQ(expectedResult, actualResult);
}