#include "bsp.h"

 /*
	������STM32-V5 �������߷��䣺
		K1 ��      : PI8   (�͵�ƽ��ʾ����)
		K2 ��      : PC13  (�͵�ƽ��ʾ����)
		K3 ��      : PI11  (�͵�ƽ��ʾ����)
		ҡ��UP��   : PH2   (�͵�ƽ��ʾ����)
		ҡ��DOWN�� : PH3   (�͵�ƽ��ʾ����)
		ҡ��LEFT�� : PF11  (�͵�ƽ��ʾ����)
		ҡ��RIGHT��: PG7   (�͵�ƽ��ʾ����)
		ҡ��OK��   : PH15  (�͵�ƽ��ʾ����)
*/


void bsp_key_init(void)
{
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		
		GPIO_InitStruct.Pin  = GPIO_PIN_8;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
}

uint8_t getkey(void)
{
	uint8_t num = 0;
	num =  HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_8);
	return num;
}
