//RECIEVE A CHARACTE , IF 'A' ADD THE VALUE OF P1 AND P2, IF 'B' SUBTRACT THE VALUES OF P1 AND P2,
// IF 'M' MULTIPLY THE VALUES OF P1 AND P2,SHOW THE RESULT IN P0, IF ANY OTHER KEY PRESSED TRANSMIT "INVALID KEY PRESSED".
#	include<reg51.h>
int i;
//unsigned chara;
unsigned char x[]="  |INVALID KEY PRESSED| ", a;
void main()
{
  SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	while(1)
	{
		while(RI==0);
	  a=SBUF;
		if(a=='A')
		{
			P0=P1+P2;
		}
		else if(a=='S')
		{
		  if(P1>P2)	
		    P0=P1-P2;
			else
				P0=P2-P1;
		}
		else if(a=='M')
		{
			P0=P1*P2;
		}
		else
		{
		  for(i=0; i<sizeof x; i++)
			{
			  SBUF=x[i];
				while(TI==0);
			  TI=0;
			}
		}
		RI=0;
	}
}