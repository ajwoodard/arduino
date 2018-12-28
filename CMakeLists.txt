###
#   this file based on the generic-gcc-avr.cmake toolchain by Matthias Kleemann
#   and multiplemonomials for LoseAVR. Had to change a lot of stuff because the
#   toolchain file wasn't working for me --aaron
###
cmake_minimum_required(VERSION 3.1)

### set avr tools
find_program(CMAKE_C_COMPILER avr-gcc)
find_program(CMAKE_CXX_COMPILER avr-g++)
find_program(AVR_OBJCOPY avr-objcopy)
find_program(AVR_SIZE_TOOL avr-size)
find_program(AVR_OBJDUMP avr-objdump)

### CMAKE needs to know the target system. These are required ###
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

### These flags need to be set for avr libraries ###
add_compile_options(-fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -ffunction-sections -Wall)
set(CMAKE_C_FLAGS "-Os -g")
set(CMAKE_CXX_FLAGS "-Os -g")

### parameters for the arduino uno board needed by the avr library ###
set(AVR_MCU atmega328p)
set(MCU_SPEED "16000000")
add_definitions(-DBAUD=9600)
add_definitions(-D__AVR_ATmega328P__)
add_definitions(-DARDUINO=10807)
add_definitions(-DARDUINO_ARCH_AVR)

### properties for uploading ###
set(AVR_UPLOAD_TOOL avrdude)
set(AVR_PROGRAMMER arduino)
set(AVR_UPLOAD_PORT COM7)

### set the project and the include directory ###
project(arduino)
include_directories(/avr/include/)

### set properties of the main target ###
add_executable(main main.cpp)
set_target_properties(main PROPERTIES OUTPUT_NAME main.elf)
set_property(TARGET main APPEND PROPERTY COMPILE_OPTIONS -mmcu=${AVR_MCU} -DF_CPU=${MCU_SPEED}UL)
set_property(TARGET main APPEND PROPERTY LINK_LIBRARIES -Wl,--gc-sections -mrelax -mmcu=${AVR_MCU})

### convert the .elf file to hex ###
add_custom_command(
    TARGET main
    POST_BUILD
    COMMAND
            ${AVR_OBJCOPY} -j .text -j .data -O ihex -R .eeprom main.elf main.hex
    COMMAND
            ${AVR_SIZE_TOOL} ${AVR_SIZE_ARGS} main.elf
    COMMAND
            ${AVR_UPLOAD_TOOL} -v -p ${AVR_MCU} -c ${AVR_PROGRAMMER} ${AVR_UPLOADTOOL_OPTIONS} -U flash:w:main.hex:i -P ${AVR_UPLOAD_PORT}
    WORKING_DIRECTORY .
)

### upload main to the board using `make upload_main` ###
#add_custom_target(
#    upload_main
#    ${AVR_UPLOAD_TOOL} -v -p ${AVR_MCU} -c ${AVR_PROGRAMMER} ${AVR_UPLOADTOOL_OPTIONS} -U flash:w:main.hex:i -P ${AVR_UPLOAD_PORT}
#    COMMENT "Uploading main.hex to ${AVR_MCU} using ${AVR_PROGRAMMER}"
#)