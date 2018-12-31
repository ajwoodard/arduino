set(SOURCE Pin.cpp)
set(HEADERS Pin.hpp)

add_library(Pin ${SOURCE} ${HEADERS})
set_target_properties(Pin PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)