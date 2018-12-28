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
    char c[8];
    while(1) {
        int n = Serial::read(c, sizeof(c)/(sizeof(*c)));
        Serial::print(c);
        Serial::putChar('\n');
        Serial::putChar(n+'0');
        _delay_ms(1000);
    }
    return 0;
}

