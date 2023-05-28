//password system.If correct then start a motor.
#include<reg51.h>
sbit m1=P1^1;
int i,k,l,m,pt=0;
unsigned char ent,y[6],z[6];
unsigned char x[]=" ENTER PASSWORD ";
unsigned char q[]=" CORRECT PASSWORD ENTERED";
unsigned char v[]=" WRONG PASSWORD ENTERED, TRY AGAIN ";
unsigned char p[]="INAYAT";
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
void correct()
{
  for(l=0; l<sizeof q; l++)
	{
	  SBUF=q[l];
		while(TI==0);
		TI=0;
	}
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
		if (pt==6)
		{
			enter();
			if(ent==0x0d)
			{
				correct();
				enterown();
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
	TH1=0XFD;      //TO SET THE BAUD RATE TO 9600: 28800/9600=3, 256-3=253=FD
	TR1=1;
	  for(k=0; k<sizeof x; k++)
		{
		  SBUF=x[k];
			while(TI==0);
			TI=0;
		}
		enterown();
		password();	
		m1=0;
}	