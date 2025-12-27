#include "usart.h"

//重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch,FILE *p)  
{
	USART_SendData(USART1,(u8)ch);	 //发送一个字节数据到串口
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);  //等待发送完毕
	return ch;
}

void USART1_Init(void)//USART1初始化：接线：PA9 (TX)、PA10(RX)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1.串口时钟、GPIOA时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	//2.GPIO端口模式设置
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				  //PA9 (TX)
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	    //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA9

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				 //PA10(RX)
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;		  //模拟输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA10
	
	//3.串口参数初始化
	USART_InitStruct.USART_BaudRate = 115200;				//串口波特率
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;			//字长为8位数据格式
	USART_InitStruct.USART_StopBits = USART_StopBits_1;			//一个停止位
	USART_InitStruct.USART_Parity = USART_Parity_No;			//无奇偶校验位
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//无硬件数据流控制
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//收发模式
	USART_Init(USART1, &USART_InitStruct);		//初始化串口1
	
	//4.开启中断并设置NVIC
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);  //开启串口接受中断
	//NVIC 配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //中断优先级分组 分2组
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3; //子优先级
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;//串口1中断通道
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//IRQ通道使能
	
	NVIC_Init(&NVIC_InitStruct);//根据指定的参数初始化NVIC寄存器
	
	//5.使能串口
	USART_Cmd(USART1, ENABLE);
}




//功能：串口1发送一个字符
//参数：temp发送的字符
//返回：无
void uart1_send_char(u8 temp)
{
	USART_SendData(USART1,(u8)temp);      
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
}

//功能：串口1发送字符串
//参数：buf发送的字符串,len字符串的长度
//返回：无
void uart1_send_buff(u8* buf,u32 len)      
{
	u32 i;

	for(i=0;i<len;i++)
	  uart1_send_char(buf[i]);
} 
