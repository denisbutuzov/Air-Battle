#pragma once

#include <memory>

#include "Enemy.h"
#include <Weapon.h>

class AbstractLevelFactory
{
public:
    virtual ~AbstractLevelFactory() = default;

    virtual std::unique_ptr<Enemy> enemy() const = 0;
    virtual std::unique_ptr<Weapon> weapon() const = 0;
};
