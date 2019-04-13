#include "AbstractVisitor.h"
#include "PlayerObject.h"
#include "HandGun.h"

#include "Weapon.h"

Weapon::Weapon(const std::shared_ptr<QGraphicsScene> &scene,
               std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Weapon::accept(AbstractVisitor &visitor)
{
    visitor.visitWeapon(this);
}

std::unique_ptr<HandWeapon> Weapon::handWeapon()
{
    return std::make_unique<HandGun>(scene());
}
