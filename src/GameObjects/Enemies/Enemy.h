#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "GameObjects/MovableObject.h"

/*!
 * \ingroup Game_objects
 * \brief Класс врага.
 *
 * Реализует класс врага, объекты которого необходимо уничтожить.
 */
class Enemy
        : public MovableObject
{
public:
    /*!
     * \brief Тип врага.
     *
     * Используется для определения к какому типу относится враг.
     */
    enum class EnemyType
    {
        Enemy, ///<Враг
        Decorator ///<Декоратор врага
    };
public:
    ///Конструктор с тремя аргументами.
    Enemy(std::weak_ptr<QGraphicsScene> scene,
          int hitpoint = 1,
          std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    ///Деструктор.
    virtual ~Enemy() override;
    ///Метод, принимающий объект посетителя.
    virtual void accept(AbstractVisitor &visitor) override;
    ///Метод для установки здоровья врага.
    void setHitpoint(int hitpoint);
    ///Метод, возвращающий значение текущего здоровья врага.
    int hitpoint() const;
protected:
    ///Метод для установки типа врага.
    void setEnemyType(EnemyType type);
private:
    ///Метод, возвращающий тип врага.
    EnemyType enemyType() const;
private:
    int hitpoint_;
    EnemyType type_;
};
