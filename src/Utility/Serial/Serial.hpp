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
 * File:   Serial.hpp
 * Author: aaron
 *
 * Created on December 27, 2018, 10:47 PM
 */

#ifndef SERIAL_HPP
#define SERIAL_HPP

#ifndef BAUD
#define BAUD 9600
#endif

#include <util/setbaud.h>
#include <stdio.h>
#include <avr/io.h>
#include <string.h>
/**
 * @class Serial Serial.hpp "src/Utility/Serial/Serial.hpp"
 * 
 * @details
 * This class provides functions for serial communication. These functions
 * assume you are using an ATmega328p (the chip Arduino uno)
 * 
 * You can add other definitions for other chips if you'd like.
 * 
 * For most of this class: 
 * @see <https://appelsiini.net/2011/simple-usart-with-avr-libc/>
 */
class Serial {
public:
    Serial() = delete;
    virtual ~Serial() = default;
    /**
     * This configures UART for the specific board
     */
    static void init();
    /**
     * writes a single character to the serial out
     * @param c : the character to be written
     */
    static void putChar(char c);
    /**
     * reads a single character from the input
     * @return c : the character received
     */
    static char getChar();
    
    /**
     * writes an entire string of characters to serial out
     * @param c : char array
     */
    static void print(char *c);
    
    /**
     * prints integers
     * @param n : the integer to print
     * @param base : the base to represent the integer
     */
    static void print(int n, uint8_t base = 10);
    
    /**
     * reads a string of characters. it either reads until it hits a newline \n
     * character or reads until the char array is filled -- whichever comes first.
     * 
     * Output will tell you how many characters were read.
     * @param c : char array to write to
     * @return length : the number of character read
     */
    static int read(char *c, size_t length);
};

#endif /* SERIAL_HPP */

