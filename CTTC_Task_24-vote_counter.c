//DESIGN A VOTE COUNTING DEVICE.
#include<reg51.h>
int i,f,g,h;
sbit a= P1^0;
sbit b= P1^1;
sbit c= P1^5;
sbit d= P1^6;
sbit e= P1^7;
void delay()
{
	for(i=0; i<14; i++)
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
	TMOD=0x01;
	a=0;
	f=0;
	g=0;
	h=0;
	P0=0;
	P2=0;
	P3=0;
	while(1)
	{
  if(c==0 && d==1 && e==1)
	 {
	 f++;
	 delay();
	 }
	else if(d==0 && c==1 && e==1)
	 {
	 g++;
	 delay();
  	}
	else if(e==0 && c==1 && d==1)
	 {
	  h++;
		delay();
	 }
	else if(b==0)
	 {
     P0=f;
		 P2=g;
		 P3=h;
   }
	 else if(b==1)
	 {
     P0=0;
		 P2=0;
		 P3=0;
   }
	// else if(c==0 && d==0 )
	//{
	  // a=1;
		// delay();
	//	 break;
	// }
 }
}