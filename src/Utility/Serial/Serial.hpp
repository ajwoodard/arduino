/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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

