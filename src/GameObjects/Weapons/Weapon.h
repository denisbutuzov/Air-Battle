#pragma once

#include "GameObjects/MovableObject.h"

class HandWeapon;

class Weapon
        : public MovableObject
{
public:
    virtual ~Weapon() override = default;
    virtual void accept(AbstractVisitor &visitor) override final;
    virtual std::unique_ptr<HandWeapon> handWeapon() = 0;
protected:
    Weapon(std::weak_ptr<QGraphicsScene> scene,
           std::shared_ptr<MoveStrategy> moveStrategy);
};
