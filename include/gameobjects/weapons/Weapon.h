#pragma once

#include "SpawnObject.h"
#include "HandWeapon.h"

class Weapon
        : public SpawnObject
{
public slots:
    virtual void move() override final;

protected:
    Weapon(QGraphicsScene *scene);

private:
    virtual void setSpeed() override final;
    virtual HandWeapon *handWeapon() = 0;
};


