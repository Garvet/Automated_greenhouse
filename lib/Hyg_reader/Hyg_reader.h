#ifndef GH_HYG_READER_H
#define GH_HYG_READER_H

#include "Analog_sensor.h"

// Класс для считывания с двух ёмкостных датчиков влажности
class Hyg_reader {
public:
    Hyg_reader(uint8_t pin_0, uint8_t pin_1);

    double read(uint8_t hyg_id);
private:
    Analog_sensor sensors[2];
};

#endif