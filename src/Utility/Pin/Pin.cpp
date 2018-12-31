/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pins.cpp
 * Author: aaron
 * 
 * Created on December 30, 2018, 2:37 PM
 */

#include "Pin.hpp"
#ifdef __AVR_ATmega328P__ 
uint16_t* Pin::DDRx[3] = {
    (uint16_t*) &DDRB,
    (uint16_t*) &DDRC,
    (uint16_t*) &DDRD
};

uint16_t* Pin::PORTx[3] = {
    (uint16_t*) &PORTB,
    (uint16_t*) &PORTC,
    (uint16_t*) &PORTD
};

uint16_t* Pin::PINx[3] = {
    (uint16_t*) &PINB,
    (uint16_t*) &PINC,
    (uint16_t*) &PIND
};
#else // your MCU pin definitions here
#error Undefined MCU
#endif

void Pin::set(uint8_t pin, uint8_t val) {
    uint16_t *port = PORTx[pin >> 3];
    if (val == HIGH) {
        *port |= 1 << (pin & 7);
    } else {
        *port &= ~(1 << (pin & 7));
    }
}

void Pin::setMode(uint8_t pin, uint8_t val) {
    uint16_t *ddr = DDRx[pin >> 3];
    if (val == OUTPUT) {
        *ddr |= 1 << (pin & 7);
    } else {
        *ddr &= ~(1 << (pin & 7));
    }
}

uint8_t Pin::read(uint8_t pin) {
    return *(PINx[pin >> 3]) & (1 << (pin & 7));
}