#include "Analog_sensor.h"

Analog_sensor::Analog_sensor(uint8_t sensorPin)
: pin(sensorPin) {

}

uint16_t Analog_sensor::read_raw() {
    return analogRead(pin);
}