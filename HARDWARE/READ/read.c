#include "read.h"
#include "sys.h"
#include "delay.h"
#include "pwm.h"
#include "timer.h"


extern u8  TIM2CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u16 TIM2CH1_CAPTURE_VAL;	//���벶��ֵ
extern u8  TIM4CH1_CAPTURE_STA;	//���벶��״̬		    				
extern u16 TIM4CH1_CAPTURE_VAL;	//���벶��ֵ
extern u8  TIM5CH2_CAPTURE_STA;	//���벶��״̬		    				
extern u16 TIM5CH2_CAPTURE_VAL;	//���벶��ֵ
 
//PA4 ������ǰ���ϰ�����
float read_qian()
{
	float temp;
	
	 GPIO_SetBits(GPIOA,GPIO_Pin_4);						 //PA.4 �����
	 delay_us(20);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_4);						 //PA.4 �����
	 delay_ms(20);
		 
		if(TIM2CH1_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
			temp=TIM2CH1_CAPTURE_STA&0X3F;
			temp*=65536;					//���ʱ���ܺ�
			temp+=TIM2CH1_CAPTURE_VAL;		//�õ��ܵĸߵ�ƽʱ��
			temp=temp*170*0.0001;
			
 			TIM2CH1_CAPTURE_STA=0;			//������һ�β���
			return temp;
 		}
		else return 99;

}
float read_you()
{
	float temp1;
	
	 GPIO_SetBits(GPIOA,GPIO_Pin_3);						 //PA.3 �����
	 delay_us(20);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_3);						 //PA.3 �����
	 delay_ms(20);
		 
		if(TIM4CH1_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
			temp1=TIM4CH1_CAPTURE_STA&0X3F;
			temp1*=65536;					//���ʱ���ܺ�
			temp1+=TIM4CH1_CAPTURE_VAL;		//�õ��ܵĸߵ�ƽʱ��
			temp1=temp1*170*0.0001;
			
 			TIM4CH1_CAPTURE_STA=0;			//������һ�β���
			return temp1;
 		}
		else return 99;

}

float read_zuo()
{
	float temp2;
	
	 GPIO_SetBits(GPIOA,GPIO_Pin_5);						 //PA.5 �����
	 delay_us(20);
	 GPIO_ResetBits(GPIOA,GPIO_Pin_5);						 //PA.5 �����
	 delay_ms(20);
		 
		if(TIM5CH2_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
			temp2=TIM5CH2_CAPTURE_STA&0X3F;
			temp2*=65536;					//���ʱ���ܺ�
			temp2+=TIM5CH2_CAPTURE_VAL;		//�õ��ܵĸߵ�ƽʱ��
			temp2=temp2*170*0.0001;
			
 			TIM5CH2_CAPTURE_STA=0;			//������һ�β���
			return temp2;
 		}
		else return 99;

}

