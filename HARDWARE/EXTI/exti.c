#include "exti.h"

//按键初始化:按键分别接在IO口上，key1:PA0, key2:PB0, key3:PC5，
void exti_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	
	//使能AFIO时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);//选择GPIO管脚用作外部中断线路 对应exti0
	
	//NVIC配置
	//中断优先级分组 分2组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	//key1:EXTI0 NVIC 配置
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3; //子优先级
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;//EXTI0中断通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//IRQ通道使能
	
	NVIC_Init(&NVIC_InitStruct);//根据指定的参数初始化NVIC寄存器
	
	//EXTI配置
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
}
