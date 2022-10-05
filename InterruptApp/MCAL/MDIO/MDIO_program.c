#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "MDIO_private.h"
#include "MDIO_interface.h"

#define NUMBER_OF_PORTS       (4)


/*DDr Array*/
static volatile u8_t* garr_ddrArray[NUMBER_OF_PORTS] = {MDIO_DDRA_ADDRESS ,MDIO_DDRB_ADDRESS , MDIO_DDRC_ADDRESS ,MDIO_DDRD_ADDRESS};
/*ports Array*/
static volatile u8_t* garr_portArray[NUMBER_OF_PORTS] = {MDIO_PORTA_ADDRESS ,MDIO_PORTB_ADDRESS , MDIO_PORTC_ADDRESS ,MDIO_PORTD_ADDRESS};
/*pins Array*/
static volatile u8_t* garr_pinArray[NUMBER_OF_PORTS] = {MDIO_PINA_ADDRESS ,MDIO_PINB_ADDRESS , MDIO_PINC_ADDRESS ,MDIO_PIND_ADDRESS};


void mdio_setPinStatus(u8_t au8_port , u8_t au8_pin , u8_t au8_status)
{
    switch (au8_status)
    {
    case INPUT_FLOAT:

        *garr_ddrArray[au8_port] &= ~(au8_pin) ;

        break;
    
    case INPUT_PULLUP:

        *garr_ddrArray[au8_port] &= ~(au8_pin) ;

        *garr_portArray[au8_port] |= (au8_pin) ;
        
        break;
    case OUTPUT:
        
        *garr_ddrArray[au8_port]  |= (au8_pin) ;

        break;
    
    default:
        break;  
    }
 
    
    return ;
}

void mdio_setpinvalue(u8_t au8_port , u8_t au8_pin ,u8_t au8_value ){
    
    switch(au8_value)
    {
        /*In case of LOW*/
        case LOW:

            /*Clearing the specified pins in PORTx register*/
            *garr_portArray[au8_port] &= ~(au8_pin);

            /*Breaking from this case*/
            break;

        /*In case of input HIGH*/
        case HIGH:

            /*Setting the specified pins in PORTx register*/
            *garr_portArray[au8_port] |= (au8_pin);

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

void mdio_togglepinvalue(u8_t au8_port , u8_t au8_pin){

*garr_portArray[au8_port] ^= (au8_pin) ;

return ;
}

void mdio_getpinvalue(u8_t au8_port , u8_t au8_pin , u8_t* pu8_pinvalue){

    if((*garr_pinArray[au8_port] & au8_pin) == LOW)
    {
        *pu8_pinvalue = LOW ;
    }
    else{
        *pu8_pinvalue = HIGH ;
    }

    return ;
}