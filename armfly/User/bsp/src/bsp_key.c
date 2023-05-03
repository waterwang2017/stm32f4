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

#define HARD_KEY_NUM	    8	   				/* ʵ�尴������ */
#define KEY_COUNT   	 	(HARD_KEY_NUM + 2)	/* 8�������� + 2����ϰ��� */

/* ʹ��GPIOʱ�� */
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
static KEY_FIFO_T s_tKey;		/* ����FIFO����,�ṹ�� */


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
*	�� �� ��: IsKeyDownFunc
*	����˵��: �жϰ����Ƿ��¡���������ϼ����֡������¼������������������¡�
*	��    ��: ��
*	�� �� ֵ: ����ֵ1 ��ʾ����(��ͨ����0��ʾδ���£��ͷţ�
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
*	�� �� ��: bsp_InitKeyHard
*	����˵��: ���ð�����Ӧ��GPIO
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_InitKeyHard(void)
{
	uint8_t i = 0;
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
		/* ��1������GPIOʱ�� */
	ALL_KEY_GPIO_CLK_ENABLE();
	/* ��2�����������еİ���GPIOΪ��������ģʽ(ʵ����CPU��λ���������״̬) */
	
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
*	�� �� ��: bsp_InitKeyVar
*	����˵��: ��ʼ����������
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void bsp_InitKeyVar(void)
{
	uint8_t i;
	s_tKey.Read = 0;
	s_tKey.Read2 = 0;
	s_tKey.Write = 0;
	/* ��ÿ�������ṹ���Ա������һ��ȱʡֵ */
	for(i = 0; i < KEY_COUNT ;i++)
	{
		s_tBtn[i].LongTime = KEY_LONG_TIME;/* ����ʱ�� 0 ��ʾ����ⳤ�����¼� */
		s_tBtn[i].Count = KEY_FILTER_TIME / 2;		/* ����������Ϊ�˲�ʱ���һ�� */
		s_tBtn[i].State = 0;							/* ����ȱʡ״̬��0Ϊδ���� */
		s_tBtn[i].RepeatSpeed = 0;						/* �����������ٶȣ�0��ʾ��֧������ */
		s_tBtn[i].RepeatCount = 0;						/* ���������� */		
	}
	/* �����Ҫ��������ĳ�������Ĳ����������ڴ˵������¸�ֵ */
	/* ҡ���������ң�֧�ֳ���1����Զ����� */

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