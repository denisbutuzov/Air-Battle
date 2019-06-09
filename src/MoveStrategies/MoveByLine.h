#pragma once

#include "MoveStrategy.h"

class MoveByLine
        : public MoveStrategy
{
public:
    MoveByLine(Direction dir, unsigned int speed);
    virtual void move(MovableObject &object) override final;
};
