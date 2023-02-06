set(LIB_NAME ${PROJECT_NAME}.AdaptersLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Adapters)

set(HEADERS
            ${HEADERS_PATH}/IDeviceManager.hpp
            ${HEADERS_PATH}/IDeviceManipulator.hpp
            ${HEADERS_PATH}/Impl/DeviceManagerImpl.hpp
            ${HEADERS_PATH}/Impl/DeviceManipulatorImpl.hpp)
set(SOURCES
            Impl/DeviceManagerImpl.cpp
            Impl/DeviceManipulator.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
message(${INCLUDE_PATH})
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH})