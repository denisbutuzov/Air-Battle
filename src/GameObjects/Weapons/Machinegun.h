#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    virtual ~Machinegun() override = default;
//    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};



