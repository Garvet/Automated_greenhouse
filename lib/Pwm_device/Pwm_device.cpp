#include "Pwm_device.h"

Pwm_device::Pwm_device(
        uint8_t device_pin, uint8_t pwm_channel,
        double pwm_freq, uint8_t initial_duty)
        : pin(device_pin), channel(pwm_channel) {
    ledcSetup(channel, pwm_freq, 8);
    ledcAttachPin(pin, channel);
    set(initial_duty);
}

uint8_t Pwm_device::get() const {
    return pwm_duty;
}

void Pwm_device::set(uint8_t value) {
    uint8_t mapped_duty = constrain(map(value, 0, 100, 0, 255), 0, 255);
    ledcWrite(channel, mapped_duty);
    pwm_duty = value;
}