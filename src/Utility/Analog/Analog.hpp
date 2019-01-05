/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Analog.hpp
 * Author: aaron
 *
 * Created on January 2, 2019, 3:15 PM
 */

#ifndef ANALOG_HPP
#define ANALOG_HPP
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
class Analog {
public:
    Analog() = delete;
    virtual ~Analog() = default;
    
    static void init();
    static uint16_t read(uint8_t pin);
private:

};

#endif /* ANALOG_HPP */

