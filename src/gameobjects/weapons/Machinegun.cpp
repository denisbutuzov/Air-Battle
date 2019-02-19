#include "HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

void Machinegun::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/machinegun.png"));
}

HandWeapon *Machinegun::handWeapon()
{
    return new HandMachinegun(scene());
}
