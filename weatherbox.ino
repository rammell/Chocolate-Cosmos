/*File: weatherbox.ino*/

/* Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"
#define DEBUG 1

/* External Libraries */
#include <SHT1x.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <XBee.h>
#include <EEPROM.h>

schematop Gpacket;
XBee Gxbee = XBee();
int globalcount = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor_init();
  Gxbee.begin(Serial);
  Gxbee.setSerial(Serial);
  clear_packet();
  Serial.println("Starting up...");
  delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:
/* routine(&globalcount);
  Serial.print("Humidity: ");
  Serial.print(sHumidity());
  Serial.println("%");
  Serial.print("Pressure: ");
  Serial.print(sPressure());
  Serial.println("pa");
  Serial.print("Temp: ");
  Serial.print(sTemperature());
  Serial.println("F");
  Serial.println("");*/
  test();
  send_packet();
  delay(1000);
}





