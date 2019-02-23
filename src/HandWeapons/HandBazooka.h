#pragma once

#include "HandWeapon.h"

class HandBazooka
        : public HandWeapon
{
public:
    HandBazooka(const std::shared_ptr<QGraphicsScene> &scene);
    virtual ~HandBazooka() override = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) override final;
};
