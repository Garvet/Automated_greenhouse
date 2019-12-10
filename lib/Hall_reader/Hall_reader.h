#ifndef GH_HALL_READER_H
#define GH_HALL_READER_H

#include <Arduino.h>

// #include <Wire.h>
/* Почему-то возникает ошибка компиляции
 * C:\...\.platformio\lib\PCF8574_ESP_ID1659\pcf8574_esp.h:17:18: fatal error: Wire.h: No such file or directory
 * но только если заголовок Hall_reader.h НЕ подключается в main.cpp
 * если он подключается, то всё нормально, неважно поключён Wire.h или нет.
 */
#include <pcf8574_esp.h>

// Класс для считывания с 10 датчиков Холла на двух расширителях PCF8574T
class Hall_reader {
public:
    Hall_reader(PCF857x& extender_1, PCF857x& extender_2,
        uint8_t adr_1 = 0x3E, uint8_t adr_2 = 0x3F);
    bool get(uint8_t sensor_id);
private:
    PCF857x& ext_1;
    PCF857x& ext_2;
};

#endif