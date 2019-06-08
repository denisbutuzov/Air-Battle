#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "MoveStrategies/MoveByCurve.h"

#include "Level5Factory.h"

Level5Factory::Level5Factory(std::shared_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level5Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), ":/images/images/Enemy1.png", 2,
                                         std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPos(randomPos(enemy->pixmap()));
    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), ":/images/images/EnemyShield.png", 3);
    return shieldEnemy;
}

std::unique_ptr<Weapon> Level5Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/Bazooka.png");
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
