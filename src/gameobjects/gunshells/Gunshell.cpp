#include "Enemy.h"

#include "Gunshell.h"

Gunshell::Gunshell(const std::shared_ptr<QGraphicsScene> &scene,
                   std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Gunshell::setDamage(unsigned int damage)
{
    damage_ = damage;
}

unsigned int Gunshell::damage() const
{
    return damage_;
}
