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

private:
    virtual void onMeetOtherObject(GameObject *otherObject) override;
    virtual std::unique_ptr<HandWeapon> handWeapon();
};
