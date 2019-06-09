#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

Enemy::Enemy(std::weak_ptr<QGraphicsScene> scene,
             int hitpoint,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , hitpoint_(hitpoint)
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
