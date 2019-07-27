#pragma once

#include <QString>

/*!
 * \brief Класс-одиночка с настройками игры.
 *
 * Реализует класс-одиночку, читающий настройки из конфигурационного
 * файла в формате *.json.
 */
class AppSettings
{
public:
    ///Структура с настройками игровой сцены.
    struct Scene
    {
        QString backGround_; ///<Путь до изображения игровой сцены
        int width_; ///<Ширина игровой сцены
        int height_; ///<Высота игровой сцены
    };
    ///Структура с настройками различных временных задержек.
    struct Time
    {
        int spawnObjectPeriod_; ///<Период порождения игровых объектов на сцене
        int removeObjectPeriod_; ///<Период удаления игровых объектов со сцены
        int moveObjectPeriod_; ///<Период перемещения игровых объектов по сцене
        int checkCollisionPeriod_; ///<Период обнаружения коллизий объектов на игровой сцене
        int levelChangePeriod_; ///<Период смены уровня игры
    };
    ///Структура с настройками игровых объектов.
    struct Objects
    {
        QString player_; ///<Путь до изображения объекта игрока
        QString enemy1_; ///<Путь до изображения объекта врага №1
        QString enemy2_; ///<Путь до изображения объекта врага №2
        QString shield_; ///<Путь до изображения объекта щита, защищающего врага
        QString heart_; ///<Путь до изображения единицы здоровья игрока на виджете здоровья
        ///Структура с настройками оружия
        struct Weapon
        {
            QString weapon_; ///<Путь до изображения объекта оружия
            QString gunshell_; ///<Путь до изображения объекта оружейного снаряда
            QString patron_; ///<Путь до изображения патрона
            QString shotSound_; ///<Путь до мелодии выстрела из оружия
            QString reloadSound_; ///<Путь до мелодии перезарядки оружия
            unsigned int capacity_; ///<Емкость оружия
            unsigned int startPatrons_; ///<Количество начальных патронов для оружия
            unsigned int shotDelay_; ///<Задержка между выстрелами из оружия
            unsigned int reloadDelay_; ///<Задержка при перезарядке оружия
        }
        gun_, ///<Настройки пистолета
        machinegun_, ///<Настройки пулемета
        bazooka_; ///<Настройки базуки
    };
public:
    ///Статический метод, возвращающий объект с настройками игры.
    static AppSettings &instance();
    ///Метод, возвращающий настройки игровой сцены.
    const Scene &scene() const;
    ///Метод, возвращающий настройки с различными временными задержками.
    const Time &time() const;
    ///Метод, возвращающий настройки игровых объектов.
    const Objects &objects() const;
private:
    ///Конструктор.
    AppSettings();
    ///Деструктор по умолчанию.
    ~AppSettings() = default;
    ///Копирующий конструктор.
    AppSettings(const AppSettings &other) = delete;
    ///Оператор копирующего присваивания.
    AppSettings &operator=(const AppSettings &other) = delete;
    ///Метод загрузки настроек.
    void load();
private:
    Scene scene_;
    Time time_;
    Objects objects_;
};
