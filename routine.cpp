#include "routine.h"

void routine(int *count)
{
  long wait_ms = 1000;
  unsigned long transmit_timer = millis();

  make_Packet(*count);

  (*count)++;

  if((*count) >= 60){
    send_Packet();
    clear_Packet();
    (*count);
    
  }
 while ((millis() - tansmit_timer <= wait_ms); 
}

