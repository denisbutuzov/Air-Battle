#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Machinegun.h"

#include "Level1Factory.h"

Level1Factory::Level1Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level1Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), ":/images/images/Enemy1.png");
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level1Factory::weapon()
{
    auto weapon = std::make_unique<Machinegun>(scene(), ":/images/images/machinegun.png");
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
