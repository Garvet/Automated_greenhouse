#ifndef GH_ANALOG_SENSOR
#define GH_ANALOG_SENSOR

#include <Arduino.h>

class AnalogSensor {
public:
    const uint8_t pin;
    AnalogSensor(uint8_t sensorPin)
        : pin(sensorPin) {
        
    }

    uint16_t readRaw() {
        return analogRead(pin);
    }

    virtual double read() {
        return readRaw() / 100.0;
    }
};

#endif