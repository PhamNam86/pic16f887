#include "D:\Proteus 8.8\pic16f887\week_8\INTERRUPT.h"

//#include <kongat.h>
#define RB 0x06
#bit led = RB.6
#bit led_int = RB.7
#bit bt = RB.2
#INT_EXT

void main()
{
set_tris_B(0x0F);


   while(TRUE)
   {
      led = 1;
      delay_ms(200);
      led = 0;
      delay_ms(200);
      if (bt == 1)
         {
            led_int = !led_int;
            delay_ms(5000);
         }
   }

}
