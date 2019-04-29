#include "AbstractEnemyDecorator.h"

AbstractEnemyDecorator::AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy)
    : Enemy(enemy->scene(), enemy->moveStrategy())
    , enemy_(std::move(enemy))
{
    setSpeed(enemy_->speed());
}

void AbstractEnemyDecorator::init()
{
    Enemy::init();
    enemy_->init();
}

std::shared_ptr<Enemy> AbstractEnemyDecorator::enemy()
{
    return enemy_;
}
