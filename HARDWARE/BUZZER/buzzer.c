#include "buzzer.h"
	
//蜂鸣器初始化
void BUZZER_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能GPIOB端口时钟

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				  //BUZZER-->PB1 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB1
	GPIO_SetBits(GPIOB,GPIO_Pin_1);						 //PB1输出高
}
