#include "GameObjects/MovableObject.h"

#include "MoveByLine.h"

MoveByLine::MoveByLine(MoveStrategy::DIRECTION dir,
                       unsigned int speed)
    : MoveStrategy(dir, speed)
{
}

void MoveByLine::move(MovableObject &object)
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
    object.setPos(tempX, tempY);
}
