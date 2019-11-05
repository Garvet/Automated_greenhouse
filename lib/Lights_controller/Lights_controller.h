#ifndef GH_LIGHTS_CONTROLLER_H
#define GH_LIGHTS_CONTROLLER_H

#include <Arduino.h>
#include "Pwm_device.h"

// Класс для управления тремя лампами
class Lights_controller {
public:
    Lights_controller(
        uint8_t pin_0, uint8_t pin_1, uint8_t pin_2,
        uint8_t ch_0, uint8_t ch1, uint8_t ch2
    );

    // Возвращяет значение ШИМ [0;100] на лампе [0;3]
    uint8_t get(uint8_t light_id);

    // Устанавливает значение ШИМ [0;100] на лампе [0;3]
    void set(uint8_t light_id, uint8_t value);
private:
    Pwm_device lights[3];
};

#endif