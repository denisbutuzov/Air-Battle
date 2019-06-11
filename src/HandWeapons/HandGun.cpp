#include "GameObjects/Gunshells/Gunshell.h"

#include "HandGun.h"

constexpr const char *GUN_GUNSHELL_IMAGE = ":/images/images/Gun_gunshell.png";

HandGun::HandGun(std::weak_ptr<QGraphicsScene> scene)
//, int delayBetweenShots)
    : HandWeapon(scene)
//    , delayBetweenShots)
{
}

std::unique_ptr<Gunshell> HandGun::shoot(qreal x, qreal y)
{
//    HandWeapon::startDelayBetweenShotsTimer();
    auto gunshell = std::make_unique<Gunshell>(scene(), 1);
    gunshell->setPixmap(QPixmap(GUN_GUNSHELL_IMAGE));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
