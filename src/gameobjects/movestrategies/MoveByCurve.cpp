#include <cmath>

#include "MoveByCurve.h"

MoveByCurve::MoveByCurve(MoveStrategy::DIRECTION dir)
    : MoveStrategy(dir)
{
}

void MoveByCurve::move(qreal &x, qreal &y, qreal speed)
{
    if(direction() == DIRECTION::UP)
    {
        y -= speed;
    }
    else
    {
        y += speed;
    }

    x += 5 * std::sin(0.02 * y);
}
