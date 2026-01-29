#ifndef DHTREADLIB_H
#define DHTREADLIB_H

#include <Arduino.h>
#include <Wire.h>
#include <DHT.h>

class DHTReadLib 
{
private:
    uint8_t dhtPIN;
    uint8_t dhtTYPE;
    DHT dht;
    unsigned long currentMillis;
    unsigned long prevMillis = 0;
    int interval = 2000;
public:
    DHTReadLib(uint8_t pin, uint8_t type);
    void readDHT();
};

#endif // DHTREADLIB_H
