#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Machinegun.h"

#include "Level2Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy2.png";
constexpr const char *MACHINEGUN_IMAGE = ":/images/images/Machinegun.png";

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

std::unique_ptr<Weapon> Level2Factory::weapon()
{
    auto weapon = std::make_unique<Machinegun>(scene());
    weapon->setPixmap(QPixmap(MACHINEGUN_IMAGE));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
