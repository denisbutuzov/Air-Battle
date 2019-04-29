#include "AbstractEnemyDecorator.h"

AbstractEnemyDecorator::AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy,
                                               const QString &pixmap,
                                               int hitpoint)
    : Enemy(enemy->scene(), pixmap, hitpoint, enemy->moveStrategy())
    , enemy_(std::move(enemy))
{
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
