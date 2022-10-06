#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "HLED_interface.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "HPBUTT_interface.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#include "util/delay.h"


u32_t x;

void func(void)
{
<<<<<<< HEAD
    x-= 200;
=======
    x = x - 200;
>>>>>>> 7bca82a2c8d6c0e08c0f26de42c6681ffd684644

    return;
}

int main(void)
{
    x = 1000;

    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);
    hputt_init(PUSH_BUTTON_2);

    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, func);
    sei();

    while (1)
    {
        hled_ledValueON(LED0);
        _delay_ms(x);
        hled_ledValueOFF(LED0); 

        hled_ledValueON(LED1);
        _delay_ms(x);
        hled_ledValueOFF(LED1); 

        hled_ledValueON(LED2);
        _delay_ms(x);
        hled_ledValueOFF(LED2);       

    }
<<<<<<< HEAD

=======
    
>>>>>>> 7bca82a2c8d6c0e08c0f26de42c6681ffd684644

    return 0;
}