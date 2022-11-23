//#include "D:\Proteus 8.8\pic16f887\week_6\main.h"
#include <string.h>
#define RS PIN_C5 
#define RW PIN_C6 
#define E PIN_C7
/*#FUSES NOWDT,PUT,HS,NOPROTECT,NOLVP
#USE DELAY(CLOCK=16M)
#define SHCP_PIN PIN_C0
#define DS_PIN PIN_C1
#define STCP_PIN PIN_C2*/
//unsigned char binary_pattern[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
//unsigned char binary_pattern[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};



char str[]="Hello World";
char str1[]="READY";

void xung_E()
{
output_low(E); 
output_high(E); 
delay_us(40);
}
void set_command_LCD(unsigned char n)
{
output_low(RS); 
output_low(RW); 
OUTPUT_D(n); 
xung_E();
}
void set_data_LCD(unsigned char n)
{
output_high(RS); 
output_low(RW); 
OUTPUT_D(n);
xung_E();
}

void set_position_LCD(unsigned char hang, unsigned char cot){

unsigned char address = 0x80 + 64*hang+cot; 
set_command_LCD(address);

}


void init_LCD()
{
xung_E();  //Just for simulation in Proteus
set_command_LCD(0x38); //Config LCD & 8_bits, 2 lines, 5x7 dots
delay_ms(40); 
set_command_LCD(0x06); 
set_command_LCD(0x0C); 
delay_ms(40); 
set_command_LCD(1);
}
void set_text_LCD(unsigned char hang,unsigned char cot,char str[])
{
   set_position_LCD(hang,cot);
int i;
for(i=0;i<strlen(str);i++)
set_data_LCD(str[i]);
}
//unsigned char Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
/* Dinh nghia cac chan cua IC74HC595 */
//int i=0;
/*int k=0;
void IC_74hc595(unsigned int data) 
{
    OUTPUT_LOW(SHCP_PIN);
    
    for(k = 0;k < 8; k++)
    {
    if((data & 0x80)==0)
    OUTPUT_LOW(DS_PIN);
    else
    OUTPUT_HIGH(DS_PIN);
    data=data<<1;
    OUTPUT_HIGH(SHCP_PIN);
    OUTPUT_LOW(SHCP_PIN);
    }
}
void IC_74HC595_Output()
{
    OUTPUT_LOW(SHCP_PIN);
    delay_us(5);
    OUTPUT_HIGH(STCP_PIN);
    OUTPUT_LOW(STCP_PIN);
}
*/
void main()
{
  
   SET_TRIS_B(0X00);
   SET_TRIS_C(0X00);
   SET_TRIS_D(0X00);
   OUTPUT_C(0x00);
   OUTPUT_D(0xFF);
   
   init_LCD();
   delay_ms(10);
   
   set_text_LCD(0,3,str);
   set_text_LCD(1,3,str1);
   While(TRUE){
   
  /* OUTPUT_D(0XFF);
   delay_ms(1000);
   OUTPUT_D(0X00);
   delay_ms(1000);
   */
 /*  int i=0;
   for(i=0;i<10;i++)
        {
            output_B(~binary_pattern[i]);
            delay_ms(1000);  //add delay of one second
        }
  */
/* int i=0;
 for(i=0;i<10;i++)
        {
             IC_74hc595(Code7Seg[i]);
            // IC_74hc595(~binary_pattern[i]); 
             IC_74HC595_Output();
             delay_ms(1000);  //add delay of one second
        }
  */     
     




}
}
