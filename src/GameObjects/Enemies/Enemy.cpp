#include <QGraphicsScene>

#include "Visitors/AbstractVisitor.h"

#include "Enemy.h"

Enemy::Enemy(std::weak_ptr<QGraphicsScene> scene,
             int hitpoint,
             std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , hitpoint_(hitpoint)
{
}

Enemy::~Enemy()
{
    if(auto wp = scene().lock())
    {
        if(pos().y() < wp->sceneRect().height())
        {
            qDebug("Enemy was destroyed by Player");
        }
    }
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
