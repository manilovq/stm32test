#include "stm32f4xx.h"
#define RED_ON()     GPIO_SetBits(GPIOD, GPIO_Pin_14)
#define RED_OFF()    GPIO_ResetBits(GPIOD, GPIO_Pin_14)
#define BLUE_ON()    GPIO_SetBits(GPIOD, GPIO_Pin_15)
#define BLUE_OFF()   GPIO_ResetBits(GPIOD, GPIO_Pin_15)
#define GREEN_ON()   GPIO_SetBits(GPIOD, GPIO_Pin_12)
#define GREEN_OFF()  GPIO_ResetBits(GPIOD, GPIO_Pin_12)
#define ORANGE_ON()  GPIO_SetBits(GPIOD, GPIO_Pin_13)
#define ORANGE_OFF() GPIO_ResetBits(GPIOD, GPIO_Pin_13)

uint16_t delay_count = 0;

void SysTick_Handler(void) { //1 ms
  if (delay_count > 0) {
		delay_count--;
	}
}

void delay_ms(uint16_t delay_temp) {
  delay_count = delay_temp;
	while(delay_count) {}
}

int main(void) {

	GPIO_InitTypeDef GPIO_Init_LED;
	 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	SysTick_Config(SystemCoreClock/1000);//1 ms
	
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
	
	
	while(1) {
		
		RED_ON();
		ORANGE_OFF();
		delay_ms(500);
		BLUE_ON();
		RED_OFF();
		delay_ms(500);
	  GREEN_ON();	
		BLUE_OFF();
		delay_ms(500);
		ORANGE_ON();
		GREEN_OFF();
		delay_ms(500);
		
	}
}
