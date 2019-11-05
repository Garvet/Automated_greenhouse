#include "Hyg_reader.h"

Hyg_reader::Hyg_reader(uint8_t pin_0, uint8_t pin_1)
: sensors{ {pin_0}, {pin_1} } {
    
}

double Hyg_reader::read(uint8_t hyg_id) {
    if (hyg_id < 2) {
        uint16_t raw = sensors[hyg_id].read_raw();

        double calculated = raw / 100.0;
        return calculated;
    }
    else
        return NAN;
}