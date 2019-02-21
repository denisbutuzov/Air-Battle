#pragma once

#include "MoveStrategy.h"

class MoveByLine
        : public MoveStrategy
{
public:
    MoveByLine(DIRECTION dir);
    virtual void move(qreal &x, qreal &y, qreal speed) override final;
};
