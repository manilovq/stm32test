#include "mcu_ini.h"

//------------------------------------------------

void LEDs_ini(void) {
  GPIO_InitTypeDef GPIO_Init_LED;
	 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
}

//-------------------------------------------------

void Button_ini(void) {
  GPIO_InitTypeDef GPIO_Init_Button;
	 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_Init_Button.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init_Button.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init_Button.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Button.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_Button.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_Init_Button);
}

//-------------------------------------------------

void Usart1_ini(void) {
	GPIO_InitTypeDef port_usart1;
	USART_InitTypeDef usart;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	port_usart1.GPIO_Pin = GPIO_Pin_6; //Tx
	port_usart1.GPIO_Speed = GPIO_Speed_50MHz;
	port_usart1.GPIO_Mode = GPIO_Mode_AF;
	port_usart1.GPIO_OType = GPIO_OType_PP;
	port_usart1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	USART_StructInit(&usart);
	GPIO_PinAFConfig(GPIOB, 6, GPIO_AF_USART1);
	
	usart.USART_BaudRate = 9600;
  usart.USART_WordLength = USART_WordLength_8b;
  usart.USART_StopBits = USART_StopBits_1;
  usart.USART_Parity = USART_Parity_No ;
  usart.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
	
	
	GPIO_Init(GPIOB, &port_usart1);
	USART_Init(USART1, &usart);
	USART_Cmd(USART1, ENABLE);
}
