#include <avr/io.h>
#include <util/delay.h>

volatile void blink() {
    PORTB = 1 << PB5;
    _delay_ms(1000);
    PORTB = 0;
    _delay_ms(1000);
}

int main(void) {

    DDRB = 1 << PB5;

    while(1) {
        //blink();
    }
    return 0;
}
/*
char uart_getchar(void) {
    DDRB = 1 << PB5;
    PORTB = 1 << PB5;
    //loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

void uart_putchar(char c) {
    if (c == '\n') {
        uart_putchar('\r');
    }
    //loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
}

void uart_init() {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

#if USE_2X
    UCSR0A |= _BV(U2X0);
#else
    UCSR0A &= ~(_BV(U2X0));
#endif

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
    UCSR0B = _BV(RXEN0) | _BV(TXEN0); 
}*/