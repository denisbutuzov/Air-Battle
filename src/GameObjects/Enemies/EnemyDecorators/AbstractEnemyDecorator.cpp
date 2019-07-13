#include "AbstractEnemyDecorator.h"

AbstractEnemyDecorator::AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy,
                                               int hitpoint)
    : Enemy(enemy->scene(), hitpoint, enemy->moveStrategy())
    , enemy_(std::move(enemy))
{
    setEnemyType(EnemyType::Decorator);
}

void AbstractEnemyDecorator::init()
{
    Enemy::init();
    enemy_->init();
}

std::unique_ptr<Enemy> &AbstractEnemyDecorator::enemy()
{
    return enemy_;
}
