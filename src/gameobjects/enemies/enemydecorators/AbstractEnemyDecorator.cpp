#include "AbstractEnemyDecorator.h"

AbstractEnemyDecorator::AbstractEnemyDecorator(QGraphicsScene *scene, Enemy *enemy)
    : Enemy(scene, enemy->moveStrategy())
    , enemy_(enemy)
{
}

Enemy *AbstractEnemyDecorator::enemy() const
{
    return enemy_;
}

void AbstractEnemyDecorator::init()
{
    enemy_->init();
}
