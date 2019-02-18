#include <QtGlobal>

#include "MoveByLine.h"

MoveByLine::MoveByLine(MoveStrategy::DIRECTION dir)
    : MoveStrategy(dir)
{
}

void MoveByLine::move(qreal &x, qreal &y, qreal speed)
{
    if(direction() == DIRECTION::UP)
    {
        y -= speed;
    }
    else
    {
        y += speed;
    }
}
