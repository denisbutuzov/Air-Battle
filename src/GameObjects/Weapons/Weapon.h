#pragma once

#include "MoveStrategies/MoveByLine.h"
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
    Weapon(std::shared_ptr<QGraphicsScene> scene,
           const QString &pixmap,
           const std::shared_ptr<MoveStrategy> &moveStrategy);
};
