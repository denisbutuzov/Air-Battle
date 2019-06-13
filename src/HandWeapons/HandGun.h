#pragma once

#include "HandWeapon.h"

class HandGun
        : public HandWeapon
{
public:
    HandGun(std::weak_ptr<QGraphicsScene> scene, int delayBetweenShots = 300);
    virtual ~HandGun() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
