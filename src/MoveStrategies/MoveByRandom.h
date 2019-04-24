#pragma once

#include "MoveStrategy.h"

class MoveByRandom
        : public MoveStrategy
{
public:
    MoveByRandom(DIRECTION dir);
    virtual void move(MovableObject &object) override final;
};
