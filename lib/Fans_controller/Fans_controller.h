#ifndef GH_FANS_CONTROLLER_H
#define GH_FANS_CONTROLLER_H

#include <Arduino.h>
#include "Pwm_device.h"

// Класс для управления двумя вентиляторами
class Fans_controller {
public:
    Fans_controller(
        uint8_t pin_0, uint8_t pin_1,
        uint8_t ch_0, uint8_t ch1
    );

    // Возвращает заполнение ШИМ [0;100] на вентиляторе [0;2]
    uint8_t get(uint8_t fan_id);

    // Устанавливает заполнение ШИМ [0;100] на вентиляторе [0;2]
    void set(uint8_t fan_id, uint8_t value);
private:
    Pwm_device fans[2];
};

#endif