//WAP TO TOGGLE ALL THE PORTS CONTINOUSLY WITH SOME DELAY.
#include<reg51.h>
unsigned int i;
void delay()
{
for(i=50000; i>0; i--);
}
void main()
{
	P0=!P0;
	P1=!P1;
	P2=!P2;
	P3=!P3;
	delay();
}