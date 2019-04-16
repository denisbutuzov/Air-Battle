#include "AbstractVisitor.h"

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
