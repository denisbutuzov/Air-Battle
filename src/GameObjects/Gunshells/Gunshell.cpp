#include "Visitors/AbstractVisitor.h"

#include "Gunshell.h"

Gunshell::Gunshell(std::shared_ptr<QGraphicsScene> scene,
                   const QString &pixmap,
                   int damage,
                   std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, pixmap, moveStrategy)
    , damage_(damage)
{
}

void Gunshell::accept(AbstractVisitor &visitor)
{
    visitor.visitGunshell(this);
}

void Gunshell::setDamage(int damage)
{
    damage_ = damage;
}

int Gunshell::damage() const
{
    return damage_;
}
