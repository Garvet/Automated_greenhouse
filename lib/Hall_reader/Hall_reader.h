#ifndef GH_HALL_READER_H
#define GH_HALL_READER_H

#include <Arduino.h>
#include <Wire.h>
#include <pcf8574_esp.h>

// Класс для считывания с 10 датчиков Холла на двух расширителях PCF8574T
class Hall_reader {
public:
    Hall_reader(TwoWire* two_wire, uint8_t adr_1 = 0x3E, uint8_t adr_2 = 0x3F);
    bool get(uint8_t sensor_id);
private:
    PCF857x ext_1;
    PCF857x ext_2;
};

#endif