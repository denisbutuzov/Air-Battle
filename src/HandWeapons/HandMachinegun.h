#pragma once

#include "HandWeapon.h"

class HandMachinegun
        : public HandWeapon
{
public:
    HandMachinegun(std::weak_ptr<QGraphicsScene> scene);
//    , int delayBetweenShots = 100);
    virtual ~HandMachinegun() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
