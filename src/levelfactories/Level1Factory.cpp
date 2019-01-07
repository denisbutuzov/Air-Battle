#include "Machinegun.h"

#include "Level1Factory.h"

std::unique_ptr<Enemy> Level1Factory::enemy() const
{
    return std::make_unique<Enemy>();
}

std::unique_ptr<Weapon> Level1Factory::weapon() const
{
    return std::make_unique<Machinegun>();
}
