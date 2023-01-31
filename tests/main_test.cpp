//
// Created by ctuh on 1/20/23.
//
#include <gtest/gtest.h>

#include "DomainTests/LightingDeviceTest.hpp"
#include "DomainTests/PerformerTests/PerformerTest.hpp"

int main(int argc, char** argv) {
    using testing::InitGoogleTest;
    InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

