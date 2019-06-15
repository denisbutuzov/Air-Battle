#pragma once

#include "HandWeapon.h"

class HandGun
        : public HandWeapon
{
public:
    HandGun(std::weak_ptr<QGraphicsScene> scene);
    virtual ~HandGun() override = default;
private:
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) override final;
    virtual bool patronsExist() const override final;
};
