//MAKE A COUNTER THAT COUNTS NO. OF PEOPLE EMTERS AND EXIT A ROOM.
#include<reg51.h>
int i,d=0;
sbit a= P3^3;
sbit b= P3^4;
void delay()  // for 1sec delay(1/0.071= 14)
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
void enter()
{
	P1=d;
	d++;
	delay();
}
void exit()
{
	P1=d;
	d--;
	delay();
}
void main()
{
	TMOD=0x01;
	while(1)
	{
	 P1=d;
   if(a==1)
     {
     enter();
     }
   else if(b==1)
     {
			 while(d!=0)
			 {
	      exit();
			 }
		 }
 }
}