set(LIB_NAME ${PROJECT_NAME}.DomainLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Domain)

set(HEADERS
        ${HEADERS_PATH}/Impl/DeviceContainer.hpp
        ${HEADERS_PATH}/Impl/LightingDevice.hpp
        ${HEADERS_PATH}/Impl/IPerformer.hpp
        ${HEADERS_PATH}/BasicDeviceInfo.hpp
        ${HEADERS_PATH}/IBasicDevice.hpp
        ${HEADERS_PATH}/IDeviceContainer.hpp
        ${HEADERS_PATH}/ILightingDevice.hpp
        ${HEADERS_PATH}/ResultObject.hpp)

set(SOURCES
        Impl/DeviceContainer.cpp
        Impl/LightingDevice.cpp
        Performer/PerformerImpl.cpp
        Performer/RequestCreator.cpp
        Performer/RequestSender.cpp
        Performer/ResponseParser.cpp)


add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INET_INCLUDE ${PROJECT_SOURCE_DIR}/third_party/InetLib/include)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${INET_INCLUDE})
target_link_libraries(${LIB_NAME} PRIVATE InetLib SocketReaderLib)