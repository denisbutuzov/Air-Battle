#pragma once

#include "MoveStrategy.h"

class MoveByLine
        : public MoveStrategy
{
public:
    MoveByLine() = default;
    virtual void move(qreal &x, qreal &y) override final;
};
