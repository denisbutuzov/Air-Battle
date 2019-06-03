#pragma once

#include "HandWeapon.h"

class HandMachinegun
        : public HandWeapon
{
public:
    HandMachinegun(std::shared_ptr<QGraphicsScene> scene);
    virtual ~HandMachinegun() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
