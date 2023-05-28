//MONITOR P1.3, IF IT IS 1 GENERATE A TIME PERIOD ON P3.3 WITH 500ms DELAY USING T1M2.
//IF 0 GENERATE A SQUARE WAVE  ON P3.3 WITH 100us DELAY USING T0M2.
#include<reg51.h>
int i,j;
sbit a= P1^3;
sbit b= P3^3;
void delay_1()
{
  TMOD=0x20;
	TH1=0;
	TR1=1;
	for(i=0; i<902; i++)
	{
	  while(TF1==0);
		TF1=0;
	}
}
void delay_2()
{
  TMOD=0x02;
	TH0=0xA4;
	TR0=1;
	while(TF0==0);
	TF0=0;
}
void main()
{ 
  if(a==1)
	{
		delay_1();
		b=~b;
	}  
	else if(a==0)
	{
	  delay_2();
		b=~b;
	}
}