#pragma once

#include "AbstractEnemyDecorator.h"

class ShieldDecorator
        : public AbstractEnemyDecorator
{
public:
    ShieldDecorator(std::unique_ptr<Enemy> enemy);
    virtual ~ShieldDecorator() override = default;
    virtual void move() override final;
};
