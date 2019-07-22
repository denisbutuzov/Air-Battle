#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Weapon.h"

/*!
 * \ingroup Game_objects
 * \brief Класс базуки.
 *
 * Реализует класс базуки, которую может подобрать игрок.
 */
class Bazooka
        : public Weapon
{
public:
    ///Конструктор с двумя аргументами.
    Bazooka(std::weak_ptr<QGraphicsScene> scene,
            std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    ///Деструктор по умолчанию.
    virtual ~Bazooka() override = default;
    ///Метод, пораждающий объект ручной базуки.
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};
