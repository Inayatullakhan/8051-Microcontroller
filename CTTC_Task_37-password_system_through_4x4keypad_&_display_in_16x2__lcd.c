//ENTER PASSWORD THROUGH 4X4 KEYPAD AND IF CORRECT DISPLAI 'CORRECT' ELSE 'WRONG' IN 16X2 LCD
#include<reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
unsigned int i,x,y,k=0,l,m,n,p,q,a,b,c,d,pt=0;
unsigned char cmnd1[]={0x38,0x0E,0x01,0x06,0x80};
unsigned char cmnd2[]={0x38,0x0E,0x06,0xC0};
unsigned int row[]={0xFE,0xFD,0xFB,0xF7};
unsigned int col[]={0xEF,0xDF,0xBF,0x7F};
//unsigned char key[]="0123456789ABCDEF";
unsigned char key[]="A987B654C321CD0F";
unsigned char pswd[]="0786";
unsigned char e[4];
unsigned char dat1[]="ENTER PASSWORD";
unsigned char dat2[]="CORRECT";
unsigned char dat3[]="WRONG, TRY AGAIN";
void delay(unsigned int z)
{
  for(x=0;x<3000;x++)
    for(y=0;y<z;y++);
}
void cmd()
{
  rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void dat()
{
  rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void command1()
{
    for(i=0; i<5; i++)
		{
		  P2=cmnd1[i];
		  cmd();
		}
}
void command2()
{
    for(d=0;d<4;d++)
    {
     P2=cmnd2[d];
     cmd();
    }
}
void password()
{
		for(l=0; l<4; l++)
    {
      a=0;
      P1=0xF0;
      while(P1==0xF0);
      for(b=0;b<4;b++)
      {
      P1=row[b];
      for(c=0;c<4;c++)
         {
           if((P1|0x0F)==col[c])
           {
			    	 e[l]=key[a];
				     P2='*';
             dat();
             delay(8);
           }
           else
             a=a+1;
         }
      }
		  if(e[l]==pswd[l])
			{
			  pt++;
			}
    }
		if(pt==4)
		{
			command1();
			for(n=0; n<7; n++)
		  {
		     P2=dat2[n];
		     dat();
		  }
		}
		else
		{
			command1();
			for(q=0; q<16; q++)
		  {
		     P2=dat3[q];
		     dat();
		  }
			command2();
			password();
		}
}
void main()
{
	  command1();
		while(k<14)
		{
		  P2=dat1[k];
			dat();
			k++;
		}
		command2();
    while(1)
	  {
		  password();
	  }
}