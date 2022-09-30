/*Header file guard*/
#ifndef  __MDIO_interface_H__
#define  __interface_H __


/*************************************************************************************************************************/
/*                                                Interfacing Macros                                                     */
/*************************************************************************************************************************/


#define PORTA          (0)  
#define PORTB          (1)  
#define PORTC          (2)  
#define PORTD          (3) 

#define PIN0          (0b00000001)
#define PIN1          (0b00000010)
#define PIN2          (0b00000100)
#define PIN3          (0b00001000)
#define PIN4          (0b00010000)
#define PIN5          (0b00100000)
#define PIN6          (0b01000000)
#define PIN7          (0b10000000)

#define INPUT_FLOAT  (0)
#define INPUT_PULLUP  (1)
#define OUTPUT         (2)

#define LOW  (0)
#define HIGH  (1)

/*************************************************************************************************************************/
/*                                                Functions Prototybye                                                   */
/*************************************************************************************************************************/


/**
 * @brief this function is responsible 
 * 
 * @param au8_port 
 * @param au8_pin 
 * @param au8_status 
 */
void mdio_setPinStatus(u8_t au8_port , u8_t au8_pin , u8_t au8_status);
void mdio_setpinvalue(u8_t au8_port , u8_t au8_pin ,u8_t au8_value );
void mdio_togglepinvalue(u8_t au8_port , u8_t au8_pin);
void mdio_getpinvalue(u8_t au8_port , u8_t au8_pin , u8_t* pu8_pinvalue);


#endif