#ifndef __BUZZER_H
#define __BUZZER_H	 
#include "sys.h"


#define BUZZER PBout(1)// PB1	

#define BUZZER_ON (BUZZER=0)//打开
#define BUZZER_OFF (BUZZER=1)//关闭

void BUZZER_Init(void);//LED初始化

		 				    
#endif
