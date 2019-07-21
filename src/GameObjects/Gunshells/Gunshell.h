#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "GameObjects/MovableObject.h"

/*!
 * \ingroup Game_objects
 * \brief Класс оружейного снаряда.
 *
 * Реализует оружейный снаряд, порожденный объектом оружия
 * HandWeapon.
 */
class Gunshell
        : public MovableObject
{
public:
    ///Конструктор с тремя аргументами.
    Gunshell(std::weak_ptr<QGraphicsScene> scene,
             int damage = 1,
             std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Up, 20));
    ///Деструктор.
    virtual ~Gunshell() override;
    ///Метод, принимающий объект посетителя.
    virtual void accept(AbstractVisitor &visitor) override final;
    ///Метод для установки урона оружейного снаряда.
    void setDamage(int damage);
    ///Метод, возвращающий значение урона оружейного снаряда.
    int damage() const;
private:
    int damage_;
};
