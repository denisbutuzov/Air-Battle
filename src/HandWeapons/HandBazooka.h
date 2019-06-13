#pragma once

#include "HandWeapon.h"

class HandBazooka
        : public HandWeapon
{
public:
    HandBazooka(std::weak_ptr<QGraphicsScene> scene, int delayBetweenShots = 600);
    virtual ~HandBazooka() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
