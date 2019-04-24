#pragma once

#include "Enemy.h"

class Enemy2
        : public Enemy
{
public:
    Enemy2(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));
    virtual ~Enemy2() override = default;

private:
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
