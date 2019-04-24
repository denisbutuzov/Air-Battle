#include <cmath>

#include "MovableObject.h"

#include "MoveByCurve.h"

MoveByCurve::MoveByCurve(MoveStrategy::DIRECTION dir)
    : MoveStrategy(dir)
{
}

void MoveByCurve::move(MovableObject &object)
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
    tempX += 5 * std::sin(0.02 * tempY);
    object.setPos(tempX, tempY);
}
