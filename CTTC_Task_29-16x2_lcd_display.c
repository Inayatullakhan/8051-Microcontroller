//WAP TO DISPLAY 'HELLO' IN THE 1ST ROW AND 'GOOD MORNING' IN THE 2ND ROW OF 16X2 LCD.
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
unsigned int i,j,k,l,m;
unsigned char cmnd1[]={0x38,0x0E,0x01,0x06,0x80};
unsigned char cmnd2[]={0x38,0x0E,0x06,0xC0};
unsigned char dat1[]="HELLO";
unsigned char dat2[]="GOOD MORNING";
void delay()
{
  for(j=0; j<10000; j++);
}
void cmd()
{
  rs=0;
	rw=0;
	en=1;
	delay();
	en=0;
}
void dat()
{
  rs=1;
	rw=0;
	en=1;
	delay();
	en=0;
}
void main()
{
  while(1)
	{
	  for(i=0; i<5; i++)
		{
		  P2=cmnd1[i];
		  cmd();
		}
		for(k=0; k<5; k++)
		{
		  P2=dat1[k];
			dat();
		}
		for(l=0; l<4; l++)
		{
		  P2=cmnd2[l];
		  cmd();
		}
		for(m=0; m<12; m++)
		{
		  P2=dat2[m];
			dat();
		}
		
	}
}