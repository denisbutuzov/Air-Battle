#include "HandWeapons/HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(std::weak_ptr<QGraphicsScene> scene,
                       std::shared_ptr<MoveStrategy> moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

std::unique_ptr<HandWeapon> Machinegun::handWeapon()
{
    return std::make_unique<HandMachinegun>(scene());
}
