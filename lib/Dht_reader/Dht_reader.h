#ifndef GH_DHT_READER_H
#define GH_DHT_READER_H

#include <Arduino.h>
#include <DHT.h>

/**
 * \brief Класс для работы с датчиками серии DHTxx
 * \details Из-за специфики шины 1-Wire датчики DHTxx имеют свойство "уходить в перезарядку" при обращении к ним.
 * Для избежания этого все методы данного класа вызывают update(), которая обновляет закешированные показания, если прошёл интервал timeout (по умолчанию 1000 мс)
 */
class Dht_reader {
public:
    /**
     * \param dht_pin Порт, к которому подключен датчик
     * \param dht_type Модель датчика, константы определены в библиотеке DHT sensor library, но можно использовать числа 11, 12, 21, 22 для соответствующих моделей
     * \param update_timeout Минимальный интервал между возможными считываниями с датчика
     */
    Dht_reader(
        uint8_t dht_pin, uint8_t dht_type = DHT22,
        unsigned long update_timeout = 1000
    );
    
    // Считывает с датчика с минимальным интервалом timeout
    // forced -- принудительно считать, если true
    /**
     * Метод, обновляющий закешированные значения показаний датчика, если с последнего обновления прошёл интервал timeout
     * \param forced При true считывание производится принудительно
     */
    void update(bool forced = false);

    /**
     * \return Влажность воздуха
     */
    float get_humidity();

    /**
     * \return Температуру воздуха
     */
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