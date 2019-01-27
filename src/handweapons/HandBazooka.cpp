#include "Rocket.h"

#include "HandBazooka.h"

HandBazooka::HandBazooka(QGraphicsScene *scene)
    : HandWeapon(scene)
{
}

void HandBazooka::shoot(qreal x, qreal y)
{
    Rocket *rocket = new Rocket(scene(), x, y);
    rocket->init();
}
