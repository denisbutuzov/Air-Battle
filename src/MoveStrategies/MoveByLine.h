#pragma once

#include "MoveStrategy.h"

class MoveByLine
        : public MoveStrategy
{
public:
    MoveByLine(DIRECTION dir, unsigned int speed);
    virtual void move(MovableObject &object) override final;
};
