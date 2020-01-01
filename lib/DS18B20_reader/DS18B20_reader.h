#ifndef GH_DS18B20_READER_H
#define GH_DS18B20_READER_H

#include <OneWire.h>
#include <DallasTemperature.h>

/**
 * \brief Класс для работы с датчиками температуры DS18B20
 * \details Устройствам 1-Wire может требоваться время на перезарядку конденсаторов перед работой, 
 * поэтому при считывании используется метод update(), кеширующий показания не чаще одного раза в timeout мс. 
 */
class DS18B20_reader {
public:
    /**
     * \param pin Порт, к которому подключены датчики
     * \param update_timeout Минимальный интервал между возможными считываниями с датчиков
     * \param resoulution Разрешение датчиков в битах
     */
    DS18B20_reader(
        uint8_t pin, unsigned long update_timeout = 1000,
        uint8_t resolution = 9);

    // Считывает температуру с датчиков,
    // если прошло timeout времени с прошлого считывания
    // forced -- принудительно считать, если true 
    /**
     * Метод, обновляющий кешированные значения температур, если c прошлого обновления прошло timeout миллисекунд
     * \param forced Если true, то обновление будет выполнено принудительно
     */
    void update(bool forced = false);

    /**
     * \return Количество обнаруженных датчиков
     */
    uint8_t get_sensor_count();

    // Возвращает температуру с датчика
    // sensor_id -- номер датчика, должен быть меньше количества датчиков,
    // иначе возвращает 0.0f
    /**
     * \param sensor_id Номер датчика
     * \return Температуру указанного датчика, если sensor_id меньше количества обнаруженных датчиков, иначе возвращает 0.0f
     */
    float get_temperature(uint8_t sensor_id);

    ~DS18B20_reader();
private:
    OneWire onewire;
    DallasTemperature sensors;

    // Указатель на массив адресов (каждый адрес uint8_t*)
    DeviceAddress* addresses;

    // Минимальный период между считываниями
    const unsigned long timeout;

    // Время последнего обновления
    unsigned long last_update = 0;

    uint8_t sensor_count = 0;

    // Массив последних считанных показаний датчиков
    float* last_temps;
};

#endif