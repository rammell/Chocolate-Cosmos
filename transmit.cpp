#include "transmit.h"

void clear_Packet(void) {
  #ifdef DEBUG
  Serial.print("Begin:clear\n");
  #endif

  int a,b,c;

  Gpacket.address = EEPROM.read(2) | (EEPROM.read(3) << 8);;
  Gpacket.uptime_ms = 0;
  Gpacket.bmp085_press_pa = 0;
  Gpacket.humudity_centi_pct = 0;
  //temperature

  for (a = 0; a < 60; a++) {
    b = a/10;
    c = a/3;
  Gpacket.batt_mv[b] = 0;
  Gpacket.panel_mv[b] = 0;
  Gpacket.apogee_w_m2[c] = 0;
  }
  #ifdef DEBUG
  Serial.print("End:clear\n");
  #endif
}



  }

