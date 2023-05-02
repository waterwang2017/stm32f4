#include "bsp.h"

 /*
	安富莱STM32-V5 按键口线分配：
		K1 键      : PI8   (低电平表示按下)
		K2 键      : PC13  (低电平表示按下)
		K3 键      : PI11  (低电平表示按下)
		摇杆UP键   : PH2   (低电平表示按下)
		摇杆DOWN键 : PH3   (低电平表示按下)
		摇杆LEFT键 : PF11  (低电平表示按下)
		摇杆RIGHT键: PG7   (低电平表示按下)
		摇杆OK键   : PH15  (低电平表示按下)
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
