#include "MoveStrategy.h"

MoveStrategy::MoveStrategy(MoveStrategy::DIRECTION dir)
    : dir_(dir)
{
}

MoveStrategy::DIRECTION MoveStrategy::direction() const
{
    return dir_;
}
