#ifndef GH_PWM_DEVICE_H
#define GH_PWM_DEVICE_H

#include <Arduino.h>

// Класс для управления одним каналом ШИМ разрядностью 8 бит
class Pwm_device {
public:
    const uint8_t pin;
    const uint8_t channel;

    Pwm_device(
        uint8_t device_pin, uint8_t pwm_channel,
        double pwm_freq = 200.0, uint8_t initial_duty = 0);

    // Возваращает текщее заполнение ШИМ в пределах [0;100]
    uint8_t get() const;

    // Метод, устанавливающий заполнение ШИМ
    // Принимает значения в интервале от 0 до 100
    void set(uint8_t value);
private:
    uint8_t pwm_duty;
};

#endif