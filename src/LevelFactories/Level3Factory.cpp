#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "GameObjects/Weapons/Machinegun.h"
#include "AppSettings.h"

#include "Level3Factory.h"

Level3Factory::Level3Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level3Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(AppSettings::instance().objects().enemy2_));
    enemy->setPos(randomPos(enemy->pixmap()));
    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), 2);
    shieldEnemy->setPixmap(QPixmap(AppSettings::instance().objects().shield_));
    return shieldEnemy;
}

std::unique_ptr<Weapon> Level3Factory::weapon()
{
    static unsigned int queue = 0;

    std::unique_ptr<Weapon> weapon;
    if(++queue <= 3)
    {
        weapon = std::make_unique<Machinegun>(scene());
        weapon->setPixmap(QPixmap(AppSettings::instance().objects().machinegun_.weapon_));
    }
    else
    {
        weapon = std::make_unique<Bazooka>(scene());
        weapon->setPixmap(QPixmap(AppSettings::instance().objects().bazooka_.weapon_));
        queue = 0;
    }
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
