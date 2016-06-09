#include <regx51.h>
void timer0_initialize(void);
unsigned int sp=1843; //100Hz===>9216,????20%=9216*0.2=1843?????
unsigned int sn=7373; //????80%=9216*0.8=7373?????
unsigned int temp;  //????????
void delay(unsigned char b) //?????
{
 unsigned char i,j;
 for(i=0;i<b;i++)
 for(j=0;j<255;j++);
}
void timer0_initialize(void)  //??????0
{
 EA=0;
 IE|=0x82;
 TMOD|=0x01;
 temp=65536-sp;
 TH0=temp/256;
 TL0=temp%256;
 TR0=1;
 P1_0=1;
}
void timer0_isr(void) interrupt TF0_VECTOR using 1 // ????0??PWM?
{
 if(P1_0==1)
 {
 TR0=0;
 temp=65536-sn;
 TH0=temp/256;
 TL0=temp%256;
 TR0=1;
 P1_0=0;
 }
 else
 {
 TR0=0;
 temp=65536-sp;
 TH0=temp/256;
 TL0=temp%256;
 TR0=1;
 P1_0=1;
 }
}
int i=0;
main()
{
 int light[6]={9206,7373,5530,3686,1843,10};
 timer0_initialize();
 P1_0=0;
 while(1) //?????????P2_0~P2_5????PWM???
 {
	for(i=9216;i>=200;i-=50){  	 
		sp=9216-i; //???=9216-???
		delay(10);
	}
	for(i=200;i<9216;i+=50){  	 
		sp=9216-i; //???=9216-???
		delay(10);
  }
 }
}