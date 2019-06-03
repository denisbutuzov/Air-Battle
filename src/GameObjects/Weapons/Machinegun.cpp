#include "HandWeapons/HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(std::shared_ptr<QGraphicsScene> scene,
                       const QString &pixmap,
                       std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, pixmap, moveStrategy)
{
}

std::unique_ptr<HandWeapon> Machinegun::handWeapon()
{
    return std::make_unique<HandMachinegun>(scene());
}
