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

protected:
    Weapon(const std::shared_ptr<QGraphicsScene> &scene,
           std::unique_ptr<MoveStrategy> &&moveStrategy);
private:
    virtual std::unique_ptr<HandWeapon> handWeapon() = 0;
};
