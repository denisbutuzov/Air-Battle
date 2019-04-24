#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjectBuilders/PresetPositionBuilder.h"

#include "HandGun.h"

HandGun::HandGun(const std::shared_ptr<QGraphicsScene> &scene)
    : HandWeapon(scene)
{
}

std::unique_ptr<Gunshell> HandGun::shoot(qreal x, qreal y)
{
    PresetPositionBuilder builder;
    return builder.buildGunshell(scene(), 10, 1, ":/images/images/Bullet.png", QPointF(x, y));
}
