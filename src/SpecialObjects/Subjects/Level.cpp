#include "Level.h"

Level::Level(unsigned int maxLevel)
    : level_(1)
    , maxLevel_(maxLevel)
{
}

unsigned int Level::value() const
{
    return level_;
}

void Level::increase()
{
    if(level_ < maxLevel_)
    {
        ++level_;
        notify();
    }
}
