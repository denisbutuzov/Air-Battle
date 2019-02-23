#pragma once

#include "MoveStrategy.h"

class MoveByCurve
        : public MoveStrategy
{
public:
    MoveByCurve(DIRECTION dir);
    virtual void move(MovableObject *object) override final;
};
