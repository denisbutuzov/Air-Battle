#pragma once

#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));

private:
    virtual void setObjectImage() override final;
    virtual HandWeapon *handWeapon() override final;
};



