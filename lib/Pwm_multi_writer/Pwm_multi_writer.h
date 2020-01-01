#ifndef GH_PWM_MULTI_WRITER_H
#define GH_PWM_MULTI_WRITER_H

#include <Arduino.h>

/**
 * \brief Класс для управления множеством генераторов ШИМ-сигнала
 * \details Служит для инкапсуляции связанных между собой генераторов ШИМ-сигнала (например, нескольких вентиляторов).
 * Индексация генераторов начинается с 0.
 */
class Pwm_multi_writer {
public:
    /**
     * \param pwm_count Количество генераторов
     * \param pins Массив портов, на которых будут установлены генераторы ШИМ-сигнала
     * \param channels Массив каналов генератора ШИМ-сигнала, соответствующих каждому из портов
     * \param pwm_freq Частота генераторов ШИМ-сигнала
     */
    Pwm_multi_writer(uint8_t pwm_count, const uint8_t pins[],
        const uint8_t channels[], double pwm_freq);
    
    /**
     * Метод, устанавливающий заполнение на конкретном генераторе
     * \param id Номер генератора. Если id больше количества генераторов, то ничего не произойдёт.
     * \param duty Заполнение ШИМ-сигнала
     */
    void set(uint8_t id, uint8_t duty);

    /**
     * \param id Номер генератора
     * \return Значение заполнения на выбранном генераторе. Если id количества генераторов, то возвращает 0.
     */
    uint8_t get(uint8_t id) const;

    /// Сокращённая форма вызова get()
    uint8_t operator[](uint8_t id) { get(id); }

    /// Количество генераторов
    const uint8_t count;

    ~Pwm_multi_writer();
private:
    uint8_t* pwm_channels;
    uint8_t* pwm_duties;
};

#endif