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

void Serial::print(char *c) {
    int length = strlen(c);
    while(length--) {
        putChar(*c++);
    }
}

int Serial::read(char *c, size_t length) {
    uint8_t n = 0;    
    while((c[n] = getChar()) != '\n' && ++n < length - 1) {}
    c[n] = '\0';
    return n;
}

void Serial::print(int n, uint8_t base) {
    int sign = 1;
    if(n < 0) {
        sign = -1;
        n *= -1;
    }
    char buf[50];
    char *str = &buf[sizeof(buf) -1];
    *str = '\0';
    if(base < 2) base = 10;
    do {
        *--str = n % base + '0';
        n /= base;
    } while(n);
    
    if(sign < 0) {
        *--str = '-';
    }
    print(str);
}