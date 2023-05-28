//GENERATE A SQUARE WAVE ON PORT 2.1 WITH Ton=500ms, Toff=30msusing TOM1.
#include<reg51.h>
sbit a= P2^1;
int i;
void on()
{
for(i=0; i<7; i++)
	{
		TH0=0;
		TL0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
	}
}
void off()
{
    TH0=0x93;
	  TL0=0xFF;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
}
void main()
{
TMOD=0x01;
	while(1)
	{
	a=1;
  on();
	a=0;
  off();		
	}
}