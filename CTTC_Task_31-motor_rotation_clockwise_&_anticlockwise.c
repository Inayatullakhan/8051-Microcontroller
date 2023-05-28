//MONITOR P1.0, IF 1 THEN ROATATE MOTOR IN CLOCKWISE DIRECTION ELSE IN ANTICLOCKWISE DIRECTION.
#include<reg51.h>
sbit a=P1^0;
sbit m1=P3^0;
sbit m2=P3^1;
void main()
{
  if(a==1)
	{
	  m1=1;
		m2=0;
	}
	else
	{
	  m1=0;
		m2=1;
	}
}