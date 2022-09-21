#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HSEV_SEG_cfg.h"
#include "HSEV_SEG_interface.h"


#define BIT_0    (0)
#define BIT_1    (1)
#define BIT_2    (2)
#define BIT_3    (3)


void hsev_seg_init(u8_t au8_sev_segNumber){

    mdio_setPinStatus(HSEV_SEG_DECODER_PORT, HSEV_SEG_A_PIN, OUTPUT);
    mdio_setPinStatus(HSEV_SEG_DECODER_PORT, HSEV_SEG_B_PIN, OUTPUT);
    mdio_setPinStatus(HSEV_SEG_DECODER_PORT, HSEV_SEG_C_PIN, OUTPUT);
    mdio_setPinStatus(HSEV_SEG_DECODER_PORT, HSEV_SEG_D_PIN, OUTPUT);

switch(au8_sev_segNumber)
{
    case SEV_SEG_1 :
    mdio_setPinStatus(HSEV_SEG_1_PORT,HSEV_SEG_1_PIN,OUTPUT);
    break;
    
    case SEV_SEG_2 :
    mdio_setPinStatus(HSEV_SEG_2_PORT,HSEV_SEG_2_PIN,OUTPUT);
    break;
}
return ;
}
void hsev_seg_enable(u8_t au8_sev_segNumber)
{
    /*Switching over seven segment modules*/
    switch(au8_sev_segNumber)
    {
        /*In case of seven segment 1*/
        case SEV_SEG_1:

            /*Setting the seven segment 1 pin to HIGH*/
            mdio_setpinvalue(HSEV_SEG_1_PORT, HSEV_SEG_1_PIN, HIGH);

            /*Break from this case*/
            break;

        /*In case of seven segment 2*/
        case SEV_SEG_2:

            /*Setting the seven segment 2 pin as HIGH*/
            mdio_setpinvalue(HSEV_SEG_2_PORT, HSEV_SEG_2_PIN, HIGH);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void hsev_seg_disable(u8_t au8_sev_segNumber)
{
    /*Switching over seven segment modules*/
    switch(au8_sev_segNumber)
    {
        /*In case of seven segment 1*/
        case SEV_SEG_1:

            /*Setting the seven segment 1 pin to LOW*/
            mdio_setpinvalue(HSEV_SEG_1_PORT, HSEV_SEG_1_PIN, LOW);

            /*Break from this case*/
            break;

        /*In case of seven segment 2*/
        case SEV_SEG_2:

            /*Setting the seven segment 2 pin as LOW*/
            mdio_setpinvalue(HSEV_SEG_2_PORT, HSEV_SEG_2_PIN, LOW);

            /*Break from this case*/
            break;

        /*In case of default*/
        default:

            /*Break from this case*/
            break;
    }

    /*Return from this function*/
    return;
}

void hsev_seg_displayNumber(u8_t au8_number)
{
    /*Checking if the number is smaller than or equal 9 or not*/
    if(au8_number <= NUMBER_9)
    {
        /*Setting the A, B, C and D pins values*/
        mdio_setpinvalue(HSEV_SEG_DECODER_PORT, HSEV_SEG_A_PIN, GET_BIT(au8_number, BIT_0));
        mdio_setpinvalue(HSEV_SEG_DECODER_PORT, HSEV_SEG_B_PIN, GET_BIT(au8_number, BIT_1));
        mdio_setpinvalue(HSEV_SEG_DECODER_PORT, HSEV_SEG_C_PIN, GET_BIT(au8_number, BIT_2));
        mdio_setpinvalue(HSEV_SEG_DECODER_PORT, HSEV_SEG_D_PIN, GET_BIT(au8_number, BIT_3));
    }
    else
    {
        /*Do nothing*/
    }
return;
}

