#include "GameObjects/Gunshells/Gunshell.h"

#include "HandBazooka.h"

constexpr const char *BAZOOKA_GUNSHELL_IMAGE = ":/images/images/Bazooka_gunshell.png";

HandBazooka::HandBazooka(std::weak_ptr<QGraphicsScene> scene, int delayBetweenShots)
    : HandWeapon(scene, delayBetweenShots)
{
}

std::unique_ptr<Gunshell> HandBazooka::shoot(qreal x, qreal y)
{    
    HandWeapon::startDelayBetweenShotsTimer();
    auto gunshell = std::make_unique<Gunshell>(scene(), 2);
    gunshell->setPixmap(QPixmap(BAZOOKA_GUNSHELL_IMAGE));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
