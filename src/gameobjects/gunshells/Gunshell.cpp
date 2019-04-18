#include "AbstractVisitor.h"

#include "Gunshell.h"

Gunshell::Gunshell(const std::shared_ptr<QGraphicsScene> &scene,
                   const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void Gunshell::accept(AbstractVisitor &visitor)
{
    visitor.visitGunshell(this);
}

void Gunshell::setDamage(unsigned int damage)
{
    damage_ = damage;
}

unsigned int Gunshell::damage() const
{
    return damage_;
}
