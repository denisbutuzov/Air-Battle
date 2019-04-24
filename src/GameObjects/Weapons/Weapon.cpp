#include "Visitors/AbstractVisitor.h"

#include "Weapon.h"

Weapon::Weapon(const std::shared_ptr<QGraphicsScene> &scene,
               const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void Weapon::accept(AbstractVisitor &visitor)
{
    visitor.visitWeapon(this);
}
