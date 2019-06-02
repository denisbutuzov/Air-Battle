#include "Visitors/AbstractVisitor.h"

#include "Weapon.h"

Weapon::Weapon(std::shared_ptr<QGraphicsScene> scene,
               const QString &pixmap,
               const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, pixmap, moveStrategy)
{
}

void Weapon::accept(AbstractVisitor &visitor)
{
    visitor.visitWeapon(this);
}
