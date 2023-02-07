set(LIB_NAME ${PROJECT_NAME}.ApplicationLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Application)

set(HEADERS
        ${HEADERS_PATH}/Impl/ApplicationImpl.hpp
        ${HEADERS_PATH}/IApplication.hpp)

set(SOURCES
        Impl/ApplicationImpl.cpp)

add_library(${LIB_NAME} ${HEADERS} ${SOURCES})

set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
message(${INCLUDE_PATH})
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_PATH})

target_link_libraries(${LIB_NAME} PRIVATE ${PROJECT_NAME}.DomainLib)