#include "Analog_multi_reader.h"

Analog_multi_reader::Analog_multi_reader(uint8_t sensor_count,
    const uint8_t pins[]) : count(sensor_count) {
    sensor_pins = new uint8_t[count];
    for (uint8_t i = 0; i < count; i++)
        sensor_pins[i] = pins[i];
}

Analog_multi_reader::~Analog_multi_reader() {
    delete[] sensor_pins;
}

uint16_t Analog_multi_reader::get(uint8_t sensor_id) {
    if (sensor_id < count)
        return analogRead(sensor_pins[sensor_id]);
    else
        return 0;
}

uint16_t* Analog_multi_reader::get_all() {
    uint16_t* readings = new uint16_t[count];
    for (uint8_t i = 0; i < count; i++)
        readings[i] = analogRead(sensor_pins[i]);
    
    return readings;
}