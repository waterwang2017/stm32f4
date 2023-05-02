#include "bsp.h"

 /* GPIO Ports Clock Enable */
 #define gpio_clock_all_eable() {
 
   /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

 }


void bsp_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
	gpio_clock_all_eable();



}




