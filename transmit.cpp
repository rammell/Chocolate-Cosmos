#include <"transmit.h"

void clear_packet(void) {
  #ifdef DEBUG
  Serial.print("Begin:clear\n");
  #endif

  /*Sensor Readings*/
  Gpacket.address = EEPROM.read(2) | (EEPROM.read(3) << 8);;
  Gpacket.uptime_ms = 0;
  Gpacket.pressrue_pa = 0;
  Gpacket.humudity_centi_pct = 0;
  Gpacket.temperature_c = 0;

  /*Voltages*/
  Gpacket.batt_mv = 0;
  Gpacket.panel_mv = 0;
  Gpacket.solirrad_w_m2 = 0;
  
  #ifdef DEBUG
  Serial.print("End:clear\n");
  #endif
}

void make_packet(int Gcount) {
	int i = Gcount;

#ifdef DEBUG
	Serial.print("Begin:make\n");
#endif

	Gpacket.schema = 297;

	long BatterymV = 0;
	long SolarIrradmV = 0;
	long SolarIrradWm2 = 0;
	long Humiditypct = 0;
	long PanelmV = 0;
	long PressurePa = 0;
	long Tempdecic = 0;
	long temperatureC = 0;
	unsigned long uptime = 0;

	/*Pulling Sensor Data*/
	BatterymV = battStatus();
	PanelmV = panelStatus();
	SolarIrradmV = sSolIrrad();

	/*Packing Health Status Data*/
	Gpacket.batt_mv = BatterymV;
	Gpacket.panel_mv = PanelmV;
	Gpacket.solarirrad_w_m2 = SolarIrradmV;

	/*Pack Rest of Data*/
	Humiditypct = sHumidity();
	PressurePa = sPressure();
	Tempdecic = sTemperature();
	Gpacket.pressure_pa = PressurePa;
	Gpacket.humidity_centi_pct = Humiditypct;
	Gpacket.temperature_c = Tempdecic;

	uptime = millis();
	Gpacket_ms = uptime;

#ifdef DEBUG
	Serial.print("\nPanelmV Data:");
	Serial.println(PanelmV);
	Serial.print("\nBatterymV Data:");
	Serial.println(BatterymV);
	Serial.print("\nSolarIrrmV Data:");
	Serial.println(SolarIrrmV);
	Serial.print("\nHumiditypct Data:");
	Serial.println(Humiditypct);
	Serial.print("\nPressurepa Data:");
	Serial.println(PressurePa);
	Serial.print("\nRoofTempdecic Data:");
	Serial.println(Tempdecic);
	Serial.print("End:con\n");
#endif
}

void send_packet() {
	int len = 0;

	//Obtain address of Xbee
	XBeeAddress64 addr64 = XbeeAddress64(0x0, 0x0);

	//Clear payload
	uint8_t payload[MAX_SIZE];

	//Find length of packet
	memset(payload, '\0', sizeof(payload));

	//Load payload
	memcpy(payload, &Gpacket, len);

	//Send payload
	ZBTxRequest xbTx = ZBTxRequest(addr64, payload, len);
	Gxbee.send(zbTx); //Prints packet to serial monitor
}

void test() {
	long batt_mv_test = 1;
	long panel_mv_test = 2;
	long solirrad_test = 3;
	long pressure_test = 4;
	long humidity_test = 5;
	long temperature_test = 6;
	unsigned long uptime 1337;

	//DEBUG
	Serial.println(F("Making bin"));

	//Makes test packet
	Gpacket.batt_mv = batt_mv_test;
	Gpacket.panel_mv = panel_mv_test;
	Gpacket.solarirrad_w_m2 = solirrad_test;
	Gpacket.pressure_pa = pressure_test;
	Gpacket.humidity_centi_pct = humidity_test;
	Gpacket.temperature_c = temperature_test;
}