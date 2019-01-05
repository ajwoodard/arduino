/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TLV0832.cpp
 * Author: aaron
 * 
 * Created on December 23, 2018, 4:27 PM
 */

#include "TLV0832.hpp"

void TLV0832::initRead(uint8_t clockPin, uint8_t clearPin, uint8_t configPin, uint8_t channel){
    Pin::setMode(clockPin, OUTPUT);
    Pin::setMode(clearPin, OUTPUT);
    Pin::setMode(configPin, OUTPUT);
    // conversion starts with the clearPin (CS) and the clockPin (CLK) set to low.
    // The clearPin must be set to low during the entire conversion process
    Pin::set(clearPin, 0);
    Pin::set(clockPin, 0);
    
    // the configPin must first be set to high
    Pin::set(configPin, 1);
    
    // pulse the clock pin high then low to start the next cycle
    Pin::set(clockPin, 1);
    Pin::set(clockPin, 0);
    
    // depending on the channel selected the configPin must be pulsed in a
    // unique pattern
    if(channel == 0) { // if CH0, pulse HIGH then LOW
        Pin::set(configPin, 1); // HIGH
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
        Pin::set(configPin, 0); // LOW
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
    } else if(channel == 1) { // if CH1 pulse HIGH and HIGH again
        Pin::set(configPin, 1); // HIGH
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle (configPin stays HIGH)
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
    } else if(channel == 2) { // voltage differential with +CH0 and -CH1
        Pin::set(configPin, 0); // LOW
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle (configPin stays LOW)
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
    } else if(channel == 3) { // voltage differential with -CH0 and +CH1
        Pin::set(configPin, 0); // LOW
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
        Pin::set(configPin, 1); // HIGH
        Pin::set(clockPin, 1);
        Pin::set(clockPin, 0);  // next clock cycle
    }
    
    Pin::set(clockPin, 1); // prepare for reading
}

uint8_t TLV0832::read(uint8_t dataPin, uint8_t clockPin, uint8_t clearPin, uint8_t configPin, uint8_t channel) {
    Pin::setMode(dataPin, INPUT);
    initRead(clockPin, clearPin, configPin, channel);
    uint8_t data = 0; // collector for data
    for(int i = 7; i >= 0; i--) { //data comes off as MSB first so count backwards
        Pin::set(clockPin, 0); // data is read in when clockPin is low
        int dataBit = Pin::read(dataPin); // read bit from the dataPin
        
        if(dataBit) { // if the data was a 1
            data |= 1 << i; // do a bitwise operation to set that bit to 1 in the data byte
        } // else do nothing
        
        Pin::set(clockPin, 1); // prepare for next read
    }
    
    Pin::set(clearPin, 1); // At the end of conversion return the clear pin to HIGH
    
    return data;
}