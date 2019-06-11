#pragma once

#include "MoveStrategies/MoveByLine.h"
#include "Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(std::weak_ptr<QGraphicsScene> scene,
            std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::Direction::Down, 6));
    virtual ~Bazooka() override = default;
//    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};
