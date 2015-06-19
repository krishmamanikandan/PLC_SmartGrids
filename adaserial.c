#include<reg51.h> sfr adcout=0xa0; sbit A1=P1^0;
sbit B1=P1^1;
sbit C1=P1^2;
sbit relay1=P1^3;
sbit relay2=P1^4;
void delay(unsigned char value2); void adata(unsigned int); unsigned char a,b,c,d;
void serialint()
{
SCON=0x50;
TMOD=0X20;
TH1=0XFD;
TR1=1;
}
void txs(unsigned char kk)
{
TI=0; SBUF=kk; while(TI==0); TI=0;
}
void conv(unsigned int value1) {
unsigned int huns,tens,ones; huns=(value1/100); txs(huns+0x30); tens=((value1/10)%10); txs(tens+0x30); ones=(value1%10); txs(ones+0x30);
}
void adata(unsigned int adcout) {
unsigned char val=0; val=val|(adcout&0x80)>>7; val=val|(adcout&0x40)>>5; val=val|(adcout&0x20)>>3; val=val|(adcout&0x10)>>1; val=val|(adcout&0x8)<<1; val=val|(adcout&0x4)<<3; val=val|(adcout&0x2)<<5; val=val|(adcout&0x1)<<7; conv(val);
}
void delay(unsigned char value2)
{
int i,j; for(i=0;i<=value2;i++) { for(j=0;j<=1000;j++) {}

void main()
{ relay1=relay2=0; serialint(); while(1)
{
while(RI==0)
{ A1=0;B1=0;C1=0; delay(50);
txs('P'); adata(adcout); delay(100);

A1=1;B1=0;C1=0; delay(50);
txs('Q'); adata(adcout); delay(100);
} switch(SBUF)
{
case 'B': relay1=1;RI=0;break; case 'C': relay2=1;RI=0;break; case 'D': relay1=0;RI=0;break; case 'E': relay2=0;RI=0;break; }
}
}
