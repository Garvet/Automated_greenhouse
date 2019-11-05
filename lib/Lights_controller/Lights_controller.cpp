#include "Lights_controller.h"

Lights_controller::Lights_controller(
        uint8_t pin_0, uint8_t pin_1, uint8_t pin_2,
        uint8_t ch_0, uint8_t ch_1, uint8_t ch_2
    ) : lights{ {pin_0, ch_0}, {pin_1, ch_1}, {pin_2, ch_2} } {
    
}

uint8_t Lights_controller::get(uint8_t light_id) {
    if (light_id < 3)
        return lights[light_id].get();
    else
        return 0; 
}

void Lights_controller::set(uint8_t light_id, uint8_t value) {
    if (light_id < 3)
        lights[light_id].set(value);
}