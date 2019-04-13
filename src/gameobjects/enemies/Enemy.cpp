#include "AbstractVisitor.h"

#include "Enemy.h"

Enemy::Enemy(const std::shared_ptr<QGraphicsScene> &scene,
             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Enemy::accept(AbstractVisitor &visitor)
{
    visitor.visitEnemy(this);
}

void Enemy::setHitpoint(unsigned int hitpoint)
{
    hitpoint_ = hitpoint;
}

unsigned int Enemy::hitpoint() const
{
    return hitpoint_;
}
