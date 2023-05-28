//TOGGLE PORT 1 USING T0M1.
//(set frequency to 11.0592MHz)
#include<reg51.h>
void main()
{
TMOD=0x01;
	while(1)
	{
	  TL0=0;
		TH0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
		P1=~P1;
	}
}