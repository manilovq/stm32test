#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"
#include "keyboard.h"

#include "stm32f4xx.h"
#define RED_ON()       GPIO_SetBits(GPIOD, GPIO_Pin_14)
#define RED_OFF()      GPIO_ResetBits(GPIOD, GPIO_Pin_14)
#define BLUE_ON()      GPIO_SetBits(GPIOD, GPIO_Pin_15)
#define BLUE_OFF()     GPIO_ResetBits(GPIOD, GPIO_Pin_15)
#define GREEN_ON()     GPIO_SetBits(GPIOD, GPIO_Pin_12)
#define GREEN_OFF()    GPIO_ResetBits(GPIOD, GPIO_Pin_12)
#define ORANGE_ON()    GPIO_SetBits(GPIOD, GPIO_Pin_13)
#define ORANGE_OFF()   GPIO_ResetBits(GPIOD, GPIO_Pin_13)
#define DELAY          500
#define DELAY_BUTTON   10

#define MODE_RED       0
#define MODE_BLUE      1
#define MODE_GREEN     2
#define MODE_ORANGE    3

#define BUTTON_READ()        GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)
#define KEYBOARD_1C_READ()  (GPIO_ReadInputData(GPIOA) & 0x07)



#endif

