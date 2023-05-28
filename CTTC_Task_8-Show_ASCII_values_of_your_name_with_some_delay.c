//WRITE THE ASCII VALUE OF YOUR NAME TO PORT 2 WITH SOME DELAY.
#include<reg51.h>
unsigned char my_name[]="INAYAT";
unsigned int i,j;
void delay()
{
for(i=50000; i>0; i--);
}
void main()
{
for(j=0; j<sizeof my_name; j++)
{
P2= my_name[j];
delay();
}
}