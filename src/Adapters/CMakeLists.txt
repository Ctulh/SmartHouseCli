set(LIB_NAME ${PROJECT_NAME}.AdaptersLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Adapters)

set(HEADERS
            ${HEADERS_PATH}/IBasicDeviceManager.hpp
            ${HEADERS_PATH}/IBasicDeviceManipulator.hpp)
set(SOURCES AdapterCli.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
message(${INCLUDE_PATH})
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH})