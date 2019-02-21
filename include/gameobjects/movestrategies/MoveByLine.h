#pragma once

#include "MoveStrategy.h"

class MoveByLine
        : public MoveStrategy
{
public:
    MoveByLine(DIRECTION dir);
    virtual void move(MovableObject *object) override final;
};
