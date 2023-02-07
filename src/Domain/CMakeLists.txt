set(LIB_NAME ${PROJECT_NAME}.DomainLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Domain)

set(HEADERS
        ${HEADERS_PATH}/Factories/AbstractFactory.hpp
        ${HEADERS_PATH}/Factories/IFactory.hpp
        ${HEADERS_PATH}/Factories/XiaomiDeviceFactory.hpp
        ${HEADERS_PATH}/Impl/DeviceContainer.hpp
        ${HEADERS_PATH}/Impl/LightingDevice.hpp
        ${HEADERS_PATH}/Impl/LightingDeviceColor.hpp
        ${HEADERS_PATH}/Impl/IPerformer.hpp
        ${HEADERS_PATH}/BasicDeviceInfo.hpp
        ${HEADERS_PATH}/IBasicDevice.hpp
        ${HEADERS_PATH}/IDeviceContainer.hpp
        ${HEADERS_PATH}/ILightingDevice.hpp
        ${HEADERS_PATH}/ResultObject.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/XiaomiPerformer.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/RequestCreator.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/RequestSender.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/ResponseParser.hpp)

set(SOURCES
        Factories/AbstractFactory.cpp
        Factories/XiaomiDeviceFactory.cpp
        Impl/LightGroupImpl.cpp
        Impl/DeviceContainer.cpp
        Impl/LightingDevice.cpp
        Impl/LightingDeviceColor.cpp
        Performers/XiaomiPerformer/XiaomiPerformer.cpp
        Performers/XiaomiPerformer/RequestCreator.cpp
        Performers/XiaomiPerformer/RequestSender.cpp
        Performers/XiaomiPerformer/ResponseParser.cpp)


add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INET_INCLUDE ${PROJECT_SOURCE_DIR}/third_party/InetLib/include)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${INET_INCLUDE} ${CONAN_INCLUDE_DIRS_NLOHMANN_JSON})
target_link_libraries(${LIB_NAME} PRIVATE InetLib SocketReaderLib ${PROJECT_NAME}.UtilsLib UtilsLib ${CONAN_LIBS_NLOHMANN_JSON})