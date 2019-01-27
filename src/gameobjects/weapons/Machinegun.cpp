#include "HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(QGraphicsScene *scene)
    : Weapon(scene)
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
