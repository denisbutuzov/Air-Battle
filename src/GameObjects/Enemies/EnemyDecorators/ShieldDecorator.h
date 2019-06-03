#pragma once

#include "AbstractEnemyDecorator.h"

class ShieldDecorator
        : public AbstractEnemyDecorator
{
public:
    ShieldDecorator(std::unique_ptr<Enemy> enemy, const QString &pixmap, int hitpoint = 1);
    virtual ~ShieldDecorator() override = default;
    virtual void init() override final;
    virtual void move() override final;

private:
    void resizeShield();
};
