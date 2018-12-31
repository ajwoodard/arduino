#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>
#include "src/Utility/Serial/Serial.hpp"
#include "src/Utility/Pin/Pin.hpp"

void blink() {
    Pin::set(B5, HIGH);
    _delay_ms(1000);
    Pin::set(B5, LOW);
    _delay_ms(1000);
}

int main() {

    Pin::setMode(B5, OUTPUT);
    while(1) {
        blink();
    }
    
    return 0;
}

