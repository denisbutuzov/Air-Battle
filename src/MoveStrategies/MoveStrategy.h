#pragma once

class MovableObject;

/*!
 * \defgroup Move_strategies Стратегии движения объектов
 * \brief Данный модуль описывает различные стратегии движения игровых объектов.
 */

/*!
 * \ingroup Move_strategies
 * \brief Абстрактный родительский класс стратегий движения
 * игровых объектов.
 *
 * Реализует основные методы стратегии движения игровых
 * объектов по игровой сцене.
 */
class MoveStrategy
{
public:
    /*!
     * \brief Направление движения.
     *
     * Используется для конкретизации направления движения
     * игрового объекта.
     */
    enum class Direction
    {
        Up, ///<Движение вверх
        Down ///<Движение вниз
    };
public:
    ///Деструктор по умолчанию.
    virtual ~MoveStrategy() = default;
    ///Метод перемещения игрового объекта.
    virtual void move(MovableObject &object) = 0;
    ///Метод, возвращающий направление движения игрового объекта.
    Direction direction() const;
    ///Метод для установки скорости объекта.
    void setSpeed(unsigned int speed);
    ///Метод, возвращающий скорость объекта.
    unsigned int speed() const;
protected:
    ///Конструктор с двумя аргументами.
    MoveStrategy(Direction dir, unsigned int speed);
private:
    Direction dir_;
    unsigned int speed_;
};
