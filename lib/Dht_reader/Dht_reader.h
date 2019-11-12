#ifndef GH_DHT_READER_H
#define GH_DHT_READER_H

#include <Arduino.h>
#include <DHT.h>

// Класс-обёртка для датчика температуры и влажности DHTxx
class Dht_reader {
public:

    // dht_pin -- пин, к которому подключен датчик
    // dht_type -- тип датчика, константа DHT11, DHT12, DHT22 из DHT.h
    // update_timeout -- минимальный интервал между считываниями
    Dht_reader(
        uint8_t dht_pin, uint8_t dht_type = DHT22,
        unsigned long update_timeout = 1000
    );
    
    // Считывает с датчика с минимальным интервалом timeout
    // forced -- принудительно считать, если true
    void update(bool forced = false);

    // Возвращает влажность
    float get_humidity();

    // Возвращает температуру
    float get_temperature();
private:
    DHT dht;

    // Минимальный интервал считывания
    const unsigned long timeout;

    // Время последнего считывания
    unsigned long last_update = 0;

    // Последняя считанная влажность
    float last_hum = 0.0;

    // Последняя считанная температура
    float last_temp = 0.0;
};

#endif