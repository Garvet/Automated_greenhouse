#ifndef GH_LIGHTS_CONTROLLER_H
#define GH_LIGHTS_CONTROLLER_H

#include <Arduino.h>
#include "Pwm_device.h"

// Класс для управления тремя лампами
class Lights_controller {
public:
    Lights_controller(uint8_t pin, uint8_t ch);

    // Возвращяет значение ШИМ [0;100] на лампе [0;3]
    uint8_t get();

    // Устанавливает значение ШИМ [0;100] на лампе [0;3]
    void set(uint8_t value);
private:
    Pwm_device light;
};

#endif