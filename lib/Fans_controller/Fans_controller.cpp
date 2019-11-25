#include "Fans_controller.h"

Fans_controller::Fans_controller(
        uint8_t pin_0, uint8_t pin_1,
        uint8_t ch_0, uint8_t ch_1
    ) : fans{ {pin_0, ch_0}, {pin_1, ch_1} } {
    
}

uint8_t Fans_controller::get(uint8_t fan_id) {
    if (fan_id < 2)
        return fans[fan_id].get();
    else
        return 0; 
}

void Fans_controller::set(uint8_t fan_id, uint8_t value) {
    if (fan_id < 2)
        fans[fan_id].set(value);
}