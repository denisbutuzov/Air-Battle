#pragma once

#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(const std::shared_ptr<QGraphicsScene> &scene,
               const QString &pixmap,
               const std::shared_ptr<MoveStrategy> &moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::DIRECTION::DOWN, 6));
    virtual ~Machinegun() override = default;
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};



