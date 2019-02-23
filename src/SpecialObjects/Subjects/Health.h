#pragma once

#include "AbstractSubject.h"

constexpr int MAX_HEALTH = 5;

class Health
        : public AbstractSubject
{
public:
    static Health *instance();
    void increase();
    void decrease();
    int value() const;

protected:
    Health(int maxHealth = MAX_HEALTH);
    Health(const Health &other) = delete;
    Health(Health &&other) = delete;

    Health &operator=(const Health &other) = delete;
    Health &operator=(Health &&other) = delete;

private:
    static Health *instance_;
    int health_;
    int maxHealth_;
};
