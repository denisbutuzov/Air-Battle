#pragma once

#include "GameObjects/Enemies/EnemyDecorators/AbstractEnemyDecorator.h"

class ShieldDecorator
        : public AbstractEnemyDecorator
{
public:
    ShieldDecorator(std::unique_ptr<Enemy> enemy);
    virtual ~ShieldDecorator() override = default;
    virtual void init() override final;
    virtual void move() override final;

private:
    void resizeShield();
};
