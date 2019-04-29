#pragma once

#include "MoveStrategy.h"

class MoveByCurve
        : public MoveStrategy
{
public:
    MoveByCurve(DIRECTION dir, unsigned int);
    virtual void move(MovableObject &object) override final;
};
