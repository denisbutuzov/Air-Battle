#include "Bazooka.h"
#include "Enemy1.h"

#include "Level2Factory.h"

Level2Factory::Level2Factory(QGraphicsScene *scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level2Factory::enemy() const
{
    return new Enemy1(scene());
}

Weapon *Level2Factory::weapon() const
{
    return new Bazooka(scene());
}

