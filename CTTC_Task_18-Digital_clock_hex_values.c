//Make a digital clock
#include<reg51.h>
int i;
void sec_delay()
{
for(i=0; i<14; i++)   // 1sec delay
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
	while(1)
	{
		P2=0;
		while(P2!=0x0C)      // loop for hour time
		{
		 P3=0;
		 while(P3!=0x3C)     //loop for minute time
		 {
	  	P1=0;
	    while(P1!=0x3C)    // loop for second time
		  {                  // loop for second time
       P1++;             // loop for second time
	     sec_delay();      // loop for second time
		  }                  // loop for second time
	    P3++;
	   }
		P2++;
	  }
	}
}