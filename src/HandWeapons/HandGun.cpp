#include "GameObjects/Gunshells/Gunshell.h"

#include "HandGun.h"

HandGun::HandGun(const std::shared_ptr<QGraphicsScene> &scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandGun::shoot(qreal x, qreal y)
{
    auto gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/Bullet.png", 1);
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
