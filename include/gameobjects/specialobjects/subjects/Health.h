#pragma once

#include <cstdint>

#include "AbstractSubject.h"

const uint16_t MAX_HEALTH = 5;

class Health
        : public AbstractSubject
{
public:
    static Health *instance();
    void increase();
    void decrease();
    uint16_t health() const;

protected:
    Health(uint16_t maxHealth = MAX_HEALTH);
    Health(const Health &other) = delete;
    Health(Health &&other) = delete;

    Health &operator=(const Health &other) = delete;
    Health &operator=(Health &&other) = delete;

private:
    static Health *instance_;
    uint16_t health_;
    uint16_t maxHealth_;
};
