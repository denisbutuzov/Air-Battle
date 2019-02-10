#include "Health.h"

Health *Health::instance_ = nullptr;

Health::Health(unsigned int maxHealth)
    : health_(maxHealth)
    , maxHealth_(maxHealth)
{
}

Health *Health::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Health();
    }
    return instance_;
}

void Health::increase()
{
    if (health_ < maxHealth_)
    {
        ++health_;
        notify();
    }
}

void Health::decrease()
{
    if (health_ > 0)
    {
        --health_;
        notify();
    }
}

unsigned int Health::health() const
{
    return health_;
}
