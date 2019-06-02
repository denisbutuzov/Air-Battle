#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

Enemy::Enemy(std::shared_ptr<QGraphicsScene> scene,
             const QString &pixmap,
             int hitpoint,
             const std::shared_ptr<MoveStrategy> &moveStrategy)
    : MovableObject(scene, pixmap, moveStrategy)
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
