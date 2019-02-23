#include "Level.h"

Level *Level::instance_ = nullptr;

Level::Level(uint16_t maxLevel)
    : level_(1)
    , maxLevel_(maxLevel)
{
}

Level *Level::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Level();
    }
    return instance_;
}

uint16_t Level::level() const
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
