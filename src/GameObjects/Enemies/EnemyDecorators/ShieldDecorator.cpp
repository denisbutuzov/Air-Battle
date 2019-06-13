#include "ShieldDecorator.h"

ShieldDecorator::ShieldDecorator(std::unique_ptr<Enemy> enemy,
                                 int hitpoint)
    : AbstractEnemyDecorator(std::move(enemy), hitpoint)
{
}

void ShieldDecorator::init()
{
    resize();
    AbstractEnemyDecorator::init();
}

void ShieldDecorator::move()
{
    Enemy::move();
    enemy()->move();
}

void ShieldDecorator::resize()
{
    auto newPixmapWidth = enemy()->pixmap().width() * 1.2;
    setPixmap(pixmap().scaledToWidth(static_cast<int>(newPixmapWidth)));
    setPos(QPointF(enemy()->pos() + QPointF(static_cast<int>(-newPixmapWidth * 0.1), 20.0)));
}
