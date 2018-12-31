set(SOURCE TLV0832.cpp)
set(HEADERS TLV0832.hpp)

add_library(TLV0832 ${SOURCE} ${HEADER})
target_link_libraries(TLV0832 Pin)
set_target_properties(TLV0832 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
target_include_directories(TLV0832 PUBLIC ${CMAKE_SOURCE_DIR})