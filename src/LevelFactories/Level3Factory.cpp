#include "GameObjects/Enemies/Enemy.h"

#include "Level3Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy2.png";

Level3Factory::Level3Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level3Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
//    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), ":/images/images/EnemyShield.png", 2);
//    return shieldEnemy;
}

//std::unique_ptr<Weapon> Level3Factory::weapon()
//{
//    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/Bazooka.png");
//    weapon->setPos(randomPos(weapon->pixmap()));
//    return weapon;
//}
