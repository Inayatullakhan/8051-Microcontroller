//DESIGN A 4 WAY TRAFFIC CONTROLLER WITH 10SEC DELAY AND DISPLAY IT IN A COUNTDOWN TIMER.
#include<reg51.h>
int i,j,a;
void delay()  // for 1sec delay(1/0.071= 14)
{
for(i=0; i<14; i++)  
	{
	  TH0=0;
		TL0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
	}
}
void timer()  //for 10sec countdown
{
	a=10;
  for(j=0; j<10; j++)
	{
	P2=a;
	a--;
	delay();
	}
}
void main()
{
	TMOD=0x01;
	while(1)
	{
  P1=0x22;     // from P1.7 to P1.0= 00100010
	P3=0x09;     // from P3.7 to P3.0= 00001001
	timer();
	P1=0x0C;     // from P1.7 to P1.0= 00001100
	P3=0x0A;     // from P3.7 to P3.0= 00001010
	timer();
	P1=0x09;     // from P1.7 to P1.0= 00001001
	P3=0x14;     // from P3.7 to P3.0= 00010100
	timer();
	P1=0x11;     // from P1.7 to P1.0= 00010001
	P3=0x21;     // from P3.7 to P3.0= 00100001
	timer();
	}
}