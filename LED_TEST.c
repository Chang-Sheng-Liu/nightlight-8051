#include"reg51.h"
#define led P1
#define SW P0
void delay(int);
int main(){
	char i,SW;
	int mask;
	while(1){
		if(SW=0xff){
			led=0xfe;
			mask=0x01;
			for(i=0 ;i<8;i++){		
				delay(50);
				led=(led<<1)|mask;
			}
		}
		else if(SW=0x00){
			led=0x7f;
			mask=0x80;
			for(i=0 ;i<8;i++){		
				delay(50);
				led=(led>>1)|mask;
			}
		}	
	}
}
void delay(int x){
int i,j;
for(i=0;i<x;i++){
	for(j=0;j<600;j++){
		}
	}
}
