#pragma once

#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(const std::shared_ptr<QGraphicsScene> &scene,
               std::unique_ptr<MoveStrategy> &&moveStrategy = std::make_unique<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Machinegun() override = default;

private:
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};



