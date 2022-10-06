#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "MEXTI_interface.h"
#include "util/delay.h"

#define INITIAL_DELAY   (1000)
#define REDUCED_DELAY   (200)


void Reducedelay(void);

u8_t counter = 5 ;

void Reducedelay(void)
{
    
    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM,RISING_EDGE_MODE,Reducedelay);
    sei();
    
    counter-- ;

    while(1)
    {

    hled_ledValueON(LED0);
    for (u8_t i = 0; i < counter; i++)
    {
        _delay_ms(REDUCED_DELAY);
    }
    hled_ledValueOFF(LED0);
        
    hled_ledValueON(LED1);
    for (u8_t i = 0; i < counter; i++)
    {
        _delay_ms(REDUCED_DELAY);
    }
    hled_ledValueOFF(LED1);
 
    hled_ledValueON(LED2);
    for (u8_t i = 0; i < counter; i++)
    {
        _delay_ms(REDUCED_DELAY);
    }
    hled_ledValueOFF(LED2);
}
}
int main(void)
{

    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);
    hputt_init(PUSH_BUTTON_2);
   
    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM,RISING_EDGE_MODE,Reducedelay);
    sei();

    while(1)
        {
            hled_ledValueON(LED0);
            _delay_ms(INITIAL_DELAY);
            hled_ledValueOFF(LED0);
            
            hled_ledValueON(LED1);
            _delay_ms(INITIAL_DELAY);
            hled_ledValueOFF(LED1);

            hled_ledValueON(LED2);
            _delay_ms(INITIAL_DELAY);
            hled_ledValueOFF(LED2);
        }

    return 0 ;
}