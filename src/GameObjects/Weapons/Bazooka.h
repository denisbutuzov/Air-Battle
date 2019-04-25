#pragma once

#include "GameObjects/Weapons/Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(const std::shared_ptr<QGraphicsScene> &scene,
            const QString &pixmap,
            const std::shared_ptr<MoveStrategy> &moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Bazooka() override = default;
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};
