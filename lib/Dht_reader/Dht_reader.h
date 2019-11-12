#ifndef GH_DHT_READER_H
#define GH_DHT_READER_H

#include <Arduino.h>
#include <DHT.h>

// Класс-обёртка для датчика температуры и влажности DHTxx
class Dht_reader {
public:
    Dht_reader(
        uint8_t dht_pin, uint8_t dht_type = DHT22,
        unsigned long update_timeout = 1000
        );
    void update(bool forced = false);
    float get_humidity();
    float get_temperature();
private:
    DHT dht;
    const unsigned long timeout;
    unsigned long last_update = 0;
    float last_hum = 0.0;
    float last_temp = 0.0;
};

#endif