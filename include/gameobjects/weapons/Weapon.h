#pragma once

#include "MoveByLine.h"
#include "MovableObject.h"

class HandWeapon;

class Weapon
        : public MovableObject
{
public:
    Weapon(QGraphicsScene &scene,
           MoveStrategy &&moveStrategy = MoveByLine(MoveStrategy::DIRECTION::DOWN));
    virtual ~Weapon() override = default;

private:
    virtual void onMeetOtherObject(GameObject *otherObject) override;
    virtual HandWeapon &handWeapon();
};
