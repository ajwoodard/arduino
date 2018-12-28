set(SOURCE Serial.cpp);
set(HEADERS Serial.hpp);

add_library(Serial ${SOURCE} ${HEADERS})
set_target_properties(Serial PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)