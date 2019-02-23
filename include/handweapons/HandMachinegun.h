#pragma once

#include "HandWeapon.h"

class HandMachinegun
        : public HandWeapon
{
public:
    HandMachinegun(QGraphicsScene *scene);
    virtual void shoot(qreal x, qreal y) override final;
};
