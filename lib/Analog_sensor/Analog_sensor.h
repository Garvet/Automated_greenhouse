#ifndef GH_ANALOG_SENSOR
#define GH_ANALOG_SENSOR

#include <Arduino.h>

// Обёртка для считывания аналогового сигнала
class Analog_sensor {
public:
    const uint8_t pin;

    Analog_sensor(uint8_t sensorPin);

    // Возвращает необработанное значение с датчика
    uint16_t read_raw();
};

#endif