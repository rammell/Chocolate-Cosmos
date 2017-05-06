#include <stdint.h>

#ifndef SCHEMA_H
#define SCHEMA_H

/*Weatherbox Packet Schema*/
struct schematop {
	uint16_t schema;
	uint16_t address; //Arduino address
	uint32_t uptime_ms; //Uptime
	uint16_t batt_mv; //Battery Voltage in mV
	uint16_t panel_mv; //Panel Voltage in mV
	uint32_t pressure_pa; //Pressure values in Pascals
	int16_t temperature_c; //Temperatuer values in Celcius
	uint16_t humidity_centi_pct; //Humidity Value in absoulte %
	uint16_t solirrad_w_m2; //Solar Irradiance
};

/*Health Status*/
struct status {
	uint16_t schema;
	uint16_t address;
	uint32_t uptime_ms;
	uint16_t batt_mv;
};

#endif





