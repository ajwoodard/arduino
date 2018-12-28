include_directories(${CMAKE_FIND_ROOT_PATH}/arduino_cores/uno/include)

set(SOURCE TLV0832.cpp)
set(HEADERS TLV0832.hpp)

add_library(TLV0832 ${SOURCE} ${HEADER})

set_target_properties(TLV0832
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)