/**
 * @file LBIT_MATH.h
 * @author Tarek Hisham (tarekhesham2017@gmail.com)
 * @brief  this file contains the bits macros
 * @version 1.0
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*Header file guard*/
#ifndef  __LBIT_MATH_R__
#define  __LBIT_MATH_R__


 /*BIt manipulation*/
#define SET_BIT(VAR,N_BIT)     VAR|=(1<<N_BIT)
#define CLEAR_BIT(VAR,N_BIT)   VAR&=(~(1<<N_BIT))                                
#define TOGGLE_BIT(VAR,N_BIT)  VAR^=(1<<N_BIT)
#define GET_BIT(VAR,N_BIT)     ((VAR>>N_BIT) & 0x1) 


#endif