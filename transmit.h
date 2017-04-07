#include "schema.h"
#include "config.h"
#include "sensors.h"
#include <EEPROM.h>
#include <XBee.h>

#define MAX_SIZE 80



#ifndef TRANSMIT_H
#define TRANSMIT_H

void clear_packet(void);
void make_packet(int Gcount);
void send_packet(void);
void test(void);

#endif
