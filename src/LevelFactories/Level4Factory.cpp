#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Bazooka.h"
#include "MoveStrategies/MoveByCurve.h"
#include "AppSettings.h"

#include "Level4Factory.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
Level4Factory::Level4Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект врага.
 */
std::unique_ptr<Enemy> Level4Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene(), 2, std::make_shared<MoveByCurve>(MoveStrategy::Direction::Down, 7));
    enemy->setPixmap(QPixmap(AppSettings::instance().objects().enemy2_));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект базуки.
 */
std::unique_ptr<Weapon> Level4Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(AppSettings::instance().objects().bazooka_.weapon_));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
