#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "GameObjects/Weapons/Machinegun.h"

#include "Level3Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy2.png";
constexpr const char *SHIELD_IMAGE = ":/images/images/EnemyShield.png";
constexpr const char *MACHINEGUN_IMAGE = ":/images/images/Machinegun.png";
constexpr const char *BAZOOKA_IMAGE = ":/images/images/Bazooka.png";

Level3Factory::Level3Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level3Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), 2);
    shieldEnemy->setPixmap(QPixmap(SHIELD_IMAGE));
    return shieldEnemy;
}

std::unique_ptr<Weapon> Level3Factory::weapon()
{
    static unsigned int queue = 0;

    std::unique_ptr<Weapon> weapon;
    if(++queue <= 3)
    {
        weapon = std::make_unique<Machinegun>(scene());
        weapon->setPixmap(QPixmap(MACHINEGUN_IMAGE));
    }
    else
    {
        weapon = std::make_unique<Bazooka>(scene());
        weapon->setPixmap(QPixmap(BAZOOKA_IMAGE));
        queue = 0;
    }
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
