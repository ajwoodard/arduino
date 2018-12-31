#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "src/Utility/Serial/Serial.hpp"
#include "src/Utility/Pin/Pin.hpp"
#include "src/TLV0832/TLV0832.hpp"

void blink() {
    Pin::set(B5, HIGH);
    _delay_ms(1000);
    Pin::set(B5, LOW);
    _delay_ms(1000);
}

int main() {

    Pin::setMode(B5, OUTPUT);
    Serial::init();
    while(1) {
        uint8_t data = TLV0832::read(D2, D3, D4, D5, 0);
        Serial::print("X: ");
        Serial::print(data);
        Serial::putChar('\t');
        
        data = TLV0832::read(D2, D3, D4, D5, 1);
        Serial::print("Y: ");
        Serial::print(data);
        Serial::putChar('\n');
        _delay_ms(1000);
    }
    
    return 0;
}

