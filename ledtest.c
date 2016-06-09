#include <regx51.h>
//void timer0_initialize(void);
unsigned int sp=5000; //100Hz===>9216,????20%=9216*0.2=1843?????
int sn=7; //????80%=9216*0.8=7373?????
unsigned int temp,u,p,PRD=0,DT1,DT2,DT3;  //????????
unsigned int count=0;
sbit LED=P1^0;
sbit LED1=P1^1;
sbit LED2=P1^2;
sbit LED3=P1^3;
sbit LED4=P1^4;
sbit LED5=P1^5;
sbit LED6=P1^6;
sbit LED7=P1^7;
sbit LED8=P3^0;
sbit sw=P2^1;
int expe[31]={/*1000,905,*/	819,	741,	670,	607,	549,	497,	449,	407,	368,	333,	301,	273,	247,	223,	202,	183,	165,	150,	135,
							122,	111,	100,	91,	82,	74,	67,	61,	55,	50,	45,	41/*,	37,	33,	30,	27,	25,	22,	20,	18,	17,	15,	14,	12,	11,	10,	9,	8,	7,	7*/
};
// int expe[49]={/*9210,9210,9110,*/9048	,8187	,7408	,6703	,6065	,5488	,4966	,4493	,4066	,3679	,3329	,3012	,2725	,2466	,2231	,2019	,1827	,1653	,
// 								 1496,	1353,	1225,	1108,	1003,	907,	821,	743,	672,	608,	550,	498,	450,	408,	369,	334,	302,	273,	247,224,
// 								 202,	183,	166,	150,	136,	123,	111,	101,	91,	82,	74/*,	67*/};							 
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
 temp=65536-12000;
 TH0=temp/256;
 TL0=temp%256;
 TR0=1;
 LED=1;
 LED1=1;
 LED2=1;
}
void timer0_isr(void) interrupt TF0_VECTOR using 1 
{        
	switch(u){
		case 0 :
			if(LED==1)
			{
				TR0=0;
				temp=65536-sn;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED=0;
			}
			else
			{
				TR0=0;
				temp=65536-sp;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED=1;
			}
		break;
		case 1 :
			if(LED1==1)
			{
				TR0=0;
				temp=65536-sn;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED1=0;
			}
			else
			{
				TR0=0;
				temp=65536-sp;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED1=1;
			}
		break;
		case 2 :
			if(LED2==1)
			{
				TR0=0;
				temp=65536-sn;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED2=0;
			}
			else
			{
				TR0=0;
				temp=65536-sp;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED2=1;
			}
	 break;
 }
 
}

// {
// 	TH0=(65536-100)/256;  //0.1ms

// 	
// 	PWM=0;
// 	DUTY1=92;
// 	DUTY2;
// 	DUTY3;
// 	
// 	PWM++;
// 	if(PWM>=100)
// 		PWM=0;
// 	
// 		//PWM  0~99;

// 	if(DUTY1>PWM)
// 		P2=0XFF;
// }


void B_pwm(int pin ,int T) //defult 80
{
 u=pin;
 for(count=30;count!=-1;count--){	 
	 sn=expe[count];
   sp=1000-sn;
	 delay(T);
	 }
	 for(count=0;count!=31;count++){	 
	 sn=expe[count];
   sp=1000-sn;
	 delay(T);
	 }
}
void pwm(int duty,int duty1,int duty2,int T) //defult 80
{
   u=0; 
	 sn=expe[duty];
   sp=1024-sn;
	 delay(T);
	 u=1; 
	 sn=expe[duty1];
   sp=1024-sn;
	 delay(T);
	 u=2; 
	 sn=expe[duty2];
   sp=1024-sn;
	 delay(T);
}
main()
{
 timer0_initialize();
 while(1) 
 { 
	 //for(p=0;p<255;p+=50){
// 	 DT1=254;
// 	 DT2=100;
// 	 DT3=10;
	 //delay(1000);
	 //}
	//for(p=10;p<21;p++) 
	B_pwm(0,100);
	//pwm(p,21,21,0);
	//delay(2000);
	}
 }
