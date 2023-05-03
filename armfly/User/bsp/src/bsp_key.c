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

#define HARD_KEY_NUM	    8	   				/* 实体按键个数 */
#define KEY_COUNT   	 	(HARD_KEY_NUM + 2)	/* 8个独立建 + 2个组合按键 */

/* 使能GPIO时钟 */
#define ALL_KEY_GPIO_CLK_ENABLE() {	\
		__HAL_RCC_GPIOC_CLK_ENABLE();	\
		__HAL_RCC_GPIOF_CLK_ENABLE();	\
	    __HAL_RCC_GPIOH_CLK_ENABLE();	\
		__HAL_RCC_GPIOG_CLK_ENABLE();	\
		__HAL_RCC_GPIOH_CLK_ENABLE();	\
		__HAL_RCC_GPIOI_CLK_ENABLE();	\
	};
typedef struct
{
	GPIO_TypeDef *gpio;
	uint16_t pin;
	uint8_t	ActiveLevel;
}X_GPIO_T;

static const X_GPIO_T s_gpio_list[HARD_KEY_NUM]={
	{GPIOI, GPIO_PIN_8,  0},	/* K1 */
	{GPIOC, GPIO_PIN_13, 0},	/* K2 */
	{GPIOI, GPIO_PIN_11, 0},	/* K3 */
	{GPIOH, GPIO_PIN_2,  0},	/* JOY_U */	
	{GPIOH, GPIO_PIN_3,  0},	/* JOY_D */
	{GPIOF, GPIO_PIN_11, 0},	/* JOY_L */	
	{GPIOG, GPIO_PIN_7,  0},	/* JOY_R */	
	{GPIOH, GPIO_PIN_15, 0},	/* JOY_OK */
 
};
static KEY_T s_tBtn[KEY_COUNT] = {0};
static KEY_FIFO_T s_tKey;		/* 按键FIFO变量,结构体 */


static uint8_t KeyPinActive(uint8_t _id)
{
	uint8_t level;
//	if(s_gpio_list[_id].gpio->IDR & s_gpio_list[_id].pin == 0)
//	{
//		level = 0;
//	}
//	else
//	{
//		level = 1;
//	}
//	
	(s_gpio_list[_id].gpio->IDR & s_gpio_list[_id].pin)?(level = 1):(level = 0);
	if (level == s_gpio_list[_id].ActiveLevel)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*
*********************************************************************************************************
*	函 数 名: IsKeyDownFunc
*	功能说明: 判断按键是否按下。单键和组合键区分。单键事件不允许有其他键按下。
*	形    参: 无
*	返 回 值: 返回值1 表示按下(导通），0表示未按下（释放）
*********************************************************************************************************
*/
static uint8_t IsKeyDownFunc(uint8_t _id)
{
	uint8_t i = 0;
	uint8_t count = 0;
	uint8_t flag = 0;
	
	
	if(_id < HARD_KEY_NUM)
	{
		for (i = 0;i < HARD_KEY_NUM;i++)
		{
			KeyPinActive(_id)?(count++):(count);
			(count == 1)?(flag = 1):(flag = 0);
			return flag;
		}
		
	}
	if(_id == HARD_KEY_NUM + 0)
	{
		if(KeyPinActive(KID_K1) && KeyPinActive(KID_K2))
		{
			return 1;
		}
		return 0;
	}
	if(_id == HARD_KEY_NUM + 1)
	{
		if(KeyPinActive(KID_K2) && KeyPinActive(KID_K3))
		{
			return 1;
		}
		return 0;		
	}
	return 0;
}

static void bsp_InitKeyHard(void);
static void bsp_InitKeyVar(void);
static void bsp_DetectKey(uint8_t i);




void bsp_InitKey(void)
{
	bsp_InitKeyHard();
	bsp_InitKeyVar();
}	

/*
*********************************************************************************************************
*	函 数 名: bsp_InitKeyHard
*	功能说明: 配置按键对应的GPIO
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
static void bsp_InitKeyHard(void)
{
	uint8_t i = 0;
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
		/* 第1步：打开GPIO时钟 */
	ALL_KEY_GPIO_CLK_ENABLE();
	/* 第2步：配置所有的按键GPIO为浮动输入模式(实际上CPU复位后就是输入状态) */
	
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	
	for(i = 0; i < HARD_KEY_NUM; i++)
	{
		GPIO_InitStruct.Pin = s_gpio_list[i].pin;
		HAL_GPIO_Init(s_gpio_list[i].gpio, &GPIO_InitStruct);
	}

}	
/*
*********************************************************************************************************
*	函 数 名: bsp_InitKeyVar
*	功能说明: 初始化按键变量
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
static void bsp_InitKeyVar(void)
{
	uint8_t i;
	s_tKey.Read = 0;
	s_tKey.Read2 = 0;
	s_tKey.Write = 0;
	/* 给每个按键结构体成员变量赋一组缺省值 */
	for(i = 0; i < KEY_COUNT ;i++)
	{
		s_tBtn[i].LongTime = KEY_LONG_TIME;/* 长按时间 0 表示不检测长按键事件 */
		s_tBtn[i].Count = KEY_FILTER_TIME / 2;		/* 计数器设置为滤波时间的一半 */
		s_tBtn[i].State = 0;							/* 按键缺省状态，0为未按下 */
		s_tBtn[i].RepeatSpeed = 0;						/* 按键连发的速度，0表示不支持连发 */
		s_tBtn[i].RepeatCount = 0;						/* 连发计数器 */		
	}
	/* 如果需要单独更改某个按键的参数，可以在此单独重新赋值 */
	/* 摇杆上下左右，支持长按1秒后，自动连发 */

	bsp_SetKeyParam(KID_JOY_U, 100, 6);
	bsp_SetKeyParam(KID_JOY_D, 100, 6);
	bsp_SetKeyParam(KID_JOY_L, 100, 6);
	bsp_SetKeyParam(KID_JOY_R, 100, 6);	
	
}	



void bsp_KeyScan10ms(void);
void bsp_PutKey(uint8_t _KeyCode);
uint8_t bsp_GetKey(void);
uint8_t bsp_GetKey2(void);
uint8_t bsp_GetKeyState(KEY_ID_E _ucKeyID);
void bsp_SetKeyParam(uint8_t _ucKeyID, uint16_t _LongTime, uint8_t  _RepeatSpeed);
void bsp_ClearKey(void);