#include "GameObjects/MovableObject.h"

#include "MoveByLine.h"

MoveByLine::MoveByLine(MoveStrategy::Direction dir,
                       unsigned int speed)
    : MoveStrategy(dir, speed)
{
}

void MoveByLine::move(MovableObject &object)
{
    if(direction() == Direction::Up)
    {
        object.setY(object.y() - speed());
    }
    else
    {
        object.setY(object.y() + speed());
    }
}
