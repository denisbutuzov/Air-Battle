#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandBazooka.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
HandBazooka::HandBazooka(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, AppSettings::instance().objects().bazooka_.capacity_,
                 AppSettings::instance().objects().bazooka_.startPatrons_,
                 AppSettings::instance().objects().bazooka_.shotDelay_,
                 AppSettings::instance().objects().bazooka_.shotSound_)
{
}

/*!
 * \param x Координата по оси Х на игровой сцене для порождения
 * оружейного снаряда базуки.
 * \param y Координата по оси Y на игровой сцене для порождения
 * оружейного снаряда базуки.
 *
 * \return Порожденный оружейный снаряд ручной базукой.
 *
 * Реализует создание оружейного снаряда ручной базукой.
 */
std::unique_ptr<Gunshell> HandBazooka::createGunshell(qreal x, qreal y)
{    
    auto gunshell = std::make_unique<Gunshell>(scene(), 2);
    gunshell->setPixmap(QPixmap(AppSettings::instance().objects().bazooka_.gunshell_));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
