/*
     �˿ڲ�����ʵ����ˮ��
��һ��������˿�
�ڶ���������Ҫ���ö�����ת��Ϊʮ�����ƣ����ð��Ķ�һ����
��������д��ˮ״̬�ö����Ʊ�ʾ
���Ĳ�����������״̬ת��Ϊʮ�����Ʊ�ʾ
���岽��������������
*/
/*
    ��һ������ԭ��ͼ ���ǽ�LED�ƽ���P1�˿���
	�������Ƕ���˿�Ϊ��#denfine led P1
*/

/*���鷽��*/
#include "reg52.h"//51��Ƭ����ͷ�ļ�
#include "intrins.h" 

sbit key1 = P2^0;
sbit key2 = P2^2;
sbit key3 = P2^4;

unsigned char led1[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//������8���Ƶ�״̬1
unsigned char led2[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};//������8���Ƶ�״̬2
unsigned char led3[4] = {0x80,0x40,0x20,0x10};//������8���Ƶ�״̬3
/*�˿ڲ���*/

void delay_ms(int t)
{
   int i = 0;
	 while(t--)
	 {
	    i =128;
		  while(i--)
			{
			   _nop_();  /*�õ�__nop_() �õ�intrins.hͷ�ļ�*/
			}
	 }
}

unsigned char read_key(void)
{
	  static unsigned int num;
    if(key1 == 0)
		{
		   delay_ms(2);
			 if(key1 == 0)
			 {
				  num =1; 
			 }
		}
		if(key2 == 0)
		{
		   delay_ms(2);
			 if(key2 == 0)
			 {
				  num =2; 
			 }
		}
		if(key3 == 0)
		{
		   delay_ms(2);
			 if(key3 == 0)
			 {
				  num =3; 
			 }
		}
		return num;
}
void main(void)
{
	 int i = 0,value =0;
	 P1 = 0X00;
   while(1)
	 {
       value =read_key();
		   if(value == 1)
			 {
			    for(i = 0;i<8;i++)
				  {
					    P1 = led1[i];
						  delay_ms(500);
					}
			 }
			 if(value == 2)
			 {
			    for(i = 0;i<8;i++)
				  {
					    P1 = led2[i];
						  delay_ms(500);
					}
			 }
			 if(value == 3)
			 {
			    for(i = 0;i<4;i++)
				  {
					    P1 = led3[i];
						  delay_ms(500);
					}
			 }
	 }
}