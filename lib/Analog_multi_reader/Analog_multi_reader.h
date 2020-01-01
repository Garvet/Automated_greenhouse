#ifndef GH_ANALOG_MULTI_READER_H
#define GH_ANALOG_MULTI_READER_H

#include <Arduino.h>

/**
 * \brief Класс для считывания с множества аналоговых сенсоров
 * \details Служит для инкапсуляции доступа к аналоговым входам, считывающим показания одного типа (например, для 3-х аналоговых гигрометров)
 * Индексанция входов начинается с 0.
 */
class Analog_multi_reader {
public:
    /**
     * \param sensor_count Количество датчиков
     * \param pins Порты микроконтроллера, к которым подключены датчики. Должны поддерживать АЦП.
     */
    Analog_multi_reader(uint8_t sensor_count, const uint8_t pins[]);

    /**
     * Метод для считывания с конкретного датчика
     * \param sensor_id Номер датчика
     * \return Значение на АЦП, под номером sensor_id, если sensor_id >= count, то всегда возвращается значение 0.
     */
    uint16_t get(uint8_t sensor_id);

    /**
     * Метод для считывания со всех имеющихся датчиков одновременно
     * \return Массив размера count со считанными значениями
     */
    uint16_t* get_all();

    /**
     * Перегрузка оператора [], аналогично get()
     * \param sensor_id Номер датчика
     * \return Значение на АЦП, под номером sensor_id, если sensor_id >= count, то всегда возвращается значение 0.
     */
    uint16_t operator[](uint8_t sensor_id) { return get(sensor_id); }

    /// Количество датчиков, обслуживаемых объектом
    const uint8_t count;
private:
    uint8_t* sensor_pins;
    ~Analog_multi_reader();
};

#endif