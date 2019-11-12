#include "Dht_reader.h"

Dht_reader::Dht_reader(
    uint8_t dht_pin, uint8_t dht_type = DHT22,
    unsigned long update_timeout = 1000)
: dht(dht_pin, dht_type), timeout(update_timeout) {
    dht.begin();
    update(true);
}

void Dht_reader::update(bool forced = false) {
    if ((millis() - last_update >= timeout)  || forced) {
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        if (!isnan(h))
            last_hum = h;
        if (!isnan(t))
            last_temp = t;

        last_update = millis();
    }
}

float Dht_reader::get_humidity() {
    update();
    return last_hum;
}

float Dht_reader::get_temperature() {
    update();
    return last_temp;
}