#include "key.h"
#include "delay.h"
#include "stm32f10x_it.h"

void key_Init(void)//按键初始化:按键分别接在IO口上，key1:PA0, key2:PB0, key3:PC5，
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC, ENABLE);	 //使能GPIOA,GPIOB,GPIOC时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //KEY1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		//设置成下拉输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //初始化GPIOA0

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //KEY2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //设置成上拉输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);					 //初始化GPIOB0

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;        //KEY3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;     //设置成上拉输入
  GPIO_Init(GPIOC, &GPIO_InitStructure);           //初始化GPIOC5
}

//按键处理函数
//返回按键值
//1，KEY1按下
//2，KEY2按下
//3，KEY3按下 
void key_Scan(void)
{
//	if (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1)//key1按下
//	{
//		delay_ms(20);//用于按键消抖
//		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) == 1);//等待按键松开
//		delay_ms(20);
//		KeyNum = 1;//赋值给KeyNum变量
//	}
//	
	if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0)//key2按下
	{
		delay_ms(20);//用于按键消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0);//等待按键松开
		delay_ms(20);
		KeyNum = 2;//赋值给KeyNum变量
	}
	
	if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5) == 0)//key3按下
	{
		delay_ms(20);//用于按键消抖
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5) == 0);//等待按键松开
		delay_ms(20);
		KeyNum = 3;//赋值给KeyNum变量
	}
}

