#include "Visitors/AbstractVisitor.h"

#include "GameObjects/Gunshells/Gunshell.h"

Gunshell::Gunshell(const std::shared_ptr<QGraphicsScene> &scene,
                   const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, moveStrategy)
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
