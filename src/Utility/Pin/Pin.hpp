/*
 * The MIT License
 *
 * Copyright 2019 aaron.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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

