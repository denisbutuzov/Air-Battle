#pragma once

#include "Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(const std::shared_ptr<QGraphicsScene> &scene,
            std::unique_ptr<MoveStrategy> &&moveStrategy = std::make_unique<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Bazooka() override = default;
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};
