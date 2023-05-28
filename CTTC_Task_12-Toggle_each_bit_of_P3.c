// TOGGLE EACH BITS OF PORT 3 WITH SOME DELAY. 
#include<reg51.h>
unsigned int i,j;
void delay()
{
	for(i=0; i<30000; i++);
}
void main()
{
  while(1)
  {
    P3=0x1;
		delay();
		for(j=0; j<8; j++)
		{
     P3=P3<<1;
     delay();			
		}
  }
}
