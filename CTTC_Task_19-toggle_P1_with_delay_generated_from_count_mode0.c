//WAP TO TOGGLE P1 WITH DELAY GENERATED FROM COUNT 0-FF MODE 2.
#include<reg51.h>
void main()
{
	TMOD=0x20;
  TH1=0;
	TR1=1;
	while(1)
	{
	while(TF1==0);
		TF1=0;
		P3=~P3;
	}
}