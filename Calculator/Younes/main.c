
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLCD_interface.h"
#include "HKPD_interface.h"
#include "avr/io.h"
#include "util/delay.h"
#include "stdlib.h"


void Operation(Void);


u8_t button;
u8_t res;
u8_t loop=0;
u8_t loop2=0;
u8_t arr[3];
u8_t arr2[4]={'A','S','B','='};

int main(void)
{
  
   hlcd_init();
   hkpd_init();

   while (1)
   {
    do
    {
        hkpd_getPressedButton(&button);
        arr[loop]=button;
    } while (arr2[loop2]='A');
    if(arr[loop]=='=')
    {
        hlcd_Clear();
    }
    else
    {
        hlcd_displayCharacter(arr[loop]);
    }
    loop++;
    loop2++;
    _delay_ms(200);

    do
    {
        hkpd_getPressedButton(&button);
        arr[loop]=button;
    } while (arr2[loop2]='s');
    if(arr[loop]='=')
    {
        hlcd_Clear();
    }
    else
    {
        hlcd_displayCharacter(arr[loop]);
    }
    loop++;
    loop2++;
    _delay_ms(200);

      do
    {
        hkpd_getPressedButton(&button);
        arr[loop]=button;
    } while (arr2[loop2]='B');
    if(arr[loop]=='=')
    {
        hlcd_Clear();
    }
    else
    {
        hlcd_displayCharacter(arr[loop]);
    }
    loop++;
    loop2++;
    _delay_ms(200);

     do
    {
        hkpd_getPressedButton(&button);
        arr[loop]=button;
    } while (arr2[loop2]='=');
    if(arr[loop]=='=')
    {
         hlcd_displayPosition(LCD_ROW_1 , LCD_COL_0);
         hlcd_displayCharacter('=');
         Operation();
         hlcd_displayCharacter(res);
    }
    else
    {
        
    }
    _delay_ms(200); 

   }
    


}


void Operation(Void)
{
     switch (arr[1])
    {
    case '+':
        itoa(arr[0],&arr2,10);
        itoa(arr[2],&arr2,10);
        res =arr[0]+arr[2];
        break;
    case '-':
        itoa(arr[0],&arr2,10);
        itoa(arr[2],&arr2,10);
        res =arr[0]-arr[2];
        break;
    case '*':
        itoa(arr[0],&arr2,10);
        itoa(arr[2],&arr2,10);
        res =arr[0]*arr[2];
        break;
    case '/':
        itoa(arr[0],&arr2,10);
        itoa(arr[2],&arr2,10);
        res =arr[0]/arr[2];
        break;
    
    default:
        break;
    }

    return;
}

