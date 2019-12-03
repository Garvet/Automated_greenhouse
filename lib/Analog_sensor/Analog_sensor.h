#ifndef GH_ANALOG_SENSOR
#define GH_ANALOG_SENSOR

#include <Arduino.h>
#include "Analog_multi_reader.h"

// Обёртка для считывания аналогового сигнала
class Analog_sensor {
public:
    const uint8_t pin;

    Analog_sensor(uint8_t sensorPin);

    // Возвращает необработанное значение с датчика
    uint16_t read_raw();
private:
    friend class Analog_multi_reader;
    Analog_sensor();
};

#endif