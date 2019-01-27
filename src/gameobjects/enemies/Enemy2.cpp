#include "Enemy2.h"

Enemy2::Enemy2(QGraphicsScene *scene)
    : Enemy(scene)
{
}

void Enemy2::setHitpoint()
{
    Enemy::setHitpoint(3);
}

void Enemy2::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/Enemy2.png"));
}
