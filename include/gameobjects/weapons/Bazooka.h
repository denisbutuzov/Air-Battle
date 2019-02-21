#pragma once

#include "Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));

private:
    virtual void setObjectImage() override final;
    virtual HandWeapon *handWeapon() override final;
};
