#include "Hall_reader.h"

Hall_reader::Hall_reader(PCF857x& extender_1, PCF857x& extender_2,
    uint8_t adr_1, uint8_t adr_2)
: ext_1(extender_1), ext_2(extender_2) {
}

bool Hall_reader::get(uint8_t sensor_id) {
    if (sensor_id < 8)
        return ext_1.read(sensor_id);
    else if (sensor_id < 10)
        // Датчики 8 и 9 подключены к портам 4 и 5 второго расширителя
        // 8-4=4, 9-4=5
        return ext_2.read(sensor_id - 4);
    else
        return LOW;
}