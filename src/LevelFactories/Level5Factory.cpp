#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "MoveStrategies/MoveByCurve.h"
#include "AppSettings.h"

#include "Level5Factory.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
Level5Factory::Level5Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект врага, защищенного щитом.
 */
std::unique_ptr<Enemy> Level5Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), 2, std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPixmap(QPixmap(AppSettings::instance().objects().enemy2_));
    enemy->setPos(randomPos(enemy->pixmap()));
    auto shieldEnemy = std::make_unique<ShieldDecorator>(std::move(enemy), 2);
    shieldEnemy->setPixmap(QPixmap(AppSettings::instance().objects().shield_));
    return shieldEnemy;
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект базуки.
 */
std::unique_ptr<Weapon> Level5Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(AppSettings::instance().objects().bazooka_.weapon_));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
