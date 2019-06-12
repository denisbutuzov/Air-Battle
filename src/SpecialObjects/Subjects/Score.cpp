#include "Score.h"

Score::Score()
    : score_(0)
{
}
void Score::increase()
{
    ++score_;
    notify();
}

unsigned int Score::value() const
{
    return score_;
}
