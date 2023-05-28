//SEND -4 TO +4 TO PORT 3 WITH SOME DELAY
#include<reg51.h>
unsigned int i,j,a=-4;
void delay()
{
for(i=50000; i>0; i--);
}
void main()
{
	for(j=0; j<9; j++)
  {
	P3=a;
	a++;
	delay();
	}
}