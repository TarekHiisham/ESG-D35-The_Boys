#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#include "util/delay.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"

void funcTimeReduce(void);
void LastLed(void);

u8_t i=0;
u32_t time_arr[6]={1000,800,600,400,200,0};

int main (void)
{
    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);
    hpbutt_init(PUSH_BUTTON_2);
    
    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, funcTimeReduce);
    sei();

    while(1)
    {
        
        hled_ledValueON(LED0);
        _delay_ms(time_arr[i]);
        hled_ledValueOFF(LED0);
        hled_ledValueON(LED1);
        _delay_ms(time_arr[i]);
        hled_ledValueOFF(LED1);
        hled_ledValueON(LED2);
        _delay_ms(time_arr[i]);
        hled_ledValueOFF(LED2);

        /*
        if(i==5)
        {
            LastLed();
        }
        else
        {

        }
        */

    }
    
    return 0;
}


void funcTimeReduce(void)
{
    i++;
    return;
}

/*
void LastLed(void)
{

}
*/