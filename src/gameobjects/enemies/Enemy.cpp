#include "Enemy.h"

Enemy::Enemy(const std::shared_ptr<QGraphicsScene> &scene,
             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : MovableObject(scene, std::move(moveStrategy))
{
}

void Enemy::setHitpoint(unsigned int hitpoint)
{
    hitpoint_ = hitpoint;
}

unsigned int Enemy::hitpoint() const
{
    return hitpoint_;
}
