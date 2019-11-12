#include "DS18B20_reader.h"

DS18B20_reader::DS18B20_reader(
    uint8_t pin, unsigned long update_timeout = 1000,
        uint8_t resolution = 9)
: onewire(pin), sensors(&onewire), timeout(update_timeout) {
    sensors.begin();

    // Получим количество датчиков и выделим столько памяти массивам
    sensor_count = sensors.getDeviceCount();
    addresses = new DeviceAddress[sensor_count];
    last_temps = new float[sensor_count];

    // Получим адреса датчиков
    for (uint8_t i = 0; i < sensor_count; i++) {
        sensors.getAddress(addresses[i], i);
    }

    // Установим разрешение
    sensors.setResolution(resolution);

    // Принудительно считаем показания
    update(true);
}

DS18B20_reader::~DS18B20_reader() {
    delete[] addresses;
    delete[] last_temps
}

void DS18B20_reader::update(bool forced = false) {
    // если с прошлого считавания прошло timeout времени
    // или принудительное считывание
    if ((millis() - last_update >= timeout) || forced) {
        sensors.requestTemperatures();
        
        for (uint8_t i = 0; i < sensor_count; i++) {
            last_temps[i] = sensors.getTempC(addresses[i]);
        }

        last_update = millis();
    }
}

uint8_t DS18B20_reader::get_sensor_count() {
    return sensor_count;
}

float DS18B20_reader::get_temperature(uint8_t sensor_id) {
    if (sensor_id < sensor_count) {
        update();
        return last_temps[sensor_id];
    }
    return 0.0f;
}