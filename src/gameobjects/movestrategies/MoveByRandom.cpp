#include "MovableObject.h"

#include "MoveByRandom.h"

MoveByRandom::MoveByRandom(MoveStrategy::DIRECTION dir)
    : MoveStrategy(dir)
{
}

void MoveByRandom::move(MovableObject &object)
{
    auto tempX = object.x();
    auto tempY = object.y();
    if(direction() == DIRECTION::UP)
    {
        tempY -= object.speed();
    }
    else
    {
        tempY += object.speed();
    }
    tempX += 10 * (rand() % 3 - 1);
    object.setPos(tempX, tempY);
}
