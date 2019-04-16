#include "HandMachinegun.h"

#include "Machinegun.h"

Machinegun::Machinegun(const std::shared_ptr<QGraphicsScene> &scene,
                       std::unique_ptr<MoveStrategy> &&moveStrategy)
    : Weapon(scene, std::move(moveStrategy))
{
}

std::unique_ptr<HandWeapon> Machinegun::handWeapon()
{
    return std::make_unique<HandMachinegun>(scene());
}
