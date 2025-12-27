#ifndef __LED_H
#define __LED_H	 
#include "sys.h"


#define LED1 PAout(8)// PA8
#define LED2 PCout(7)// PC7
#define LED3 PCout(6)// PC6

#define LED1_ON (LED1=0)//打开LED1
#define LED1_OFF (LED1=1)//关闭LED1
#define LED2_ON (LED2=0)//打开LED2
#define LED2_OFF (LED2=1)//关闭LED2
#define LED3_ON (LED3=0)//打开LED3
#define LED3_OFF (LED3=1)//关闭LED3

void LED_Init(void);//LED初始化

		 				    
#endif
