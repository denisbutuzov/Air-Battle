#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

Enemy::Enemy(const std::shared_ptr<QGraphicsScene> &scene,
             const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, moveStrategy)
{
}

void Enemy::accept(AbstractVisitor &visitor)
{
    visitor.visitEnemy(this);
}

void Enemy::setHitpoint(int hitpoint)
{
    hitpoint_ = hitpoint;
}

int Enemy::hitpoint() const
{
    return hitpoint_;
}
