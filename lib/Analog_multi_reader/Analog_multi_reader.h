#ifndef GH_ANALOG_MULTI_READER_H
#define GH_ANALOG_MULTI_READER_H

#include <Arduino.h>

class Analog_multi_reader {
public:
    Analog_multi_reader(uint8_t sensor_count, const uint8_t pins[]);
    ~Analog_multi_reader();
    uint16_t get(uint8_t sensor_id);
    uint16_t* get_all();
    uint16_t operator[](uint8_t sensor_id) { return get(sensor_id); }
    
    const uint8_t count;
private:
    uint8_t* sensor_pins;
};

#endif