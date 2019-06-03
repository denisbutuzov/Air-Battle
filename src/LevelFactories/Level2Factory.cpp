#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Bazooka.h"

#include "Level2Factory.h"

Level2Factory::Level2Factory(std::shared_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level2Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), ":/images/images/Enemy2.png");
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level2Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/Bazooka.png");
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
