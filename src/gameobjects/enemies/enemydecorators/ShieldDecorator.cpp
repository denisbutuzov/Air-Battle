#include "ShieldDecorator.h"

ShieldDecorator::ShieldDecorator(std::unique_ptr<Enemy> enemy)
    : AbstractEnemyDecorator(std::move(enemy))
{
}

void ShieldDecorator::move()
{
    Enemy::move();
    enemy()->move();
}
