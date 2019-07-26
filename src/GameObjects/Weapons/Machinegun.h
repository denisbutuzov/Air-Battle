#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Weapon.h"

/*!
 * \ingroup Game_objects
 * \brief Класс пулемета.
 *
 * Реализует класс пулемета, который может подобрать игрок.
 */
class Machinegun
        : public Weapon
{
public:
    ///Конструктор с двумя аргументами.
    Machinegun(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    ///Деструктор по умолчанию.
    virtual ~Machinegun() override = default;
    ///Метод, пораждающий объект ручного пулемета.
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};



