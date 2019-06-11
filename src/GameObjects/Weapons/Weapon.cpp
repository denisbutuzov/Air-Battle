#include "Visitors/AbstractVisitor.h"

#include "Weapon.h"

Weapon::Weapon(std::weak_ptr<QGraphicsScene> scene,
               std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void Weapon::accept(AbstractVisitor &visitor)
{
    visitor.visitWeapon(this);
}
