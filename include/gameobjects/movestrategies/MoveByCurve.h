#pragma once

#include "MoveStrategy.h"

class MoveByCurve
        : public MoveStrategy
{
public:
    MoveByCurve(DIRECTION dir);
    virtual void move(qreal &x, qreal &y, qreal speed) override final;
};
