#include "Bullet.h"

#include "HandMachinegun.h"

void HandMachinegun::shoot(QGraphicsScene *scene, qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;
    Bullet *bullet = nullptr;

    if(side == SIDE::LEFT)
    {
        bullet = new Bullet(x - 30, y + 60);
        side = SIDE::RIGHT;
    }
    else if(side == SIDE::RIGHT)
    {
        bullet = new Bullet(x + 30, y + 60);
        side = SIDE::LEFT;
    }

    bullet->init(scene);
}
