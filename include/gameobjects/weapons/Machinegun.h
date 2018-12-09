#pragma once

#include "Weapon.h"

class Machinegun
        : public Weapon
{
public:
    Machinegun(QGraphicsItem *parent = nullptr);
private:
    virtual void setObjectImage() override final;
    virtual IHandWeapon *handWeapon() override final;
};



