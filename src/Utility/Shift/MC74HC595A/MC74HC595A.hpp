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
 * File:   MC74HC595A.hpp
 * Author: aaron
 *
 * Created on August 10, 2019, 11:10 PM
 */

#ifndef MC74HC595A_HPP
#define MC74HC595A_HPP
#include "../../Pin/Pin.hpp"
#include <stdlib.h>
/**
 * @class MC74HC595A
 * This class represents the MC74HC595A serial to serial or parallel shift register
 * @param serialIn - Specifies which pin on the controller is connected to pin A (pin 14) on the MC74HC595A.
 * @param latchClock - Specifies which pin on the controller is connected to LATCH CLOCK (pin 12) on the MC74HC595A
 * @param shiftClock - Specifies which pin on the controller is connected to SHIFT CLOCK (pin 11) on the MC74HC595A
 * @param reset - Specifies which pin on the controller is connected to RESET (pin 10) on the MC74HC595A
 * @param outputEnable - Specifies which pin on the controller is connected to OUTPUT ENABEL (pin 13) on the MC74HC595A
 * @see https://www.onsemi.com/pub/Collateral/MC74HC595A-D.PDF
 */
class MC74HC595A {
public:
    MC74HC595A(uint8_t serialIn, uint8_t latchClock, uint8_t shiftClock);
    virtual ~MC74HC595A() = default;
    void shiftOut(uint8_t data);
    void * operator new(size_t n) {
        void * const p = malloc(n);
        return p;
    }
    void operator delete(void *p) {
        free(p);
    }
private:
    uint8_t serialIn;
    uint8_t latchClock;
    uint8_t shiftClock;
};

#endif /* MC74HC595A_HPP */

