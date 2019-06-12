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
    if(direction() == Direction::Up)
    {
        object.setY(object.y() - speed());
    }
    else
    {
        object.setY(object.y() + speed());
    }
    object.setX(object.x() + 5 * std::sin(0.02 * object.y()));
}
