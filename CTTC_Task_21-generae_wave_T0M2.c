//generate a pulse in P3.7 such that it's one cycle has 500ms delay(T0M2) and next 3 cycle has 30ms delay(T1M1)
#include<reg51.h>
sbit s= P3^7;
int i,j,a,b;
void delay_1()
{
  TMOD=0x02;
	TH0=0;
	TR0=1;
	for(i=0; i<541; i++)
	{
	  while(TF0==0);
		TF0=0;		
	}
}
void delay_2()
{
  TMOD=0x10;
	TH1=0x93;
	TL1=0xFE;
	TR1=1;
	while(TF1==0);
	TF1=0;	
  TR1=0;	
}
void main()
{
	while(1)
	{
    for(a=0; a<2; a++)
	{
		delay_1();
	  s=~s;
	}
	  for(b=0; b<6; b++)
	{
	  delay_2();
		s=~s;
	}
  }
}