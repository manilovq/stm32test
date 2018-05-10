#include "main.h"


uint16_t delay_count = 0;
uint8_t Mode = 0;
uint16_t Mode_count = 0;
uint8_t Mode_new = 0;

//------------------------------------------------

void SysTick_Handler(void) { //1 ms
  if (delay_count > 0) {
		delay_count--;
	}
	if (Mode_count > 0) {
	  Mode_count--;
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
	Mode_count = DELAY;
	Mode = MODE_RED;
	
	
	while(1) {
		if (Mode == MODE_RED) {
			if (Mode_new == 1) {
			  Mode_count = DELAY;
				RED_ON();
				Mode_new = 0;
			}
				
			if (Mode_count == 0) {
				RED_OFF();
			  Mode = MODE_BLUE;
				Mode_new = 1;
			}
		}
		else if (Mode == MODE_BLUE) {
			if (Mode_new == 1) {
				Mode_count = DELAY;
			  BLUE_ON();
				Mode_new = 0;
			}
			
			if (Mode_count == 0) {
			  Mode = MODE_GREEN;
				Mode_count = DELAY;
				BLUE_OFF();
				Mode_new = 1;
			}
		}
		else if (Mode == MODE_GREEN) {
			
			if (Mode_new == 1) {
			  Mode_count = DELAY;
				GREEN_ON();
				Mode_new = 0;
			}
			if (Mode_count == 0) {
				GREEN_OFF();
			  Mode = MODE_ORANGE;
				Mode_count = DELAY;
				Mode_new = 1;
			}
		}
		else if (Mode == MODE_ORANGE) {
			if (Mode_new == 1) {
			  Mode_count = DELAY;
				ORANGE_ON();
				Mode_new = 0;
			}
			if (Mode_count == 0) {
				ORANGE_OFF();
			  Mode = MODE_RED;
				Mode_count = DELAY;
				Mode_new = 1;
			}
		}
/*
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
	*/	
	}
}
