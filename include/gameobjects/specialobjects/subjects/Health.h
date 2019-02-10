#pragma once

#include "AbstractSubject.h"

const unsigned int MAX_HEALTH = 5;

class Health
        : public AbstractSubject
{
public:
    static Health *instance();
    void increase();
    void decrease();
    unsigned int health() const;

protected:
    Health(unsigned int maxHealth = MAX_HEALTH);
    Health(const Health &other) = delete;
    Health(Health &&other) = delete;

    Health &operator=(const Health &other) = delete;
    Health &operator=(Health &&other) = delete;

private:
    static Health *instance_;
    unsigned int health_;
    unsigned int maxHealth_;
};
