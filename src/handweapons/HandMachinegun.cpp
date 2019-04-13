#include "Gunshell.h"
#include "PresetPositionBuilder.h"

#include "HandMachinegun.h"

HandMachinegun::HandMachinegun(const std::shared_ptr<QGraphicsScene> &scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandMachinegun::shoot(qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;

    PresetPositionBuilder builder;
    std::unique_ptr<Gunshell> gunshell;
    if(side == SIDE::LEFT)
    {
        side = SIDE::RIGHT;
        gunshell = builder.buildGunshell(scene(), 10, 1, ":/images/images/Bullet.png", QPointF(x - 30.0, y + 60.0));
    }
    else if(side == SIDE::RIGHT)
    {
        side = SIDE::LEFT;
        gunshell = builder.buildGunshell(scene(), 10, 1, ":/images/images/Bullet.png", QPointF(x + 30.0, y + 60.0));
    }
    return gunshell;
}
