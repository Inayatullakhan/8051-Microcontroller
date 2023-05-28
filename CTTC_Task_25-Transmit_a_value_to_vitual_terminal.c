//TRANSMIT 'GOOD MORNING' TO THE VIRTUAL TERMINAL CONTINOUSLT.
#include<reg51.h>
int i;
unsigned char x[]="GOOD MORNING  ";
void delay()
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
void main()
{
	SCON=0x50;
	TMOD=0x21;
	TH1=0xFD;
	TR1=1;
	while(1)
	{
		for(i=0; i<sizeof x; i++)
	  {
	    SBUF=x[i];
			while(TI==0);
			TI=0;
	  }
		delay();
	}
}