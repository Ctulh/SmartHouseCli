set(LIB_NAME ${PROJECT_NAME}.UtilsLib)

set(HEADERS_PATH ${PROJECT_SOURCE_DIR}/include/Utils)

set(HEADERS
        ${HEADERS_PATH}/StringOperations.hpp)

set(SOURCES
        StringOperations.cpp)


add_library(${LIB_NAME} ${HEADERS} ${SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)