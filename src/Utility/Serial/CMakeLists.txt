set(SOURCE Serial.cpp)
set(HEADERS Serial.hpp)

add_library(Serial ${SOURCE} ${HEADERS})
set_property(TARGET Serial APPEND PROPERTY COMPILE_OPTIONS -mmcu=${AVR_MCU} -DF_CPU=${MCU_SPEED}UL)