#pragma once

#include "GameObjects/Enemies/Enemy.h"

class AbstractEnemyDecorator
        : public Enemy
{
public:
    virtual ~AbstractEnemyDecorator() override = default;
    virtual void init() override;
    std::unique_ptr<Enemy> &enemy();
protected:
    AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy, int hitpoint);
private:
    std::unique_ptr<Enemy> enemy_;
};
