#include "led.h"
	
//LED初始化
void LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	 //使能GPIOA,GPIOC端口时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				  //LED1-->PA8 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA8
  GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PA8输出高

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //LED2-->PC7 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC7
  GPIO_SetBits(GPIOC,GPIO_Pin_7);						 //PD2输出高


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;        //LED3-->PC6 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    //IO口速度为50MHz
  GPIO_Init(GPIOC, &GPIO_InitStructure);           //根据设定参数初始化GPIOC6
  GPIO_SetBits(GPIOC,GPIO_Pin_6);            //PB12输出高
}
