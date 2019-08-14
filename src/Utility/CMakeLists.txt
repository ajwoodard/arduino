set(SOURCE 
    "./Shift/MC74HC595A/MC74HC595A.cpp"
    "./Pin/Pin.cpp"
    "./Serial/Serial.cpp"
    "./Analog/Analog.cpp"
)

set(HEADERS 
    "./Shift/MC74HC595A/MC74HC595A.cpp"
    "./Pin/Pin.cpp"
    "./Serial/Serial.cpp"
    "./Analog/Analog.cpp"
)

add_library(Utility ${SOURCE} ${HEADERS})

set_property(TARGET Utility APPEND PROPERTY COMPILE_OPTIONS -mmcu=${AVR_MCU} -DF_CPU=${MCU_SPEED}UL)
set_property(TARGET Utility APPEND PROPERTY LINK_LIBRARIES -Wl,--gc-sections -mrelax -mmcu=${AVR_MCU})