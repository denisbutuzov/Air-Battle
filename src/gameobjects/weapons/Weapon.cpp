#include "PlayerObject.h"
#include "HandWeapon.h"

#include "Weapon.h"

Weapon::Weapon(const std::shared_ptr<QGraphicsScene> &scene,
               std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

std::unique_ptr<HandWeapon> Weapon::handWeapon()
{
    return std::make_unique<HandWeapon>(scene());
}
