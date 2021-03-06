/*Internal Libraries*/
#include "sensors.h"
#include "config.h"

/* Objects */
SHT1x sht1x(H_DATA_PIN, H_CLK_PIN);
Adafruit_BMP085 bmp085;


void sensor_init(void) {
  bmp085.begin();
}

/*HUMUDITY*/
long sHumidity(void) {
  long val = sht1x.readHumidity();
  return val;
}

/*PRESSURE*/
long sPressure(void) {
  long val = bmp085.readPressure();
  return val;
}

/*TEMPERATURE*/
long sTemperature(void) {
  long val = sht1x.readTemperatureF();
  return val;
}

/*SOLAR IRRADIANCE*/
long sSolIrrad(void) {
  long val = analogRead(APOGEE_PIN) * (5000.0/1023);
  return (val/2);
}

/*BATTERY*/
long battStatus(void) {
  long val = analogRead(BATT_PIN) * (5000.0/1023);
  return val;
}

/*SOLAR PANEL*/
long panelStatus(void) {
  long val = 2 * (analogRead(PANEL_PIN) * (5000.0/1023));
  return val;
}






