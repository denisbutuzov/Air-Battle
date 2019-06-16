#pragma once

#include "HandWeapon.h"

class HandMachinegun
        : public HandWeapon
{
public:
    HandMachinegun(std::weak_ptr<QGraphicsScene> scene);
    virtual ~HandMachinegun() override = default;
private:
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
};
