#include<reg51.h>
sbit red=P1^0;
void delay(unsigned char b){
 unsigned char i,j;
 for(i=0;i<b;i++)
 for(j=0;j<255;j++);
}
void pwm(char pinname,int dutycycle){
	int i=0;
	for(i=0;i<=100;i++){
		if(i<=dutycycle && i>=0){
			pinname=1;
			//delay(10);
		}
			else if(i>dutycycle && i<=100){
				pinname=0;
			//delay(10);
			}
	}
}
main(){
	while(1){
		int m;
		for(j=0;j<=100;j+=1){
			for(m=0;m<1000;M++)
			pwm(red,j);
			}
	}	
}