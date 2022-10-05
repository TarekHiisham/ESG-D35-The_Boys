#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HKPD_cfg.h"
#include "HKPD_interface.h"
#include"util/delay.h"


/***************************************************************************************************/
/*                                       Functions' definitions                                    */
/***************************************************************************************************/

static u8_t garr_keypadmapping[KPD_NUM_ROWS][KPD_NUM_COLS] = KEYPAD_MAPPING ;

void hkpd_init(void)
{
    mdio_setPinStatus(KPD_PORT,(KPD_ROW0 |KPD_ROW1 |KPD_ROW2 |KPD_ROW3 ), INPUT_PULLUP) ;

    mdio_setPinStatus(KPD_PORT,(KPD_COL0 |KPD_COL1 |KPD_COL2 |KPD_COL3 ), OUTPUT) ;

    mdio_setpinvalue(KPD_PORT,(KPD_COL0 |KPD_COL1 |KPD_COL2 |KPD_COL3 ), HIGH);    
    
    return ;
}


void hkpd_getPressedButton(u8_t * pu8_button)
{
    u8_t au8_column;
    u8_t au8_row;
    
    u8_t au8_returnValue ;

    *pu8_button = KPD_DEFAULT_VALUE ;

    for(au8_column = 0 ; au8_column < KPD_NUM_COLS ; au8_column++)
        {
            mdio_setpinvalue(KPD_PORT , (KPD_COL0 << au8_column)  , LOW);
            
            for (au8_row = 0; au8_row < KPD_NUM_ROWS;  au8_row++)
            {
                mdio_getpinvalue(KPD_PORT , (KPD_ROW0 << au8_row) , &au8_returnValue);
                
                    if( au8_returnValue == LOW )
                    {
                        _delay_ms(150);
                        *pu8_button = garr_keypadmapping[au8_row][au8_column];
                        break;
                    }
            }
            
            mdio_setpinvalue(KPD_PORT , (KPD_COL0 << au8_column) ,HIGH);

            if(*pu8_button != KPD_DEFAULT_VALUE)
            {
                break;
            }
            else
            {
                
            }
        }

    return ;
}

