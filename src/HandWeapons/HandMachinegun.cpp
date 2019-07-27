#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandMachinegun.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
HandMachinegun::HandMachinegun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, AppSettings::instance().objects().machinegun_.capacity_,
                 AppSettings::instance().objects().machinegun_.startPatrons_,
                 AppSettings::instance().objects().machinegun_.shotDelay_,
                 AppSettings::instance().objects().machinegun_.shotSound_)
{
}

/*!
 * \param x Координата по оси Х на игровой сцене для порождения
 * оружейного снаряда пулемета.
 * \param y Координата по оси Y на игровой сцене для порождения
 * оружейного снаряда пулемета.
 *
 * \return Порожденный оружейный снаряд ручным пулеметом.
 *
 * Реализует создание оружейного снаряда ручным пулеметом.
 */
std::unique_ptr<Gunshell> HandMachinegun::createGunshell(qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;

    std::unique_ptr<Gunshell> gunshell;
    if(side == SIDE::LEFT)
    {
        side = SIDE::RIGHT;
        gunshell = std::make_unique<Gunshell>(scene(), 1);
        gunshell->setPos(QPointF(x - 30.0, y + 60.0));
    }
    else if(side == SIDE::RIGHT)
    {
        side = SIDE::LEFT;
        gunshell = std::make_unique<Gunshell>(scene(), 1);
        gunshell->setPos(QPointF(x + 30.0, y + 60.0));
    }
    gunshell->setPixmap(QPixmap(AppSettings::instance().objects().machinegun_.gunshell_));
    return gunshell;
}
