#include <DHTReadLib.h>

DHTReadLib::DHTReadLib(uint8_t pin, uint8_t type) : dhtPIN(pin), dhtTYPE(type), dht(dhtPIN, dhtTYPE) {
    dht.begin();
}

void DHTReadLib::readDHTInterval(int interval) {
    int intervalDHT = interval;
    unsigned long currentMillis = millis();
    if (currentMillis - prevMillis >= intervalDHT) {
        prevMillis = currentMillis;
        
        float temperature = dht.readTemperature();
        if (isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
        } else {
            Serial.print("Temperature: ");
            Serial.println(temperature);
        }
    }  
}
