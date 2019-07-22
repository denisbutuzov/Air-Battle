#pragma once

#include "GameObjects/MovableObject.h"

class HandWeapon;

/*!
 * \ingroup Game_objects
 * \brief Абстрактный родительский класс всех класов оружия.
 *
 * Реализует класс оружия, которое может подобрать игрок.
 */
class Weapon
        : public MovableObject
{
public:
    ///Деструктор по умолчанию.
    virtual ~Weapon() override = default;
    ///Метод, принимающий объект посетителя.
    virtual void accept(AbstractVisitor &visitor) override final;
    ///Метод, порождающий соответствующий объект ручного оружия.
    virtual std::unique_ptr<HandWeapon> handWeapon() = 0;
protected:
    ///Конструктор с двумя аргументами.
    Weapon(std::weak_ptr<QGraphicsScene> scene,
           std::shared_ptr<MoveStrategy> moveStrategy);
};
