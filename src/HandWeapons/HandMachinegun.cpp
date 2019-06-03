#include "GameObjects/Gunshells/Gunshell.h"

#include "HandMachinegun.h"

HandMachinegun::HandMachinegun(std::shared_ptr<QGraphicsScene> scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandMachinegun::shoot(qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;

    std::unique_ptr<Gunshell> gunshell;
    if(side == SIDE::LEFT)
    {
        side = SIDE::RIGHT;
        gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/Machinegun_gunshell.png", 1);
        gunshell->setPos(QPointF(x - 30.0, y + 60.0));
    }
    else if(side == SIDE::RIGHT)
    {
        side = SIDE::LEFT;
        gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/Machinegun_gunshell.png", 1);
        gunshell->setPos(QPointF(x + 30.0, y + 60.0));
    }
    return gunshell;
}
