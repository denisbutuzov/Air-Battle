#include "Rocket.h"

#include "HandBazooka.h"

void HandBazooka::shoot(QGraphicsScene *scene, qreal x, qreal y)
{
    Rocket *rocket = new Rocket(x, y);
    rocket->init(scene);
}
