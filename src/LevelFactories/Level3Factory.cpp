#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"

#include "Level3Factory.h"

Level3Factory::Level3Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level3Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), ":/images/images/Enemy2.png");
    auto shield = std::make_unique<ShieldDecorator>(std::move(enemy), ":/images/images/EnemyShield.png", 2);
    shield->setPos(randomPos(shield->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level3Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/bazooka.png");
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
