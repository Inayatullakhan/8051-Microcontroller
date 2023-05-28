//Design a digital clock which shows time in decimal numbers.
#include<reg51.h>
int i,j,k,l,m;
void delay()
{
for(i=0; i<1; i++)   // 1sec delay
 {
	  TH0=0x33;
		TL0=0xFF;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
 }
}
void main()
{
	TMOD=0x01;
	for(m=0; m<=1; m++)       //for 7seg connected to P0
	{
		P0=m;
	  for(l=0; l<=9; l++)     //for 7seg connected to P1
	  {
			if(m==1 && l==2)      //for hours only one to 12 no. are needed
       break;			
		  P1=l;
	    for(k=0; k<=5; k++)   //for 7seg connected to P2
	    {
		   P2=k;
       for(j=0; j<=9; j++)  //for 7seg connected to P3
	     {
		    P3=j;
		    delay();
	     }
      }
    }
  }
}