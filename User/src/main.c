#include "main.h"


uint16_t delay_count = 0;
uint8_t Mode = 0;
uint16_t Mode_count = 0;
uint8_t Mode_new = 0;

uint8_t Button_count=0;
uint8_t Button_state=0;

uint8_t Button_push=0;

//------------------------------------------------

void SysTick_Handler(void) { //1 ms
  if (delay_count > 0) {
		delay_count--;
	}	
	
}

//------------------------------------------------

void delay_ms(uint16_t delay_temp) {
  delay_count = delay_temp;
	while(delay_count) {}
}


//------------------------------------------------
int main(void) {
	
	LEDs_ini();
	Keyboard_ini();
	Usart1_ini();
  SysTick_Config(SystemCoreClock/1000);//1 ms


	while(1) {
		
		
		
		// first column scan
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		GPIO_SetBits(GPIOA, GPIO_Pin_4 | GPIO_Pin_5);
	
		if ((KEYBOARD_1C_READ() & 1) == 0) {
			Button_push=1;
			RED_ON();
			USART_SendData(USART1, 'r');
			while ((KEYBOARD_1C_READ() & 1) == 0);
			
		}
		if ((KEYBOARD_1C_READ() & 2) == 0) {
			Button_push=1;
			GREEN_ON();
			USART_SendData(USART1, 'g');
			while ((KEYBOARD_1C_READ() & 2) == 0);
		}
		if ((KEYBOARD_1C_READ() & 4) == 0) {
			Button_push=1;
			BLUE_ON();
			USART_SendData(USART1, 'b');
			while ((KEYBOARD_1C_READ() & 4) == 0);
		}
		
		if (Button_push == 1) {
			delay_ms(DELAY);
			Button_push=0;
		}
		GREEN_OFF();
		BLUE_OFF();
		RED_OFF();
		ORANGE_OFF();
		
		// second column scan
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);
		GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_5);
	  
		if ((KEYBOARD_1C_READ() & 1) == 0) {
			Button_push=1;
			RED_ON();
			ORANGE_ON();
		}
		if ((KEYBOARD_1C_READ() & 2) == 0) {
			Button_push=1;
			GREEN_ON();
			ORANGE_ON();
		}
		if ((KEYBOARD_1C_READ() & 4) == 0) {
			Button_push=1;
			BLUE_ON();
			ORANGE_ON();
		}
		
		if (Button_push == 1) {
			delay_ms(DELAY);
			Button_push=0;
		}
		GREEN_OFF();
		BLUE_OFF();
		RED_OFF();
		ORANGE_OFF();
		
		// third column scan
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4);
		if ((KEYBOARD_1C_READ() & 1) == 0) {
			Button_push=1;
			RED_ON();
			ORANGE_ON();
			GREEN_ON();
		}
		if ((KEYBOARD_1C_READ() & 2) == 0) {
			Button_push=1;
			GREEN_ON();
			ORANGE_ON();
			BLUE_ON();
		}
		if ((KEYBOARD_1C_READ() & 4) == 0) {
			Button_push=1;
			BLUE_ON();
			ORANGE_ON();
			RED_ON();
		}
		
		if (Button_push == 1) {
			delay_ms(DELAY);
			Button_push=0;
		}
		GREEN_OFF();
		BLUE_OFF();
		RED_OFF();
		ORANGE_OFF();
	}
}
