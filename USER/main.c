#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
#include "gpio.h"
#include "read.h"
#include "timer.h"
#include "ai.h"
//�����ʼ������������δд��
//TIM3_CH3->PB0 �Ҳ���
//TIM3_CH1->PA6 �����

//TIM2_CH1->PA0 ǰ��� GPIOA4

//TIM5_CH2->PA1 ���� GPIOA5

//TIM4_CH1->PB6 �Ҳ�� GPIOA3

 int main(void)
 {	
//	u8 t;
	float	zuo,qian,you;
	delay_init();	    	 //��ʱ������ʼ��	  
	gpio_Init();
	
	TIM2_Cap_Init(0XFFFF,72-1);		//��1Mhz��Ƶ�ʼ��� 
	TIM4_Cap_Init(0XFFFF,72-1);
	TIM5_Cap_Init(0XFFFF,72-1);
	 
	TIM3_PWM_Init(899,0);		//����Ƶ��PWMƵ��=72000/(899+1)=80Khz
	TIM3_2_PWM_Init(899,0);	//����Ƶ��PWMƵ��=72000/(899+1)=80Khz

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
   	while(1)
	{	

/********��ȡǰ���ҡ������*******/		
		qian=read_qian();
		you=read_you();
		zuo=read_zuo();		
		printf("\n\rǰ=%f\n\r",qian);
		printf("\n\r��=%f\n\r",you);
		printf("\n\r��=%f\n\r",zuo);
		
		calculate(qian,zuo,you);


	} 
}
