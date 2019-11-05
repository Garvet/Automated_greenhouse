#include "Fans_controller.h"

Fans_controller::Fans_controller(
        uint8_t pin_0, uint8_t pin_1, uint8_t pin_2, uint8_t pin_3,
        uint8_t ch_0, uint8_t ch_1, uint8_t ch_2, uint8_t ch_3
    ) : fans{ {pin_0, ch_0}, {pin_1, ch_1}, {pin_2, ch_2}, {pin_3, ch_3} } {
    
}

uint8_t Fans_controller::get(uint8_t fan_id) {
    if (fan_id < 4)
        return fans[fan_id].get();
    else
        return 0; 
}

void Fans_controller::set(uint8_t fan_id, uint8_t value) {
    if (fan_id < 4)
        fans[fan_id].set(value);
}