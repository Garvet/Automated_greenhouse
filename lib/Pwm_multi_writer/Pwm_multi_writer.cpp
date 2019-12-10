#include "Pwm_multi_writer.h"

Pwm_multi_writer::Pwm_multi_writer(uint8_t pwm_count, const uint8_t pins[],
    const uint8_t channels[], double pwm_freq)
: count(pwm_count) {
    pwm_channels = new uint8_t[count];
    pwm_duties = new uint8_t[count];
    for (uint8_t i = 0; i < count; i++) {
        pwm_channels[i] = channels[i];
        pwm_duties[i] = 0;
        ledcSetup(channels[i], pwm_freq, 8);
        ledcAttachPin(pins[i], channels[i]);
    }
}

Pwm_multi_writer::~Pwm_multi_writer() {
    delete[] pwm_channels;
    delete[] pwm_duties;
}

void Pwm_multi_writer::set(uint8_t id, uint8_t duty) {
    if (id < count) {
        ledcWrite(pwm_channels[id], duty);
        pwm_duties[id] = duty;
    }
}

uint8_t Pwm_multi_writer::get(uint8_t id) const {
    if (id < count) {
        return pwm_duties[id];
    }
    else
        return 0;
}