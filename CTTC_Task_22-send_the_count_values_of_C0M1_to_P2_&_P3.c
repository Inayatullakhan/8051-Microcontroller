//WAP TO SEND THE COUNT VALUES OF COUNTER O MODE 1 TO P2(THO) AND P1(TLO).
#include<reg51.h>
void main()
{
  TMOD=0x05;
	while(1)
	{
	TH0=0;
	TL0=0;
	TR0=1;
	while(TF0==0)
	{
	 P2= TH0;
	 P1= TL0;
	}
	TF0=0;
  TR0=0;
  }	
}
