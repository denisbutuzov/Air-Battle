#include "MoveStrategy.h"

MoveStrategy::MoveStrategy(MoveStrategy::Direction dir,
                           unsigned int speed)
    : dir_(dir)
    , speed_(speed)
{
}

MoveStrategy::Direction MoveStrategy::direction() const
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
