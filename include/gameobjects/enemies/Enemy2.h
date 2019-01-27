#pragma once

#include "Enemy.h"

class Enemy2
        : public Enemy
{
public:
    Enemy2(QGraphicsScene *scene);

private:
    virtual void setHitpoint() override final;
    virtual void setObjectImage() override final;
};
