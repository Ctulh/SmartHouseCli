cmake_minimum_required(VERSION 3.24)
project(SmartHouseManagerCli)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src)
add_subdirectory(tests)

add_executable(SmartHouseManagerCli main.cpp)

target_link_libraries(SmartHouseManagerCli PRIVATE ${PROJECT_NAME}.AdaptersLib)

