#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Machinegun.h"
#include "AppSettings.h"

#include "Level2Factory.h"

Level2Factory::Level2Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level2Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(AppSettings::instance().objects().enemy2_));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

std::unique_ptr<Weapon> Level2Factory::weapon()
{
    auto weapon = std::make_unique<Machinegun>(scene());
    weapon->setPixmap(QPixmap(AppSettings::instance().objects().machinegun_.weapon_));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
