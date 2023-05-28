//MONITOR P1.3, IF IT IS 1 DO THE ADDITION BETWEEN P2 AND P3 OTHERWISE DO SUBSTRACTION. SHOW THE RESULT IN P0.
#include<reg51.h>
sbit A= P1^3;
void main()
{
if(A==1)
{
P0=P2+P3;
}
else
{
P0=P2-P3;
}
}