#include "bsp.h"

#define LED1_PORT GPIOI
#define LED1_PIN  GPIO_PIN_10

#define LED2_PORT GPIOF
#define LED2_PIN  GPIO_PIN_7

#define LED3_PORT GPIOF
#define LED3_PIN  GPIO_PIN_8

#define LED4_PORT GPIOC
#define LED4_PIN  GPIO_PIN_2



void bsp_led_init(void)
{
 /*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_RESET);
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};


  /*Configure GPIO pin   */
  GPIO_InitStruct.Pin = LED1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED1_PORT, &GPIO_InitStruct);

	  /*Configure GPIO pin   */
  GPIO_InitStruct.Pin = LED2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED2_PORT, &GPIO_InitStruct);
	
	
	  /*Configure GPIO pin   */
  GPIO_InitStruct.Pin = LED3_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED3_PORT, &GPIO_InitStruct);
	
	
	  /*Configure GPIO pin   */
  GPIO_InitStruct.Pin = LED4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED4_PORT, &GPIO_InitStruct);
}

void bsp_led_on(uint8_t _no)
{
	switch (_no)
	{
		case 1:
		{
			HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_RESET);
			break;
		}
		
		case 2:
		{
			HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_RESET);
			break;
		}

		case 3:
		{
			HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_RESET);
			break;
		}

		case 4:
		{
			HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_RESET);
			break;
		}
		default :break;
	}
}


void bsp_led_off(uint8_t _no)
{
	switch (_no)
	{
		case 1:
		{
			HAL_GPIO_WritePin(LED1_PORT, LED1_PIN, GPIO_PIN_SET);
			break;
		}
		
		case 2:
		{
			HAL_GPIO_WritePin(LED2_PORT, LED2_PIN, GPIO_PIN_SET);
			break;
		}

		case 3:
		{
			HAL_GPIO_WritePin(LED3_PORT, LED3_PIN, GPIO_PIN_SET);
			break;
		}

		case 4:
		{
			HAL_GPIO_WritePin(LED4_PORT, LED4_PIN, GPIO_PIN_SET);
			break;
		}
		default :break;
	}
}

