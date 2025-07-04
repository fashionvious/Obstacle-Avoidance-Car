#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
#include "gpio.h"
#include "read.h"
#include "timer.h"
#include "ai.h"
//电机初始化的两个引脚未写入
//TIM3_CH3->PB0 右侧轮
//TIM3_CH1->PA6 左侧轮

//TIM2_CH1->PA0 前测距 GPIOA4

//TIM5_CH2->PA1 左测距 GPIOA5

//TIM4_CH1->PB6 右测距 GPIOA3

 int main(void)
 {	
//	u8 t;
	float	zuo,qian,you;
	delay_init();	    	 //延时函数初始化	  
	gpio_Init();
	
	TIM2_Cap_Init(0XFFFF,72-1);		//以1Mhz的频率计数 
	TIM4_Cap_Init(0XFFFF,72-1);
	TIM5_Cap_Init(0XFFFF,72-1);
	 
	TIM3_PWM_Init(899,0);		//不分频。PWM频率=72000/(899+1)=80Khz
	TIM3_2_PWM_Init(899,0);	//不分频。PWM频率=72000/(899+1)=80Khz

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	uart_init(9600);	 //串口初始化为9600
   	while(1)
	{	

/********读取前、右、左距离*******/		
		qian=read_qian();
		you=read_you();
		zuo=read_zuo();		
		printf("\n\r前=%f\n\r",qian);
		printf("\n\r右=%f\n\r",you);
		printf("\n\r左=%f\n\r",zuo);
		
		calculate(qian,zuo,you);


	} 
}
