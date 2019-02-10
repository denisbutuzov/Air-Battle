#include "Score.h"

Score *Score::instance_ = nullptr;

Score::Score()
    : score_(0)
{
}

Score *Score::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Score();
    }
    return instance_;
}

void Score::increase()
{
    ++score_;
    notify();
}

unsigned int Score::score() const
{
    return score_;
}
