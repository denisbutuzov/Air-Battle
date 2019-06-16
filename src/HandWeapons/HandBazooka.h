#pragma once

#include "HandWeapon.h"

class HandBazooka
        : public HandWeapon
{
public:
    HandBazooka(std::weak_ptr<QGraphicsScene> scene);
    virtual ~HandBazooka() override = default;
private:
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
};
