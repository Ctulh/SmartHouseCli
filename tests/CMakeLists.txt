cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)

set(TEST_NAME ${PROJECT_NAME}.Test)

set(SOURCES
        main_test.cpp)

set(HEADERS
             DomainTests/LightingDeviceTest.hpp
             UtilsTests/StringOperationsTest.hpp)

add_executable(${TEST_NAME} ${SOURCES})

target_include_directories(${TEST_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${TEST_NAME} PRIVATE ${PROJECT_NAME}.DomainLib ${CONAN_LIBS})

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
