#include "GameObjects/Gunshells/Gunshell.h"

#include "HandBazooka.h"

HandBazooka::HandBazooka(const std::shared_ptr<QGraphicsScene> &scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandBazooka::shoot(qreal x, qreal y)
{    
    auto gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/rocket.png", 2);
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
