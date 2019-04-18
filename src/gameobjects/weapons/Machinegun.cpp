#include "HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(const std::shared_ptr<QGraphicsScene> &scene,
                       const std::shared_ptr<MoveStrategy> &moveStrategy)
    : Weapon(scene, moveStrategy)
{
}

std::unique_ptr<HandWeapon> Machinegun::handWeapon()
{
    return std::make_unique<HandMachinegun>(scene());
}
