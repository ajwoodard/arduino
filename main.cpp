#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "src/Utility/Serial/Serial.hpp"

void blink() {
    PORTB = 1 << PB5;
    _delay_ms(1000);
    PORTB = 0;
    _delay_ms(1000);
}

int main() {

    DDRB = 1 << PB5;
    Serial::init();
    while(1) {
        Serial::print(-500);
        Serial::putChar('\n');
        _delay_ms(1000);
    }
    return 0;
}

