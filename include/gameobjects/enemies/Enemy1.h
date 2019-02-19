#pragma once

#include "Enemy.h"

class Enemy1
        : public Enemy
{
public:
    Enemy1(QGraphicsScene *scene, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::DOWN));
    virtual ~Enemy1() override = default;

private:
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
