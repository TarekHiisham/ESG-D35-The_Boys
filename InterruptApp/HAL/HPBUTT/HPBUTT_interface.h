/*Header file guard*/
#ifndef __HPBUTT_INTERFACE_H__
#define __HPBUTT_INTERFACE_H__



#define PUSH_BUTTON_0       (0)
#define PUSH_BUTTON_1       (1)
#define PUSH_BUTTON_2       (2)



void hputt_init(u8_t au8_pbNumber);
void hputt_getstatus(u8_t au8_pbNumber , u8_t * pu8_PbStatus);



#endif /*__HLED_INTERFACE_H__*/