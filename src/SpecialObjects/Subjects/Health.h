#pragma once

#include "AbstractSubject.h"

constexpr int MAX_HEALTH = 5;

class Health
        : public AbstractSubject
{
public:
    explicit Health(int maxHealth = MAX_HEALTH);
    void increase();
    void decrease();
    int value() const;
private:
    int health_;
    int maxHealth_;
};
