#pragma once

#include "Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(QGraphicsScene *scene);

private:
    virtual void setObjectImage() override final;
    virtual HandWeapon *handWeapon() override final;
};
