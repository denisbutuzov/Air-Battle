#pragma once

#include "Enemy.h"

class Enemy1
        : public Enemy
{
public:
    Enemy1(QGraphicsScene *scene);

private:
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
