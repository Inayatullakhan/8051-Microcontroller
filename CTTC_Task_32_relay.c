//turn on two 12v lamp one at a time using_relay.
#include<reg51.h>
sbit a=P1^0;
sbit r=P3^0;
void main()
{
  if(a==0)
	{
	  r=0;
	}
	else
	{
	  r=1;
	}
}