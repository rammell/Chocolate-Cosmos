/*File: weatherbox.ino*/

/* Libraries */
#include "config.h"
#include "sensor.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"

/* External Libraries */
#include <SHT1x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <XBee.h>
#include <EEPROM.h>

schema_1 Gpacket;
XBee Gxbee = Xbee();
int globalcount = 0;

void setup() {
  // put your setup code here, to run once:
  sensor_init();
  Serial.begin(9600);
  Gxbee.begin(Serial);

  clear_packet();

}

void loop() {
  // put your main code here, to run repeatedly:
  routine(&globalcount);
}
