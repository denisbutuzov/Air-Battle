#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Bazooka.h"
//#include "MoveStrategies/MoveByCurve.h"

#include "Level4Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy2.png";
constexpr const char *BAZOOKA_IMAGE = ":/images/images/Bazooka.png";

Level4Factory::Level4Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level4Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), 2);
//                                         std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level4Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(BAZOOKA_IMAGE));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
