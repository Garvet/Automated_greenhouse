#include "Hall_reader.h"

Hall_reader::Hall_reader(TwoWire* two_wire, uint8_t adr_1, uint8_t adr_2)
: ext_1(adr_1, two_wire), ext_2(adr_2, two_wire) {
    ext_1.begin();
    ext_2.begin();
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