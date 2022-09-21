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
    Button_status();  
    while(status[0]==0 &&status[1]==0 &&status[2]==0) 
    {
    Button_status(); 
    /* Use 'ones' and 'tens' variable to display last number on seven segment  */
    /* until pressing in another Bottun  */
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
            
            /* then turnnig on LED0 */
            
            /*make do while to display first number for one time*/
            
            /*make infinity loop to display nembers from 29 to 00 */
            
            /*checking if tens = 0 then turnoff LED0 and calling last_Number Fun then timer again*/
            
            }
        else if(status[1]==1)
            {
                /* Intializing 'tens' = 5  */
            
                /* then turnnig on LED1 */
            
                /*make infinity loop to display nembers from 50 to 99 */
            
                /*checking if tens = 9 then turnoff LED1 and calling last_Number Fun then timer again*/
            }
    else if(status[2]==1)
            {
                /* Intializing 'tens' = 0  */
                tens = 0;

                /* then turnnig on LED2 */
                hled_ledValueON(LED2);

                /*make infinity loop to display nembers from 00 to 40 */
                while (tens < NUMBER_4)
                {
                    for (u8_t i = 0; i < 50; i++)
                    {
                        for ( ones = 0; ones <= NUMBER_9; ones++)
                        {
                            hsev_seg_enable(SEV_SEG_2);
                            hsev_seg_displayNumber(ones);
                            _delay_ms(10);
                            hsev_seg_disable(SEV_SEG_2);   

                            hsev_seg_enable(SEV_SEG_1);
                            hsev_seg_displayNumber(tens);
                            _delay_ms(10);
                            hsev_seg_disable(SEV_SEG_1);   
                        }
                    }

                    tens++;

                }      
                
                /*checking if tens = 4 then turnoff LED2 and calling last_Number Fun then timer again*/
                if (tens == NUMBER_4)
                {
                    hled_ledValueOFF(LED2);
                }
                
            }
    }    
}
