#include "usart.h"




uint8_t usartData[10];
uint16_t button;

uint16_t usartCounter = 0;
uint16_t numOfBytes;


/*

void send_to_usart(uint8_t data) {
	while (!(USART1->SR & USART_SR_TC));
	USART1->DR=data;
}

*/



