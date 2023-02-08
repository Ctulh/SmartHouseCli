//
// Created by ctuh on 1/20/23.
//
#include <gtest/gtest.h>

#include "DomainTests/LightingDeviceTest.hpp"
#include "DomainTests/PerformerTests/PerformerTest.hpp"
#include "DomainTests/DeviceContainerTest.hpp"
#include "DomainTests/LightGroupTest.hpp"
#include "DomainTests/PerformerTests/RequestBuilderTest.hpp"
#include "DomainTests/PerformerTests/ResponseParserTest.hpp"
#include "UtilsTests/StringOperationsTest.hpp"
#include "UtilsTests/RGBOperationsTest.hpp"
#include "DomainTests/CastOrNullptrTest.hpp"
#include "DomainTests/LightingDeviceStateTest.hpp"

int main(int argc, char** argv) {
    using testing::InitGoogleTest;
    InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

