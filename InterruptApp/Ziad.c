#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "avr/interrupt.h"
#define __DELAY_BACKWARD_COMPATIBLE__
#include "util/delay.h"
#include "MDIO_interface.h"
#include "MEXTI_interface.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"

#define NULL    (0) 
u8_t status;
s32_t i=1000;
void stopfunc(void);
void func(void);

void func(void)
{
    i=i-200;
    return;
}

int main(void)
{    
    hpbutt_init(PUSH_BUTTON_2);
    hled_init(LED0);
    hled_init(LED1);
    hled_init(LED2);

    mexti_enableExternalInterrupt(INT0_REQ_NUM);
    mexti_attachISR(INT0_REQ_NUM, RISING_EDGE_MODE, func);

    sei();
    while(i!=0)
    {
        

        hled_ledValueON(LED0);
        _delay_ms(i);
        hled_ledValueOFF(LED0);
        hled_ledValueON(LED1);
        _delay_ms(i);
        hled_ledValueOFF(LED1);
        hled_ledValueON(LED2);
        _delay_ms(i);
        hled_ledValueOFF(LED2);
        
      
    
    }
    mexti_attachISR(INT1_REQ_NUM,RISING_EDGE_MODE,stopfunc);

    sei();
    while(i==0);
    return 0;
}
void stopfunc(void)
    {
        hled_ledValueOFF(LED0);
        hled_ledValueOFF(LED1);
        hled_ledValueOFF(LED2);
    }
  