#include <REGX51.H>
void lcdinit();
void lcdcmd(unsigned char value); void lcddat(unsigned char *value); void delay(unsigned int itime); unsigned char *k="safety systems"; unsigned int i,j;
sbit rs=P3^5;
sbit rw=P3^6;
sbit en=P3^7;
void main() {
while(1)
{
lcdinit(); lcdcmd(0x80); lcddat(k);
}
}
void lcdinit()
{
lcdcmd(0x38);
delay(20);
lcdcmd(0x0e);
delay(20);
lcdcmd(0x01);
delay(20);
lcdcmd(0x06);
delay(20);
}
void lcdcmd(unsigned char value) {
rs=0;
rw=0;
P0=value;
en=1;
delay(1);
en=0;
}
void lcddat(unsigned char *value) {
for(;*value;) { P0=*value++; rs=1;
rw=0; en=1; delay(1); en=0;
}}
void delay(unsigned int itime) {
for(i=0;i<itime;i++) for(j=0;j<1275;j++);
}
