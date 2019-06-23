#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandGun.h"

HandGun::HandGun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, AppSettings::instance().objects().gun_.capacity_,
                 AppSettings::instance().objects().gun_.startPatrons_,
                 AppSettings::instance().objects().gun_.shotDelay_,
                 AppSettings::instance().objects().gun_.shotSound_)
{
}

std::unique_ptr<Gunshell> HandGun::createGunshell(qreal x, qreal y)
{
    auto gunshell = std::make_unique<Gunshell>(scene(), 1);
    gunshell->setPixmap(QPixmap(AppSettings::instance().objects().gun_.gunshell_));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}

bool HandGun::unlimitedPatrons() const
{
    return true;
}
