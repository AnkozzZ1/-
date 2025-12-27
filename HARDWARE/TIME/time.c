#include "time.h"

void TIM2_Int_Init(u16 arr, u16 psc)//TIME3中断初始化
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1、使能定时器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	//2、初始化定时器，配置ARR,PSC
	TIM_TimeBaseInitStruct.TIM_Period = arr;//定时器周期
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//预分频器
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//没有分频
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);//初始化TIMx的时基单元
	//3、配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置优先级分组2
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;//TIM2中断
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;//主优先级0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;//子优先级3
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//使能TIM2
	NVIC_Init(&NVIC_InitStruct);
	//4、开启定时器中断
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//使能TIM2中断，允许更新中断
	//5、使能定时器
	TIM_Cmd(TIM2, ENABLE);
}

void TIM3_PWM_Init(u16 arr, u16 psc)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;
	
	//1、使能定时器、相关IO口时钟、AFIO时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	
		//3、设置重映射（失能JTAG下载；配置TIM3部分重映射）
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	
	//2、初始化IO口为复用功能输出
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;				  //LED1->PC7 端口配置
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; 		 //复用推挽
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOC, &GPIO_InitStruct);//根据设定参数初始化GPIOB8

	//4、初始化定时器，配置ARR,PSC
	TIM_TimeBaseInitStruct.TIM_Period = arr;//定时器周期
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//预分频器
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//没有分频
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);//初始化TIMx的时基单元
	//5、初始化输出比较参数
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;//比较输出模式
	TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCPolarity_High;//输出极性
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;//比较输出使能
	TIM_OC2Init(TIM3, &TIM_OCInitStruct);
	//6、使能预装载寄存器
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	//7、使能定时器
	TIM_Cmd(TIM3, ENABLE);
}
