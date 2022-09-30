#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HPBUTT_cfg.h"
#include "HPBUTT_interface.h"


void hputt_init(u8_t au8_pbNumber){

switch (au8_pbNumber)
{
case PUSH_BUTTON_0:
    mdio_setPinStatus(PB0_PORT,PB0_PIN,INPUT_FLOAT);
    break;

case PUSH_BUTTON_1:
    mdio_setPinStatus(PB1_PORT,PB1_PIN,INPUT_FLOAT);
    break;

case PUSH_BUTTON_2:

    mdio_setPinStatus(PB2_PORT,PB2_PIN,INPUT_FLOAT);
    
    break;

default:
    break;
}

return ;
}


void hputt_getstatus(u8_t au8_pbNumber , u8_t * pu8_PbStatus){

switch (au8_pbNumber)
{
case PUSH_BUTTON_0:
    mdio_getpinvalue(PB0_PORT,PB0_PIN,pu8_PbStatus);
    break;

case PUSH_BUTTON_1:
    mdio_getpinvalue(PB1_PORT,PB1_PIN,pu8_PbStatus);
    break;

case PUSH_BUTTON_2:

    mdio_getpinvalue(PB2_PORT,PB2_PIN,pu8_PbStatus);
    
    break;

default:
    break;
}

}
