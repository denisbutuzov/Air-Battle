#include "Bazooka.h"
#include "Enemy1.h"
#include "ShieldDecorator.h"

#include "Level3Factory.h"

Level3Factory::Level3Factory(QGraphicsScene *scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level3Factory::enemy() const
{
    return new ShieldDecorator(scene(), new Enemy1(scene()));
}

Weapon *Level3Factory::weapon() const
{
    return new Bazooka(scene());
}
