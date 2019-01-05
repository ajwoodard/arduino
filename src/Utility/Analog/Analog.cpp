/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analog.cpp
 * Author: aaron
 * 
 * Created on January 2, 2019, 3:15 PM
 */

#include "Analog.hpp"

void Analog::init() {
    ADCSRA = (1 << ADEN) | 7;
    ADMUX |= (1 << REFS0);
}

uint16_t Analog::read(uint8_t pin) {
    pin &= 7;
    ADMUX = (ADMUX & 0xF8) | pin;
    
    ADCSRA |= (1 << ADSC);
    while(ADCSRA & (1 << ADIF));
    
    return ADC;
}