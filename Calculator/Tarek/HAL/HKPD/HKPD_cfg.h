/*Header file guard*/
#ifndef __HKPD_CFG_H__
#define __HKPD_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/
#define KPD_NUM_ROWS    (4)
#define KPD_NUM_COLS    (4)

/*KeyPad Mapping configurations*/
#define KEYPAD_MAPPING  {                        \
                            {'7','8','9','/'},   \
                            {'4','5','6','x'},   \
                            {'1','2','3','-'},   \
                            {'O','0','=','+'}    \
                        }

#define KPD_PORT    (PORTD)

#define KPD_ROW0    (PIN0)
#define KPD_ROW1    (PIN1)
#define KPD_ROW2    (PIN2)
#define KPD_ROW3    (PIN3)
#define KPD_COL0    (PIN4)
#define KPD_COL1    (PIN5)
#define KPD_COL2    (PIN6)
#define KPD_COL3    (PIN7)

#define KPD_DEFAULT_VALUE   (0)




#endif /*__HLCD_CFG_H__*/