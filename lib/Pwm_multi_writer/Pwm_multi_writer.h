#ifndef GH_PWM_MULTI_WRITER_H
#define GH_PWM_MULTI_WRITER_H

#include <Arduino.h>

class Pwm_multi_writer {
public:
    Pwm_multi_writer(uint8_t pwm_count, const uint8_t pins[],
        const uint8_t channels[], double pwm_freq);
    ~Pwm_multi_writer();
    void set(uint8_t id, uint8_t duty);
    const uint8_t count;
private:
    uint8_t* pwm_channels;
};

#endif