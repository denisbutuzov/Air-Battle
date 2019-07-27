#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandGun.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
HandGun::HandGun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, AppSettings::instance().objects().gun_.capacity_,
                 AppSettings::instance().objects().gun_.startPatrons_,
                 AppSettings::instance().objects().gun_.shotDelay_,
                 AppSettings::instance().objects().gun_.shotSound_)
{
}

/*!
 * \param x Координата по оси Х на игровой сцене для порождения
 * оружейного снаряда пистолета.
 * \param y Координата по оси Y на игровой сцене для порождения
 * оружейного снаряда пистолета.
 *
 * \return Порожденный оружейный снаряд ручным пистолетом.
 *
 * Реализует создание оружейного снаряда ручным пистолетом.
 */
std::unique_ptr<Gunshell> HandGun::createGunshell(qreal x, qreal y)
{
    auto gunshell = std::make_unique<Gunshell>(scene(), 1);
    gunshell->setPixmap(QPixmap(AppSettings::instance().objects().gun_.gunshell_));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}

/*!
 * \return true
 *
 * Возвращает true - если безлимитное количество патронов, false - в другом случаем.
 */
bool HandGun::unlimitedPatrons() const
{
    return true;
}
