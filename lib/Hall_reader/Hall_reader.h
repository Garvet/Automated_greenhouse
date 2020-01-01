#ifndef GH_HALL_READER_H
#define GH_HALL_READER_H

#include <Arduino.h>
#include <pcf8574_esp.h>

/**
 * \brief Класс для считывания с 10 датчиков Холла на двух расширителях PCF8574T
 * \details Позволяет работать с 10 датчиками Холла: 8 на первом расширителе и 2 на втором (4 и 5 порты).
 * Нумерация начинается с 0.
 */
class Hall_reader {
public:
    /**
     * Конструктор класса Hall_reader
     * \param extender_1, extender_2 Ссылки на заранее инициализированные объекты расширителей
     * \param adr_1, adr2 Адреса расширителей на шине I2C
     */
    Hall_reader(PCF857x& extender_1, PCF857x& extender_2,
        uint8_t adr_1 = 0x3E, uint8_t adr_2 = 0x3F);

    /**
     * Метод для считывания состояния конкретного датчика Холла
     * \param sensor_id Номер датчика (0-9)
     * \return Сигнал на указанном датчике. Если sensor_id > 9, то всегда возвращается LOW
     */
    bool get(uint8_t sensor_id);
private:
    PCF857x& ext_1;
    PCF857x& ext_2;
};

#endif