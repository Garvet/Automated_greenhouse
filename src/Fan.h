#ifndef GH_FAN_H
#define GH_FAN_H

#include "PwmDevice.h"

class Fan : public PwmDevice {
public:
    Fan(
        uint8_t devicePin, uint8_t pwmChannel,
        double pwmFreq = 200.0, uint8_t initialDuty = 0)
        : PwmDevice(devicePin, pwmChannel, pwmFreq, initialDuty) {
        
    }
};

#endif