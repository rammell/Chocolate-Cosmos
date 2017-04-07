/*File: weatherbox.ino*/

/* Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"

/* External Libraries */
#include <SHT1x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <XBee.h>
#include <EEPROM.h>

#define DEBUG 1
schematop Gpacket;
XBee Gxbee = XBee();
int globalcount = 0;

void setup() {
  // put your setup code here, to run once:
  /*sensor_init();
  Serial.begin(9600);
  Gxbee.begin(Serial);

  clear_packet();
*/
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //routine(&globalcount);
  Serial.print("Test\n");
}
