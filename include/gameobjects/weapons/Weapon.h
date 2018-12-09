#pragma once

#include "SpawnObject.h"
#include "IHandWeapon.h"

class Weapon
        : public SpawnObject
{
public:
    Weapon(QGraphicsItem *parent = nullptr);
public slots:
    virtual void move() override final;
private:
    virtual IHandWeapon *handWeapon() = 0;
    virtual void setSpeed() override final;
};


