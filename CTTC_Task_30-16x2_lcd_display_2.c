//MONITOR P3.1, IF 1 THEN DISPLAY YOUR FIRST NAME OR ELSE DISPLAY YOUR SURNAME IN 16X2 LCD.
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit a=P3^1;
unsigned int i,j,k,m;
unsigned char cmnd1[]={0x38,0x0E,0x01,0x06};
unsigned char f_name[]="INAYAT";
unsigned char l_name[]="KHAN";
void delay()
{
  for(j=0; j<20000; j++);
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
		if(a==1)
		{
		  for(k=0; k<6; k++)
		  {
		    P2=f_name[k];
		  	 dat();
		  }
		}
		else
		{
		  for(m=0; m<4; m++)
		  {
		    P2=l_name[m];
			  dat();
		  }
		}
	}
}