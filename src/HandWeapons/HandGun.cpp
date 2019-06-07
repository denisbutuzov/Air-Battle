#include "GameObjects/Gunshells/Gunshell.h"

#include "HandGun.h"

HandGun::HandGun(std::shared_ptr<QGraphicsScene> scene, int delayBetweenShots)
    : HandWeapon(scene, delayBetweenShots)
{
}

std::unique_ptr<Gunshell> HandGun::shoot(qreal x, qreal y)
{
    HandWeapon::startDelayBetweenShotsTimer();
    auto gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/Gun_gunshell.png", 1);
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
