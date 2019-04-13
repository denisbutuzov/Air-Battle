#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class HandWeapon;

class Weapon
        : public MovableObject
{
public:
    Weapon(const std::shared_ptr<QGraphicsScene> &scene,
           std::unique_ptr<MoveStrategy> &&moveStrategy = std::make_unique<MoveByLine>(MoveStrategy::DIRECTION::DOWN));
    virtual ~Weapon() override = default;
    virtual void accept(AbstractVisitor &visitor) override;

private:
    virtual std::unique_ptr<HandWeapon> handWeapon();
};
