#include "GameObjects/Gunshells/Gunshell.h"

#include "HandGun.h"

constexpr unsigned int GUN_SHOT_DELAY = 100;
constexpr const char *GUN_SHOT_SOUND = "qrc:/sounds/sounds/bullet.wav";
constexpr const char *GUN_GUNSHELL_IMAGE = ":/images/images/Gun_gunshell.png";

HandGun::HandGun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, 0, 0, GUN_SHOT_DELAY, GUN_SHOT_SOUND)
{
}

std::unique_ptr<Gunshell> HandGun::createGunshell(qreal x, qreal y)
{
    auto gunshell = std::make_unique<Gunshell>(scene(), 1);
    gunshell->setPixmap(QPixmap(GUN_GUNSHELL_IMAGE));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}

bool HandGun::unlimitedPatrons() const
{
    return true;
}
