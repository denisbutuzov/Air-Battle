#pragma once

#include "MoveStrategy.h"

class MoveByCurve
        : public MoveStrategy
{
public:
    MoveByCurve() = default;
    virtual void move(qreal &x, qreal &y) override final;
};
