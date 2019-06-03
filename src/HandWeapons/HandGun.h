#pragma once

#include "HandWeapon.h"

class HandGun
        : public HandWeapon
{
public:
    HandGun(std::shared_ptr<QGraphicsScene> scene);
    virtual ~HandGun() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
