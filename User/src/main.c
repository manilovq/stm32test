#include "main.h"


uint16_t delay_count = 0;

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
  SysTick_Config(SystemCoreClock/1000);//1 ms
	
	
	while(1) {
		
		RED_OFF();
		ORANGE_ON();
		delay_ms(DELAY);
		GREEN_ON();
		ORANGE_OFF();
		delay_ms(DELAY);
	  GREEN_OFF();	
		BLUE_ON();
		delay_ms(DELAY);
		RED_ON();
		BLUE_OFF();
		delay_ms(DELAY);
		
	}
}
