#include "Lights_controller.h"

Lights_controller::Lights_controller(uint8_t pin, uint8_t ch)
: light(pin, ch) {
    
}

uint8_t Lights_controller::get() {
    light.get();
}

void Lights_controller::set(uint8_t value) {
    light.set(value);
}