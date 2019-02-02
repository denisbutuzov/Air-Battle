#include "ShieldDecorator.h"

ShieldDecorator::ShieldDecorator(QGraphicsScene *scene, Enemy *enemy)
    : AbstractEnemyDecorator(scene, enemy)
{
}

void ShieldDecorator::init()
{
    AbstractEnemyDecorator::init();
    Enemy::init();
}

void ShieldDecorator::setStartObjectPos()
{
    setPos(enemy()->pos());
}

void ShieldDecorator::setHitpoint()
{
    Enemy::setHitpoint(2);
}

void ShieldDecorator::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/EnemyShield.png"));
}
