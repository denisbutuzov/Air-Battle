#include "GameObjects/Gunshells/Gunshell.h"

#include "HandMachinegun.h"

constexpr const char *MACHINEGUN_GUNSHELL_IMAGE = ":/images/images/Machinegun_gunshell.png";

HandMachinegun::HandMachinegun(std::weak_ptr<QGraphicsScene> scene)
//, int delayBetweenShots)
    : HandWeapon(scene)
//                 , delayBetweenShots)
{
}

std::unique_ptr<Gunshell> HandMachinegun::shoot(qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;

//    HandWeapon::startDelayBetweenShotsTimer();
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
    gunshell->setPixmap(QPixmap(MACHINEGUN_GUNSHELL_IMAGE));
    return gunshell;
}
