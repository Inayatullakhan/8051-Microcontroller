//4x4 keypad
#include<reg51.h>
unsigned char chk1[]={0xfe,0xfd,0xfb,0xf7};
unsigned char chk2[]={0xef,0xdf,0xbf,0x7f};
unsigned char dat[]="0123456789abcdef";
unsigned int i,j,a;
void main()
{
  while(1)
	{
		a=0;
		P1=0xf0;
		while(P1==0xf0);            //until any key is pressed the program will run in this loop only
	  for(i=0; i<4; i++)          //row key check
		{
		  P1=chk1[i];
			for(j=0; j<4; j++)        //column check
			{
			  if(P1|0x0f==chk2[j])
				{
				  P3=dat[a];
				}
				else
				{
				  a=a+1;
				}
			}
		}
	}
}