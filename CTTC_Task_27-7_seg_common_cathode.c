//7segment_common cathode
#include<reg51.h>
unsigned int a,x;
unsigned char dat[] = {0XFC, 0X60, 0XDA, 0XF2, 0X66, 0XB6, 0XBE, 0XE0,0XFE, 0XF6, 0XEE, 0X3E, 0X1A, 0X7A, 0X9E, 0X8E};
void delay()
{
for(x=0;x<50000;x++);
}
void main()
{
while(1)
{
for(a=0;a<sizeof dat;a++)
{
P1=dat[a];
delay();
}
}
} 