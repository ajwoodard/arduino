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
 * File:   MC74HC595A.cpp
 * Author: aaron
 * 
 * Created on August 10, 2019, 11:10 PM
 */

#include "MC74HC595A.hpp"

MC74HC595A::MC74HC595A(uint8_t serialIn, uint8_t latchClock, uint8_t shiftClock, uint8_t reset, uint8_t outputEnable) {
    this->serialIn = serialIn;
    this->latchClock = latchClock;
    this->shiftClock = shiftClock;
    this->reset = reset;
    this->outputEnable = outputEnable;
}

void MC74HC595A::shiftOut(uint8_t data) {
    // clear any data on the shift register (just in case)
    Pin::set(reset, LOW);
    Pin::set(reset, HIGH);
    Pin::set(latchClock, LOW);
    Pin::set(outputEnable, LOW);
    
    for(uint8_t i = 0; i < 8; i++) {
        // data is shifted out when there is a low to high switch on the shift clock
        Pin::set(shiftClock, LOW);
        Pin::set(serialIn, (data >> i) & 1);
        Pin::set(shiftClock, HIGH);
    }
    
    // transfer shift register data to latch register
    Pin::set(latchClock, HIGH);
    Pin::set(latchClock, LOW);
}