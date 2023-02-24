set(LIB_NAME ${PROJECT_NAME}.DomainLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Domain)

set(HEADERS
        ${HEADERS_PATH}/Factories/AbstractFactory.hpp
        ${HEADERS_PATH}/Factories/IFactory.hpp
        ${HEADERS_PATH}/Factories/XiaomiFactory.hpp
        ${HEADERS_PATH}/Warehouse/DeviceContainer.hpp
        ${HEADERS_PATH}/Warehouse/DeviceReaderYaml.hpp
        ${HEADERS_PATH}/Warehouse/DeviceWriterYaml.hpp
        ${HEADERS_PATH}/Warehouse/IDeviceReader.hpp
        ${HEADERS_PATH}/Warehouse/IDeviceWriter.hpp
        ${HEADERS_PATH}/Warehouse/IPerformer.hpp
        ${HEADERS_PATH}/LightingDevices/Impl/LightGroupImpl.hpp
        ${HEADERS_PATH}/LightingDevices/Impl/LightingDevice.hpp
        ${HEADERS_PATH}/LightingDevices/Impl/LightingDeviceColor.hpp
        ${HEADERS_PATH}/BasicDeviceInfo.hpp
        ${HEADERS_PATH}/IBasicDevice.hpp
        ${HEADERS_PATH}/IDeviceContainer.hpp
        ${HEADERS_PATH}/LightingDevices/ILightingDevice.hpp
        ${HEADERS_PATH}/LightingDevices/ILightingDeviceColor.hpp
        ${HEADERS_PATH}/LightingDevices/LightingDeviceState.hpp
        ${HEADERS_PATH}/ResultObject.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/XiaomiPerformer.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/RequestCreator.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/RequestSender.hpp
        ${HEADERS_PATH}/Performers/XiaomiPerformer/ResponseParser.hpp)

set(SOURCES
        Factories/AbstractFactory.cpp
        Factories/XiaomiFactory.cpp
        Warehouse/DeviceContainer.cpp
        Warehouse/DeviceReaderYaml.cpp
        Warehouse/DeviceWriterYaml.cpp
        LightingDevices/LightingDeviceState.cpp
        LightingDevices/Impl/LightGroupImpl.cpp
        LightingDevices/Impl/LightingDevice.cpp
        LightingDevices/Impl/LightingDeviceColor.cpp
        Performers/XiaomiPerformer/XiaomiPerformer.cpp
        Performers/XiaomiPerformer/RequestCreator.cpp
        Performers/XiaomiPerformer/RequestSender.cpp
        Performers/XiaomiPerformer/ResponseParser.cpp)


add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INET_INCLUDE ${PROJECT_SOURCE_DIR}/third_party/InetLib/include)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${INET_INCLUDE} ${CONAN_INCLUDE_DIRS_YAMLCPP})

target_link_libraries(${LIB_NAME} PRIVATE InetLib SocketReaderLib ${PROJECT_NAME}.UtilsLib UtilsLib ${CONAN_LIBS})