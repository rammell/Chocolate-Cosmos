
/*Sensor Libraries*/
#include <Wire.h>
#include <XBee.h>
#include <SHT1x.h>
#include <Adafruit_BMP085.h>

/*Initialization Function*/
void sensor_init(void);

/* Sensor Functions */
long sPressure(void);
long sSolIrrad(void);
long sHumidity(void);         
long sTemperature(void);             
long batteryStatus(void);
long panelStatus(void);

