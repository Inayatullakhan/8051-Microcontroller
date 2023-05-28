//4x4 keypad with 16x2 lcd.
#include<reg51.h>
unsigned int x,y;
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;
unsigned int row[]={0xFE,0xFD,0xFB,0xF7};
unsigned int col[]={0xEF,0xDF,0xBF,0x7F};
unsigned char key[]="0123456789ABCDEF";
unsigned int cmmd[]={0x38,0x0E,0x80};
int a,b,c,d;
void delay(unsigned int z)
{

for(x=0;x<12000;x++)
  for(y=0;y<z;y++);
}
void cmm()
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
void main()
{
    for(d=0;d<3;d++)
    {
     P3=cmmd[d];
     cmm();
    }
while(1)
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

     P3=key[a];
     dat();
     delay(4);
  }
  else
    a=a+1;
 }
}
}
}