//WAP TO SEND THE COUNT VALUES OF COUNTER 0 MODE 2 TO P2(TL0).
#include<reg51.h>
void main()
{
while(1)
 {
	 TMOD=0x06;
   TH0=0;
	 TR0=1;
	 while(TF0==0)
	 {
	   P2= TL0;
	 }
	 TF0=0;
 }
}
