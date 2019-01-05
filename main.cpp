#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "src/Utility/Serial/Serial.hpp"
#include "src/Utility/Pin/Pin.hpp"
#include "src/Utility/Analog/Analog.hpp"
#include "src/TLV0832/TLV0832.hpp"

int main() {

    Pin::setMode(B5, OUTPUT);
    Pin::setMode(C5, INPUT);
    Pin::setMode(C4, INPUT);
    Serial::init();
    Analog::init();
    while(1) {
        uint16_t x = Analog::read(0);
        Serial::print("X: ");
        Serial::print(x);
        Serial::putChar('\t');
        
        uint16_t y = Analog::read(1);
        Serial::print("Y: ");
        Serial::print(y);
        Serial::putChar('\n');
        _delay_ms(1000);
    }
    
    return 0;
}

