#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "MoveStrategies/MoveByCurve.h"

#include "Level4Factory.h"

Level4Factory::Level4Factory(std::shared_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level4Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), ":/images/images/Enemy2.png", 2,
                                         std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level4Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/Bazooka.png");
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
