#include "ShieldDecorator.h"

ShieldDecorator::ShieldDecorator(std::unique_ptr<Enemy> enemy,
                                 int hitpoint)
    : AbstractEnemyDecorator(std::move(enemy), hitpoint)
{
}

void ShieldDecorator::init()
{
    initShield();
    AbstractEnemyDecorator::init();
}

void ShieldDecorator::move()
{
    auto pos1 = enemy()->pos();
    enemy()->move();
    auto deltaPos = enemy()->pos() - pos1;
    setPos(pos() + deltaPos);
}

void ShieldDecorator::initShield()
{
    auto newPixmapWidth = enemy()->pixmap().width() * 1.2;
    setPixmap(pixmap().scaledToWidth(static_cast<int>(newPixmapWidth)));
    auto x = enemy()->pos().x() - newPixmapWidth * 0.1;
    auto y = enemy()->pos().y() + enemy()->pixmap().height() * 0.8;
    setPos(x, y);
}
