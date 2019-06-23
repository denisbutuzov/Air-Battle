#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandMachinegun.h"

HandMachinegun::HandMachinegun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, AppSettings::instance().objects().machinegun_.capacity_,
                 AppSettings::instance().objects().machinegun_.startPatrons_,
                 AppSettings::instance().objects().machinegun_.shotDelay_,
                 AppSettings::instance().objects().machinegun_.shotSound_)
{
}

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
