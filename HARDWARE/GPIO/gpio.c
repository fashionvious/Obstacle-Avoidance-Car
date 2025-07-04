#include "gpio.h"

void gpio_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PA�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//�Ҳ�෢�ź�
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.3
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//ǰ��෢�ź�
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.4
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//���෢�ź�
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//PB8\PB9 AN1-2  PB10\PB11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//PB8\PB9 AN1-2  PB10\PB11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//PB8\PB9 AN1-2  PB10\PB11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;				  
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz							//PB8\PB9 AN1-2  PB10\PB11 BN1-2
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.5
}

void GO(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_8);						 //PB8 �����
	GPIO_SetBits(GPIOB,GPIO_Pin_10);					 //PB10 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);					 //PB9 low
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);				 //PB11 low
	TIM_SetCompare1(TIM3,L);	
	TIM_SetCompare3(TIM3,R);
}

void Left(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_8);						 //PB8 �����
	GPIO_SetBits(GPIOB,GPIO_Pin_11);					 //PB10 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);					 //PB9 low
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);				 //PB11 low
	TIM_SetCompare1(TIM3,L);	
	TIM_SetCompare3(TIM3,R);
}

void Right(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_9);						 //PB8 �����
	GPIO_SetBits(GPIOB,GPIO_Pin_10);					 //PB10 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);					 //PB9 low
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);				 //PB11 low
	TIM_SetCompare1(TIM3,L);	
	TIM_SetCompare3(TIM3,R);
}

void Behind(int L,int R)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_9);						 //PB8 �����
	GPIO_SetBits(GPIOB,GPIO_Pin_11);					 //PB10 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);					 //PB9 low
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);				 //PB11 low
	TIM_SetCompare1(TIM3,L);	
	TIM_SetCompare3(TIM3,R);
}

void Stop()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);
	GPIO_ResetBits(GPIOB,GPIO_Pin_10);
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);
}

