//#include "D:\Proteus 8.8\pic16f887\week_8\DAC.h"
 
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
//End LCD module connections

#include <16F887.h>
#include <lcd.h>


void main(){
  lcd_init();                 // Initialize LCD module
  while(TRUE){
    lcd_putc('\f');
    lcd_gotoxy(4, 1);           // Go to column 4 row 1
    lcd_putc("PIC16F877A");
    lcd_gotoxy(4, 2);           // Go to column 4 row 2
    lcd_putc("LCD example");
    delay_ms(5000);
    lcd_putc('\f');             // LCD clear
    lcd_gotoxy(3, 1);           // Go to column 3 row 1
    lcd_putc("Hello world!");
    lcd_gotoxy(2, 2);           // Go to column 2 row 2
    lcd_putc("Have a nice day");
    delay_ms(5000);
    lcd_putc('\f');             // LCD clear
    lcd_gotoxy(3, 1);           // Go to column 3 row 1
    lcd_putc("Hello world!");
  
   }
}


