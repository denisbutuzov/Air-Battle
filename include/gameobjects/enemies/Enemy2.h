#pragma once

#include "Enemy.h"

class Enemy2
        : public Enemy
{
public:
    Enemy2(QGraphicsScene *scene);
    virtual ~Enemy2() override = default;

private:
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
