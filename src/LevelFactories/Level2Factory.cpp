#include "GameObjects/Enemies/Enemy.h"

#include "Level2Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy2.png";

Level2Factory::Level2Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level2Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

//std::unique_ptr<Weapon> Level2Factory::weapon()
//{
//    auto weapon = std::make_unique<Bazooka>(scene(), ":/images/images/Bazooka.png");
//    weapon->setPos(randomPos(weapon->pixmap()));
//    return weapon;
//}
