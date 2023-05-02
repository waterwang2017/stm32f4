#include "bsp.h"

/*

*	˵    �� : ɨ�������������������˲����ƣ����а���FIFO�����Լ�������¼���
*				(1) ��������
*				(2) ��������
*				(3) ������
*				(4) ����ʱ�Զ�����

*/

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
#define HARD_KEY_NUM 8 /*��������8*/
#define KEY_COUNT (HARD_KEY_NUM+2)

/*ʹ��GPIO ʱ��*/
 #define ALL_KEY_GPIO_CLK_ENABLE() {
 
   /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

 }
 
 /*���ζ���GPIO*/
 typedef struct
 {
	 GPIO_TypeDef * gpio;
	 uint16_t pin;
	 uint8_t ActiveLevel;
 }X_GPIO_T;
 
 /*GPIO �� Pin����*/
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
 
 