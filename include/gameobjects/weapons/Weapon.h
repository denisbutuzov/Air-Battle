#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class HandWeapon;

class Weapon
        : public MovableObject
{
public:
    virtual ~Weapon() override = default;
    virtual void accept(AbstractVisitor &visitor) override final;
    virtual std::unique_ptr<HandWeapon> handWeapon() = 0;

protected:
    Weapon(const std::shared_ptr<QGraphicsScene> &scene,
           const std::shared_ptr<MoveStrategy> &moveStrategy);
};
