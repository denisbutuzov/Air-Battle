#pragma once

#include "MoveByLine.h"
#include "SpawnObject.h"

class HandWeapon;

class Weapon
        : public SpawnObject
{
protected:
    Weapon(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));

private:
    virtual void setSpeed() override final;
    virtual void OnMeetOtherObject(GameObject *otherObject) override;
    virtual HandWeapon *handWeapon() = 0;
};


