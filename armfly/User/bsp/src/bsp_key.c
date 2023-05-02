#include "bsp.h"

/*

*	说    明 : 扫描独立按键，具有软件滤波机制，具有按键FIFO。可以检测如下事件：
*				(1) 按键按下
*				(2) 按键弹起
*				(3) 长按键
*				(4) 长按时自动连发

*/

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
#define HARD_KEY_NUM 8 /*按键数量8*/
#define KEY_COUNT (HARD_KEY_NUM+2)

/*使能GPIO 时钟*/
 #define ALL_KEY_GPIO_CLK_ENABLE() {
 
   /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

 }
 
 /*依次定义GPIO*/
 typedef struct
 {
	 GPIO_TypeDef * gpio;
	 uint16_t pin;
	 uint8_t ActiveLevel;
 }X_GPIO_T;
 
 /*GPIO 和 Pin定义*/
 static const X_GPIO_T s_gpio_list[HARD_KEY_NUM] = {
 
	{GPIOI,	GPIO_PIN_8,		0},
	{GPIOC,	GPIO_PIN_13,	0},
	{GPIOI,	GPIO_PIN_11,	0},
	{GPIOH,	GPIO_PIN_2,		0},
	{GPIOH,	GPIO_PIN_3,		0},
	{GPIOF,	GPIO_PIN_11,	0},
	{GPIOG,	GPIO_PIN_7,		0},
	{GPIOH,	GPIO_PIN_15,	0}, 
 };
 
 