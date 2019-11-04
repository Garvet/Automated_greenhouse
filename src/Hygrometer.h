#ifndef GH_HYGROMETER_H
#define GH_HYGROMETER_H

#include "AnalogSensor.h"

class Hygrometer : public AnalogSensor {
public:
    Hygrometer(uint8_t sensorPin)
        : AnalogSensor(sensorPin) {
        
    }

    double read() {
        // TODO
        return readRaw() / 2.0;
    }
};

#endif