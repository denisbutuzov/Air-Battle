#pragma once

#include "MoveStrategy.h"

class MoveByRandom
        : public MoveStrategy
{
public:
    MoveByRandom(DIRECTION dir);
    virtual void move(qreal &x, qreal &y, qreal speed) override final;
};
