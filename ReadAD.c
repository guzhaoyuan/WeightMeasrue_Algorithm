sbit ADDO = P1^5;
sbit ADSK = P0^0;


unsigned long ReadCount(void)
{
unsigned long Count;
unsigned char i;
ADSK=0; //??AD(PD_SCK ??)
Count=0;
while(ADDO); //AD????????,??????
for (i=0;i<24;i++)
{
ADSK=1; //PD_SCK ??(????)
Count=Count<<1; //???????Count????,????
ADSK=0; //PD_SCK ??
if(ADDO) Count++;
}
ADSK=1;
Count=Count^0x800000;//?25????????,????
ADSK=0;
return(Count);
}