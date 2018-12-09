#pragma once

#include "Weapon.h"

class Bazooka
        : public Weapon
{
public:
    Bazooka(QGraphicsItem *parent = nullptr);
private:
    virtual void setObjectImage() override final;
};
