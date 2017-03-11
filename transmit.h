#include "schema.h"
#include "config.h"
#include "sensor.h"
#include <EEPROM.h>
#include <XBee.h>

#define MAX_SIZE 80

extern schema_1 Gpacket;

extern XBee Gxbee;

#ifndef TRANSMIT_H
#define TRANSMIT_H

void clear_Packet(void);
void make_Packet(int Gcount);
void send_Packet(void);
void test(void);

#endif
