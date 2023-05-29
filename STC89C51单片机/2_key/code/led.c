/*
     端口操作来实现流水灯
第一步：定义端口
第二步：必须要懂得二进制转换为十六进制（采用八四二一法则）
第三步：写流水状态用二进制表示
第四步：将二进制状态转换为十六进制表示
第五步：基础代码流程
*/
/*
    第一步：看原理图 我们将LED灯接在P1端口上
	所以我们定义端口为：#denfine led P1
*/

/*数组方法*/
#include "reg52.h"//51单片机的头文件
#include "intrins.h" 

sbit key1 = P2^0;
sbit key2 = P2^2;
sbit key3 = P2^4;

unsigned char led1[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//定义了8个灯的状态1
unsigned char led2[8] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};//定义了8个灯的状态2
unsigned char led3[4] = {0x80,0x40,0x20,0x10};//定义了8个灯的状态3
/*端口操作*/

void delay_ms(int t)
{
   int i = 0;
	 while(t--)
	 {
	    i =128;
		  while(i--)
			{
			   _nop_();  /*用到__nop_() 用到intrins.h头文件*/
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