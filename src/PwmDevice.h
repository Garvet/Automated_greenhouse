#ifndef GH_PWM_DEVICE_H
#define GH_PWM_DEVICE_H

#include <Arduino.h>

class PwmDevice {
public:
    const uint8_t pin;
    const uint8_t channel;

    PwmDevice(
        uint8_t devicePin, uint8_t pwmChannel,
        double pwmFreq = 200.0, uint8_t initialDuty = 0)
            : pin(devicePin), channel(pwmChannel) {
        ledcSetup(channel, pwmFreq, 8);
        ledcAttachPin(pin, channel);
        set(initialDuty);
    }

    uint8_t get() const {
        return pwmDuty;
    }

    void set(uint8_t duty) {
        ledcWrite(channel, duty);
        pwmDuty = duty;
    }
private:
    uint8_t pwmDuty;
};

#endif