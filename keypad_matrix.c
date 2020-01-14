#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

#define Key_PRT  PORTB
#define Key_DDR  DDRB
#define Key_PIN  PINB
#define Key_PRT1  PORTA
#define Key_DDR1  DDRA

void delay_ms(unsigned int d )
{

_delay_ms(d);

}

volatile char keypad[6][6]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

void main()
{
unsigned char col,row;

 MCUCSR=0x80;
 MCUCSR=0x80;
 InitLCD(0);
  LCDClear();
//DDRD=0xff;
Key_DDR=0xC0;
Key_PRT=0xff;
Key_DDR1=0x0F;
Key_PRT1=0xFF;

 LCDWriteStringXY(0,0,"system loading....");
 
 for(int i=0;i<=100;i++)
 {
   LCDWriteIntXY(0,1,i,3);
   LCDWriteStringXY(4,1,"%");
   _delay_ms(20);
   } 
    
  _delay_ms(2000);
  LCDClear();
while(1)
{
do{
Key_PRT&=0x3f;
Key_PRT1&=0x00;
col=(Key_PIN&0x3f);
}
while(col!=0x3f);
do
{
do
{
  delay_ms(20);
  col=(Key_PIN&0x3f);

}
while(col==0x3f);

delay_ms(20);
col=(Key_PIN&0x3f);

}
while(col==0x3f);
while(1)
{
Key_PRT=0xBF;
Key_PRT1=0x0F;
col=(Key_PIN&0x3f);
if(col!=0x3f)
{
row=0;
break;
}

Key_PRT=0x7F;
Key_PRT1=0x0F;
col=(Key_PIN&0x3f);
if(col!=0x3f)
{
row=1;
break;
}
Key_PRT=0xFF;
Key_PRT1=0x0E;
col=(Key_PIN&0x3f);
if(col!=0x3f)
{
row=2;
break;
}
Key_PRT=0xFF;
Key_PRT1=0x0D;
col=(Key_PIN&0x3f);
if(col!=0x3f)
{
row=3;
break;
}
Key_PRT=0xFF;
Key_PRT1=0x0B;
col=(Key_PIN&0x3f);
if(col!=0x3f)
{
row=4;
break;
}
Key_PRT=0xFF;
Key_PRT1=0x07;
col=(Key_PIN&0x3f);
row=5;
break;


}
if(col==0x3E)
 {//LCDClear();
  //LCDWriteStringXY(1,1,'keypad[row][0]');
 LCDWriteIntXY(3,0,keypad[row][0],2);
//PORTD=(keypad[row][0]);
}
else if(col==0x3D)
{
   LCDWriteIntXY(3,0,keypad[row][1],2);

//PORTD=(keypad[row][1]);
}
else if(col==0x3B)
{
LCDWriteIntXY(3,0,keypad[row][2],2);
//PORTD=(keypad[row][2]);
}
else if(col==0x37)
{

LCDWriteIntXY(3,0,keypad[row][3],2);
//PORTD=(keypad[row][3]);
}
else if(col==0x2F)
{

LCDWriteIntXY(3,0,keypad[row][4],2);
//PORTD=(keypad[row][3]);
}
else if(col==0x1F)
{

LCDWriteIntXY(3,0,keypad[row][5],2);
//PORTD=(keypad[row][3]);
}
}
//return 0;
}
