//A DIGITAL TEMPERATURE SENSOR IS CONNECTED TO PORT 3. IF TEMP>50, DISPLAY THE TEMP ON PO. IF TEMP<50,DISPLAY ON P1,
#include<reg51.h>
 unsigned int temp;
void main()
{
P3=temp;
if(temp>0x50)
{
P0=temp;
}
else
{
P1=temp;
}
}