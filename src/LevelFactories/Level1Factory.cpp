#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Machinegun.h"
#include "AppSettings.h"

#include "Level1Factory.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
Level1Factory::Level1Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект врага.
 */
std::unique_ptr<Enemy> Level1Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(AppSettings::instance().objects().enemy1_));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}

/*!
 * \return Указатель с исключительными правами владения на
 * объект пулемета.
 */
std::unique_ptr<Weapon> Level1Factory::weapon()
{
    auto weapon = std::make_unique<Machinegun>(scene());
    weapon->setPixmap(QPixmap(AppSettings::instance().objects().machinegun_.weapon_));
    weapon->setPos(randomPos(weapon->pixmap()));
    return weapon;
}
