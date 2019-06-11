#include "Visitors/AbstractVisitor.h"

#include "Gunshell.h"

Gunshell::Gunshell(std::weak_ptr<QGraphicsScene> scene,
                   int damage,
                   std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
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
