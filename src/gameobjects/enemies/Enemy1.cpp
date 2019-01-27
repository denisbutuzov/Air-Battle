#include "Enemy1.h"

Enemy1::Enemy1(QGraphicsScene *scene)
    : Enemy(scene)
{
}

void Enemy1::setHitpoint()
{
    Enemy::setHitpoint(2);
}

void Enemy1::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/Enemy1.png"));
}
