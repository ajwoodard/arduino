/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pins.hpp
 * Author: aaron
 *
 * Created on December 30, 2018, 2:37 PM
 */

#ifndef PIN_HPP
#define PIN_HPP

#include <avr/io.h>
/**
 * @class Pin Pin.hpp "src/Utility/Pin/Pin.hpp"
 * 
 */
class Pin {
public:
    Pin() = delete;
    virtual ~Pin() = default;
    
    static void set(uint8_t pin, uint8_t val);
    static void setMode(uint8_t pin, uint8_t val);
    static uint8_t read(uint8_t pin);
    
private:
    static uint16_t* DDRx[3];
    static uint16_t* PORTx[3];
    static uint16_t* PINx[3];
};
/*
* Basically my idea is this :
* First 5 bits tell you what port
* Last 3 bits tell you what pin
*
* Ports are designated PB = 0, PC = 1, PD = 2, ... and so on.
* The first 5 bits of pin values B#, C#, D#, etc will indicate what port this
* pin belongs to. When you right shift these pin values by 3, you will get the
* port number. The way this is written there is a maximum of 32 ports.
*
* Pins are designated 0 to a maximum of 7. The last 3 bits tell you what the
* pin number is. When you & these pin values with 7, it will give you
* the pin number.
*/
#define LOW 0
#define HIGH 1
#define OUTPUT 1
#define INPUT 0

#ifdef __AVR_ATmega328P__
#define PB 0
#define B0 0b00000000
#define B1 0b00000001
#define B2 0b00000010
#define B3 0b00000011
#define B4 0b00000100
#define B5 0b00000101
#define B6 0b00000110
#define B7 0b00000111

#define PC 1
#define C0 0b00001000
#define C1 0b00001001
#define C2 0b00001010
#define C3 0b00001011
#define C4 0b00001100
#define C5 0b00001101
#define C6 0b00001110

#define PD 2
#define D0 0b00010000
#define D1 0b00010001
#define D2 0b00010010
#define D3 0b00010011
#define D4 0b00010100
#define D5 0b00010101
#define D6 0b00010110
#define D7 0b00010111


#else // your MCU pin definitions here
#error Undefiend MCU
#endif

#endif /* PIN_HPP */

