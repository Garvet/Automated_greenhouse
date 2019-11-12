#include "Dht_reader.h"

Dht_reader::Dht_reader(
    uint8_t dht_pin, uint8_t dht_type, unsigned long update_timeout
) : dht(dht_pin, dht_type), timeout(update_timeout) {
    // Инициализация объекта для работы с датчиком
    dht.begin();

    // Принудительное считываение
    update(true);
}

void Dht_reader::update(bool forced) {
    // Если с прошлого считывания прошло timeout мс или принудительно
    if ((millis() - last_update >= timeout)  || forced) {
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        // В h и t могут быть NaN, поэтому нужно выплонить проверку
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