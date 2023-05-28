//ENTER PASSWORD IN VIRTUAL TERMINAL. IF CORRECT THEN DISPLAY 'WELCOME'IN 16X2 LCD.
#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
int i,j,k,l,m,n,t,pt=0;
unsigned char ent,y[6],z[6];
unsigned char x[]=" ENTER PASSWORD ";
unsigned char v[]=" WRONG PASSWORD ENTERED, TRY AGAIN ";
unsigned char p[]="INAYAT";
unsigned char cmnd1[]={0x38,0x0E,0x01,0x06,0x80};
unsigned char dat1[]="WELCOME";
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
void enterown()
{
  SBUF=0x0d;
	while(TI==0);
	TI=0;
}
void enter()
{
   while(RI==0);
	 ent=SBUF;
	 RI=0;
}
void wrong()
{
  for(m=0; m<sizeof v; m++)
	{
	  SBUF=v[m];
		while(TI==0);
		TI=0;
	}
}
void password()
{
  for(i=0;i<6; i++)
		{
		  while(RI==0);
		  y[i]=SBUF;
	  	if(y[i]==p[i])
	  	{
	  	  pt++;
	    }
		  RI=0;
			SBUF='*';
	    while(TI==0);
    	TI=0;
  	}
		if(pt==6)
		{
			enter();
		  for(n=0; n<5; n++)
		  {
		    P2=cmnd1[n];
		    cmd();
	   	}
		  for(t=0; t<7; t++)
		  {
		    P2=dat1[t];
		  	dat();
		  }
  	}
		else
		{
			enter();
			if(ent==0x0d)
			{
	       wrong();
				enterown();
			}
			password();
		}
	}
void main()
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0XFD;   //TO SET THE BAUD RATE TO 9600: 28800/9600=3, 256-3=253=FD
	TR1=1;
	  for(k=0; k<sizeof x; k++)
		{
		  SBUF=x[k];
			while(TI==0);
			TI=0;
		}
		enterown();
		password();	
}	