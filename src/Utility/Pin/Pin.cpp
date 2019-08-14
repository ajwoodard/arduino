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

/** 
 * @file:   Pins.cpp
 * @author: aaron
 * 
 * Created on December 30, 2018, 2:37 PM
 */


#include "Pin.hpp"

/**
 * PORTs, DDRs, and PINs are put in arrays for easy access.
 * By right shifting the pin values above, you can access each of
 * these registers by right shifting the pin values above
 */
uint16_t* Pin::PORTx[3] = {
    (uint16_t*) & PORTB,
    (uint16_t*) & PORTC,
    (uint16_t*) & PORTD
};

uint16_t* Pin::DDRx[3] = {
    (uint16_t*) & DDRB,
    (uint16_t*) & DDRC,
    (uint16_t*) & DDRD
};

uint16_t* Pin::PINx[3] = {
    (uint16_t*) & PINB,
    (uint16_t*) & PINC,
    (uint16_t*) & PIND
};


/**
 * Sets the pin to either high (1) or low (0)
 * @param pin - the pin to set. @see Pin.hpp
 * @param val - value to set the pin either 1 or 0
 */
void Pin::set(uint8_t pin, uint8_t val) {
    uint16_t *port = PORTx[pin >> 3]; 
    if (val == HIGH) {
        *port |= 1 << (pin & 7);
    } else {
        *port &= ~(1 << (pin & 7));
    }
}

/**
 * Sets the mode of the pin. Either output (1) or input (0)
 * @param pin - the pin to set. @see Pin.hpp
 * @param val - the value to set it, either 1 or 0
 */
void Pin::setMode(uint8_t pin, uint8_t val) {
    uint16_t *ddr = DDRx[pin >> 3];
    if (val == OUTPUT) {
        *ddr |= 1 << (pin & 7);
    } else {
        *ddr &= ~(1 << (pin & 7));
    }
}

/**
 * reads the state of a pin
 * @param pin - the pin to read from. @see Pin.hpp
 * @return - the value of the pin, either high (1) or low (0)
 */
uint8_t Pin::read(uint8_t pin) {
    return *(PINx[pin >> 3]) & (1 << (pin & 7));
}