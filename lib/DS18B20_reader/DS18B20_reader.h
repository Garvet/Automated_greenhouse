#ifndef GH_DS18B20_READER_H
#define GH_DS18B20_READER_H

#include <OneWire.h>
#include <DallasTemperature.h>

// Класс для работы с датчиками температуры DS18B20
class DS18B20_reader {
public:

    // pin -- пин, к которому подключены датчики
    // update_timeout -- минимальное время в мс, через которое можно считывать
    // resolution -- разрешение датчиков в битах
    DS18B20_reader(
        uint8_t pin, unsigned long update_timeout = 1000,
        uint8_t resolution = 9);

    // Считывает температуру с датчиков,
    // если прошло timeout времени с прошлого считывания
    // forced -- принудительно считать, если true 
    void update(bool forced = false);

    // Возвращает общее количество датчиков
    uint8_t get_sensor_count();

    // Возвращает температуру с датчика
    // sensor_id -- номер датчика, должен быть меньше количества датчиков,
    // иначе возвращает 0.0f
    float get_temperature(uint8_t sensor_id);

    ~DS18B20_reader();
private:
    OneWire onewire;
    DallasTemperature sensors;

    // Указатель на массив адресов (каждый адрес uint8_t*)
    DeviceAddress* addresses;

    // Минимальный период между считываниями
    const unsigned long timeout;

    // Время последнего обновления
    unsigned long last_update = 0;

    uint8_t sensor_count = 0;

    // Массив последних считанных показаний датчиков
    float* last_temps;
};

#endif