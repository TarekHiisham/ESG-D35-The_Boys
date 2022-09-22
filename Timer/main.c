#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLED_interface.h"
#include "HPBUTT_interface.h"
#include "HSEV_SEG_interface.h"
#include "util/delay.h"


void timer(void); /*This Function looping on timer*/
void Button_status(void); /*this Finction get Button status */
void last_Number(void);   /*this function displaying last number in timer until pressing another Button*/

u8_t status[3]; /*this array to carry Button status*/ 
s8_t tens ;     /*left 7Seg*/
s8_t ones ;     /*Right 7Seg*/


int main(void)
{
    
hsev_seg_init(SEV_SEG_1);
hsev_seg_init(SEV_SEG_2);

hled_init(LED0);
hled_init(LED1);
hled_init(LED2);

hputt_init(PUSH_BUTTON_0);
hputt_init(PUSH_BUTTON_1);
hputt_init(PUSH_BUTTON_2);
    
timer();

return 0 ;
}

void Button_status(void)
{
    hputt_getstatus(PUSH_BUTTON_0,&status[0]);
    hputt_getstatus(PUSH_BUTTON_1,&status[1]);
    hputt_getstatus(PUSH_BUTTON_2,&status[2]);

return ;
}

void last_Number()
{
    /*updading Button status to 0*/
    Button_status();
    
    /* Use 'ones' and 'tens' variable to display last number on seven segment  */
    /* until pressing in another Bottun  */  
    while(status[0]==0 &&status[1]==0 &&status[2]==0) 
    {
    Button_status(); 
    hsev_seg_enable(SEV_SEG_1);
    hsev_seg_displayNumber(tens);
    _delay_ms(10);
    hsev_seg_disable(SEV_SEG_1);

    hsev_seg_enable(SEV_SEG_2);
    hsev_seg_displayNumber(ones);
    _delay_ms(10);
    hsev_seg_disable(SEV_SEG_2);
    }
    return ;
}

void timer(void)
{
while (1)
    {
        Button_status();
        if(status[0]==1)
            {
            /* Intializing 'tens' = 2  */
            tens = 2 ;
            /* then turnnig on LED0 */
            hled_ledValueON(LED0);  
            /*make do while to display first number for one time*/
            do
            {
                for(u8_t i=0 ; i<=50 ; i++)
                {
                hsev_seg_enable(SEV_SEG_1);
                hsev_seg_displayNumber(NUMBER_3);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);

                hsev_seg_enable(SEV_SEG_2);
                hsev_seg_displayNumber(NUMBER_0);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_2);
                }
            } while(0);

            /*make infinity loop to display nembers from 29 to 00 */

            while (1)
            {
            for (ones = 9; ones >= 0; ones--)
            {
                for(u8_t i=0 ; i<=50 ; i++)
                {
                hsev_seg_enable(SEV_SEG_1);
                hsev_seg_displayNumber(tens);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_1);

                hsev_seg_enable(SEV_SEG_2);
                hsev_seg_displayNumber(ones);
                _delay_ms(10);
                hsev_seg_disable(SEV_SEG_2);
                }
            }            
            /*checking if tens = 0 then turnoff LED0 and calling last_Number Fun then timer again*/
            
            if (tens == 0)
            {
                hled_ledValueOFF(LED0);
                last_Number(); 
                timer();
            }
             tens-- ;
                    }
            }

        else if(status[1]==1)
            {
                /* Intializing 'tens' = 5  */
                tens=5;
            
                /* then turnnig on LED1 */
                hled_ledValueON(LED1);
            
                /*make infinity loop to display nembers from 50 to 99 */
                while(1)
                {   
                    for ( ones = NUMBER_0; ones <= NUMBER_9; ones++)
                    {
                    
                        for(u8_t i=0;i<=50;i++)
                        {
                        hsev_seg_enable(SEV_SEG_1);
                        hsev_seg_displayNumber(tens);
                        _delay_ms(10);
                        hsev_seg_disable(SEV_SEG_1);   

                        hsev_seg_enable(SEV_SEG_2);
                        hsev_seg_displayNumber(ones);
                        _delay_ms(10);
                        hsev_seg_disable(SEV_SEG_2);  

                        }
                         
                    }
                    /*checking if tens = 9 then turnoff LED1 and calling last_Number Fun then timer again*/
                    if(tens== NUMBER_9)
                    {
                        hled_ledValueOFF(LED1);
                        ones--;
                        last_Number();
                        timer();
                    }
                    tens ++ ;

                }
            }

    else if(status[2]==1)
            {
                
                /* Intializing 'tens' = 0  */
                tens = 0;

                /* then turnnig on LED2 */
                hled_ledValueON(LED2);

                /*make infinity loop to display nembers from 00 to 40 */
                while (1)
                {
                    for ( ones = 0; ones <= NUMBER_9; ones++)
                    {
                        
                        for (u8_t i = 0; i < 50; i++)
                        {
                            hsev_seg_enable(SEV_SEG_1);
                            hsev_seg_displayNumber(tens);
                            _delay_ms(10);
                            hsev_seg_disable(SEV_SEG_1); 

                            hsev_seg_enable(SEV_SEG_2);
                            hsev_seg_displayNumber(ones);
                            _delay_ms(10);
                            hsev_seg_disable(SEV_SEG_2);   
  
                        }
                    }
                    /*checking if tens = 4 then turnoff LED2 and calling last_Number Fun then timer again*/
                    if (tens == NUMBER_3)
                    {
                        hled_ledValueOFF(LED2);
                        ones=NUMBER_0;
                        tens = NUMBER_4;
                        last_Number();
                        timer();                
                    }  
                    tens++;                 
                }      
                
            }
    }    
}
