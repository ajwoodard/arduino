#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "src/Utility/Serial/Serial.hpp"
#include "src/Utility/Pin/Pin.hpp"
#include "src/Utility/Shift/MC74HC595A/MC74HC595A.hpp"

int main() {

    uint8_t bit0 = 0b10000001;
    uint8_t bit1 = 0b01000010;
    uint8_t bit2 = 0b00100100;
    uint8_t bit3 = 0b00011000;
    uint8_t bit4 = 0b00100100;
    uint8_t bit5 = 0b01000010;
    uint8_t bit6 = 0b10000001;
    uint8_t bit7 = 0b00000000;
    
    uint8_t bits[8] = {bit0, bit1, bit2, bit3, bit4, bit5, bit6, bit7};
    
    uint8_t serialIn = B5;
    uint8_t outputEnable = B4;
    uint8_t latchClock = B3;
    uint8_t shiftClock = B2;
    uint8_t reset = B1;
    
    Pin::setMode(serialIn, OUTPUT);
    Pin::setMode(outputEnable, OUTPUT);
    Pin::setMode(latchClock, OUTPUT);
    Pin::setMode(shiftClock, OUTPUT);
    Pin::setMode(reset, OUTPUT);
    
    MC74HC595A mc = MC74HC595A(serialIn, latchClock, shiftClock);
    uint8_t i = 0;
    while(1) {
        mc.shiftOut(bits[i++]);
        if (i >= 8) {
            i = 0;
        }
        _delay_ms(1000);
    }
    
    return 0;
}

