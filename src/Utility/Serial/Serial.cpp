/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serial.cpp
 * Author: aaron
 * 
 * Created on December 27, 2018, 10:47 PM
 */

#include "Serial.hpp"

void Serial::init() {
#ifdef __AVR_ATmega328P__
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
    UCSR0B = _BV(RXEN0) | _BV(TXEN0); 
#else // Add UART configs for your MCU here
    #error Unknown MCU.
#endif
}

void Serial::putChar(char c) {
    if (c == '\n') {
        putChar('\r');
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}

char Serial::getChar() {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}