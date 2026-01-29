#include <DHTReadLib.h>

DHTReadLib::DHTReadLib(uint8_t pin, uint8_t type) : dhtPIN(pin), dhtTYPE(type), dht(dhtPIN, dhtTYPE) {
    dht.begin();
}

void DHTReadLib::readDHT() {
    unsigned long prevMillis = millis();
    if (currentMillis - prevMillis >= interval) {
        prevMillis = currentMillis;
        float temperature = dht.readTemperature();
        if (isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
        } else {
            Serial.print("Temperature: ");
            Serial.println(temperature);
            delay(2000);
        }
    }   
}

