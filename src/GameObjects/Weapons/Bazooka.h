#pragma once

#include "GameObjects/Weapons/Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(std::shared_ptr<QGraphicsScene> scene,
            const QString &pixmap,
            std::shared_ptr<MoveStrategy> moveStrategy = std::make_shared<MoveByLine>(MoveStrategy::DIRECTION::DOWN, 6));
    virtual ~Bazooka() override = default;
    virtual std::unique_ptr<HandWeapon> handWeapon() override final;
};
