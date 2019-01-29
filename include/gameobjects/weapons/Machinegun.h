#pragma once

#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(QGraphicsScene *scene);

private:
    virtual void setObjectImage() override final;
    virtual HandWeapon *handWeapon() override final;
};



