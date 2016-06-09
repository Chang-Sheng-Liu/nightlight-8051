#include <regx51.h>
//void timer0_initialize(void);
unsigned int sp=5000; //100Hz===>9216,????20%=9216*0.2=1843?????
int sn=7; //????80%=9216*0.8=7373?????
unsigned int temp,u,p,PRD=0,DT1,DT2,DT3;  //????????
unsigned int count=0;
int flag=6;
sbit LED=P3^0;
sbit LED1=P3^1;
sbit LED2=P3^2;
sbit LED3=P1^3;
sbit LED4=P1^4;
sbit LED5=P1^5;
sbit LED6=P1^6;
sbit LED7=P1^7;
sbit LED8=P3^0;
sbit sw=P2^1;
int expe[33]={/*1000,905,	819,	*/741,	670,	607,	549,	497,	449,	407,	368,	333,	301,	273,	247,	223,	202,	183,	165,	150,	135,
							122,	111,	100,	91,	82,	74,	67,	61,	55,	50,	45,	41,	37,	33,	30/*,	27,	25,	22,	20,	18,	17,	15,	14,	12,	11,	10,	9,	8,	7,	7*/
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
void sw_c(){
	if(sw==0 && flag==0){
		
		flag=1;
		delay(500);
		}else if(sw==0 && flag==1){
		 
		 flag=2;
		 delay(500);
		}
		else if(sw==0 && flag==2){
		 
		 flag=3;
		 delay(500);
		}else if(sw==0 && flag==3){
		 
		 flag=4;
		 delay(500);
		}else if(sw==0 && flag==4){
		 
		 flag=5;
		 delay(500);
		}else if(sw==0 && flag==5){		 
		 flag=6;
		 delay(500);
 		}
			else if(sw==0 && flag==6){		 
		 flag=0;
		 delay(500);
			
		}
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
				LED1=0;
				LED2=0;
			}
			else
			{
				TR0=0;
				temp=65536-sp;
				TH0=temp/256;
				TL0=temp%256;
				TR0=1;
				LED=1;
				LED1=1;
				LED2=1;
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
 for(count=28;count!=-1;count--){	 
	 sn=expe[count];
   sp=1000-sn;
	 sw_c();if(flag==0){break;};
	 delay(T);
	 }
	 for(count=6;count!=-1;count--){	 
	 sn=expe[0];
   sp=1000-sn;
	 sw_c();delay(T);if(flag==0){break;};
	 }
	 for(count=0;count!=29;count++){	 
	 sn=expe[count];
   sp=1000-sn;
	 sw_c();delay(T);if(flag==0){break;};
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
void pwm_test(int DT1,int DT2,int DT3,int b,int delay)
{
	int test=0,u;
	unsigned char i,j;
  for(i=0;i<b;i++){
		//for(j=0;j<255;j++){
	sw_c();
	if(flag==6){break;}
	for(u=0;u<=100;u++){
	if(DT1>u && DT2>u && DT3>u){test=0;}
	if(DT1>u && DT2>u && DT3<u){test=1;}
	if(DT1>u && DT2<u && DT3>u){test=2;}
	if(DT1>u && DT2<u && DT3<u){test=3;}
	if(DT1<u && DT2>u && DT3>u){test=4;}
	if(DT1<u && DT2>u && DT3<u){test=5;}
	if(DT1<u && DT2<u && DT3>u){test=6;}
	if(DT1<u && DT2<u && DT3<u){test=7;}
	
	
	switch(test){
		case 0:
		LED=1;
		LED1=1;
		LED2=1;
		//timer(delay);
		break;
		case 1:
		LED=1;
		LED1=1;
		LED2=0;
		//timer(delay);
		break;
		case 2:
		LED=1;
		LED1=0;
		LED2=1;
		//timer(delay);
		break;
		case 3:
		LED=1;
		LED1=0;
		LED2=0;
		//timer(delay);
		break;
		case 4:
		LED=0;
		LED1=1;
		LED2=1;
		//timer(delay);
		break;
		case 5:
		LED=0;
		LED1=1;
		LED2=0;
		//timer(delay);
		break;
		case 6:
		LED=0;
		LED1=0;
		LED2=1;
		//timer(delay);
		break;
		case 7:
		LED=0;
		LED1=0;
		LED2=0;
		//timer(delay);
		break;
//}
}
}
}
}

main()
{
	
 timer0_initialize();
 while(1) 
 { 
	//B_pwm(0,130);
	
  sw_c();
	if(flag==1){
	//pwm_test(20,70,70,1,0);}//²`ÂÅ
	pwm_test(20,10,20,1,0);
	}//²HÂÅ
	else if(flag==0) {
	pwm_test(20,70,70,1,0);//²`ÂÅ
		//pwm_test(10,20,90,1,0);//µµ
	}else if(flag==2){
		pwm_test(70,10,20,1,0);//ÂÅºñ				
  }else if(flag==3){
		pwm_test(20,90,50,1,0);//ºñ
	}
	else if(flag==4){
		pwm_test(10,40,90,1,0);//µµ
	}
  else if(flag==5){
		pwm_test(20,10,20,10,0);
		//sw_c();
		pwm_test(20,70,70,10,0);
		//sw_c();
		pwm_test(70,10,20,10,0);
		//sw_c();
		pwm_test(20,90,50,10,0);
		//sw_c();
		pwm_test(10,40,90,10,0);
		//sw_c();
	}else if(flag==6){
		B_pwm(0,100);
	}
	}
 }
