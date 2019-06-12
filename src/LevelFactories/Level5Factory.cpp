#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"
//#include "MoveStrategies/MoveByCurve.h"

#include "Level5Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy1.png";
constexpr const char *SHIELD_IMAGE = ":/images/images/EnemyShield.png";
constexpr const char *BAZOOKA_IMAGE = ":/images/images/Bazooka.png";

Level5Factory::Level5Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level5Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), 2);
//                                         std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), 2);
    shieldEnemy->setPixmap(QPixmap(SHIELD_IMAGE));
    return shieldEnemy;
}

std::unique_ptr<Weapon> Level5Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(BAZOOKA_IMAGE));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
