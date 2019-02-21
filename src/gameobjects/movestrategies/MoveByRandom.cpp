#include "MoveByRandom.h"

MoveByRandom::MoveByRandom(MoveStrategy::DIRECTION dir)
    : MoveStrategy(dir)
{
}

void MoveByRandom::move(qreal &x, qreal &y, qreal speed)
{
    if(direction() == DIRECTION::UP)
    {
        y -= speed;
    }
    else
    {
        y += speed;
    }

    x += 10 * (rand() % 3 - 1);
}
