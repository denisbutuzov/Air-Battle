#include <cmath>

#include "GameObjects/MovableObject.h"

#include "MoveByCurve.h"

MoveByCurve::MoveByCurve(MoveStrategy::Direction dir,
                         unsigned int speed)
    : MoveStrategy(dir, speed)
{
}

void MoveByCurve::move(MovableObject &object)
{
    auto tempX = object.x();
    auto tempY = object.y();
    if(direction() == Direction::Up)
    {
        tempY -= speed();
    }
    else
    {
        tempY += speed();
    }
    tempX += 5 * std::sin(0.02 * tempY);
    object.setPos(tempX, tempY);
}
