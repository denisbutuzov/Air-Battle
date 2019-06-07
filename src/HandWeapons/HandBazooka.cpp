#include "GameObjects/Gunshells/Gunshell.h"

#include "HandBazooka.h"

HandBazooka::HandBazooka(std::shared_ptr<QGraphicsScene> scene, int delayBetweenShots)
    : HandWeapon(scene, delayBetweenShots)
{
}

std::unique_ptr<Gunshell> HandBazooka::shoot(qreal x, qreal y)
{    
    HandWeapon::startDelayBetweenShotsTimer();
    auto gunshell = std::make_unique<Gunshell>(scene(), ":/images/images/Bazooka_gunshell.png", 2);
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
