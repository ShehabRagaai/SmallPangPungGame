/********************************************************************************/
/********************************************************************************/
/*****************       Aathur:Shehab Ahmed Ragaai          ********************/
/*****************       Layer:MCAL                          ********************/
/*****************       SWC:EXTI                            ********************/
/*****************       version:1.00                        ********************/
/********************************************************************************/
/********************************************************************************/

#ifndef EXTI_REGISTER_H_

#define EXTI_REGISTER_H_


#define  MCUCR     *((volatile u8*)0X55)
#define MCUCR_ISC00   0
#define MCUCR_ISC01   1
#define MCUCR_ISC10   2
#define MCUCR_ISC11   3

#define MCUCSR    *((volatile u8*)0X54)
#define MCUCSR_ISC2   6

#define GICR    *((volatile u8*)0X5B)
#define GICR_INT1    7
#define GICR_INT0    6
#define GICR_INT2    5

#define GIFR  *((volatile u8*)0X5A)

 

#endif
