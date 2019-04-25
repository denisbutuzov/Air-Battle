#include "MoveStrategy.h"

MoveStrategy::MoveStrategy(MoveStrategy::DIRECTION dir,
                           unsigned int speed)
    : dir_(dir)
    , speed_(speed)
{
}

MoveStrategy::DIRECTION MoveStrategy::direction() const
{
    return dir_;
}

void MoveStrategy::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

unsigned int MoveStrategy::speed() const
{
    return speed_;
}
