//COMPLIMENT PORT 1 WITH 1.5 SEC DELAY USING T1M1.
#include<reg51.h>
unsigned int i;
void delay()
{
for(i=0; i<21; i++)
	{
	  TL1=0;
		TH1=0;
		TR1=1;
		while(TF1==0);
		TF1=0;
		TR1=0;
	}
}
void main()
{
	TMOD=0x10;
	while(1)
	{
	  delay();
		P1=~P1;
	}
}